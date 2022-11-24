/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-18 09:48:45
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-24 11:05:19
 * @FilePath: \CODE\Peripheral\P18\P18_Analog.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _P18_ANALOG_H_
#define _P18_ANALOG_H_

#include "MM32_ADC.h"
#include "MM32_DAC.h"

#include "P18_TYPEDEF.h"

/**
 * @description: 初始化控制P18平台所需的ADC/DAC引脚
 * @return {*}
 */
void P18_analogPinInit(void);

/**
 * @description: 采样一个通道的电压值
 * @param {P18_channel_t} channel
 * @return {float} 电压值
 * @note 0-9.9V
 */
float P18_getVoltageFromADC(P18_channel_t channel);

/**
 * @description: 设定两个通道DAC转换值
 * @param {float} voltage1 第一个通道的转换值
 * @param {float} voltage2 第二个通道的转换值
 * @return {*}
 * @note 内部限幅0-9.9V
 */
void P18_setVoltageToDAC(float voltage1, float voltage2);

#endif