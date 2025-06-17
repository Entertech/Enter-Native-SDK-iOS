//
//  AffectiveHandler.h
//  AffectiveAlgorithmSDK_iOS
//
//  Created by Enter M1 on 2023/4/23.
//

#ifndef AffectiveWrapper_h
#define AffectiveWrapper_h
#import <Foundation/Foundation.h>

/// 激活度报表
@interface ArousalReportResOC: NSObject
/// 平均激活度
@property (nonatomic, assign, readwrite) double arousalAvg;
/// 激活度全程记录
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *arousalRec;
@end

/// 和谐度报表
@interface CoherenceReportResOC: NSObject
/// 平均和谐度
@property (nonatomic, assign, readwrite) double coherenceAvg;
/// 和谐时长
@property (nonatomic, assign, readwrite) int coherenceDuration;
/// 和谐度列表
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *coherenceRec;
/// 和谐度全程记录
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *coherenceFlag;
@end

/// 愉悦度报表
@interface PleasureReportResOC: NSObject
/// 愉悦度均值
@property (nonatomic, assign, readwrite) double pleasureAvg;
/// 愉悦度全程记录
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *pleasureRec;
@end

/// 压力报表
@interface PressureReportResOC: NSObject
/// 压力均值
@property (nonatomic, assign, readwrite) double pressureAvg;
/// 压力全程记录
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *pressureRec;
@end

/// 放松度报表
@interface RelaxationReportResOC: NSObject
/// 放松度均值
@property (nonatomic, assign, readwrite) double relaxationAvg;
/// 放松度全程记录
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *relaxationRec;
@end

/// 注意力报表
@interface AttentionReportResOC: NSObject
/// 注意力均值
@property (nonatomic, assign, readwrite) double attentionAvg;
/// 注意力全程记录
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *attentionRec;
@end

/// 睡眠报表
@interface SleepReportResOC : NSObject
/// 睡眠全程记录
@property (strong, nonatomic) NSMutableArray<NSNumber *> *sleepCurve;
/// 睡眠阶段全程记录
/// WAKE = 0  # 清醒
/// NREM1 = 1  # 非快速眼动期1（思睡期）
/// NREM2 = 2  # 非快速眼动期2（浅睡期）
/// NREM3 = 3  # 非快速眼动期3（深睡期）
/// REM = 4  # 快速眼动期
@property (strong, nonatomic) NSMutableArray<NSNumber *> *sleepStage;
/// 入睡点
@property (nonatomic) int sleepPoint;
/// 睡眠潜伏期时间点
@property (nonatomic) int sleepLatency;
/// 清醒时长
@property (nonatomic) int awakeDuration;
/// REM期时长
@property (nonatomic) int remDuration;
/// 浅睡时长
@property (nonatomic) int lightDuration;
/// 深睡时长
@property (nonatomic) int deepDuration;
/// EEG alpha 全程记录
@property (strong, nonatomic) NSMutableArray<NSNumber *> *eegAlphaCurve;
/// EEG beta 全程记录
@property (strong, nonatomic) NSMutableArray<NSNumber *> *eegBetaCurve;
/// EEG theta 全程记录
@property (strong, nonatomic) NSMutableArray<NSNumber *> *eegThetaCurve;
/// EEG delta 全程记录
@property (strong, nonatomic) NSMutableArray<NSNumber *> *eegDeltaCurve;
/// EEG gamma 全程记录
@property (strong, nonatomic) NSMutableArray<NSNumber *> *eegGammaCurve;

@property (strong, nonatomic) NSMutableArray<NSNumber *> *eegLowBetaCurve;
@property (strong, nonatomic) NSMutableArray<NSNumber *> *eegHighBetaCurve;

@property (strong, nonatomic) NSMutableArray<NSNumber *> *eegQualityRec;
/// 体动次数
@property (nonatomic) int movementCount;
/// 觉醒次数
@property (nonatomic) int arousalCount;
/// 抗干扰能力
@property (nonatomic) double disturbTolerance;
/// 体动标志记录
@property (strong, nonatomic) NSMutableArray<NSNumber *> *movementRec;
/// 觉醒标志记录
@property (strong, nonatomic) NSMutableArray<NSNumber *> *arousalRec;
@end

/// 心流报表
@interface FlowReportResOC : NSObject
/// 心流平均值
@property (nonatomic, assign) double flowAvg;
/// 心流全程记录
@property (nonatomic, strong) NSMutableArray<NSNumber *> *flowRec;
/// 心流状态提示全程记录
@property (nonatomic, strong) NSMutableArray<NSNumber *> *flowTipsRec;
/// 心流状态占比
@property (nonatomic, assign) double flowPercent;
/// 心流状态时长
@property (nonatomic, assign) double flowDuration;
/// 进入心流状态的用时
@property (nonatomic, assign) double flowLatency;
/// 心流状态最大连续时间
@property (nonatomic, assign) int flowCombo;
/// 心流状态最大深度
@property (nonatomic, assign) double flowDepth;
/// 心流状态恢复提示次数
@property (nonatomic, assign) int flowBackNum;
/// 心流状态丢失提示次数
@property (nonatomic, assign) int flowLossNum;
@end

/// 心率报表
@interface HRReportResOC: NSObject
/// 心率全程记录
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *hrRec;
/// 心率变异性全程记录
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *hrvRec;
@end

/// EEG报表
@interface EEGReprotResOC: NSObject
/// EEG alpha 全程记录
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *eegAlphaRec;
/// EEG beta 全程记录
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *eegBetaRec;
/// EEG theta 全程记录
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *eegThetaRec;
/// EEG delta 全程记录
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *eegDeltaRec;
/// EEG gamma 全程记录
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *eegGammaRec;

@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *eegLowBetaRec;
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *eegHighBetaRec;

@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *eegQualityRec;
@end

// 单通道 EEG 报表
@interface SCEEGReportResOC : NSObject
/// 单通道 EEG alpha 全程记录
@property (nonatomic, strong) NSMutableArray<NSNumber *> *eegAlphaRec;
/// 单通道 EEG beta 全程记录
@property (nonatomic, strong) NSMutableArray<NSNumber *> *eegBetaRec;
/// 单通道 EEG theta 全程记录
@property (nonatomic, strong) NSMutableArray<NSNumber *> *eegThetaRec;
/// 单通道 EEG delta 全程记录
@property (nonatomic, strong) NSMutableArray<NSNumber *> *eegDeltaRec;
/// 单通道 EEG gamma 全程记录
@property (nonatomic, strong) NSMutableArray<NSNumber *> *eegGammaRec;
/// 单通道 EEG 质量全程记录
@property (nonatomic, strong) NSMutableArray<NSNumber *> *eegQualityRec;
@end

/// 压电压阻报表
@interface PEPRReportResOC : NSObject
/// 心率均值
@property (nonatomic, assign) int hrAvg;
/// 心率区间最大值
@property (nonatomic, assign) int hrMax;
/// 心率区间最小值
@property (nonatomic, assign) int hrMin;
/// 心率全程记录
@property (nonatomic, strong) NSMutableArray<NSNumber *> *hrRec;
/// 呼吸率全程记录
@property (nonatomic, strong) NSMutableArray<NSNumber *> *rrRec;
/// 呼吸率均值
@property (nonatomic, assign) int rrAvg;
/// 心率变异性全程记录
@property (nonatomic, strong) NSMutableArray<NSNumber *> *hrvRec;
/// 心率变异性均值
@property (nonatomic, assign) double hrvAvg; // Average heart rate variability
/// 脉搏波质量(0: NONE, 1: POOR, 2: NORM)
@property (nonatomic, strong) NSMutableArray<NSNumber *> *bcgQualityRec; // Full record of pulse wave signal quality (0: NONE, 1: POOR, 2: NORM)
/// 呼吸波质量(0: NONE, 1: POOR, 2: NORM)
@property (nonatomic, strong) NSMutableArray<NSNumber *> *rwQualityRec; // Full record of respiration wave signal quality (0: NONE, 1: POOR, 2: NORM)
@end

/// 实时睡眠
@interface SleepTriggerResOC : NSObject
/// 睡眠程度
@property (nonatomic, assign) double sleepDegree; // Degree of sleep
/// 睡眠状态（0:清醒，1:睡着）
@property (nonatomic, assign) int sleepState; // Sleep state
@property (nonatomic, assign) int sleepStage;
@property (nonatomic, assign) double sleepSpindle;
@property (nonatomic, assign) bool updateFlag;
@end

/// 实时心流
@interface FlowTriggerResOC : NSObject
/// 心流程度
@property (nonatomic, assign) double meditation; // Degree of meditation
/// 心流状态提示（0:初始状态，1:状态恢复提醒， 2:状态丢失提醒）
@property (nonatomic, assign) double meditationTips; // Meditation state tips
@end

/// 实时心率
@interface HRTriggerResOC: NSObject
/// 心率变异性
@property (nonatomic, assign, readwrite) double hrv;
/// 心率
@property (nonatomic, assign, readwrite) int hr;
@end

/// 实时 EEG
@interface EEGTriggerResOC: NSObject
/// EEG 左脑实时数据
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *eeglWave;
/// EEG 右脑实时数据
@property (nonatomic, strong, readwrite) NSMutableArray<NSNumber *> *eegrWave;
/// EEG alpha 实时数据
@property (nonatomic, assign, readwrite) double eegAlphaPower;
/// EEG beta 实时数据
@property (nonatomic, assign, readwrite) double eegBetaPower;
/// EEG theta 实时数据
@property (nonatomic, assign, readwrite) double eegThetaPower;
/// EEG delta 实时数据
@property (nonatomic, assign, readwrite) double eegDeltaPower;
/// EEG gamma 实时数据
@property (nonatomic, assign, readwrite) double eegGammaPower;

@property (nonatomic, assign, readwrite) double eegLowBetaPower;
@property (nonatomic, assign, readwrite) double eegHighBetaPower;

@property (nonatomic, assign, readwrite) double eegQuality;
@end

/// 单通道 EEG 实时数据
@interface SCEEGTriggerResOC : NSObject
/// EEG 实时数据
@property (nonatomic, strong) NSMutableArray<NSNumber *> *eegWave; // Brain wave
/// EEG alpha 实时数据
@property (nonatomic, assign) double eegAlphaPower; // Alpha wave energy
/// EEG beta 实时数据
@property (nonatomic, assign) double eegBetaPower; // Beta wave energy
/// EEG theta 实时数据
@property (nonatomic, assign) double eegThetaPower; // Theta wave energy
/// EEG delta 实时数据
@property (nonatomic, assign) double eegDeltaPower; // Delta wave energy
/// EEG gamma 实时数据
@property (nonatomic, assign) double eegGammaPower; // Gamma wave energy
/// EEG 质量实时数据
@property (nonatomic, assign) double eegQuality; // Quality of the EEG signal
@end

/// 压电压阻实时数据
@interface PEPRAffectiveResOC : NSObject
/// 脉搏波数据
@property (nonatomic, strong) NSMutableArray<NSNumber *> *bcgWave; // Pulse wave waveform
/// 呼吸波数据
@property (nonatomic, strong) NSMutableArray<NSNumber *> *rwWave; // Respiratory wave waveform
/// 脉搏波质量(0: NONE, 1: POOR, 2: NORM)
@property (nonatomic, assign) int bcgQuality; // Quality level of pulse wave signal 0: NONE 1: POOR 2: NORM
/// 呼吸波质量(0: NONE, 1: POOR, 2: NORM)
@property (nonatomic, assign) int rwQuality; // Quality level of respiratory wave signal 0: NONE 1: POOR 2: NORM
/// 心率
@property (nonatomic, assign) int hr; // Heart rate
/// 心率变异性
@property (nonatomic, assign) double hrv; // Heart rate variability
/// 呼吸率
@property (nonatomic, assign) double rr; // Respiration rate
/// 呼吸率变异性
@property (nonatomic, assign) double pressure; // Pressure level
/// 和谐度变异性
@property (nonatomic, assign) double coherence; // Coherence
@end

/// 单通道实时数据综合
@interface SCEEGAffectiveResOC : NSObject
/// 放松度实时数据
@property (nonatomic, assign) double relaxation;
/// 睡眠实时数据
@property (nonatomic, strong) SleepTriggerResOC *sleep;
/// 脑波实时数据
@property (nonatomic, strong) SCEEGTriggerResOC *eeg;
@end

/// 双通道实时数据综合
@interface EEGAffectiveResOC: NSObject
/// EEG 实时数据
@property (nonatomic, strong, readwrite) EEGTriggerResOC *eeg;
/// 睡眠实时数据
@property (nonatomic, strong, readwrite) SleepTriggerResOC *sleep;
/// 心流实时数据
@property (nonatomic, strong, readwrite) FlowTriggerResOC *flow;
/// 放松度实时数据
@property (nonatomic, assign, readwrite) double relaxation;
/// 愉悦度实时数据
@property (nonatomic, assign, readwrite) double pleasure;
/// 注意力实时数据
@property (nonatomic, assign, readwrite) double attention;

@end

/// 心率实时数据综合
@interface HRAffectiveResOC: NSObject
/// 心率实时数据
@property (nonatomic, strong, readwrite) HRTriggerResOC *hr;
/// 压力值实时数据
@property (nonatomic, assign, readwrite) double pressure;
/// 和谐度实时数据
@property (nonatomic, assign, readwrite) double coherence;
/// 激活度实时数据
@property (nonatomic, assign, readwrite) double arousal;
@end

@interface LicenseInfo : NSObject
@end

@interface AffectiveHandler : NSObject
- (instancetype)init;
- (void)dealloc;
// 停止计算, 需要释放前需要提前先停止, 防止由于蓝牙异步输入原因导致的释放后计算
- (void)disableCalculate;
// 开启计算, 初始化默认开启
- (void)enableCalculate;
// 返回当前状态, true开启计算, false停止计算
- (bool)isCalculate;

- (EEGAffectiveResOC *) appendEEG: (NSMutableArray<NSNumber *> *)eegRaw isEar: (BOOL)isEar;

- (HRAffectiveResOC *) appendHR: (NSMutableArray<NSNumber *> *)hrRaw;

/// 计算压电压阻
- (PEPRAffectiveResOC *) appendPEPR: (NSMutableArray<NSNumber *> *)peprRaw;

- (SCEEGAffectiveResOC *) appendSCEEG: (NSMutableArray<NSNumber *> *)sceegRaw isEar: (BOOL)isEar;

- (ArousalReportResOC *) getArousalReport;

/// 获取和谐度报表
- (CoherenceReportResOC *) getCoherenceReport;

/// 获取愉悦度报表
- (PleasureReportResOC *) getPleasureReport;

/// 获取压力报表
- (PressureReportResOC *) getPressureReport;

/// 获取放松度报表
- (RelaxationReportResOC *) getRelaxationReport;

/// 获取注意力报表
- (AttentionReportResOC *) getAttentionReport;

- (SleepReportResOC *) getSleepReport: (BOOL)isEar;

- (HRReportResOC *) getHRReport;

/// 获取心率报表
- (EEGReprotResOC *) getEEGReport;

/// 获取压电压阻报表
- (PEPRReportResOC *) getPEPRReport;

/// 获取单通道报表
- (SCEEGReportResOC *) getSCEEGReport;

/// 获取心流报表
- (FlowReportResOC *) getFlowReport;

/// 获取授权
- (BOOL)AuthFromBundle: (NSString *) path;

/// 获取激活度是否可用
- (BOOL) getArousalEnable;
/// 获取和谐度是否可用
- (BOOL) getCoherenceEnable;
/// 获取愉悦度是否可用
- (BOOL) getPleasureEnable;
/// 获取压力是否可用
- (BOOL) getPressureEnable;
/// 获取放松度是否可用
- (BOOL) getRelaxationEnable;
/// 获取注意力是否可用
- (BOOL) getAttentionEnable;
/// 获取睡眠是否可用
- (BOOL) getSleepEnable;
/// 获取心流是否可用
- (BOOL) getFlowEnable;
/// 获取双通道脑电是否可用
- (BOOL) getEEGEnable;
/// 获取心率是否可用
- (BOOL) getHREnable;
/// 获取单通道脑电是否可用
- (BOOL) getSCEEGEnable;
/// 获取压电压阻是否可用
- (BOOL) getPEPREnable;

@end


#endif /* AffectiveHandler_h */
