/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 14:00:42
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-23 15:45:32
 * @FilePath: \CODE\MM32\mLLD\RCC\MM32_RCC.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_RCC_H_
#define _MM32_RCC_H_

#include "MM32_RCCReg.h"

/**
 * @description: 复位模块FSMC
 * @return {*}
 */
void MM32RCC_resetFSMC(void);

/**
 * @description: 复位模块USB
 * @return {*}
 */
void MM32RCC_resetUSB(void);

/**
 * @description:复位模块GPIOA
 * @return {*}
 */
void MM32RCC_resetGPIOA(void);

/**
 * @description: 复位模块GPIOB
 * @return {*}
 */
void MM32RCC_resetGPIOB(void);

/**
 * @description: 复位模块GPIOC
 * @return {*}
 */
void MM32RCC_resetGPIOC(void);

/**
 * @description: 复位模块GPIOD
 * @return {*}
 */
void MM32RCC_resetGPIOD(void);

/**
 * @description: 复位模块GPIOE
 * @return {*}
 */
void MM32RCC_resetGPIOE(void);

/**
 * @description: 复位模块GPIOF
 * @return {*}
 */
void MM32RCC_resetGPIOF(void);

/**
 * @description: 复位模块GPIOG
 * @return {*}
 */
void MM32RCC_resetGPIOG(void);

/**
 * @description: 复位模块GPIOH
 * @return {*}
 */
void MM32RCC_resetGPIOH(void);

/**
 * @description: 复位模块SDIO
 * @return {*}
 */
void MM32RCC_resetSDIO(void);

/**
 * @description: 复位模块CRC
 * @return {*}
 */
void MM32RCC_resetCRC(void);

/**
 * @description: 复位模块DMA1
 * @return {*}
 */
void MM32RCC_resetDMA1(void);

/**
 * @description: 复位模块DMA2
 * @return {*}
 */
void MM32RCC_resetDMA2(void);

/**
 * @description: 复位模块TIM1
 * @return {*}
 */
void MM32RCC_resetTIM1(void);

/**
 * @description: 复位模块TIM8
 * @return {*}
 */
void MM32RCC_resetTIM8(void);

/**
 * @description: 复位模块UART1
 * @return {*}
 */
void MM32RCC_resetUART1(void);

/**
 * @description: 复位模块UART6
 * @return {*}
 */
void MM32RCC_resetUART6(void);

/**
 * @description: 复位模块ADC1
 * @return {*}
 */
void MM32RCC_resetADC1(void);

/**
 * @description: 复位模块ADC2
 * @return {*}
 */
void MM32RCC_resetADC2(void);

/**
 * @description: 复位模块ADC3
 * @return {*}
 */
void MM32RCC_resetADC3(void);

/**
 * @description: 复位模块SPI1
 * @return {*}
 */
void MM32RCC_resetSPI1(void);

/**
 * @description: 复位模块SYSCFG
 * @return {*}
 */
void MM32RCC_resetSYSCFG(void);

/**
 * @description: 复位模块COMP
 * @return {*}
 */
void MM32RCC_resetCOMP(void);

/**
 * @description: 复位模块TIM2
 * @return {*}
 */
void MM32RCC_resetTIM2(void);

/**
 * @description: 复位模块TIM3
 * @return {*}
 */
void MM32RCC_resetTIM3(void);

/**
 * @description: 复位模块TIM4
 * @return {*}
 */
void MM32RCC_resetTIM4(void);

/**
 * @description: 复位模块TIM5
 * @return {*}
 */
void MM32RCC_resetTIM5(void);

/**
 * @description: 复位模块TIM6
 * @return {*}
 */
void MM32RCC_resetTIM6(void);

/**
 * @description: 复位模块TIM7
 * @return {*}
 */
void MM32RCC_resetTIM7(void);

/**
 * @description: 复位模块WWDG
 * @return {*}
 */
void MM32RCC_resetWWDG(void);

/**
 * @description: 复位模块SPI2
 * @return {*}
 */
void MM32RCC_resetSPI2(void);

/**
 * @description: 复位模块SPI3
 * @return {*}
 */
void MM32RCC_resetSPI3(void);

/**
 * @description: 复位模块UART2
 * @return {*}
 */
void MM32RCC_resetUART2(void);

/**
 * @description: 复位模块UART3
 * @return {*}
 */
void MM32RCC_resetUART3(void);

/**
 * @description: 复位模块UART4
 * @return {*}
 */
void MM32RCC_resetUART4(void);

/**
 * @description: 复位模块UART5
 * @return {*}
 */
void MM32RCC_resetUART5(void);

/**
 * @description: 复位模块I2C1
 * @return {*}
 */
void MM32RCC_resetI2C1(void);

/**
 * @description: 复位模块I2C2
 * @return {*}
 */
void MM32RCC_resetI2C2(void);

/**
 * @description: 复位模块CRS
 * @return {*}
 */
void MM32RCC_resetCRS(void);

/**
 * @description: 复位模块CAN
 * @return {*}
 */
void MM32RCC_resetCAN(void);

/**
 * @description: 复位模块BKP
 * @return {*}
 */
void MM32RCC_resetBKP(void);

/**
 * @description: 复位模块PWR
 * @return {*}
 */
void MM32RCC_resetPWR(void);

/**
 * @description: 复位模块DAC
 * @return {*}
 */
void MM32RCC_resetDAC(void);

/**
 * @description: 复位模块UART7
 * @return {*}
 */
void MM32RCC_resetUART7(void);

/**
 * @description: 复位模块UART8
 * @return {*}
 */
void MM32RCC_resetUART8(void);


/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableFSMC(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableUSB(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableGPIOA(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableGPIOB(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableGPIOC(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableGPIOD(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableGPIOE(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableGPIOF(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableGPIOG(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableGPIOH(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableSDIO(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableCRC(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableDMA1(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableDMA2(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableTIM1(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableTIM8(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableUART1(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableUART6(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableADC1(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableADC2(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableADC3(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableSPI1(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableSYSCFG(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableCOMP(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableTIM2(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableTIM3(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableTIM4(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableTIM5(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableTIM6(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableTIM7(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableWWDG(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableSPI2(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableSPI3(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableUART2(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableUART3(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableUART4(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableUART5(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableI2C1(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableI2C2(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableCRS(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableCAN(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableBKP(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enablePWR(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableDAC(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableUART7(void);

/**
 * @description: 使能模块
 * @return {*}
 */
void MM32RCC_enableUART8(void);


/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableFSMC(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableUSB(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableGPIOA(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableGPIOB(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableGPIOC(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableGPIOD(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableGPIOE(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableGPIOF(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableGPIOG(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableGPIOH(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableSDIO(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableCRC(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableDMA1(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableDMA2(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableTIM1(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableTIM8(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableUART1(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableUART6(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableADC1(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableADC2(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableADC3(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableSPI1(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableSYSCFG(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableCOMP(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableTIM2(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableTIM3(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableTIM4(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableTIM5(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableTIM6(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableTIM7(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableWWDG(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableSPI2(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableSPI3(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableUART2(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableUART3(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableUART4(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableUART5(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableI2C1(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableI2C2(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableCRS(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableCAN(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableBKP(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disablePWR(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableDAC(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableUART7(void);

/**
 * @description: 失能模块
 * @return {*}
 */
void MM32RCC_disableUART8(void);

#endif