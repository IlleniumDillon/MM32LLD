/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-17 18:25:34
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-23 14:15:28
 * @FilePath: \CODE\MM32\mLLD\DAC\MM32_DAC.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_DAC_H_
#define _MM32_DAC_H_

#include "MM32_DACReg.h"
#include "MM32_RCC.h"
#include "MM32_GPIO.h"

/**
 * @brief 数字/模拟转换模块枚举
 */
typedef enum _MM32DAC_Moudle
{
    DAC1,
    DAC2,
}MM32DAC_Moudle;

/**
 * @brief 转换精度枚举
 */
typedef enum _MM32DAC_Bits
{
    BIT_12,
    BIT_8,
}MM32DAC_Bits;

/**
 * @description: DAC模块初始化
 * @param {MM32DAC_Moudle} moudle
 * @return {*}
 * @example
 * \code
 *      //初始化DAC1模块
 *      MM32DAC_pinInit(DAC1);
 * \endcode
 */
void MM32DAC_pinInit(MM32DAC_Moudle moudle);

/**
 * @description: 设定一个DAC模块的转换值（12位分辨率）
 * @param {MM32DAC_Moudle} moudle   DAC模块
 * @param {uint16_t} data   转换值
 * @return {*}
 * @example
 * \code
 *      //设置DAC1模块的转换值为4095
 *      MM32DAC_setData12(DAC1,4095);
 * \endcode
 */
void MM32DAC_setData12(MM32DAC_Moudle moudle, uint16_t data);

/**
 * @description: 同时设定两个DAC模块的转换值（12位分辨率）
 * @param {uint16_t} dataCh1    模块1的转换值
 * @param {uint16_t} dataCh2    模块2的转换值
 * @return {*}
 * @example
 * \code
 *      //分别设置两个模块的转换值为0、4095
 *      MM32DAC_set2ChannelData12(0,4095);
 * \endcode
 */
void MM32DAC_set2ChannelData12(uint16_t dataCh1, uint16_t dataCh2);

#endif