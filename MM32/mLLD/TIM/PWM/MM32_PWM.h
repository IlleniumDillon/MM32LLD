/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-12-13 18:30:02
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-13 19:20:11
 * @FilePath: \CODE\MM32\mLLD\TIM\PWM\MM32_PWM.H
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_PWM_H_
#define _MM32_PWM_H_

#include "MM32_TIM.h"
#include "common.h"

/**
 * @brief PWM模块枚举
 */
typedef enum
{
  PWM1 = TIM1_BASE,
  PWM2 = TIM8_BASE,
  PWM3 = TIM2_BASE,
  PWM4 = TIM5_BASE,
  PWM5 = TIM3_BASE,
  PWM6 = TIM4_BASE
}MM32PWM_Moudle;

/**
 * @brief PWM模块通道枚举
 */
typedef enum
{
    CH1P = 0,
    CH1N,
    CH2P,
    CH2N,
    CH3P,
    CH3N,
    CH4
}MM32PWM_Channel;

/**
 * @brief PWM引脚定义结构体
 */
typedef struct
{
    MM32GPIO_Port port;
    MM32GPIO_Pin pin;
    MM32GPIO_Pin_Config conf;
    MM32GPIO_Pin_AF af;
    MM32PWM_Moudle moudle;
    MM32PWM_Channel channel;
}MM32PWM_Pin;

void MM32PWM_pinInit(MM32PWM_Pin* pin, uint32_t freq);

void MM32PWM_setDuty(MM32PWM_Pin* pin, float duty);

#endif