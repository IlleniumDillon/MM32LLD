/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-02 21:32:48
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-23 17:00:05
 * @FilePath: \CODE\MM32\mLLD\TIM\PIT\MM32_PIT.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_PIT_H_
#define _MM32_PIT_H_

#include "MM32_TIM.h"
#include "common.h"

/**
 * @brief 定时中断模块枚举
 */
typedef enum
{
  PIT1 = TIM6_BASE,
  PIT2 = TIM7_BASE
}MM32PIT_Moudle;

/*转换寄存器地址为模块枚举*/
#define GET_PITMODULE_INDX(PITMODULE) (((uint32_t)PITMODULE-TIM6_BASE)/0x400)

/**
 * @description: 创建一个定时任务
 * @param {MM32PIT_Moudle} module 定时模块
 * @param {uint32_t} freq 执行频率
 * @param {uint32_t} pro  优先级
 * @return {*}
 * @example
 * \code
 *    MM32PIT_timerTaskInit(PIT1,1000,0);
 * \endcode
 */
void MM32PIT_timerTaskInit(MM32PIT_Moudle module, uint32_t freq, uint32_t pro);

/**
 * @description: 使能定时器
 * @param {MM32PIT_Moudle} module 定时模块
 * @return {*}
 * @example
 * \code
 *    MM32PIT_Start(PIT1);
 * \endcode
 */
void MM32PIT_Start(MM32PIT_Moudle module);

/**
 * @description: 关闭定时器
 * @param {MM32PIT_Moudle} module 定时模块
 * @return {*}
 * @example
 * \code
 *    MM32PIT_Close(PIT1);
 * \endcode
 */
void MM32PIT_Close(MM32PIT_Moudle module);

#endif