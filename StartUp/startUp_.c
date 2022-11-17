/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:45:42
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:08:14
 * @FilePath: \CODE\StartUp\startUp_.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "startUp_.h"

extern void __iar_program_start();

unsigned int SystemCoreClock = 120000000;

void LowSpeedClkInit(void)
{
  RCC_CR->B.HSION = 1;
  while(RCC_CR->B.HSIRDY != 1);
  RCC_AHB1ENR->B.SRAM = 1;
  RCC_AHB1ENR->B.FLASH = 1;
  RCC_SYSCFG->B.DATAPREFETCH = 0;
}

void HighSpeedClkInit(void)
{
  /*RCC_CR.B.HSION = 0;
  RCC_BDCR.B.LSEON = 0;
  RCC_BDCR.B.RTCSEL = 0;
  RCC_BDCR.B.RTCEN = 0;*/
  RCC_CR->B.HSION = 1;
  while(RCC_CR->B.HSIRDY != 1);
  RCC_PLLCFGR->B.PLLSRC = 0;
  //RCC_PLLCFGR->B.PLLXTPRE = 0;
  RCC_PLLCFGR->B.PLLDIV = 0;
  RCC_PLLCFGR->B.PLLMUL = 14;
  RCC_CR->B.PLLON = 1;
  while(RCC_CR->B.PLLRDY != 1);
  RCC_CFGR->B.SW = 2;
  FLASH_ACR->B.LATENCY = 3;
  FLASH_ACR->B.PRFTBE = 1;
  /*RCC_CFGR.B.HPRE = 0;
  RCC_CFGR.B.PPRE1 = 0;
  RCC_CFGR.B.PPRE2 = 0;*/
  RCC_CFGR->B.MCO = 0;
}

void SystemInit(void)
{
  LowSpeedClkInit();
  
  HighSpeedClkInit();
  
  __iar_program_start();
}