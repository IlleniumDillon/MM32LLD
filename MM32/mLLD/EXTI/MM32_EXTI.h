/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-05 19:44:15
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-23 14:39:17
 * @FilePath: \CODE\MM32\mLLD\EXTI\MM32_EXTI.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_EXTI_H_
#define _MM32_EXTI_H_

#include "MM32_GPIO.h"
#include "MM32_RCC.h"
#include "common.h"

#include "MM32_EXTIReg.h"
#include "MM32_SYSCFGReg.h"

/**
 * @brief 外部中断触发方式枚举
 */
typedef enum
{
    RISING = 0x01,      //上升沿触发
    FALLING = 0x10,     //下降沿触发
    BOTH = 0x11,        //双边沿触发
    DISABLE = 0x00,     //禁用触发
}MM32EXTI_Trigger;

/**
 * @description: 外部触发引脚初始化（并使能中断）
 * @param {MM32GPIO_GPIO_Pin} pin   引脚属性结构体
 * @param {MM32EXTI_Trigger} trigger    触发方式
 * @param {uint8_t} pro 中断优先级
 * @return {*}
 * @example
 * \code
 *      //引脚定义
 *      MM32GPIO_GPIO_Pin pin = {.port = GPIOF, .pin = P05, .conf = INPUT_FLOATING};
 *      //初始化外部中断引脚
 *      MM32EXTI_pinInit(pin,FALLING,10);
 * \endcode
 */
void MM32EXTI_pinInit(MM32GPIO_GPIO_Pin pin, MM32EXTI_Trigger trigger, uint8_t pro);

/**
 * @description: 使能指定引脚的外部中断
 * @param {MM32GPIO_GPIO_Pin} pin   引脚属性结构体
 * @return {*}
 * @example
 * \code
 *      //使能引脚的外部中断
 *      MM32EXTI_enable(pin);
 * \endcode
 */
void MM32EXTI_enable(MM32GPIO_GPIO_Pin pin);

/**
 * @description: 禁用指定引脚的外部中断
 * @param {MM32GPIO_GPIO_Pin} pin   引脚属性结构体
 * @return {*}
 * @example
 * \code
 *      //禁用引脚的外部中断
 *      MM32EXTI_disable(pin);
 * \endcode
 */
void MM32EXTI_disable(MM32GPIO_GPIO_Pin pin);

#endif