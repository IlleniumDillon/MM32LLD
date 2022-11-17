/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 14:00:55
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:05:48
 * @FilePath: \CODE\MM32\mLLD\RCC\MM32_RCC.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "MM32_RCC.h"

void MM32RCC_resetFSMC(void)
{
  RCC_AHB3RSTR->B.FSMC = 1;
  RCC_AHB3RSTR->B.FSMC = 0;

}

void MM32RCC_resetUSB(void)
{
  RCC_AHB2RSTR->B.USBOTGFS = 1;
  RCC_AHB2RSTR->B.USBOTGFS = 0;

}

void MM32RCC_resetGPIOA(void)
{
  RCC_AHB1RSTR->B.GPIOA = 1;
  RCC_AHB1RSTR->B.GPIOA = 0;

}

void MM32RCC_resetGPIOB(void)
{
  RCC_AHB1RSTR->B.GPIOB = 1;
  RCC_AHB1RSTR->B.GPIOB = 0;

}

void MM32RCC_resetGPIOC(void)
{
  RCC_AHB1RSTR->B.GPIOC = 1;
  RCC_AHB1RSTR->B.GPIOC = 0;

}

void MM32RCC_resetGPIOD(void)
{
  RCC_AHB1RSTR->B.GPIOD = 1;
  RCC_AHB1RSTR->B.GPIOD = 0;

}

void MM32RCC_resetGPIOE(void)
{
  RCC_AHB1RSTR->B.GPIOE = 1;
  RCC_AHB1RSTR->B.GPIOE = 0;

}

void MM32RCC_resetGPIOF(void)
{
  RCC_AHB1RSTR->B.GPIOF = 1;
  RCC_AHB1RSTR->B.GPIOF = 0;

}

void MM32RCC_resetGPIOG(void)
{
  RCC_AHB1RSTR->B.GPIOG = 1;
  RCC_AHB1RSTR->B.GPIOG = 0;

}

void MM32RCC_resetGPIOH(void)
{
  RCC_AHB1RSTR->B.GPIOH = 1;
  RCC_AHB1RSTR->B.GPIOH = 0;

}

void MM32RCC_resetSDIO(void)
{
  RCC_AHB1RSTR->B.SDIO = 1;
  RCC_AHB1RSTR->B.SDIO = 0;

}

void MM32RCC_resetCRC(void)
{
  RCC_AHB1RSTR->B.CRC = 1;
  RCC_AHB1RSTR->B.CRC = 0;

}

void MM32RCC_resetDMA1(void)
{
  RCC_AHB1RSTR->B.DMA1 = 1;
  RCC_AHB1RSTR->B.DMA1 = 0;

}

void MM32RCC_resetDMA2(void)
{
  RCC_AHB1RSTR->B.DMA2 = 1;
  RCC_AHB1RSTR->B.DMA2 = 0;

}

void MM32RCC_resetTIM1(void)
{
  RCC_APB2RSTR->B.TIM1 = 1;
  RCC_APB2RSTR->B.TIM1 = 0;

}

void MM32RCC_resetTIM8(void)
{
  RCC_APB2RSTR->B.TIM8 = 1;
  RCC_APB2RSTR->B.TIM8 = 0;

}

void MM32RCC_resetUART1(void)
{
  RCC_APB2RSTR->B.UART1 = 1;
  RCC_APB2RSTR->B.UART1 = 0;

}

void MM32RCC_resetUART6(void)
{
  RCC_APB2RSTR->B.UART6 = 1;
  RCC_APB2RSTR->B.UART6 = 0;

}

void MM32RCC_resetADC1(void)
{
  RCC_APB2RSTR->B.ADC1 = 1;
  RCC_APB2RSTR->B.ADC1 = 0;

}

void MM32RCC_resetADC2(void)
{
  RCC_APB2RSTR->B.ADC2 = 1;
  RCC_APB2RSTR->B.ADC2 = 0;

}

void MM32RCC_resetADC3(void)
{
  RCC_APB2RSTR->B.ADC3 = 1;
  RCC_APB2RSTR->B.ADC3 = 0;

}

void MM32RCC_resetSPI1(void)
{
  RCC_APB2RSTR->B.SPI1 = 1;
  RCC_APB2RSTR->B.SPI1 = 0;

}

void MM32RCC_resetSYSCFG(void)
{
  RCC_APB2RSTR->B.SYSCFG = 1;
  RCC_APB2RSTR->B.SYSCFG = 0;

}

void MM32RCC_resetCOMP(void)
{
  RCC_APB2RSTR->B.COMP = 1;
  RCC_APB2RSTR->B.COMP = 0;

}

void MM32RCC_resetTIM2(void)
{
  RCC_APB1RSTR->B.TIM2 = 1;
  RCC_APB1RSTR->B.TIM2 = 0;

}

void MM32RCC_resetTIM3(void)
{
  RCC_APB1RSTR->B.TIM3 = 1;
  RCC_APB1RSTR->B.TIM3 = 0;

}

void MM32RCC_resetTIM4(void)
{
  RCC_APB1RSTR->B.TIM4 = 1;
  RCC_APB1RSTR->B.TIM4 = 0;

}

void MM32RCC_resetTIM5(void)
{
  RCC_APB1RSTR->B.TIM5 = 1;
  RCC_APB1RSTR->B.TIM5 = 0;

}

void MM32RCC_resetTIM6(void)
{
  RCC_APB1RSTR->B.TIM6 = 1;
  RCC_APB1RSTR->B.TIM6 = 0;

}

void MM32RCC_resetTIM7(void)
{
  RCC_APB1RSTR->B.TIM7 = 1;
  RCC_APB1RSTR->B.TIM7 = 0;

}

void MM32RCC_resetWWDG(void)
{
  RCC_APB1RSTR->B.WWDG = 1;
  RCC_APB1RSTR->B.WWDG = 0;

}

void MM32RCC_resetSPI2(void)
{
  RCC_APB1RSTR->B.SPI2 = 1;
  RCC_APB1RSTR->B.SPI2 = 0;

}

void MM32RCC_resetSPI3(void)
{
  RCC_APB1RSTR->B.SPI3 = 1;
  RCC_APB1RSTR->B.SPI3 = 0;

}

void MM32RCC_resetUART2(void)
{
  RCC_APB1RSTR->B.UART2 = 1;
  RCC_APB1RSTR->B.UART2 = 0;

}

void MM32RCC_resetUART3(void)
{
  RCC_APB1RSTR->B.UART3 = 1;
  RCC_APB1RSTR->B.UART3 = 0;

}

void MM32RCC_resetUART4(void)
{
  RCC_APB1RSTR->B.UART4 = 1;
  RCC_APB1RSTR->B.UART4 = 0;

}

void MM32RCC_resetUART5(void)
{
  RCC_APB1RSTR->B.UART5 = 1;
  RCC_APB1RSTR->B.UART5 = 0;

}

void MM32RCC_resetI2C1(void)
{
  RCC_APB1RSTR->B.I2C1 = 1;
  RCC_APB1RSTR->B.I2C1 = 0;

}

void MM32RCC_resetI2C2(void)
{
  RCC_APB1RSTR->B.I2C2 = 1;
  RCC_APB1RSTR->B.I2C2 = 0;

}

void MM32RCC_resetCRS(void)
{
  RCC_APB1RSTR->B.CRS = 1;
  RCC_APB1RSTR->B.CRS = 0;

}

void MM32RCC_resetCAN(void)
{
  RCC_APB1RSTR->B.CAN = 1;
  RCC_APB1RSTR->B.CAN = 0;

}

void MM32RCC_resetBKP(void)
{
  RCC_APB1RSTR->B.BKP = 1;
  RCC_APB1RSTR->B.BKP = 0;

}
void MM32RCC_resetPWR(void)
{
  RCC_APB1RSTR->B.PWR = 1;
  RCC_APB1RSTR->B.PWR = 0;

}

void MM32RCC_resetDAC(void)
{
  RCC_APB1RSTR->B.DAC = 1;
  RCC_APB1RSTR->B.DAC = 0;

}

void MM32RCC_resetUART7(void)
{
  RCC_APB1RSTR->B.UART7 = 1;
  RCC_APB1RSTR->B.UART7 = 0;

}

void MM32RCC_resetUART8(void)
{
  RCC_APB1RSTR->B.UART8 = 1;
  RCC_APB1RSTR->B.UART8 = 0;

}

void MM32RCC_enableFSMC(void)
{
  RCC_AHB3ENR->B.FSMC = 1;

}

void MM32RCC_enableUSB(void)
{
  RCC_AHB2ENR->B.USBOTGFS = 1;

}

void MM32RCC_enableGPIOA(void)
{
  RCC_AHB1ENR->B.GPIOA = 1;

}

void MM32RCC_enableGPIOB(void)
{
  RCC_AHB1ENR->B.GPIOB = 1;

}

void MM32RCC_enableGPIOC(void)
{
  RCC_AHB1ENR->B.GPIOC = 1;

}

void MM32RCC_enableGPIOD(void)
{
  RCC_AHB1ENR->B.GPIOD = 1;

}

void MM32RCC_enableGPIOE(void)
{
  RCC_AHB1ENR->B.GPIOE = 1;

}

void MM32RCC_enableGPIOF(void)
{
  RCC_AHB1ENR->B.GPIOF = 1;

}

void MM32RCC_enableGPIOG(void)
{
  RCC_AHB1ENR->B.GPIOG = 1;

}

void MM32RCC_enableGPIOH(void)
{
  RCC_AHB1ENR->B.GPIOH = 1;

}

void MM32RCC_enableSDIO(void)
{
  RCC_AHB1ENR->B.SDIO = 1;

}

void MM32RCC_enableCRC(void)
{
  RCC_AHB1ENR->B.CRC = 1;

}

void MM32RCC_enableDMA1(void)
{
  RCC_AHB1ENR->B.DMA1 = 1;

}

void MM32RCC_enableDMA2(void)
{
  RCC_AHB1ENR->B.DMA2 = 1;

}

void MM32RCC_enableTIM1(void)
{
  RCC_APB2ENR->B.TIM1 = 1;

}

void MM32RCC_enableTIM8(void)
{
  RCC_APB2ENR->B.TIM8 = 1;

}

void MM32RCC_enableUART1(void)
{
  RCC_APB2ENR->B.UART1 = 1;

}

void MM32RCC_enableUART6(void)
{
  RCC_APB2ENR->B.UART6 = 1;

}

void MM32RCC_enableADC1(void)
{
  RCC_APB2ENR->B.ADC1 = 1;

}

void MM32RCC_enableADC2(void)
{
  RCC_APB2ENR->B.ADC2 = 1;

}

void MM32RCC_enableADC3(void)
{
  RCC_APB2ENR->B.ADC3 = 1;

}

void MM32RCC_enableSPI1(void)
{
  RCC_APB2ENR->B.SPI1 = 1;

}

void MM32RCC_enableSYSCFG(void)
{
  RCC_APB2ENR->B.SYSCFG = 1;

}

void MM32RCC_enableCOMP(void)
{
  RCC_APB2ENR->B.COMP = 1;

}

void MM32RCC_enableTIM2(void)
{
  RCC_APB1ENR->B.TIM2 = 1;

}

void MM32RCC_enableTIM3(void)
{
  RCC_APB1ENR->B.TIM3 = 1;

}

void MM32RCC_enableTIM4(void)
{
  RCC_APB1ENR->B.TIM4 = 1;

}

void MM32RCC_enableTIM5(void)
{
  RCC_APB1ENR->B.TIM5 = 1;

}

void MM32RCC_enableTIM6(void)
{
  RCC_APB1ENR->B.TIM6 = 1;

}

void MM32RCC_enableTIM7(void)
{
  RCC_APB1ENR->B.TIM7 = 1;

}

void MM32RCC_enableWWDG(void)
{
  RCC_APB1ENR->B.WWDG = 1;

}

void MM32RCC_enableSPI2(void)
{
  RCC_APB1ENR->B.SPI2 = 1;

}

void MM32RCC_enableSPI3(void)
{
  RCC_APB1ENR->B.SPI3 = 1;

}

void MM32RCC_enableUART2(void)
{
  RCC_APB1ENR->B.UART2 = 1;

}

void MM32RCC_enableUART3(void)
{
  RCC_APB1ENR->B.UART3 = 1;

}

void MM32RCC_enableUART4(void)
{
  RCC_APB1ENR->B.UART4 = 1;

}

void MM32RCC_enableUART5(void)
{
  RCC_APB1ENR->B.UART5 = 1;

}

void MM32RCC_enableI2C1(void)
{
  RCC_APB1ENR->B.I2C1 = 1;

}

void MM32RCC_enableI2C2(void)
{
  RCC_APB1ENR->B.I2C2 = 1;

}

void MM32RCC_enableCRS(void)
{
  RCC_APB1ENR->B.CRS = 1;

}

void MM32RCC_enableCAN(void)
{
  RCC_APB1ENR->B.CAN = 1;

}

void MM32RCC_enableBKP(void)
{
  RCC_APB1ENR->B.BKP = 1;

}

void MM32RCC_enablePWR(void)
{
  RCC_APB1ENR->B.PWR_DBG = 1;

}

void MM32RCC_enableDAC(void)
{
  RCC_APB1ENR->B.DAC = 1;

}

void MM32RCC_enableUART7(void)
{
  RCC_APB1ENR->B.UART7 = 1;

}

void MM32RCC_enableUART8(void)
{
  RCC_APB1ENR->B.UART8 = 1;

}


void MM32RCC_disableFSMC(void)
{
  RCC_AHB3ENR->B.FSMC = 0;

}

void MM32RCC_disableUSB(void)
{
  RCC_AHB2ENR->B.USBOTGFS = 0;

}

void MM32RCC_disableGPIOA(void)
{
  RCC_AHB1ENR->B.GPIOA = 0;

}

void MM32RCC_disableGPIOB(void)
{
  RCC_AHB1ENR->B.GPIOB = 0;

}

void MM32RCC_disableGPIOC(void)
{
  RCC_AHB1ENR->B.GPIOC = 0;

}

void MM32RCC_disableGPIOD(void)
{
  RCC_AHB1ENR->B.GPIOD = 0;

}

void MM32RCC_disableGPIOE(void)
{
  RCC_AHB1ENR->B.GPIOE = 0;

}

void MM32RCC_disableGPIOF(void)
{
  RCC_AHB1ENR->B.GPIOF = 0;

}

void MM32RCC_disableGPIOG(void)
{
  RCC_AHB1ENR->B.GPIOG = 0;

}

void MM32RCC_disableGPIOH(void)
{
  RCC_AHB1ENR->B.GPIOH = 0;

}

void MM32RCC_disableSDIO(void)
{
  RCC_AHB1ENR->B.SDIO = 0;

}

void MM32RCC_disableCRC(void)
{
  RCC_AHB1ENR->B.CRC = 0;

}

void MM32RCC_disableDMA1(void)
{
  RCC_AHB1ENR->B.DMA1 = 0;

}

void MM32RCC_disableDMA2(void)
{
  RCC_AHB1ENR->B.DMA2 = 0;

}

void MM32RCC_disableTIM1(void)
{
  RCC_APB2ENR->B.TIM1 = 0;

}

void MM32RCC_disableTIM8(void)
{
  RCC_APB2ENR->B.TIM8 = 0;

}

void MM32RCC_disableUART1(void)
{
  RCC_APB2ENR->B.UART1 = 0;

}

void MM32RCC_disableUART6(void)
{
  RCC_APB2ENR->B.UART6 = 0;

}

void MM32RCC_disableADC1(void)
{
  RCC_APB2ENR->B.ADC1 = 0;

}

void MM32RCC_disableADC2(void)
{
  RCC_APB2ENR->B.ADC2 = 0;

}

void MM32RCC_disableADC3(void)
{
  RCC_APB2ENR->B.ADC3 = 0;

}

void MM32RCC_disableSPI1(void)
{
  RCC_APB2ENR->B.SPI1 = 0;

}

void MM32RCC_disableSYSCFG(void)
{
  RCC_APB2ENR->B.SYSCFG = 0;

}

void MM32RCC_disableCOMP(void)
{
  RCC_APB2ENR->B.COMP = 0;

}

void MM32RCC_disableTIM2(void)
{
  RCC_APB1ENR->B.TIM2 = 0;

}

void MM32RCC_disableTIM3(void)
{
  RCC_APB1ENR->B.TIM3 = 0;

}

void MM32RCC_disableTIM4(void)
{
  RCC_APB1ENR->B.TIM4 = 0;

}

void MM32RCC_disableTIM5(void)
{
  RCC_APB1ENR->B.TIM5 = 0;

}

void MM32RCC_disableTIM6(void)
{
  RCC_APB1ENR->B.TIM6 = 0;

}

void MM32RCC_disableTIM7(void)
{
  RCC_APB1ENR->B.TIM7 = 0;

}

void MM32RCC_disableWWDG(void)
{
  RCC_APB1ENR->B.WWDG = 0;

}

void MM32RCC_disableSPI2(void)
{
  RCC_APB1ENR->B.SPI2 = 0;

}

void MM32RCC_disableSPI3(void)
{
  RCC_APB1ENR->B.SPI3 = 0;

}

void MM32RCC_disableUART2(void)
{
  RCC_APB1ENR->B.UART2 = 0;

}

void MM32RCC_disableUART3(void)
{
  RCC_APB1ENR->B.UART3 = 0;

}

void MM32RCC_disableUART4(void)
{
  RCC_APB1ENR->B.UART4 = 0;

}

void MM32RCC_disableUART5(void)
{
  RCC_APB1ENR->B.UART5 = 0;

}

void MM32RCC_disableI2C1(void)
{
  RCC_APB1ENR->B.I2C1 = 0;

}

void MM32RCC_disableI2C2(void)
{
  RCC_APB1ENR->B.I2C2 = 0;

}

void MM32RCC_disableCRS(void)
{
  RCC_APB1ENR->B.CRS = 0;

}

void MM32RCC_disableCAN(void)
{
  RCC_APB1ENR->B.CAN = 0;

}

void MM32RCC_disableBKP(void)
{
  RCC_APB1ENR->B.BKP = 0;

}

void MM32RCC_disablePWR(void)
{
  RCC_APB1ENR->B.PWR_DBG = 0;

}

void MM32RCC_disableDAC(void)
{
  RCC_APB1ENR->B.DAC = 0;

}

void MM32RCC_disableUART7(void)
{
  RCC_APB1ENR->B.UART7 = 0;

}

void MM32RCC_disableUART8(void)
{
  RCC_APB1ENR->B.UART8 = 0;

}
