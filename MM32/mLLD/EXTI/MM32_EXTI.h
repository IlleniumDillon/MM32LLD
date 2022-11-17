/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-05 19:44:15
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-05 20:46:57
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

typedef enum
{
    RISING = 0x01,
    FALLING = 0x10,
    BOTH = 0x11,
    DISABLE = 0x00,
}MM32EXTI_Trigger;

void MM32EXTI_pinInit(MM32GPIO_GPIO_Pin pin, MM32EXTI_Trigger trigger, uint8_t pro);

void MM32EXTI_enable(MM32GPIO_GPIO_Pin pin);

void MM32EXTI_disable(MM32GPIO_GPIO_Pin pin);

#endif