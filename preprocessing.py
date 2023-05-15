"""
Eye Tracking: Experiment design and machine learning methods
Assignment 3
GAO Fei (22-736-359)
"""

from argparse import ArgumentParser, FileType
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import scipy as sp
from typing import TextIO


# some quick commands for running:
# python preprocessing.py --mode dispersion --trial 11 --freq 60 --dis_thres 20 JumpingDots60.csv
# python preprocessing.py --mode dispersion --trial 13 --freq 2000 --dis_thres 20 JumpingDots2000.csv
# python preprocessing.py --mode velocity --trial 14 --freq 60 --vel_thres 10 JumpingDots60.csv
# python preprocessing.py --mode velocity --trial 12 --freq 2000 --vel_thres 5 JumpingDots2000.csv


def read_file(infile: TextIO, trial_id: int, freq):
    """
    Read in the raw eye tracking data
    :param infile: raw eye tracking file: trialID, pointID, time, x_left, y_left, pupil_left, x_right, y_right, pupil_right
    :param trial_id: the trial ID to focus on
    :return:
    """
    # Our codes start here
    df = pd.read_csv(infile.name)
    df = df[df['trialId'] == trial_id].reset_index(drop=True)
    if freq == 2000:
        df["dtime"] = 0
        if df['time'][0] == df['time'][1]:
            df.loc[1::2, "dtime"] = 0.5
        else:
            df.loc[0::2, "dtime"] = 0.5
        df["time"] = df["time"] + df["dtime"]
    return df


def get_dispersion(df):
    x_dispersion = np.ptp(df.x_right)
    y_dispersion = np.ptp(df.y_right)
    return (x_dispersion + y_dispersion) / 2


def idt(df, dispersion_threshold, duration_threshold):
    """ Implementation of the duration-based fixation algorithm. """
    df = df.dropna()
    fixations = []

    i = 0
    while i < len(df.index):
        end_time = df.iloc[i].time + duration_threshold
        df_window = df[df["time"] < end_time][i:]
        dispersion = get_dispersion(df_window)

        if dispersion <= dispersion_threshold:
            j = i + len(df_window.index) - 1
            while dispersion <= dispersion_threshold and j < len(df.index):
                j = j + 1
                df_window = df.iloc[i : j + 1]
                dispersion = get_dispersion(df_window)

            df_window = df.iloc[i : j]
            fixation = { "startTime" : df_window.iloc[ 0].time
                       , "endTime"   : df_window.iloc[-1].time
                       , "centroidX" : np.mean(df_window.x_right)
                       , "centroidY" : np.mean(df_window.y_right)
                       }
            fixations.append(fixation)
            i = j
        else:
            i = i + 1

    return pd.DataFrame(fixations)


def ivt(df, velocity_threshold):
    """ Implementation of the velocity-based fixation detection algorithm. """
    df['velocity'] = np.sqrt((df['x_right'] - df['x_right'].shift()) ** 2 + (df['y_right'] - df['y_right'].shift()) ** 2) / (df['time'] - df['time'].shift())
    df = df.replace([np.inf, -np.inf], np.nan).dropna()
    df["under_threshold"] = df["velocity"] < velocity_threshold
    groups, _ = sp.ndimage.label(df["under_threshold"])
    ref_df = pd.DataFrame({'times': df.time, 'group': groups})
    fixations = (ref_df[ref_df['group'] != 0].groupby('group')['times'].agg(startTime='first', endTime='last'))

    return fixations


def pretty_print(df, fixations, args):
    fig, ax = plt.subplots(figsize=(12, 6), dpi=120)

    ax.plot(df.time, df.x_right, linewidth=0.8, label="horizontal movement")
    ax.plot(df.time, df.y_right, linewidth=0.8, label="vertical movement")

    plt.ylabel('Position in Pixels [px]')
    plt.xlabel('Time [ms]')
    ax.tick_params(axis='y')

    if args.mode == 'velocity':
        ax_ = ax.twinx()
        ax_.set_ylim([0, 50])
        ax_.set_ylabel('velocity [px/ms]')
        ax_.plot(df.time, df.velocity, label="velocity", color="yellowgreen", linewidth=0.75)
        ax_.axhline(y=args.vel_thres, color='r', linewidth=1)
        ax_.tick_params(axis='y')
        ax_.legend(loc="upper right")

    ymin, ymax = ax.get_ylim()
    for i, r in fixations.iterrows():
        ax.fill_between([r.startTime, r.endTime], ymin, ymax,
                        alpha=0.25, color='grey', edgecolor=None,
                        label="fixations" if i == 0 else "")
    
    ax.xaxis.set_major_formatter('{x:.0f}')
    ax.legend(loc="upper left")

    if args.mode == 'dispersion':
        plt.title(f"{args.freq} Hz, Trial {args.trial} (dispersion, {args.dis_thres} pixels, {args.dur_thres} ms)")
        output_path = f"{args.freq}Hz_Trial{args.trial}_dispersion_{args.dis_thres}px_{args.dur_thres}ms)"
    if args.mode == 'velocity':
        plt.title(f"{args.freq} Hz, Trial {args.trial} (velocity, {args.vel_thres} pixels/ms, {args.dur_thres} ms)")
        output_path = f"{args.freq}Hz_Trial{args.trial}_velocity_{args.vel_thres}_pxms_{args.dur_thres}ms)"

    fig.savefig(output_path + ".png")

    print("Figure printed.")


def get_parser() -> ArgumentParser:
    parser = ArgumentParser(description='Preprocess raw eye tracking data.')
    parser.add_argument('infile', type=FileType('r', encoding='utf-8'),
                        help='Input file with raw eye tracking data.')
    parser.add_argument('--mode', type=str, choices=['dispersion', 'velocity'], required=True,
                        help='The kind of algorithm to apply for fixation detection')
    parser.add_argument('--trial', type=int, help='the trial ID')
    parser.add_argument('--freq', type=int, choices=[60, 2000], required=True,
                        help='the sampling frequency')
    parser.add_argument('--vel_thres', type=float, help='the min velocity threshold for I-VT, in pixels/ms')
    parser.add_argument('--dis_thres', type=float, help='the max dispersion threshold for I-DT, in pixels')
    parser.add_argument('--dur_thres', type=float, default=200, help='the min duration threshold for I-DT in ms')

    return parser


def main():
    parser = get_parser()
    args = parser.parse_args()
    
    # command line input checker
    if args.mode == 'dispersion' and args.dis_thres is None:
        raise ValueError('Dispersion threshold not specified in dispersion mode.')
        
    if args.mode == 'velocity' and args.vel_thres is None:
        raise ValueError('Velocity threshold not specified in velocity mode.')

    df = read_file(args.infile, args.trial, args.freq)

    if args.mode == 'dispersion':
        fixations = idt(df, args.dis_thres, args.dur_thres)
        pretty_print(df, fixations, args)

    if args.mode == 'velocity':
        fixations = ivt(df, args.vel_thres)
        pretty_print(df, fixations, args)

    print("Program finished.")

    
if __name__ == '__main__':
    main()