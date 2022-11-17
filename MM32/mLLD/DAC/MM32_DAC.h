/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-17 18:25:34
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-17 19:00:20
 * @FilePath: \CODE\MM32\mLLD\DAC\MM32_DAC.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_DAC_H_
#define _MM32_DAC_H_

#include "MM32_DACReg.h"
#include "MM32_RCC.h"
#include "MM32_GPIO.h"

typedef enum _MM32DAC_Moudle
{
    DAC1,
    DAC2,
}MM32DAC_Moudle;

typedef enum _MM32DAC_Bits
{
    BIT_12,
    BIT_8,
}MM32DAC_Bits;

void MM32DAC_pinInit(MM32DAC_Moudle moudle);

void MM32DAC_setData12(MM32DAC_Moudle moudle, uint16_t data);

void MM32DAC_set2ChannelData12(uint16_t dataCh1, uint16_t dataCh2);

#endif