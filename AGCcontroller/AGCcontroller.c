#include "AGCcontroller.h"

extern DAC_HandleTypeDef hdac;

/**
 * @brief 设定ADC输出为对应幅度，单位mV
 * @param voltage_mV 单位mV
 */
void DACvalueSet_mv(uint16_t voltage_mV)
{
    float value = voltage_mV * (DAC_MAX_VALUE / REF_VOLTAGE); // 计算DAC值
    if(value > DAC_MAX_VALUE) {
        value = DAC_MAX_VALUE;
    }
    HAL_DAC_Stop(&hdac, DAC_CHANNEL);
    HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, (uint32_t)value);
    HAL_DAC_Start(&hdac, DAC_CHANNEL_1);
}

/**
 * @brief AGC增益控制函数
 * @param dB 增益值，单位dB
 * @note 增益公式 y = 0.0685x - 30.737，其中y为dB增益，X为DAC输出值（mV）
 * @note 增益调节范围在10.45757dB到20dB
 */
void AGC_gainControl(float dB)
{
    uint16_t dac_value = (uint16_t)((dB + 30.737) / 0.0685);
    DACvalueSet_mv(dac_value);
}