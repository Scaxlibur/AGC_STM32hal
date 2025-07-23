#ifndef _AGCcontroller_H_
#define _AGCcontroller_H_

#include "dac.h"

#define DAC_MAX_VALUE (float)4096  // 12位DAC最大值
#define REF_VOLTAGE (float)3300    // 参考电压2048mV
#define DAC_CHANNEL DAC_CHANNEL_1

void DACvalueSet_mv(uint16_t voltage_mV);
void AGC_gainControl(float dB);


#endif