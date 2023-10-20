#ifndef AFFECTIVE_GUARD_EXPORT_H
#define AFFECTIVE_GUARD_EXPORT_H
#include "Define.h"

class AffectiveAlgorithm
{
public:

    /**
     * @brief 双通道脑电, 每个算法周期到了就触发算法,默认0.6秒触发一次相当于蓝牙接收50个脑电包
     *
     * @param eegRaw 每个周期的脑电数组
     * @return EEGAffectiveRes 实时值
     */
    EEGAffectiveRes appendEEG(const std::vector<uint8_t> &eegRaw);

    /**
     * @brief 单通道脑电, 每个算法周期到了就触发算法,默认0.6秒触发一次相当于蓝牙接收30个脑电包
     *
     * @param eegRaw 每个周期的脑电数组
     * @return EEGAffectiveRes 实时值
     */
    SCEEGAffectiveRes appendSCEEG(const std::vector<uint8_t> &eegRaw);

    /**
     * @brief 每个算法周期到了就触发算法,默认0.6秒触发一次相当于蓝牙接收3个心率包
     *
     * @param hrRaw  每个周期的心率数组
     * @return HRAffectiveRes 实时值
     */
    HRAffectiveRes appendHR(const std::vector<uint8_t> &hrRaw);

    /// @brief 坐垫算法,每个算法周期到了就触发算法,默认0.6秒触发一次相当于蓝牙接收15个压力包
    /// \param peprRaw
    /// \return
    PEPRAffectiveRes appendPEPR(const std::vector<uint8_t> &peprRaw);

    /**
     * @brief 获取激活度报表
     *
     * @return ArousalReportRes
     */
    ArousalReportRes getArousalReport();
    /**
     * @brief 获取和谐度报表
     *
     * @return CoherenceReportRes
     */
    CoherenceReportRes getCoherenceReport();
    /**
     * @brief 获取愉悦度报表
     *
     * @return PleasureReportRes
     */
    PleasureReportRes getPleasureReport();
    /**
     * @brief 获取压力值报表
     *
     * @return PressureReportRes
     */
    PressureReportRes getPressureReport();

    /**
     * @brief 获取放松度报表
     *
     * @return RelaxationReportRes
     */
    RelaxationReportRes getRelaxationReport();

    /**
     * @brief 获取注意力报表
     *
     * @return AttentionReportRes
     */
    AttentionReportRes getAttentionReport();

    /**
     * @brief 获取睡眠报表
     *
     * @return SleepReportRes
     */
    SleepReportRes getSleepReport();

    /**
     * @brief 获取心率报表
     *
     * @return HRReportRes
     */
    HRReportRes getHRReport();

    /**
     * @brief 获取脑电报表
     *
     * @return EEGReprotRes
     */
    EEGReprotRes getEEGReport();

    /**
     * @brief 获取坐垫报表
     *
     * @return PEPRReportRes
     */
    PEPRReportRes getPEPRReport();

    /**
     * @brief 获取单通道脑电报表
     *
     * @return SCEEGReportRes
     */
    SCEEGReportRes getSCEEGReport();

    /**
     * @brief 获取冥想度报表
     *
     * @return
     */
    FlowReportRes getFlowReport();
    AffectiveAlgorithm();

    ~AffectiveAlgorithm();

    /// @brief 获取脑电数据长度
    /// @return
    int eegIndex();
    /// @brief 获取心率数据长度
    /// @return
    int hrIndex();
    /// @brief 获取睡眠数据长度
    /// @return
    int sleepLength();

    void setArousalEnable(bool enable);
    void setAttentionEnable(bool enable);
    void setCoherenceEnable(bool enable);
    void setRelaxationEnable(bool enable);
    void setPleasureEnable(bool enable);
    void setPressureEnable(bool enable);
    void setSleepEnable(bool enable);
    void setFlowEnable(bool enable);
    void setEEGEnable(bool enable);
    void setHREnable(bool enable);
    void setPEPREnable(bool enable);
    void setSCEEGEnable(bool enable);
    bool getArousalEnable();
    bool getAttentionEnable();
    bool getCoherenceEnable();
    bool getRelaxationEnable();
    bool getPleasureEnable();
    bool getPressureEnable();
    bool getSleepEnable();
    bool getFlowEnable();
    bool getEEGEnable();
    bool getHREnable();
    bool getPEPREnable();
    bool getSCEEGEnable();
private:
    class AffectiveAlgorithmImpl;
    AffectiveAlgorithmImpl *ptr;
};

#endif
