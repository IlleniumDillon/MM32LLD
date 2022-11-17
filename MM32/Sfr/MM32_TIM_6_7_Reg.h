/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-02 20:59:59
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-02 21:29:15
 * @FilePath: \CODE\MM32\Sfr\MM32_TIM_6_7_Reg.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_TIM_6_7_REG_H_
#define _MM32_TIM_6_7_REG_H_

#include "MM32_RegBase.h"

#include "MM32_TIM_6_7_RegDef.h"

#define MOUDLE_TIM6		((MM32_TIM_6_7*)TIM6_BASE)

#define MOUDLE_TIM7		((MM32_TIM_6_7*)TIM7_BASE)

#define TIM6_CR1		((MM32_TIM_6_7_CR1*)(TIM6_BASE+0X00))

#define TIM6_DIER		((MM32_TIM_6_7_DIER*)(TIM6_BASE+0X0C))

#define TIM6_SR		((MM32_TIM_6_7_SR*)(TIM6_BASE+0X10))

#define TIM6_EGR		((MM32_TIM_6_7_EGR*)(TIM6_BASE+0X14))

#define TIM6_CNT		((MM32_TIM_6_7_CNT*)(TIM6_BASE+0X24))

#define TIM6_PSC		((MM32_TIM_6_7_PSC*)(TIM6_BASE+0X28))

#define TIM6_ARR		((MM32_TIM_6_7_ARR*)(TIM6_BASE+0X2C))

#define TIM7_CR1		((MM32_TIM_6_7_CR1*)(TIM7_BASE+0X00))

#define TIM7_DIER		((MM32_TIM_6_7_DIER*)(TIM7_BASE+0X0C))

#define TIM7_SR		((MM32_TIM_6_7_SR*)(TIM7_BASE+0X10))

#define TIM7_EGR		((MM32_TIM_6_7_EGR*)(TIM7_BASE+0X14))

#define TIM7_CNT		((MM32_TIM_6_7_CNT*)(TIM7_BASE+0X24))

#define TIM7_PSC		((MM32_TIM_6_7_PSC*)(TIM7_BASE+0X28))

#define TIM7_ARR		((MM32_TIM_6_7_ARR*)(TIM7_BASE+0X2C))



#endif