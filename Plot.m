% ============================================================
% Author: Fei Gao
% Email: fei.gao@uzh.ch
% Modified: 14.09.2023
% ============================================================
% Plotting
% Input: vpxx_TFR_spectra.mat, result_trial.mat
% Output: 
% vpxxGrandAvgSpec.pdf
% vpxxGrandAvgTopo.pdf
% vpxx_sur1_delta_0.pdf
% 
% ============================================================
%% Plot UI
clear; clc;
cd('/Users/askr/Desktop/Courses/Innosuisse/dataNcodes/data')

% ================= input participant number =================
number                      = '05';
% ============== pick clean level: ica/ica_more ==============
cleanLevel                  = ''; % regular(-blink, -saccade)
% cleanLevel                  = 'more_';% additional(-T7 T8)
% =========== choose input: varied of fixed length ===========
dataLength                  = '';
% dataLength                  = 'Fix';
% ============================================================

% automatic
inputTFR                   = ['vp', number, '_TFR_', cleanLevel, 'spectra', dataLength, '.mat']; 
% inputTFR                   = ['vp', number, '_TFR_', more, 'spectra', length, '_rel.mat']; 
load("result_trial.mat");
load(inputTFR);

if isempty(cleanLevel)
    clean                   = 'conservative';
else
    clean                   = 'thoroughly cleaned';
end

if isempty(dataLength)
    timeAnalysis            = 'dynamically adjusted time';
else
    timeAnalysis            = 'time 0-38';
end

fprintf('Plotting participant %s, using %s data in %s.\n', number, clean, timeAnalysis);

delta                       = [1 4];
theta                       = [4 8];
alpha                       = [8 13];
deltaAndTheta               = [1 8];
beta                        = [13 32];
gamma                       = [32 40];
all                         = [1 40];

freqBands.delta             = [1 4];
freqBands.theta             = [4 8];
freqBands.deltaAndTheta     = [1 8];
freqBands.alpha             = [8 13];
freqBands.beta              = [13 32];
freqBands.gamma             = [32 40];
freqBands.all               = [1 40];
waveNames                   = fieldnames(freqBands);

left                        = {'T7', 'CP5'};
right                       = {'T8', 'CP6'};
central                     = {'Cz', 'CP1', 'CP2'};
channelList.left            = {'T7', 'CP5'};
channelList.right           = {'T8', 'CP6'};
channelList.central         = {'Cz', 'CP1', 'CP2'};
channelNames                = fieldnames(channelList);

% For grand average
% >> run "Plot GrandAverage"
% >> if trial 3, change zlim
% >> result: singleplot and topopolot

% For single trial
% >> run "Plot a certain trial"
% >> configure the trial number and the wave band
% >> if trial 3, change zlim
% >> result: multiplot of powerspectra, and topographical mapping

% For continuum
% >> run "Map a continuum"
% >> configure the emotion and the wave band
% >> result: powerspectrum and topographical mapping

% For map low(0+1) and high(5+4/6)
% >> run "Map low and high"
% >> configure the emotion and the wave band
% >> result: 2 powerspectra and 2 topographical mappings

%% Plot Single
% cfg                         = [];
% cfg.ylim                    = [8 13];
% cfg.zlim                    = [-50 200]; % the value 1 means 100%, so this ranges from 60% to 140% of the baseline power
% cfg.baseline                = [-2 0];
% cfg.baselinetype            = 'relchange';
% cfg.layout                  = 'biosemi32.lay';
% figure; ft_topoplotTFR(cfg,allSpec{1:1}); colorbar;

%% Plot GrandAverage
cfg                         =[];
[grandAvg]                  = ft_freqgrandaverage(cfg, allSpec{:});
grandAvg.powspctrm          = 10*log10(grandAvg.powspctrm);

% spectrum
cfg.layout                  = 'biosemi32.lay';
cfg.parameter               = 'powspctrm'; 
% cfg.ylim                    = wave;
cfg.zlim                    = [0 10];
cfg.colorbar                = 'yes'; 
ft_singleplotTFR(cfg, grandAvg)

f                           = gcf;
% f.Position                  = [100, 100, 800, 800];  % Adjust the values as needed
specName                    = ['vp', number, 'GrandAvgSpec.pdf'];
print(f, '-dpdf', specName);

% topographical mapping
cfg                         = [];
cfg.layout                  = 'biosemi32.lay';
cfg.colorbar                = 'yes'; 
cfg.zlim                    = [0 10];
cfg.contournum              = 8;
% cfg.ylim                    = wave;
% cfg.colormap                = '*RdBu';
ft_topoplotTFR(cfg, grandAvg);

f                           = gcf;
% f.Position                  = [100, 100, 800, 800];  % Adjust the values as needed
topoName                    = ['vp', number, 'GrandAvgTopo.pdf'];
print(f, '-dpdf', topoName);

disp(['Figure saved to ' specName]);
disp(['Figure saved to ' topoName]);

% Deicde a zlim
flatSpectrum = grandAvg.powspctrm(:);
sortedSpectrum = sort(flatSpectrum);
lowest10Values = sortedSpectrum(1:10);
highest10Values = sortedSpectrum(end-9:end);
% result: [-14 23]
%% Plot a certain trial
% ==================== input trial number ====================
trial                       = i; %1-31
% ============= input target band to investigate =============
wave                        = deltaAndTheta; 
% wave                        = alpha; 
% =============== input channels to investigate ==============
% selectedChannels            = left;
% selectedChannels            = right;
% selectedChannels            = central;
% =================== modify the plot range ==================
% plotRange                   = [-5 15];
% plotRange                   = [5 15];
plotRange                   = [-5 15]; % alpha
% plotRange                   = [-2 12]; % beta
% plotRange                   = [-5 8]; % beta
% plotRange                   = [-10 10]; % gamma
% ============================================================
for i = 1:numel(waveNames)
    if isequal(wave, freqBands.(waveNames{i}))
        waveName = waveNames{i};
        break;
    end
end

for j = 1:numel(channelNames)
    if isequal(selectedChannels, channelList.(channelNames{j}))
        channelName = channelNames{j};
        break;
    end
end

% multiplot
% cfg                         = [];
% cfg.showlabels              = 'yes';
% cfg.layout                  = 'biosemi32.lay';
% cfg.ylim                    = wave;
% cfg.zlim                    = plotRange; 
% cfg.channel                 = {'T7', 'CP5'};
% ft_multiplotTFR(cfg, allSpec{trial});

% topoplot
% cfg                         = [];
% cfg.layout                  = 'biosemi32.lay';
% cfg.xlim                    = [0 20];
% cfg.ylim                    = wave;
% cfg.zlim                    = plotRange;
% cfg.colorbar                = 'yes';
% ft_topoplotTFR(cfg, allSpec{trial});

% calculate power spectrum for low and for high
grandAvg                    = allSpec{trial};
grandAvg.powspctrm          = 10*log10(grandAvg.powspctrm);

% spectral mapping
cfg                         = [];
cfg.layout                  = 'biosemi32.lay';
cfg.parameter               = 'powspctrm'; 
cfg.xlim                    = [0 20];
cfg.ylim                    = wave;
cfg.zlim                    = plotRange;
cfg.channel                 = selectedChannels;
cfg.colorbar                = 'yes'; 
ft_singleplotTFR(cfg, grandAvg);
set(gcf, 'Position', [100, 100, 1200, 300]);
figName = ['vp', num2str(number), '_', waveName, '_', num2str(trial), '_', channelName '.jpg'];
saveas(gcf, figName);
close(gcf);

%% Batch processing trials
waveTypes                   = {'deltaAndTheta', 'alpha'};
plotRange                   = [-5 15];
default_width               = 1200;
default_time                = 55;
scaling_factor              = default_width / default_time;
height                      = 150;

for trial = 1:31
    max_time = max(allSpec{1, trial}.time);
    counter = 0;
    if max_time <= default_time
        new_width = scaling_factor * max_time;
        % ============ code starts here ============
        for w = 1:2  % Loop through wave types
            % define waveName and select channels
            waveName = waveTypes{w};
            if strcmp(waveName, 'deltaAndTheta')
                channelNameList     = {'left', 'right'};
                wave                = [1, 8];
            else 
                channelNameList     = {'central'};
                wave                = [8, 13];
            end
    
            for s = 1:length(channelNameList) 
                channelName         = channelNameList{s};
            % now: a waveName and a channelName to print, a wave to use
    
                if strcmp(channelName, 'left')
                    selectedChannels = left;
                elseif strcmp(channelName, 'right')
                    selectedChannels = right;
                else  % for 'central'
                    selectedChannels = central;
                end
                % now: waveName and channelName to print
                % wave and selectedChannels to use
                
                % calculate power spectrum
                grandAvg                    = allSpec{trial};
                grandAvg.powspctrm          = 10*log10(grandAvg.powspctrm);

                % spectral mapping
                cfg                         = [];
                cfg.layout                  = 'biosemi32.lay';
                cfg.parameter               = 'powspctrm'; 
                cfg.ylim                    = wave;
                cfg.zlim                    = plotRange;
                cfg.channel                 = selectedChannels;
                cfg.colorbar                = 'yes'; 
                ft_singleplotTFR(cfg, grandAvg);
                set(gcf, 'Position', [100, 100, new_width, height]);
                figName = ['vp', num2str(number), '_', waveName, '_', num2str(trial), '_', channelName, '_', num2str(counter), '.jpg'];
                saveas(gcf, figName);
                close(gcf);
            end
        end
        % ============ code ends here ============   
    else
        % above 60 seconds, first plot the initial 60-second
        % ============ code starts here ============
        for w = 1:2  % Loop through wave types
            % define waveName and select channels
            waveName = waveTypes{w};
            if strcmp(waveName, 'deltaAndTheta')
                channelNameList     = {'left', 'right'};
                wave                = [1, 8];
            else 
                channelNameList     = {'central'};
                wave                = [8, 13];
            end
    
            for s = 1:length(channelNameList) 
                channelName         = channelNameList{s};
            % now: a waveName and a channelName to print, a wave to use
    
                if strcmp(channelName, 'left')
                    selectedChannels = left;
                elseif strcmp(channelName, 'right')
                    selectedChannels = right;
                else  % for 'central'
                    selectedChannels = central;
                end
                % now: waveName and channelName to print
                % wave and selectedChannels to use
                
                % calculate power spectrum
                grandAvg                    = allSpec{trial};
                grandAvg.powspctrm          = 10*log10(grandAvg.powspctrm);

                % spectral mapping
                cfg                         = [];
                cfg.layout                  = 'biosemi32.lay';
                cfg.parameter               = 'powspctrm'; 
                cfg.xlim                    = [0, default_time];
                cfg.ylim                    = wave;
                cfg.zlim                    = plotRange;
                cfg.channel                 = selectedChannels;
                cfg.colorbar                = 'yes'; 
                ft_singleplotTFR(cfg, grandAvg);
                set(gcf, 'Position', [100, 100, default_width, height]);
                figName = ['vp', num2str(number), '_', waveName, '_', num2str(trial), '_', channelName, '_', num2str(counter), '.jpg'];
                saveas(gcf, figName);
                close(gcf);
            end
        end
        % ============ code ends here ============  
        % Loop to plot remaining time chunks
        counter = 0;
        for t = default_time:default_time:max_time
            blockLength = min(default_time, max_time - t + 1);
            new_width = scaling_factor * blockLength;
            counter = counter + 1;
            newEnd = t + blockLength;
        % ============ code starts here ============
            for w = 1:2  % Loop through wave types
                % define waveName and select channels
                waveName = waveTypes{w};
                if strcmp(waveName, 'deltaAndTheta')
                    channelNameList     = {'left', 'right'};
                    wave                = [1, 8];
                else 
                    channelNameList     = {'central'};
                    wave                = [8, 13];
                end
        
                for s = 1:length(channelNameList) 
                    channelName         = channelNameList{s};
                    if strcmp(channelName, 'left')
                        selectedChannels = left;
                    elseif strcmp(channelName, 'right')
                        selectedChannels = right;
                    else  % for 'central'
                        selectedChannels = central;
                    end

                    % now: waveName and channelName to print
                    % wave and selectedChannels to use
                    
                    % calculate power spectrum
                    grandAvg                    = allSpec{trial};
                    grandAvg.powspctrm          = 10*log10(grandAvg.powspctrm);
        
                    % spectral mapping
                    cfg                         = [];
                    cfg.layout                  = 'biosemi32.lay';
                    cfg.parameter               = 'powspctrm'; 
                    cfg.xlim                    = [t, newEnd];
                    cfg.ylim                    = wave;
                    cfg.zlim                    = plotRange;
                    cfg.channel                 = selectedChannels;
                    cfg.colorbar                = 'yes'; 
                    ft_singleplotTFR(cfg, grandAvg);
                    set(gcf, 'Position', [100, 100, new_width, height]);
                    figName = ['vp', num2str(number), '_', waveName, '_', num2str(trial), '_', channelName, '_', num2str(counter), '.jpg'];
                    saveas(gcf, figName);
                    close(gcf);
                end
            end
        % ============ code ends here ============
        end
    end  
end

%% Databrowser
load('vp02_ica.mat');
% load('vp02_ica_more.mat');

cfg                         = [];
cfg.viewmode                = 'vertical'; % 'butterfly', or after ICA/PCA 'component' 
% cfg.blocksize               = 5;  % set how many seconds to view
cfg.ylim                    = [-20 20];
cfg.plotevents              = 'yes';
cfg.preproc.demean          = 'yes';
cfg.layout                  = 'biosemi32.lay';
cfg                         = ft_databrowser(cfg, data_ica);

%% Map a continuum
% ============= input target band to investigate =============
% wave                        = delta;
% wave                        = theta;
% wave                        = alpha;
% wave                        = beta;
wave                        = gamma;
% =============== input emotion to investigate ===============
emotion                     = 'sur1';
% emotion                     = 'sur2';
% emotion                     = 'em1';
% emotion                     = 'em2';
% emotion                     = 'em3';
% emotion                     = 'em4';
% emotion                     = 'em5';
% emotion                     = 'em6';
% emotion                     = 'em7';
% emotion                     = 'em8';
% emotion                     = 'em9';
% =================== modify the plot range ===================
% plotRange                   = [0 15];
% plotRange                   = [5 15];
% plotRange                   = [3 15]; % alpha
% plotRange                   = [-2 12]; % beta
% plotRange                   = [-5 8]; % beta
plotRange                   = [-10 10]; % gamma
% =============================================================


counter                     = [];
for i = 1:numel(waveNames)
    if isequal(wave, freqBands.(waveNames{i}))
        waveName = waveNames{i};
        break;
    end
end

for rating = 0:6
    rating_str              = ['x', num2str(rating)];
    % skip if no rating exist
    if ~isfield(result_trial.(['vp', number]).(emotion), rating_str)
        continue;
    end

    % find the trials for each rating in each emotion
    trials                  = result_trial.(['vp', number]).(emotion).(rating_str);

    % debug starts
    % specific trials
    % if rating == 6
    %     trialComponents     = trials;
    % end
    % debug ends
    

    % if only one trial, don't use grandAverage
    if numel(trials) == 1
        grandAvg            = allSpec{trials}; % trial length = 1
        counter             = counter + 1; % check if executed
    else
        cfg = [];
        [grandAvg]          = ft_freqgrandaverage(cfg, allSpec{trials});
    end

    % % debug starts
    % if numel(trials) <= 3
    %     grandAvg            = allSpec{trials(1)}; % trial length = 1
    %     counter             = [counter, rating]; % check if executed
    % else
    %     cfg = [];
    %     % [grandAvg]          = ft_freqgrandaverage(cfg, allSpec{trials});
    % 
    %     % debug starts
    %     [grandAvg]          = ft_freqgrandaverage(cfg, allSpec{trials(1:4, :)});
    %     % debug ends
    % end
    % % debug ends


    % calculate power spectrum
    grandAvg.powspctrm      = 10*log10(grandAvg.powspctrm); % convert to dB

    % If you need to plot it
    % cfg                     = [];
    % cfg.layout              = 'biosemi32.lay';
    % cfg.parameter           = 'powspctrm'; 
    % % cfg.ylim                = wave;
    % cfg.zlim                = [2 15];
    % cfg.colorbar            = 'yes'; 
    % ft_singleplotTFR(cfg, grandAvg);
   
    % Deicde a zlim for the first trial in the group
    % if rating == 2
    %     cfg = [];
    %     [grandAvg2]          = ft_freqgrandaverage(cfg, allSpec{trials(1)});
    %     grandAvg2.powspctrm  = 10*log10(grandAvg2.powspctrm);
    % 
    %     flatSpectrum        = grandAvg2.powspctrm(:);
    %     flatSpectrum        = flatSpectrum(~isnan(flatSpectrum));
    %     sortedSpectrum      = sort(flatSpectrum);
    %     lowest10Values      = sortedSpectrum(1:10);
    %     highest10Values     = sortedSpectrum(end-9:end);
    %     disp('Bottom 10 values:');
    %     disp(lowest10Values);    
    %     disp('Top 10 values:');
    %     disp(highest10Values);
    % end

    % topographical mapping
    cfg                     = [];
    cfg.layout              = 'biosemi32.lay';
    cfg.colorbar            = 'yes';
    cfg.title               = [emotion, '(', num2str(rating), ')'];
    cfg.ylim                = wave;
    cfg.zlim                = plotRange;
    ft_topoplotTFR(cfg, grandAvg);

    % Save the figure after plotting
    figName = ['vp', num2str(number), '_', emotion, '_', waveName, '_', num2str(rating), '.pdf'];
    saveas(gcf, figName);

    % Close the figure
    close(gcf);

end

%% Map low and high

% ============= input target band to investigate =============
% wave                        = delta;
% wave                        = theta;
% wave                        = alpha;
% wave                        = beta;
wave                        = gamma;
% =============== input emotion to investigate ===============
emotion                     = 'sur1';
% emotion                     = 'sur2';
% the code only works for sur1 and sur 2 where rating is from 0 - 6
% if you want to use em1 - em9, the scale is 1-5
% emotion                     = 'em1';
% emotion                     = 'em2';
% emotion                     = 'em3';
% emotion                     = 'em4';
% emotion                     = 'em5';
% emotion                     = 'em6';
% emotion                     = 'em7';
% emotion                     = 'em8';
% emotion                     = 'em9';
% =================== modify the plot range ===================
% plotRange                   = [0 15];
% plotRange                   = [5 15];
% plotRange                   = [3 15]; % alpha
% plotRange                   = [-2 12]; % beta
% plotRange                   = [-5 8]; % beta
plotRange                   = [-10 10]; % gamma
% =============================================================



for i = 1:numel(waveNames)
    if isequal(wave, freqBands.(waveNames{i}))
        waveName = waveNames{i};
        break;
    end
end
outputName                  =['vp', num2str(number), '_', emotion, '_', waveName];

if isfield(result_trial.(['vp', participantNum]).(emotion), 'x0')
    trialsA = result_trial.(['vp', participantNum]).(emotion).('x0');
else
    trialsA = [];
end

if isfield(result_trial.(['vp', participantNum]).(emotion), 'x1')
    trialsB = result_trial.(['vp', participantNum]).(emotion).('x1');
else
    trialsB = [];
end

if isfield(result_trial.(['vp', participantNum]).(emotion), 'x5')
    trialsC = result_trial.(['vp', participantNum]).(emotion).('x5');
else
    trialsC = [];
end

if isfield(result_trial.(['vp', participantNum]).(emotion), 'x6')
    trialsD = result_trial.(['vp', participantNum]).(emotion).('x6');
else
    trialsD = [];
end

trialsL                     = [trialsA; trialsB];
trialsH                     = [trialsC; trialsD];

% if only one trial, don't use grandAverage
if numel(trialsL) == 1
    grandAvg             = allSpec{trialsL};
else
    cfg                     =[];
    [grandAvg]           = ft_freqgrandaverage(cfg, allSpec{trialsL});
end

if numel(trialsH) == 1
    grandAvgHigh            = allSpec{trialsH};
else
    cfg                     =[];
    [grandAvgHigh]          = ft_freqgrandaverage(cfg, allSpec{trialsH});
end

% calculate power spectrum for low and for high
grandAvg.powspctrm       = 10*log10(grandAvg.powspctrm);
grandAvgHigh.powspctrm      = 10*log10(grandAvgHigh.powspctrm);

% spectral mapping for low excitation
cfg                         = [];
cfg.layout                  = 'biosemi32.lay';
cfg.parameter               = 'powspctrm'; 
cfg.ylim                    = wave;
cfg.zlim                    = plotRange;
cfg.colorbar                = 'yes'; 
ft_singleplotTFR(cfg, grandAvg);

% Save the figure after plotting
figName                     = [outputName, '_low_spec.pdf'];
saveas(gcf, figName);
close(gcf);

% spectral mapping for high excitation
cfg                         = [];
cfg.layout                  = 'biosemi32.lay';
cfg.parameter               = 'powspctrm'; 
cfg.ylim                    = wave;
cfg.zlim                    = plotRange;
cfg.colorbar                = 'yes'; 
ft_singleplotTFR(cfg, grandAvgHigh);

% Save the figure after plotting
figName                     = [outputName, '_high_spec.pdf'];
saveas(gcf, figName);
close(gcf);

% topographical mapping for low excitation
cfg                         = [];
cfg.layout                  = 'biosemi32.lay';
cfg.colorbar                = 'yes';
cfg.title                   = ['low ', emotion];
cfg.ylim                    = wave;
cfg.zlim                    = plotRange;
ft_topoplotTFR(cfg, grandAvg);

% Save the figure after plotting
figName                     = [outputName, '_low_topo.pdf'];
saveas(gcf, figName);
close(gcf);

% topographical mapping for high excitation
cfg                         = [];
cfg.layout                  = 'biosemi32.lay';
cfg.colorbar                = 'yes';
cfg.title                   = ['high ', emotion];
cfg.ylim                    = wave;
cfg.zlim                    = plotRange;
ft_topoplotTFR(cfg, grandAvgHigh);

% Save the figure after plotting
figName                     = [outputName, '_high_topo.pdf'];
saveas(gcf, figName);
close(gcf);

%% General Mapping: averaged across participants

% ============= input target band to investigate =============
% wave                        = delta;
% wave                        = theta;
% wave                        = alpha;
% wave                        = beta;
wave                        = gamma;
% =============== input emotion to investigate ===============
emotion                     = 'sur1';
% emotion                     = 'sur2';
% doesnt work for emotion 1 - 9 which has a scale of 1-5
% emotion                     = 'em1';
% emotion                     = 'em2';
% emotion                     = 'em3';
% emotion                     = 'em4';
% emotion                     = 'em5';
% emotion                     = 'em6';
% emotion                     = 'em7';
% emotion                     = 'em8';
% emotion                     = 'em9';
% =================== modify the plot range ===================
% plotRange                   = [4 16];
% plotRange                   = [5 15];
% plotRange                   = [4 16]; % alpha
% plotRange                   = [0 18]; % beta
% plotRange                   = [-5 8]; % beta
plotRange                   = [-10 18]; % gamma
% =============================================================

for i = 1:numel(waveNames)
    if isequal(wave, freqBands.(waveNames{i}))
        waveName = waveNames{i};
        break;
    end
end

dataL = {};
dataH = {};

% find the trials for each rating in each emotion

% Loop through participant numbers 02 to 05
for j = 2:5
    number_str              = sprintf('%02d', j);
    % clean level and data length is defiend at the beginning;
    load(['vp', number_str, '_TFR_', cleanLevel, 'spectra', dataLength, '.mat']);
    % check low
    if isfield(result_trial.(['vp', number_str]).(emotion), 'x0')
        trialL              = result_trial.(['vp', number_str]).(emotion).('x0');
    else
        trialL              = [];
    end
    % check high
    if isfield(result_trial.(['vp', number_str]).(emotion), 'x6')
        trialH              = result_trial.(['vp', number_str]).(emotion).('x6');
    else
        trialH              = [];
    end
    % % Aggregate low-rating trials across all participants
    
    if ~isempty(trialL)
        for t = 1:length(trialL)
            % Add each trial data to the dataL cell array
            dataL = [dataL, allSpec(trialL(t))];  % Horizontal concatenation into a cell array
        end
    end

    % % Aggregate high-rating trials across all participants
    if ~isempty(trialH)
        for t = 1:length(trialH)
            % Add each trial data to the dataL cell array
            dataH = [dataH, allSpec(trialH(t))];  % Horizontal concatenation into a cell array
        end
    end

end

cfg                         =[];
[grandAvg]               = ft_freqgrandaverage(cfg, dataL{:});
grandAvg.powspctrm       = 10*log10(grandAvg.powspctrm);

cfg                         =[];
[grandAvgHigh]              = ft_freqgrandaverage(cfg, dataH{:});
grandAvgHigh.powspctrm      = 10*log10(grandAvgHigh.powspctrm);

% spectral mapping for low excitation
cfg                         = [];
cfg.layout                  = 'biosemi32.lay';
cfg.parameter               = 'powspctrm'; 
cfg.ylim                    = wave;
cfg.zlim                    = plotRange;
cfg.colorbar                = 'yes'; 
ft_singleplotTFR(cfg, grandAvg);

% Save the figure after plotting
figName                     =[emotion, '_low_', waveName, '_spec.pdf'];
saveas(gcf, figName);
close(gcf);

% spectral mapping for high excitation
cfg                         = [];
cfg.layout                  = 'biosemi32.lay';
cfg.parameter               = 'powspctrm'; 
cfg.ylim                    = wave;
cfg.zlim                    = plotRange;
cfg.colorbar                = 'yes'; 
ft_singleplotTFR(cfg, grandAvgHigh);

% Save the figure after plotting
figName                     =[emotion, '_high_', waveName, '_spec.pdf'];
saveas(gcf, figName);
close(gcf);

% topographical mapping for low excitation
cfg                         = [];
cfg.layout                  = 'biosemi32.lay';
cfg.colorbar                = 'yes';
cfg.title                   = ['low ', emotion];
cfg.ylim                    = wave;
cfg.zlim                    = plotRange;
ft_topoplotTFR(cfg, grandAvg);

% Save the figure after plotting
figName                     =[emotion, '_low_', waveName, '_topo.pdf'];
saveas(gcf, figName);
close(gcf);

% topographical mapping for high excitation
cfg                         = [];
cfg.layout                  = 'biosemi32.lay';
cfg.colorbar                = 'yes';
cfg.title                   = ['high ', emotion];
cfg.ylim                    = wave;
cfg.zlim                    = plotRange;
ft_topoplotTFR(cfg, grandAvgHigh);

% Save the figure after plotting
figName                     =[emotion, '_high_', waveName, '_topo.pdf'];
saveas(gcf, figName);
close(gcf);


%% Biosemi 32 layout
cfg                       = [];
cfg.layout                = 'biosemi32.lay';
ft_layoutplot(cfg);
