#include "common.h"

void nvic_init(IRQn_Type irqn, uint8_t preemption_priority, uint8_t sub_priority, uint8_t status)
{
    if (status != 0) 
    {
        uint32_t pri = (0x00000700U & ~(SCB->AIRCR & SCB_AIRCR_PRIGROUP_Msk)) >> SCB_AIRCR_PRIGROUP_Pos;

        pri = (((uint32_t)preemption_priority << (0x4 - pri)) |
               (sub_priority & (0x0F >> pri)))
              << 0x04;

        NVIC->IP[irqn]           = pri;
        NVIC->ISER[irqn >> 0x05] = 0x01 << (irqn & 0x1F);
    }
    else 
    {
        NVIC->ICER[irqn >> 0x05] = 0x01 << (irqn & 0x1F);
    }
}

void nvic_interrput_enable (void)
{
    __ASM volatile("cpsie i");
}

void nvic_interrput_disable (void)
{
    __ASM volatile("cpsid i");
}

void systick_delay (uint32_t time)
{
    SysTick->CTRL	= 0x00;
	SysTick->LOAD	= time-1;
	SysTick->VAL	= 0x00;
	SysTick->CTRL	=	SysTick_CTRL_CLKSOURCE_Msk |					//时钟源选择 (core clk)
						SysTick_CTRL_ENABLE_Msk;						//使能 systick
	while( !(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
}

void systick_delay_ms(uint32_t ms)
{
    unsigned int SystemCoreClock;
    while(ms--) systick_delay(SystemCoreClock / 1000);
}

void systick_timing(uint32_t time)
{
    SysTick->CTRL	= 0x00;
	SysTick->LOAD = time-1;												// 设置延时时间
	SysTick->VAL = 0x00;												// 清空计数器
	NVIC_SetPriority(SysTick_IRQn, 0x0);								// 设置优先级
	SysTick->CTRL = ( 0 
		| SysTick_CTRL_ENABLE_Msk										// 使能 systick
		| SysTick_CTRL_TICKINT_Msk										// 使能中断
		| SysTick_CTRL_CLKSOURCE_Msk									// 时钟源选择 (core clk)
		);
}

void systick_start (void)
{
    SysTick->LOAD = SysTick_LOAD_RELOAD_Msk;							// 设置延时时间
	SysTick->VAL = 0x00;												// 清空计数器
	SysTick->CTRL = ( 0
		| SysTick_CTRL_ENABLE_Msk										// 使能 systick
		| SysTick_CTRL_CLKSOURCE_Msk									// 时钟源选择 (core clk)
		);
}

uint32_t systick_getval(void)
{
    return (SysTick_LOAD_RELOAD_Msk - SysTick->VAL);
}