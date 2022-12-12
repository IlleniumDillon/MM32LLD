/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-17 20:47:55
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-23 14:01:12
 * @FilePath: \CODE\MM32\mLLD\ADC\MM32_ADC.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_ADC_H_
#define _MM32_ADC_H_

#include "MM32_ADCReg.h"
#include "MM32_RCC.h"
#include "MM32_GPIO.h"

/**
 * @brief 模拟/数字转换模块枚举定义
 */
typedef enum _MM32ADC_Moudle
{
    ADC1 = ADC1_BASE,
    ADC2 = ADC2_BASE,
    ADC3 = ADC3_BASE,
}MM32ADC_Moudle;

/**
 * @brief 模拟/数字转换模块引脚结构体定义
 */
typedef struct _MM32ADC_Pin
{
    MM32GPIO_Port port;             //引脚端口
    MM32GPIO_Pin pin;               //引脚号
    MM32GPIO_Pin_Config conf;       //引脚配置
    MM32ADC_Moudle moudle;          //ADC模块
    uint8_t ch;                     //ADC通道
}MM32ADC_Pin;

/**
 * @description: ADC引脚初始化
 * @param {MM32ADC_Pin} pin ADC引脚结构体
 * @return {*}
 * @example
 * \code
 *      //定义ADC引脚
 *      MM32ADC_Pin ADCPin = {.port = GPIOA, .pin = P00, .conf = INPUT_FLOATING, .moudle = ADC1, .ch = 0};
 *      //初始化ADC引脚
 *      MM32ADC_pinInit(ADCPin);
 * \endcode
 */
void MM32ADC_pinInit(MM32ADC_Pin pin);

/**
 * @description: 获得ADC引脚的转换值（12位分辨率）
 * @param {MM32ADC_Pin} pin ADC引脚
 * @return {uint16_t}   ADC转换值
 * @bug 同一模块多个通道读取会卡死
 * @example
 * \code
 *      //获取ADC转换值
 *      uint16_t data = MM32ADC_getData(ADCPin);
 * \endcode
 */
uint16_t MM32ADC_getData(MM32ADC_Pin pin);

#endif