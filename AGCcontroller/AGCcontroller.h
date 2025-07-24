#ifndef _AGCcontroller_H_
#define _AGCcontroller_H_

#include "dac.h"
#include "main.h"
#include "ad7606.h"

#define DAC_MAX_VALUE (float)4096  // 12位DAC最大值
#define REF_VOLTAGE (float)3300    // 参考电压2048mV
#define DAC_CHANNEL DAC_CHANNEL_1

#define OUTPUT_VOLTAGE  ((10000*(float)((short)g_tAD.usBuf[0])/32768/2)); // 通道1是输出
#define INPUT_VOLTAGE   ((10000*(float)((short)g_tAD.usBuf[1])/32768/2)); // 通道2是输入

#define DAC_SAFE_MAX_VALUE  1990        // AGC最大安全控制电压2V，这里的单位是mV
#define DAC_SAFE_MIN_VALUE  0           // AGC最小安全控制电压0V，这里的单位是mV
#define DAC_STEP            1           // DAC步进单位，单位mV
#define SWITCH_LEVEL        141         // 继电器切换电平，单位mV
#define SWITCH_BUFFER       5           // 继电器切换缓冲区，单位mV

extern float targetVoltage;
extern uint16_t dac_value;

typedef enum roughGainControl_t
{
    rough_devide4,
    rough_times5,
}roughGainControl_t;

void DACvalueSet_mv(uint16_t voltage_mV);
void AGC_gainControl(float dB);
void roughGainControl();
void AGCmove2target(float target);

#endif