//
//  AffectiveHandler.h
//  AffectiveAlgorithmSDK_iOS
//
//  Created by Enter M1 on 2023/4/23.
//

#ifndef AffectiveWrapper_h
#define AffectiveWrapper_h
#import <Foundation/Foundation.h>

@interface ArousalReportResOC: NSObject
@property (nonatomic, assign, readwrite) double arousalAvg;
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *arousalRec;
@end

@interface CoherenceReportResOC: NSObject
@property (nonatomic, assign, readwrite) double coherenceAvg;
@property (nonatomic, assign, readwrite) int coherenceDuration;
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *coherenceRec;
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *coherenceFlag;

@end

@interface PleasureReportResOC: NSObject
@property (nonatomic, assign, readwrite) double pleasureAvg;
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *pleasureRec;
@end

@interface PressureReportResOC: NSObject
@property (nonatomic, assign, readwrite) double pressureAvg;
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *pressureRec;
@end

@interface RelaxationReportResOC: NSObject
@property (nonatomic, assign, readwrite) double relaxationAvg;
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *relaxationRec;
@end

@interface AttentionReportResOC: NSObject
@property (nonatomic, assign, readwrite) double attentionAvg;
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *attentionRec;
@end

@interface SleepReportResOC : NSObject
@property (strong, nonatomic) NSMutableArray<NSNumber *> *sleepCurve;
@property (strong, nonatomic) NSMutableArray<NSNumber *> *sleepStage;
@property (nonatomic) int sleepPoint;
@property (nonatomic) int sleepLatency;
@property (nonatomic) int awakeDuration;
@property (nonatomic) int remDuration;
@property (nonatomic) int lightDuration;
@property (nonatomic) int deepDuration;
@property (strong, nonatomic) NSMutableArray<NSNumber *> *eegAlphaCurve;
@property (strong, nonatomic) NSMutableArray<NSNumber *> *eegBetaCurve;
@property (strong, nonatomic) NSMutableArray<NSNumber *> *eegThetaCurve;
@property (strong, nonatomic) NSMutableArray<NSNumber *> *eegDeltaCurve;
@property (strong, nonatomic) NSMutableArray<NSNumber *> *eegGammaCurve;
@property (strong, nonatomic) NSMutableArray<NSNumber *> *eegHighBetaDBCurve;
@property (strong, nonatomic) NSMutableArray<NSNumber *> *eegLowBetaDBCurve;
@property (strong, nonatomic) NSMutableArray<NSNumber *> *eegQualityRec;
@property (nonatomic) int movementCount;
@property (nonatomic) int arousalCount;
@property (nonatomic) double disturbTolerance;
@property (strong, nonatomic) NSMutableArray<NSNumber *> *movementRec;
@property (strong, nonatomic) NSMutableArray<NSNumber *> *arousalRec;
@end

@interface FlowReportResOC : NSObject
@property (nonatomic, assign) double flowAvg; // Average meditation value
@property (nonatomic, strong) NSMutableArray<NSNumber *> *flowRec; // Full record of meditation
@property (nonatomic, strong) NSMutableArray<NSNumber *> *flowTipsRec; // Full record of meditation state tips
@property (nonatomic, assign) double flowPercent; // Percentage of flow state
@property (nonatomic, assign) double flowDuration; // Duration of flow state
@property (nonatomic, assign) double flowLatency; // Time to enter the flow state
@property (nonatomic, assign) int flowCombo; // Maximum continuous time of flow state
@property (nonatomic, assign) double flowDepth; // Maximum depth of flow state
@property (nonatomic, assign) int flowBackNum; // Number of flow state recovery tips
@property (nonatomic, assign) int flowLossNum; // Number of flow state loss tips
@end

@interface HRReportResOC: NSObject
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *hrRec;
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *hrvRec;
@end

@interface EEGReprotResOC: NSObject
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *eegAlphaRec;
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *eegBetaRec;
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *eegThetaRec;
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *eegDeltaRec;
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *eegGammaRec;
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *eegQualityRec;
@end

// SC EEG Report
@interface SCEEGReportResOC : NSObject
@property (nonatomic, strong) NSMutableArray<NSNumber *> *eegAlphaRec; // Full course change curve of brain wave α wave energy
@property (nonatomic, strong) NSMutableArray<NSNumber *> *eegBetaRec; // Full course change curve of brain wave β wave energy
@property (nonatomic, strong) NSMutableArray<NSNumber *> *eegThetaRec; // Full course change curve of brain wave θ wave energy
@property (nonatomic, strong) NSMutableArray<NSNumber *> *eegDeltaRec; // Full course change curve of brain wave δ wave energy
@property (nonatomic, strong) NSMutableArray<NSNumber *> *eegGammaRec; // Full course change curve of brain wave γ wave energy
@property (nonatomic, strong) NSMutableArray<NSNumber *> *eegQualityRec; // Full course change curve of brain wave quality level
@end

@interface PEPRReportResOC : NSObject
@property (nonatomic, assign) int hrAvg; // Average heart rate
@property (nonatomic, assign) int hrMax; // Maximum heart rate
@property (nonatomic, assign) int hrMin; // Minimum heart rate
@property (nonatomic, strong) NSMutableArray<NSNumber *> *hrRec; // Full record of heart rate
@property (nonatomic, strong) NSMutableArray<NSNumber *> *rrRec; // Full record of respiration rate
@property (nonatomic, assign) int rrAvg; // Average respiration rate
@property (nonatomic, strong) NSMutableArray<NSNumber *> *hrvRec; // Full record of heart rate variability
@property (nonatomic, assign) double hrvAvg; // Average heart rate variability
@property (nonatomic, strong) NSMutableArray<NSNumber *> *bcgQualityRec; // Full record of pulse wave signal quality (0: NONE, 1: POOR, 2: NORM)
@property (nonatomic, strong) NSMutableArray<NSNumber *> *rwQualityRec; // Full record of respiration wave signal quality (0: NONE, 1: POOR, 2: NORM)
@end

@interface SleepTriggerResOC : NSObject
@property (nonatomic, assign) double sleepDegree; // Degree of sleep
@property (nonatomic, assign) int sleepState; // Sleep state
@end

@interface FlowTriggerResOC : NSObject
@property (nonatomic, assign) double meditation; // Degree of meditation
@property (nonatomic, assign) double meditationTips; // Meditation state tips
@end

@interface HRTriggerResOC: NSObject
@property (nonatomic, assign, readwrite) double hrv;
@property (nonatomic, assign, readwrite) int hr;
@end

@interface EEGTriggerResOC: NSObject
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *eeglWave;
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *eegrWave;
@property (nonatomic, assign, readwrite) double eegAlphaPower;
@property (nonatomic, assign, readwrite) double eegBetaPower;
@property (nonatomic, assign, readwrite) double eegThetaPower;
@property (nonatomic, assign, readwrite) double eegDeltaPower;
@property (nonatomic, assign, readwrite) double eegGammaPower;
@property (nonatomic, assign, readwrite) double eegQuality;
@end

@interface SCEEGTriggerResOC : NSObject
@property (nonatomic, strong) NSMutableArray<NSNumber *> *eegWave; // Brain wave
@property (nonatomic, assign) double eegAlphaPower; // Alpha wave energy
@property (nonatomic, assign) double eegBetaPower; // Beta wave energy
@property (nonatomic, assign) double eegThetaPower; // Theta wave energy
@property (nonatomic, assign) double eegDeltaPower; // Delta wave energy
@property (nonatomic, assign) double eegGammaPower; // Gamma wave energy
@property (nonatomic, assign) double eegQuality; // Quality of the EEG signal
@end

@interface PEPRAffectiveResOC : NSObject
@property (nonatomic, strong) NSMutableArray<NSNumber *> *bcgWave; // Pulse wave waveform
@property (nonatomic, strong) NSMutableArray<NSNumber *> *rwWave; // Respiratory wave waveform
@property (nonatomic, assign) int bcgQuality; // Quality level of pulse wave signal 0: NONE 1: POOR 2: NORM
@property (nonatomic, assign) int rwQuality; // Quality level of respiratory wave signal 0: NONE 1: POOR 2: NORM
@property (nonatomic, assign) int hr; // Heart rate
@property (nonatomic, assign) double hrv; // Heart rate variability
@property (nonatomic, assign) double rr; // Respiration rate
@property (nonatomic, assign) double pressure; // Pressure level
@property (nonatomic, assign) double coherence; // Coherence
@end

@interface SCEEGAffectiveResOC : NSObject
@property (nonatomic, assign) double relaxation;
@property (nonatomic, strong) SleepTriggerResOC *sleep;
@property (nonatomic, strong) SCEEGTriggerResOC *eeg;
@end

@interface EEGAffectiveResOC: NSObject
@property (nonatomic, strong, readwrite) EEGTriggerResOC *eeg;
@property (nonatomic, strong, readwrite) SleepTriggerResOC *sleep;
@property (nonatomic, strong, readwrite) FlowTriggerResOC *flow;
@property (nonatomic, assign, readwrite) double relaxation;
@property (nonatomic, assign, readwrite) double pleasure;
@property (nonatomic, assign, readwrite) double attention;

@end

@interface HRAffectiveResOC: NSObject
@property (nonatomic, strong, readwrite) HRTriggerResOC *hr;
@property (nonatomic, assign, readwrite) double pressure;
@property (nonatomic, assign, readwrite) double coherence;
@property (nonatomic, assign, readwrite) double arousal;
@end

@interface LicenseInfo : NSObject
@end

@interface AffectiveHandler : NSObject
- (instancetype)init;
- (void)dealloc;

- (EEGAffectiveResOC *) appendEEG: (NSMutableArray<NSNumber *> *)eegRaw;
- (HRAffectiveResOC *) appendHR: (NSMutableArray<NSNumber *> *)hrRaw;
- (PEPRAffectiveResOC *) appendPEPR: (NSMutableArray<NSNumber *> *)peprRaw;
- (SCEEGAffectiveResOC *) appendSCEEG: (NSMutableArray<NSNumber *> *)sceegRaw;
- (ArousalReportResOC *) getArousalReport;
- (CoherenceReportResOC *) getCoherenceReport;
- (PleasureReportResOC *) getPleasureReport;
- (PressureReportResOC *) getPressureReport;
- (RelaxationReportResOC *) getRelaxationReport;
- (AttentionReportResOC *) getAttentionReport;
- (SleepReportResOC *) getSleepReport;
- (HRReportResOC *) getHRReport;
- (EEGReprotResOC *) getEEGReport;
- (PEPRReportResOC *) getPEPRReport;
- (SCEEGReportResOC *) getSCEEGReport;
- (FlowReportResOC *) getFlowReport;
- (BOOL)AuthFromBundle: (NSString *) path;
- (BOOL) getArousalEnable;
- (BOOL) getCoherenceEnable;
- (BOOL) getPleasureEnable;
- (BOOL) getPressureEnable;
- (BOOL) getRelaxationEnable;
- (BOOL) getAttentionEnable;
- (BOOL) getSleepEnable;
- (BOOL) getFlowEnable;
- (BOOL) getEEGEnable;
- (BOOL) getHREnable;
- (BOOL) getSCEEGEnable;
- (BOOL) getPEPREnable;

@end


#endif /* AffectiveHandler_h */
