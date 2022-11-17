/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-17 20:47:55
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-17 21:59:11
 * @FilePath: \CODE\MM32\mLLD\ADC\MM32_ADC.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_ADC_H_
#define _MM32_ADC_H_

#include "MM32_ADCReg.h"
#include "MM32_RCC.h"
#include "MM32_GPIO.h"

typedef enum _MM32ADC_Moudle
{
    ADC1 = ADC1_BASE,
    ADC2 = ADC2_BASE,
    ADC3 = ADC3_BASE,
}MM32ADC_Moudle;

typedef struct _MM32ADC_Pin
{
    MM32GPIO_Port port;
    MM32GPIO_Pin pin;
    MM32GPIO_Pin_Config conf;
    MM32ADC_Moudle moudle;
    uint8_t ch;
}MM32ADC_Pin;

void MM32ADC_pinInit(MM32ADC_Pin pin);

uint16_t MM32ADC_getData(MM32ADC_Pin pin);

#endif