/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-02 21:32:48
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-02 21:51:18
 * @FilePath: \CODE\MM32\mLLD\TIM\PIT\MM32_PIT.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_PIT_H_
#define _MM32_PIT_H_

#include "MM32_TIM.h"
#include "common.h"

typedef enum
{
  PIT1 = TIM6_BASE,
  PIT2 = TIM7_BASE
}MM32PIT_Moudle;

#define GET_PITMODULE_INDX(PITMODULE) (((uint32_t)PITMODULE-TIM6_BASE)/0x400)


void MM32PIT_timerTaskInit(MM32PIT_Moudle module, uint32_t freq, uint32_t pro);

void MM32PIT_Start(MM32PIT_Moudle module);

void MM32PIT_Close(MM32PIT_Moudle module);

#endif