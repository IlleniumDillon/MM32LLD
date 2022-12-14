/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-12-14 11:30:11
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-14 12:55:55
 * @FilePath: \CODE\MM32\mLLD\TIM\CCU\MM32_CCU.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "MM32_CCU.h"

void MM32CCU_pinInit(MM32CCU_Pin* pin, float freq)
{
    //初始化GPIO
    MM32GPIO_setAFPinConfig(pin->port,pin->pin,pin->conf,pin->af);
    //核心工作频率
    extern unsigned int SystemCoreClock;

    switch (pin->moudle)
    {
    case CCU1:
    {        
        MM32RCC_enableTIM1();
        //根据频率计算分频系数
        uint32_t arr = SystemCoreClock / freq;
        uint32_t psr = 1;
        while(arr > 65535)
        {
            arr = arr >> 1;
            psr = psr << 1;
        }
        TIM1_ARR->B.ARR = (uint16_t)arr;
        TIM1_PSC->B.PSC = (uint16_t)psr-1;
        TIM1_SMCR->B.TS = 4;
        TIM1_SMCR->B.SMS = 4;
        TIM1_CR1->B.APRE = 1;
        TIM1_EGR->B.UG = 1;
        TIM1_CCMR1->B.CC1S = 1;
        TIM1_CCER->B.CC1P = 1;
        TIM1_CCER->B.CC1E = 1;
        TIM1_CR1->B.CEN = 1;        
        break;
    }
    case CCU2:
    {        
        MM32RCC_enableTIM8();
        //根据频率计算分频系数
        uint32_t arr = SystemCoreClock / freq;
        uint32_t psr = 1;
        while(arr > 65535)
        {
            arr = arr >> 1;
            psr = psr << 1;
        }
        TIM8_ARR->B.ARR = (uint16_t)arr;
        TIM8_PSC->B.PSC = (uint16_t)psr-1;
        TIM8_SMCR->B.TS = 4;
        TIM8_SMCR->B.SMS = 4;
        TIM8_CR1->B.APRE = 1;
        TIM8_EGR->B.UG = 1;
        TIM8_CCMR1->B.CC1S = 1;
        TIM8_CCER->B.CC1P = 1;
        TIM8_CCER->B.CC1E = 1;
        TIM8_CR1->B.CEN = 1;        
        break;
    }
    case CCU3:
    {        
        MM32RCC_enableTIM2();
        //根据频率计算分频系数
        uint64_t arr = SystemCoreClock / freq;
        uint32_t psr = 1;
        while(arr > UINT32_MAX)
        {
            arr = arr >> 1;
            psr = psr << 1;
        }
        TIM2_ARR->B.ARR = (uint32_t)arr;
        TIM2_PSC->B.PSC = (uint16_t)psr-1;
        TIM2_SMCR->B.TS = 4;
        TIM2_SMCR->B.SMS = 4;
        TIM2_CR1->B.APRE = 1;
        TIM2_EGR->B.UG = 1;
        TIM2_CCMR1->B.CC1S = 1;
        TIM2_CCER->B.CC1P = 1;
        TIM2_CCER->B.CC1E = 1;
        TIM2_CR1->B.CEN = 1;        
        break;
    }
    case CCU4:
    {        
        MM32RCC_enableTIM5();
        //根据频率计算分频系数
        uint64_t arr = SystemCoreClock / freq;
        uint32_t psr = 1;
        while(arr > UINT32_MAX)
        {
            arr = arr >> 1;
            psr = psr << 1;
        }
        TIM5_ARR->B.ARR = (uint32_t)arr;
        TIM5_PSC->B.PSC = (uint16_t)psr-1;
        TIM5_SMCR->B.TS = 4;
        TIM5_SMCR->B.SMS = 4;
        TIM5_CR1->B.APRE = 1;
        TIM5_EGR->B.UG = 1;
        TIM5_CCMR1->B.CC1S = 1;
        TIM5_CCER->B.CC1P = 1;
        TIM5_CCER->B.CC1E = 1;
        TIM5_CR1->B.CEN = 1;        
        break;
    }
    case CCU5:
    {        
        MM32RCC_enableTIM3();
        //根据频率计算分频系数
        uint32_t arr = SystemCoreClock / freq;
        uint32_t psr = 1;
        while(arr > 65535)
        {
            arr = arr >> 1;
            psr = psr << 1;
        }
        TIM3_ARR->B.ARR = (uint16_t)arr;
        TIM3_PSC->B.PSC = (uint16_t)psr-1;
        TIM3_SMCR->B.TS = 4;
        TIM3_SMCR->B.SMS = 4;
        TIM3_CR1->B.APRE = 1;
        TIM3_EGR->B.UG = 1;
        TIM3_CCMR1->B.CC1S = 1;
        TIM3_CCER->B.CC1P = 1;
        TIM3_CCER->B.CC1E = 1;
        TIM3_CR1->B.CEN = 1;        
        break;
    }
    case CCU6:
    {        
        MM32RCC_enableTIM4();
        //根据频率计算分频系数
        uint32_t arr = SystemCoreClock / freq;
        uint32_t psr = 1;
        while(arr > 65535)
        {
            arr = arr >> 1;
            psr = psr << 1;
        }
        TIM4_ARR->B.ARR = (uint16_t)arr;
        TIM4_PSC->B.PSC = (uint16_t)psr-1;
        TIM4_SMCR->B.TS = 4;
        TIM4_SMCR->B.SMS = 4;
        TIM4_CR1->B.APRE = 1;
        TIM4_EGR->B.UG = 1;
        TIM4_CCMR1->B.CC1S = 1;
        TIM4_CCER->B.CC1P = 1;
        TIM4_CCER->B.CC1E = 1;
        TIM4_CR1->B.CEN = 1;        
        break;
    }
    default:        break;
    }

}

uint32_t MM32CCU_getCCR(MM32CCU_Pin* pin)
{
    switch (pin->moudle)
    {
    case CCU1:
    {        
        return TIM1_CCR1->B.CCR1;
    }
    case CCU2:
    {
        return TIM8_CCR1->B.CCR1;
    }
    case CCU3:
    {        
        return TIM2_CCR1->B.CCR1;
    }
    case CCU4:
    {        
        return TIM5_CCR1->B.CCR1;
    }
    case CCU5:
    {        
        return TIM3_CCR1->B.CCR1;
    }
    case CCU6:
    {        
        return TIM4_CCR1->B.CCR1;
    }
    default:        return 0;
    }
}

float MM32CCU_getDuty(MM32CCU_Pin* pin)
{
    uint32_t t = 0;
    switch (pin->moudle)
    {
    case CCU1:        t = TIM1_ARR->U;        break;
    case CCU2:        t = TIM8_ARR->U;        break;
    case CCU3:        t = TIM2_ARR->U;        break;
    case CCU4:        t = TIM5_ARR->U;        break;
    case CCU5:        t = TIM3_ARR->U;        break;
    case CCU6:        t = TIM4_ARR->U;        break;
    default:        return 0;
    }
    return (float)MM32CCU_getCCR(pin) / (float)t;
}