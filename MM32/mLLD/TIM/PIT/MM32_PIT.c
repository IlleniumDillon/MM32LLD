#include "MM32_PIT.h"

void MM32PIT_timerTaskInit(MM32PIT_Moudle module, uint32_t freq, uint32_t pro)
{
    extern unsigned int SystemCoreClock;

    MM32_TIM_6_7* m = (MM32_TIM_6_7*)module;
    IRQn_Type irq;

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