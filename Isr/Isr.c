/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-01 22:23:55
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-10 15:23:03
 * @FilePath: \CODE\Isr\Isr.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "Isr.h"

#define DELAYTIME 120000

void UART4_IRQHandler(void)
{
	if(UART4_ISR->B.TX_INTF)
	{
		UART4_ICR->B.TX_ICLR = 1;
	}
	if(UART4_ISR->B.RX_INTF)
	{
		UART4_ICR->B.RX_ICLR = 1;;
        P18_uartReadCallBack();
	}
}

void UART2_IRQHandler(void)
{
	if(UART2_ISR->B.TX_INTF)
	{
		UART2_ICR->B.TX_ICLR = 1;
	}
	if(UART2_ISR->B.RX_INTF)
	{
		UART2_ICR->B.RX_ICLR = 1;
        HOST_uartReadCallBack();
        //P18_uartReadCallBack();
	}
}


void TIM6_IRQHandler (void)
{
	uint16_t state = TIM6_SR->U;														// 读取中断状态
	TIM6_SR->U &= ~state;
    //UART_floatVarUpload(UART2,&(P18_device.shift[0]),3);
	P18_ctrlCallBack();
}

void TIM7_IRQHandler (void)
{
	uint16_t state = TIM7_SR->U;														// 读取中断状态
	TIM7_SR->U &= ~state;															// 清空中断状态
	OLED_printBuf();
}

void EXTI0_IRQHandler(void)
{
	EXTI_PR->U |= (0x1 << 0);
}

void EXTI1_IRQHandler(void)
{
	EXTI_PR->U |= (0x1 << 1);
}

void EXTI2_IRQHandler(void)
{
	EXTI_PR->U |= (0x1 << 2);
}

void EXTI3_IRQHandler(void)
{
	EXTI_PR->U |= (0x1 << 3);
}

void EXTI4_IRQHandler(void)
{
	EXTI_PR->U |= (0x1 << 4);
}

void EXTI9_5_IRQHandler(void)
{
	if(EXTI_PR->U & (0x1 << 5))
	{
		EXTI_PR->U |= (0x1 << 5);
	}

	if(EXTI_PR->U & (0x1 << 6))
	{
		EXTI_PR->U |= (0x1 << 6);
	}

	if(EXTI_PR->U & (0x1 << 7))
	{
		EXTI_PR->U |= (0x1 << 7);
	}

	if(EXTI_PR->U & (0x1 << 8))
	{
		EXTI_PR->U |= (0x1 << 8);
	}

	if(EXTI_PR->U & (0x1 << 9))
	{
        /*uint8_t temp = 0;
        if(menuCurLev==0)
        {
            temp = menuCurNum;
        }
        else
        {
            temp = (menuCurLev-1) * LEVEL1SIZE + menuCurNum + LEVEL0SIZE;
        }*/
		systick_delay(DELAYTIME);
		if(MM32GPIO_getPinState(GPIOE,P09)==1)
		keyPressFlag |= KEYPRESS_RIGHT;
		//menuSpace[temp].menu.keyRightTask(NULL);
        EXTI_PR->U |= (0x1 << 9);
	}
}

void EXTI15_10_IRQHandler (void)
{
	if(EXTI_PR->U & (0x1 << 10))
	{
        /*uint8_t temp = 0;
        if(menuCurLev==0)
        {
            temp = menuCurNum;
        }
        else
        {
            temp = (menuCurLev-1) * LEVEL1SIZE + menuCurNum + LEVEL0SIZE;
        }*/
		systick_delay(DELAYTIME);
		if(MM32GPIO_getPinState(GPIOE,P10)==1)
		keyPressFlag |= KEYPRESS_DOWN;
		//menuSpace[temp].menu.keyDownTask(NULL);
        EXTI_PR->U |= (0x1 << 10);
	}

	if(EXTI_PR->U & (0x1 << 11))
	{
        /*uint8_t temp = 0;
        if(menuCurLev==0)
        {
            temp = menuCurNum;
        }
        else
        {
            temp = (menuCurLev-1) * LEVEL1SIZE + menuCurNum + LEVEL0SIZE;
        }*/
		systick_delay(DELAYTIME);
		if(MM32GPIO_getPinState(GPIOE,P11)==1)
		keyPressFlag |= KEYPRESS_LEFT;
		//menuSpace[temp].menu.keyLeftTask(NULL);
        EXTI_PR->U |= (0x1 << 11);
	}

	if(EXTI_PR->U & (0x1 << 12))
	{
        /*uint8_t temp = 0;
        if(menuCurLev==0)
        {
            temp = menuCurNum;
        }
        else
        {
            temp = (menuCurLev-1) * LEVEL1SIZE + menuCurNum + LEVEL0SIZE;
        }*/
		systick_delay(DELAYTIME);
		if(MM32GPIO_getPinState(GPIOE,P12)==1)
		keyPressFlag |= KEYPRESS_OK;
		//menuSpace[temp].menu.keyOkTask(NULL);
        EXTI_PR->U |= (0x1 << 12);
	}

	if(EXTI_PR->U & (0x1 << 13))
	{
        /*uint8_t temp = 0;
        if(menuCurLev==0)
        {
            temp = menuCurNum;
        }
        else
        {
            temp = (menuCurLev-1) * LEVEL1SIZE + menuCurNum + LEVEL0SIZE;
        }*/
		systick_delay(DELAYTIME);
		if(MM32GPIO_getPinState(GPIOE,P13)==1)
		keyPressFlag |= KEYPRESS_UP;
		//menuSpace[temp].menu.keyUpTask(NULL);
        EXTI_PR->U |= (0x1 << 13);
	}

	if(EXTI_PR->U & (0x1 << 14))
	{
		EXTI_PR->U |= (0x1 << 14);
	}

	if(EXTI_PR->U & (0x1 << 15))
	{
		EXTI_PR->U |= (0x1 << 15);
	}
}
