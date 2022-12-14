/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-12-14 11:30:03
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-14 12:52:06
 * @FilePath: \CODE\MM32\mLLD\TIM\CCU\MM32_CCU.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_CCU_H_
#define _MM32_CCU_H_

#include "MM32_TIM.h"
#include "common.h"

/**
 * @brief CCU模块枚举
 */
typedef enum
{
  CCU1 = TIM1_BASE,
  CCU2 = TIM8_BASE,
  CCU3 = TIM2_BASE,
  CCU4 = TIM5_BASE,
  CCU5 = TIM3_BASE,
  CCU6 = TIM4_BASE
}MM32CCU_Moudle;

/**
 * @brief CCU模块通道枚举
 */
// typedef enum
// {
//     CCUCH1 = 0,
//     CCUCH2,
//     CCUCH3,
//     CCUCH4
// }MM32CCU_Channel;

/**
 * @brief CCU引脚定义结构体
 */
typedef struct
{
    MM32GPIO_Port port;
    MM32GPIO_Pin pin;
    MM32GPIO_Pin_Config conf;
    MM32GPIO_Pin_AF af;
    MM32CCU_Moudle moudle;
    //MM32CCU_Channel channel;
}MM32CCU_Pin;

/**
 * @description: 初始化CCU引脚
 * @param {MM32CCU_Pin*} pin CCU引脚结构体指针
 * @param {float} freq PWM频率
 * @return {*}
 * @example
 * \code
 *    MM32CCU_pinInit(&pwmpin,1000);
 * \endcode
 */
void MM32CCU_pinInit(MM32CCU_Pin* pin, float freq);

/**
 * @description: 捕获PWM计数
 * @param {MM32CCU_Pin*} pin CCU引脚结构体指针
 * @return {uint32_t} PWM计数
 * @example
 * \code
 *    uint32_t time = MM32CCU_getCCR(&pwmpin);
 * \endcode
 */
uint32_t MM32CCU_getCCR(MM32CCU_Pin* pin);

/**
 * @description: 捕获PWM占空比
 * @param {MM32CCU_Pin*} pin CCU引脚结构体指针
 * @return {float} PWM计数
 * @example
 * \code
 *    float time = MM32CCU_getDuty(&pwmpin);
 * \endcode
 */
float MM32CCU_getDuty(MM32CCU_Pin* pin);

#endif