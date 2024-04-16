% ============================================================
% Author: Fei Gao
% Email: fei.gao@uzh.ch
% Modified: 14.09.2023
% ============================================================
% Time-Frequency Analysis
% Input: vp0x_ica.mat or vp0x_ica_more.mat, vp0x_stimuli_length.txt
% Output: vp0x_TFR_spectra.mat, vp0x_TFR_spectraFix.mat
% ============================================================
%% Edit the participant number
clear; clc;

% ============ input participant number e.g. '02' ============
number                      = '02';
% ============== pick clean level: ica/ica_more ==============
% cleanLevel                  = '';
cleanLevel                  = 'more_';
% ============================================================

% automatic
cd('/Users/askr/Desktop/Courses/Innosuisse/dataNcodes/data')
name_cleaned                = ['vp', number, '_ica.mat'];
name_lengthFile             = ['vp', number, '_stimuli_length.txt'];
name_save                   = ['vp', number, '_TFR_', cleanLevel, 'spectra.mat'];
% name_save                   = ['vp', number, '_TFR_', more, 'spectra_rel.mat'];
name_save_fix               = ['vp', number, '_TFR_', cleanLevel, 'spectraFix.mat'];
% name_save_fix               = ['vp', number, '_TFR_', more, 'spectraFix_rel.mat'];
lengths                     = load(name_lengthFile); % load lengths
numDouble                   = str2double(number);
load(name_cleaned);
allSpec                     = [];
if isempty(cleanLevel)
    clean = 'conservative';
else
    clean = 'thoroughly cleaned';
end

fprintf('Currently doing TFR on participant %s, using %s data.\n', number, clean);
%% Create data of varied length
for i = 1:31
    % Convert the integer to a string and pad with zeros to get two digits
    input_trial             = sprintf('%02d', i);
    % Frequency analysis
    cfg                     = [];
    cfg.method              = 'mtmconvol'; % 'trf'
    cfg.baseline            = [-2 -0];
    cfg.baselinetype        = 'relchange'; % 'relative'
    cfg.output              = 'pow';
    cfg.channel             = 'all';
    cfg.taper               = 'hanning';
    cfg.trials              = str2double(input_trial);
    cfg.foi                 = 1 : 0.5 : 40;
    cfg.toi                 = 0 : 0.2 : lengths(i);
    cfg.t_ftimwin           = ones(1,numel(cfg.foi)).*0.1; % or 0.05
    data_tf                 = ft_freqanalysis(cfg, data_ica);
    % store into allSpec
    data_tf.trial           = i;
    allSpec{i}              = data_tf;
end
save(name_save, 'allSpec');
fprintf('\nSpectral analysis(varied length) finished. Data saved to: %s\n', name_save);

%% Create data of fixed length
for i = 1:31
    % Convert the integer to a string and pad with zeros to get two digits
    input_trial             = sprintf('%02d', i);
    % Frequency analysis
    cfg                     = [];
    cfg.method              = 'mtmconvol'; % 'trf'
    cfg.baseline            = [-2 -0];
    cfg.baselinetype        = 'relchange';
    cfg.output              = 'pow';
    cfg.channel             = 'all';
    cfg.taper               = 'hanning';
    cfg.trials              = str2double(input_trial);
    cfg.foi                 = 1 : 0.5 : 40;
    cfg.toi                 = 0 : 0.5 : 38; % shortest data is 38
    cfg.t_ftimwin           = ones(1,numel(cfg.foi)).*0.1; % or 0.05
    data_tf                 = ft_freqanalysis(cfg, data_ica);
    data_tf.trial           = i;
    % store into allSpec
    allSpec{i}              = data_tf;
end
save(name_save_fix, 'allSpec');
fprintf('\nSpectral analysis(fixed length) finished. Data saved to: %s\n', name_save_fix);
