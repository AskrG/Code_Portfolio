% ============================================================
% Author: Fei Gao
% Email: fei.gao@uzh.ch
% Modified: 14.09.2023
% ============================================================
% Preprocessing
% Input: vp0x_innosuisse.bdf, vp0x_stimuli_length.txt
% Output: vp0x_preprocessed.mat
% ============================================================
%% Script information
clear;
clc;

% ============ input participant number e.g. '02' ============
number = '04';

% ===================== click on run all =====================
% >> visual inspection + browse on raw data
% >> if reject channels/trials, modified data is saved to placeholder_reject
% >> interpolation is skipped by default
% >> databrowser on preprocessed data
% >> result saved to the output folder

%% Names and Directories
% create filenames based on the number string
name_data                   = ['vp', number, '_innosuisse.bdf'];
name_lengthFile             = ['vp', number, '_stimuli_length.txt'];
name_preprocessed           = ['vp', number, '_preprocessed.mat'];
% add directories to paths
cd('/Users/askr/Desktop/Courses/Innosuisse/dataNcodes/data')

%% Define trial
cfg                         = [];
cfg.dataset                 = name_data;
% raw_data                  = ft_databrowser(cfg);
cfg.trialdef.eventtype      = 'STATUS';
cfg.trialdef.eventvalue     = 11;
cfg.trialdef.prestim        = 2; % two seconds before 
cfg.trialdef.poststim       = 10; % placeholder
cfg                         = ft_definetrial(cfg);

%% Adjust lengths
lengths                     = load(name_lengthFile); % load lengths
hdr                         = ft_read_header(cfg.dataset); % read header for sampling rate
% loop to adjust trial length
for i = 1:length(cfg.trl)
    % begin and end with?
    beginsample             = cfg.trl(i, 1);
    triallength             = round((lengths(i)+2) * hdr.Fs);
    % modify which sample to start and end
    cfg.trl(i, 2)           = beginsample + triallength - 1;
end 
data                        = ft_preprocessing(cfg);

% Check the data
dataToCheck                 = cellfun(@length, data.time)/hdr.Fs - 2;
find_matching_music(dataToCheck, number);

%% Resampling
cfg                         = [];
cfg.resamplefs              = 500; % otherwise cant do hp filter > 1
data                        = ft_resampledata(cfg, data);

%% define the eeg channels

allChannels                 = data.label'; % label returns a column, convert to row
ekgChannels                 = {'RA', 'LA', 'LL'};
if ismember(number, {'02', '04'}) % 02 and 04 has shorter setting
    excludeChannels         = {'Erg1', 'RA', 'LA', 'LL', 'EXG4', 'EXG5', 'EXG6', 'EXG7', 'EXG8', 'Status'};  
else
    excludeChannels         = {'Erg1', 'RA', 'LA', 'LL', 'EXG4', 'EXG5', 'EXG6', 'EXG7', 'EXG8', 'Status', 'Erg2', 'GSR1', 'GSR2', 'Plet', 'Resp', 'Temp'};
end
eegChannels                 = setdiff(allChannels, excludeChannels);

%% Identify bad channels

% % identify bad channels
% cfg                         = [];
% cfg.method                  = 'summary';
% cfg.channel                 = eegChannels;
% cfg.layout                  = 'biosemi32.lay';  % specify your layout here
% placeholder_reject          = ft_rejectvisual(cfg, data);

% browse
cfg                         = [];
cfg.channel                 = eegChannels;
cfg.continuous              = 'yes';
cfg.layout                  = 'biosemi32.lay';
cfg.ylim                    = [-20 20];
cfg.viewmode                = 'vertical';
cfg.preproc.demean          = 'yes';
cfg.blocksize               = 5; % time window to browse
cfg.artfctdef.blinks.artifact     = [];
cfg.artfctdef.badchannel.artifact = [];
cfg.artfctdef.muscle.artifact     = [];
placeholder_browse          = ft_databrowser(cfg, data);

%% Interpolate

% bad_channels = {'CP1'}; % 'CP1' for 04
% 
% cfg                         = [];
% cfg.channel                 = eegChannels;
% cfg.method                  = 'template';
% cfg.template                = 'biosemi32_neighb.mat';
% neighbours                  = ft_prepare_neighbours(cfg);
% 
% cfg                         = [];
% cfg.method                  = 'weighted';
% cfg.badchannel              = bad_channels;
% cfg.neighbours              = neighbours;
% cfg.elec                    = 'standard_1020.elc';
% cfg.senstype                = 'EEG';
% data                        = ft_channelrepair(cfg, data);

%% Rereference

% % EEG (remove biosemi CMS)
cfg                         = [];
cfg.channel                 = eegChannels; % '-Erg1';
cfg.reref                   = 'yes';
cfg.refchannel              = eegChannels;
data                        = ft_preprocessing(cfg, data);

%% Baseline correction and Filter

cfg.demean                  = 'yes';
cfg.cfg.baselinewindow      = [-2 0]; % default all

cfg                         = []; 
cfg.detrend                 = 'yes';
cfg.hpfilter                = 'yes';    
cfg.hpfreq                  = 1;     
cfg.lpfilter                = 'yes';   
cfg.lpfreq                  = 40;
cfg.dftfilter               = 'yes';    
cfg.dftfreq                 = [50 100 150]; % 50hz in EU + harmonics

data                        = ft_preprocessing(cfg, data);

save(name_preprocessed, 'data', 'eegChannels');
fprintf(['\nPreprocessed data saved to: ' name_preprocessed '\n']);

%% Data Broswer

% load('vp02_preprocessed.mat', 'data', 'eegChannels')
% load('vp03_preprocessed.mat', 'data', 'eegChannels')
load('vp04_preprocessed.mat', 'data', 'eegChannels')
% load('vp02_preprocessed.mat', 'data', 'eegChannels')

cfg                         = [];
cfg.channel                 = eegChannels;
% cfg.continuous              = 'yes';
cfg.viewmode                = 'vertical'; % 'butterfly', or after ICA/PCA 'component' 
cfg.blocksize               = 5;  % set how many seconds to view
cfg.ylim                    = [-20 20]; % [-5 5];
cfg.plotevents              = 'yes';
cfg.preproc.demean          = 'yes';
cfg.layout                  = 'biosemi32.lay';
cfg                         = ft_databrowser(cfg, data);
