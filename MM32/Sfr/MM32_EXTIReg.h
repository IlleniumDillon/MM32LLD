/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:43:27
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:07:07
 * @FilePath: \CODE\MM32\Sfr\MM32_EXTIReg.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_EXTIREG_H_
#define _MM32_EXTIREG_H_

#include "MM32_RegBase.h"

#include "MM32_EXTIRegDef.h"

#define MOUDLE_EXTI		((MM32_EXTI*)EXTI_BASE)

#define EXTI_IMR		((MM32_EXTI_IMR*)(EXTI_BASE+0X00))

#define EXTI_EMR		((MM32_EXTI_EMR*)(EXTI_BASE+0X04))

#define EXTI_RTSR		((MM32_EXTI_RTSR*)(EXTI_BASE+0X08))

#define EXTI_FTSR		((MM32_EXTI_FTSR*)(EXTI_BASE+0X0C))

#define EXTI_SWIER		((MM32_EXTI_SWIER*)(EXTI_BASE+0X10))

#define EXTI_PR		((MM32_EXTI_PR*)(EXTI_BASE+0X14))

#endif