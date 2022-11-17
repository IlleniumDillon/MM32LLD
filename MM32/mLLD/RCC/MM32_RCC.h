/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 14:00:42
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:05:51
 * @FilePath: \CODE\MM32\mLLD\RCC\MM32_RCC.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_RCC_H_
#define _MM32_RCC_H_

#include "MM32_RCCReg.h"

void MM32RCC_resetFSMC(void);

void MM32RCC_resetUSB(void);

void MM32RCC_resetGPIOA(void);

void MM32RCC_resetGPIOB(void);

void MM32RCC_resetGPIOC(void);

void MM32RCC_resetGPIOD(void);

void MM32RCC_resetGPIOE(void);

void MM32RCC_resetGPIOF(void);

void MM32RCC_resetGPIOG(void);

void MM32RCC_resetGPIOH(void);

void MM32RCC_resetSDIO(void);

void MM32RCC_resetCRC(void);

void MM32RCC_resetDMA1(void);

void MM32RCC_resetDMA2(void);

void MM32RCC_resetTIM1(void);

void MM32RCC_resetTIM8(void);

void MM32RCC_resetUART1(void);

void MM32RCC_resetUART6(void);

void MM32RCC_resetADC1(void);

void MM32RCC_resetADC2(void);

void MM32RCC_resetADC3(void);

void MM32RCC_resetSPI1(void);

void MM32RCC_resetSYSCFG(void);

void MM32RCC_resetCOMP(void);

void MM32RCC_resetTIM2(void);

void MM32RCC_resetTIM3(void);

void MM32RCC_resetTIM4(void);

void MM32RCC_resetTIM5(void);

void MM32RCC_resetTIM6(void);

void MM32RCC_resetTIM7(void);

void MM32RCC_resetWWDG(void);

void MM32RCC_resetSPI2(void);

void MM32RCC_resetSPI3(void);

void MM32RCC_resetUART2(void);

void MM32RCC_resetUART3(void);

void MM32RCC_resetUART4(void);

void MM32RCC_resetUART5(void);

void MM32RCC_resetI2C1(void);

void MM32RCC_resetI2C2(void);

void MM32RCC_resetCRS(void);

void MM32RCC_resetCAN(void);

void MM32RCC_resetBKP(void);

void MM32RCC_resetPWR(void);

void MM32RCC_resetDAC(void);

void MM32RCC_resetUART7(void);

void MM32RCC_resetUART8(void);


void MM32RCC_enableFSMC(void);

void MM32RCC_enableUSB(void);

void MM32RCC_enableGPIOA(void);

void MM32RCC_enableGPIOB(void);

void MM32RCC_enableGPIOC(void);

void MM32RCC_enableGPIOD(void);

void MM32RCC_enableGPIOE(void);

void MM32RCC_enableGPIOF(void);

void MM32RCC_enableGPIOG(void);

void MM32RCC_enableGPIOH(void);

void MM32RCC_enableSDIO(void);

void MM32RCC_enableCRC(void);

void MM32RCC_enableDMA1(void);

void MM32RCC_enableDMA2(void);

void MM32RCC_enableTIM1(void);

void MM32RCC_enableTIM8(void);

void MM32RCC_enableUART1(void);

void MM32RCC_enableUART6(void);

void MM32RCC_enableADC1(void);

void MM32RCC_enableADC2(void);

void MM32RCC_enableADC3(void);

void MM32RCC_enableSPI1(void);

void MM32RCC_enableSYSCFG(void);

void MM32RCC_enableCOMP(void);

void MM32RCC_enableTIM2(void);

void MM32RCC_enableTIM3(void);

void MM32RCC_enableTIM4(void);

void MM32RCC_enableTIM5(void);

void MM32RCC_enableTIM6(void);

void MM32RCC_enableTIM7(void);

void MM32RCC_enableWWDG(void);

void MM32RCC_enableSPI2(void);

void MM32RCC_enableSPI3(void);

void MM32RCC_enableUART2(void);

void MM32RCC_enableUART3(void);

void MM32RCC_enableUART4(void);

void MM32RCC_enableUART5(void);

void MM32RCC_enableI2C1(void);

void MM32RCC_enableI2C2(void);

void MM32RCC_enableCRS(void);

void MM32RCC_enableCAN(void);

void MM32RCC_enableBKP(void);

void MM32RCC_enablePWR(void);

void MM32RCC_enableDAC(void);

void MM32RCC_enableUART7(void);

void MM32RCC_enableUART8(void);


void MM32RCC_disableFSMC(void);

void MM32RCC_disableUSB(void);

void MM32RCC_disableGPIOA(void);

void MM32RCC_disableGPIOB(void);

void MM32RCC_disableGPIOC(void);

void MM32RCC_disableGPIOD(void);

void MM32RCC_disableGPIOE(void);

void MM32RCC_disableGPIOF(void);

void MM32RCC_disableGPIOG(void);

void MM32RCC_disableGPIOH(void);

void MM32RCC_disableSDIO(void);

void MM32RCC_disableCRC(void);

void MM32RCC_disableDMA1(void);

void MM32RCC_disableDMA2(void);

void MM32RCC_disableTIM1(void);

void MM32RCC_disableTIM8(void);

void MM32RCC_disableUART1(void);

void MM32RCC_disableUART6(void);

void MM32RCC_disableADC1(void);

void MM32RCC_disableADC2(void);

void MM32RCC_disableADC3(void);

void MM32RCC_disableSPI1(void);

void MM32RCC_disableSYSCFG(void);

void MM32RCC_disableCOMP(void);

void MM32RCC_disableTIM2(void);

void MM32RCC_disableTIM3(void);

void MM32RCC_disableTIM4(void);

void MM32RCC_disableTIM5(void);

void MM32RCC_disableTIM6(void);

void MM32RCC_disableTIM7(void);

void MM32RCC_disableWWDG(void);

void MM32RCC_disableSPI2(void);

void MM32RCC_disableSPI3(void);

void MM32RCC_disableUART2(void);

void MM32RCC_disableUART3(void);

void MM32RCC_disableUART4(void);

void MM32RCC_disableUART5(void);

void MM32RCC_disableI2C1(void);

void MM32RCC_disableI2C2(void);

void MM32RCC_disableCRS(void);

void MM32RCC_disableCAN(void);

void MM32RCC_disableBKP(void);

void MM32RCC_disablePWR(void);

void MM32RCC_disableDAC(void);

void MM32RCC_disableUART7(void);

void MM32RCC_disableUART8(void);

#endif