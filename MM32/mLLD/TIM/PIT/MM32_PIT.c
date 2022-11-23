/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-02 21:32:58
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-23 17:01:33
 * @FilePath: \CODE\MM32\mLLD\TIM\PIT\MM32_PIT.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "MM32_PIT.h"

void MM32PIT_timerTaskInit(MM32PIT_Moudle module, uint32_t freq, uint32_t pro)
{
    extern unsigned int SystemCoreClock;
    //模块指针
    MM32_TIM_6_7* m = (MM32_TIM_6_7*)module;
    IRQn_Type irq;

    //
    switch (module)
    {
        case PIT1:        {MM32RCC_enableTIM6(); irq = TIM6_IRQn;}        break;
        case PIT2:        {MM32RCC_enableTIM7(); irq = TIM7_IRQn;}        break;
        default:        return;
    }

    m->CR1.B.APRE = 1;
    m->DIER.B.UIE = 1;

    uint32_t arr = SystemCoreClock / freq;
    uint32_t psr = 1;
    while(arr > 32767)
    {
        arr = arr >> 1;
        psr = psr << 1;
    }

    m->PSC.B.PSC = (uint16_t)psr-1;
    m->ARR.B.ARR = (uint16_t)arr;

    nvic_init(irq,0x1,pro,1);

    m->CR1.B.CEN = 1;
}

void MM32PIT_Start(MM32PIT_Moudle module)
{
    MM32_TIM_6_7* m = (MM32_TIM_6_7*)module;
    m->CR1.B.CEN = 1;
}

void MM32PIT_Close(MM32PIT_Moudle module)
{
    MM32_TIM_6_7* m = (MM32_TIM_6_7*)module;
    m->CR1.B.CEN = 0;
}