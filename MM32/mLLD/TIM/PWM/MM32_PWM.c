/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-12-13 18:30:25
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-14 11:22:35
 * @FilePath: \CODE\MM32\mLLD\TIM\PWM\MM32_PWM.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "MM32_PWM.h"

void MM32PWM_pinInit(MM32PWM_Pin* pin, float freq)
{
    //初始化GPIO
    MM32GPIO_setAFPinConfig(pin->port,pin->pin,pin->conf,pin->af);
    //核心工作频率
    extern unsigned int SystemCoreClock;

    switch (pin->moudle)
    {
    case PWM1:
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
        TIM1_CR1->B.APRE = 1;
        TIM1_BDTR->B.MOE = 1;
        TIM1_EGR->B.UG = 1;
        switch (pin->channel)
        {
        case CH1P:
            TIM1_CCER->B.CC1E = 1;
            TIM1_CCMR1->B.CC1S = 0;
            TIM1_CCMR1->B.OC1FE = 1;
            TIM1_CCMR1->B.OC1PE = 1;
            TIM1_CCMR1->B.OC1M = 6;
            break;
        case CH1N:
            TIM1_CCER->B.CC1NE = 1;
            TIM1_CCMR1->B.CC1S = 0;
            TIM1_CCMR1->B.OC1FE = 1;
            TIM1_CCMR1->B.OC1PE = 1;
            TIM1_CCMR1->B.OC1M = 6;
            break;
        case CH2P:
            TIM1_CCER->B.CC2E = 1;
            TIM1_CCMR1->B.CC2S = 0;
            TIM1_CCMR1->B.OC2FE = 1;
            TIM1_CCMR1->B.OC2PE = 1;
            TIM1_CCMR1->B.OC2M = 6;
            break;
        case CH2N:
            TIM1_CCER->B.CC2NE = 1;
            TIM1_CCMR1->B.CC2S = 0;
            TIM1_CCMR1->B.OC2FE = 1;
            TIM1_CCMR1->B.OC2PE = 1;
            TIM1_CCMR1->B.OC2M = 6;
            break;
        case CH3P:
            TIM1_CCER->B.CC3E = 1;
            TIM1_CCMR2->B.CC3S = 0;
            TIM1_CCMR2->B.OC3FE = 1;
            TIM1_CCMR2->B.OC3PE = 1;
            TIM1_CCMR2->B.OC3M = 6;
            break;
        case CH3N:
            TIM1_CCER->B.CC3NE = 1;
            TIM1_CCMR2->B.CC3S = 0;
            TIM1_CCMR2->B.OC3FE = 1;
            TIM1_CCMR2->B.OC3PE = 1;
            TIM1_CCMR2->B.OC3M = 6;
            break;
        case CH4:
            TIM1_CCER->B.CC4E = 1;
            TIM1_CCMR2->B.CC4S = 0;
            TIM1_CCMR2->B.OC4FE = 1;
            TIM1_CCMR2->B.OC4PE = 1;
            TIM1_CCMR2->B.OC4M = 6;
            break;
        default:
            break;
        }
        TIM1_CR1->B.CEN = 1;        
        break;
    }
    case PWM2:
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
        TIM8_CR1->B.APRE = 1;
        TIM8_BDTR->B.MOE = 1;
        TIM8_EGR->B.UG = 1;
        switch (pin->channel)
        {
        case CH1P:
            TIM8_CCER->B.CC1E = 1;
            TIM8_CCMR1->B.CC1S = 0;
            TIM8_CCMR1->B.OC1FE = 1;
            TIM8_CCMR1->B.OC1PE = 1;
            TIM8_CCMR1->B.OC1M = 6;
            break;
        case CH1N:
            TIM8_CCER->B.CC1NE = 1;
            TIM8_CCMR1->B.CC1S = 0;
            TIM8_CCMR1->B.OC1FE = 1;
            TIM8_CCMR1->B.OC1PE = 1;
            TIM8_CCMR1->B.OC1M = 6;
            break;
        case CH2P:
            TIM8_CCER->B.CC2E = 1;
            TIM8_CCMR1->B.CC2S = 0;
            TIM8_CCMR1->B.OC2FE = 1;
            TIM8_CCMR1->B.OC2PE = 1;
            TIM8_CCMR1->B.OC2M = 6;
            break;
        case CH2N:
            TIM8_CCER->B.CC2NE = 1;
            TIM8_CCMR1->B.CC2S = 0;
            TIM8_CCMR1->B.OC2FE = 1;
            TIM8_CCMR1->B.OC2PE = 1;
            TIM8_CCMR1->B.OC2M = 6;
            break;
        case CH3P:
            TIM8_CCER->B.CC3E = 1;
            TIM8_CCMR2->B.CC3S = 0;
            TIM8_CCMR2->B.OC3FE = 1;
            TIM8_CCMR2->B.OC3PE = 1;
            TIM8_CCMR2->B.OC3M = 6;
            break;
        case CH3N:
            TIM8_CCER->B.CC3NE = 1;
            TIM8_CCMR2->B.CC3S = 0;
            TIM8_CCMR2->B.OC3FE = 1;
            TIM8_CCMR2->B.OC3PE = 1;
            TIM8_CCMR2->B.OC3M = 6;
            break;
        case CH4:
            TIM8_CCER->B.CC4E = 1;
            TIM8_CCMR2->B.CC4S = 0;
            TIM8_CCMR2->B.OC4FE = 1;
            TIM8_CCMR2->B.OC4PE = 1;
            TIM8_CCMR2->B.OC4M = 6;
            break;
        default:
            break;
        }
        TIM8_CR1->B.CEN = 1;        
        break;
    }
    case PWM3:
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
        TIM2_CR1->B.APRE = 1;
        TIM2_EGR->B.UG = 1;
        switch (pin->channel)
        {
        case CH1P:
            TIM2_CCER->B.CC1E = 1;
            TIM2_CCMR1->B.CC1S = 0;
            TIM2_CCMR1->B.OC1FE = 1;
            TIM2_CCMR1->B.OC1PE = 1;
            TIM2_CCMR1->B.OC1M = 6;
            break;
        case CH1N:
            TIM2_CCER->B.CC1NE = 1;
            TIM2_CCMR1->B.CC1S = 0;
            TIM2_CCMR1->B.OC1FE = 1;
            TIM2_CCMR1->B.OC1PE = 1;
            TIM2_CCMR1->B.OC1M = 6;
            break;
        case CH2P:
            TIM2_CCER->B.CC2E = 1;
            TIM2_CCMR1->B.CC2S = 0;
            TIM2_CCMR1->B.OC2FE = 1;
            TIM2_CCMR1->B.OC2PE = 1;
            TIM2_CCMR1->B.OC2M = 6;
            break;
        case CH2N:
            TIM2_CCER->B.CC2NE = 1;
            TIM2_CCMR1->B.CC2S = 0;
            TIM2_CCMR1->B.OC2FE = 1;
            TIM2_CCMR1->B.OC2PE = 1;
            TIM2_CCMR1->B.OC2M = 6;
            break;
        case CH3P:
            TIM2_CCER->B.CC3E = 1;
            TIM2_CCMR2->B.CC3S = 0;
            TIM2_CCMR2->B.OC3FE = 1;
            TIM2_CCMR2->B.OC3PE = 1;
            TIM2_CCMR2->B.OC3M = 6;
            break;
        case CH3N:
            TIM2_CCER->B.CC3NE = 1;
            TIM2_CCMR2->B.CC3S = 0;
            TIM2_CCMR2->B.OC3FE = 1;
            TIM2_CCMR2->B.OC3PE = 1;
            TIM2_CCMR2->B.OC3M = 6;
            break;
        case CH4:
            TIM2_CCER->B.CC4E = 1;
            TIM2_CCMR2->B.CC4S = 0;
            TIM2_CCMR2->B.OC4FE = 1;
            TIM2_CCMR2->B.OC4PE = 1;
            TIM2_CCMR2->B.OC4M = 6;
            break;
        default:
            break;
        }
        TIM2_CR1->B.CEN = 1;        
        break;
    }
    case PWM4:
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
        TIM5_CR1->B.APRE = 1;
        TIM5_EGR->B.UG = 1;
        switch (pin->channel)
        {
        case CH1P:
            TIM5_CCER->B.CC1E = 1;
            TIM5_CCMR1->B.CC1S = 0;
            TIM5_CCMR1->B.OC1FE = 1;
            TIM5_CCMR1->B.OC1PE = 1;
            TIM5_CCMR1->B.OC1M = 6;
            break;
        case CH1N:
            TIM5_CCER->B.CC1NE = 1;
            TIM5_CCMR1->B.CC1S = 0;
            TIM5_CCMR1->B.OC1FE = 1;
            TIM5_CCMR1->B.OC1PE = 1;
            TIM5_CCMR1->B.OC1M = 6;
            break;
        case CH2P:
            TIM5_CCER->B.CC2E = 1;
            TIM5_CCMR1->B.CC2S = 0;
            TIM5_CCMR1->B.OC2FE = 1;
            TIM5_CCMR1->B.OC2PE = 1;
            TIM5_CCMR1->B.OC2M = 6;
            break;
        case CH2N:
            TIM5_CCER->B.CC2NE = 1;
            TIM5_CCMR1->B.CC2S = 0;
            TIM5_CCMR1->B.OC2FE = 1;
            TIM5_CCMR1->B.OC2PE = 1;
            TIM5_CCMR1->B.OC2M = 6;
            break;
        case CH3P:
            TIM5_CCER->B.CC3E = 1;
            TIM5_CCMR2->B.CC3S = 0;
            TIM5_CCMR2->B.OC3FE = 1;
            TIM5_CCMR2->B.OC3PE = 1;
            TIM5_CCMR2->B.OC3M = 6;
            break;
        case CH3N:
            TIM5_CCER->B.CC3NE = 1;
            TIM5_CCMR2->B.CC3S = 0;
            TIM5_CCMR2->B.OC3FE = 1;
            TIM5_CCMR2->B.OC3PE = 1;
            TIM5_CCMR2->B.OC3M = 6;
            break;
        case CH4:
            TIM5_CCER->B.CC4E = 1;
            TIM5_CCMR2->B.CC4S = 0;
            TIM5_CCMR2->B.OC4FE = 1;
            TIM5_CCMR2->B.OC4PE = 1;
            TIM5_CCMR2->B.OC4M = 6;
            break;
        default:
            break;
        }
        TIM5_CR1->B.CEN = 1;        
        break;
    }
    case PWM5:
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
        TIM3_CR1->B.APRE = 1;
        TIM3_EGR->B.UG = 1;
        switch (pin->channel)
        {
        case CH1P:
            TIM3_CCER->B.CC1E = 1;
            TIM3_CCMR1->B.CC1S = 0;
            TIM3_CCMR1->B.OC1FE = 1;
            TIM3_CCMR1->B.OC1PE = 1;
            TIM3_CCMR1->B.OC1M = 6;
            break;
        case CH1N:
            TIM3_CCER->B.CC1NE = 1;
            TIM3_CCMR1->B.CC1S = 0;
            TIM3_CCMR1->B.OC1FE = 1;
            TIM3_CCMR1->B.OC1PE = 1;
            TIM3_CCMR1->B.OC1M = 6;
            break;
        case CH2P:
            TIM3_CCER->B.CC2E = 1;
            TIM3_CCMR1->B.CC2S = 0;
            TIM3_CCMR1->B.OC2FE = 1;
            TIM3_CCMR1->B.OC2PE = 1;
            TIM3_CCMR1->B.OC2M = 6;
            break;
        case CH2N:
            TIM3_CCER->B.CC2NE = 1;
            TIM3_CCMR1->B.CC2S = 0;
            TIM3_CCMR1->B.OC2FE = 1;
            TIM3_CCMR1->B.OC2PE = 1;
            TIM3_CCMR1->B.OC2M = 6;
            break;
        case CH3P:
            TIM3_CCER->B.CC3E = 1;
            TIM3_CCMR2->B.CC3S = 0;
            TIM3_CCMR2->B.OC3FE = 1;
            TIM3_CCMR2->B.OC3PE = 1;
            TIM3_CCMR2->B.OC3M = 6;
            break;
        case CH3N:
            TIM3_CCER->B.CC3NE = 1;
            TIM3_CCMR2->B.CC3S = 0;
            TIM3_CCMR2->B.OC3FE = 1;
            TIM3_CCMR2->B.OC3PE = 1;
            TIM3_CCMR2->B.OC3M = 6;
            break;
        case CH4:
            TIM3_CCER->B.CC4E = 1;
            TIM3_CCMR2->B.CC4S = 0;
            TIM3_CCMR2->B.OC4FE = 1;
            TIM3_CCMR2->B.OC4PE = 1;
            TIM3_CCMR2->B.OC4M = 6;
            break;
        default:
            break;
        }
        TIM3_CR1->B.CEN = 1;        
        break;
    }
    case PWM6:
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
        TIM4_CR1->B.APRE = 1;
        TIM4_EGR->B.UG = 1;
        switch (pin->channel)
        {
        case CH1P:
            TIM4_CCER->B.CC1E = 1;
            TIM4_CCMR1->B.CC1S = 0;
            TIM4_CCMR1->B.OC1FE = 1;
            TIM4_CCMR1->B.OC1PE = 1;
            TIM4_CCMR1->B.OC1M = 6;
            break;
        case CH1N:
            TIM4_CCER->B.CC1NE = 1;
            TIM4_CCMR1->B.CC1S = 0;
            TIM4_CCMR1->B.OC1FE = 1;
            TIM4_CCMR1->B.OC1PE = 1;
            TIM4_CCMR1->B.OC1M = 6;
            break;
        case CH2P:
            TIM4_CCER->B.CC2E = 1;
            TIM4_CCMR1->B.CC2S = 0;
            TIM4_CCMR1->B.OC2FE = 1;
            TIM4_CCMR1->B.OC2PE = 1;
            TIM4_CCMR1->B.OC2M = 6;
            break;
        case CH2N:
            TIM4_CCER->B.CC2NE = 1;
            TIM4_CCMR1->B.CC2S = 0;
            TIM4_CCMR1->B.OC2FE = 1;
            TIM4_CCMR1->B.OC2PE = 1;
            TIM4_CCMR1->B.OC2M = 6;
            break;
        case CH3P:
            TIM4_CCER->B.CC3E = 1;
            TIM4_CCMR2->B.CC3S = 0;
            TIM4_CCMR2->B.OC3FE = 1;
            TIM4_CCMR2->B.OC3PE = 1;
            TIM4_CCMR2->B.OC3M = 6;
            break;
        case CH3N:
            TIM4_CCER->B.CC3NE = 1;
            TIM4_CCMR2->B.CC3S = 0;
            TIM4_CCMR2->B.OC3FE = 1;
            TIM4_CCMR2->B.OC3PE = 1;
            TIM4_CCMR2->B.OC3M = 6;
            break;
        case CH4:
            TIM4_CCER->B.CC4E = 1;
            TIM4_CCMR2->B.CC4S = 0;
            TIM4_CCMR2->B.OC4FE = 1;
            TIM4_CCMR2->B.OC4PE = 1;
            TIM4_CCMR2->B.OC4M = 6;
            break;
        default:
            break;
        }
        TIM4_CR1->B.CEN = 1;        
        break;
    }
    default:        break;
    }

}

void MM32PWM_setDuty(MM32PWM_Pin* pin, float duty)
{
    switch (pin->moudle)
    {
    case PWM1:
    {        
        switch (pin->channel)
        {
        case CH1N:
        case CH1P:
            TIM1_CCR1->B.CCR1 = (uint16_t)(TIM1_ARR->U * duty);
            break;
        case CH2N:
        case CH2P:
            TIM1_CCR2->B.CCR2 = (uint16_t)(TIM1_ARR->U * duty);
            break;
        case CH3N:
        case CH3P:
            TIM1_CCR3->B.CCR3 = (uint16_t)(TIM1_ARR->U * duty);
            break;
        case CH4:
            TIM1_CCR4->B.CCR4 = (uint16_t)(TIM1_ARR->U * duty);
            break;
        default:
            break;
        }
        break;
    }
    case PWM2:
    {
        switch (pin->channel)
        {        
        case CH1N:
        case CH1P:
            TIM8_CCR1->B.CCR1 = (uint16_t)(TIM8_ARR->U * duty);
            break;
        case CH2N:
        case CH2P:
            TIM8_CCR2->B.CCR2 = (uint16_t)(TIM8_ARR->U * duty);
            break;
        case CH3N:
        case CH3P:
            TIM8_CCR3->B.CCR3 = (uint16_t)(TIM8_ARR->U * duty);
            break;
        case CH4:
            TIM8_CCR4->B.CCR4 = (uint16_t)(TIM8_ARR->U * duty);
            break;
        }
        break;
    }
    case PWM3:
    {        
        switch (pin->channel)
        {        
        case CH1N:
        case CH1P:
            TIM2_CCR1->B.CCR1 = (uint32_t)(TIM2_ARR->U * duty);
            break;
        case CH2N:
        case CH2P:
            TIM2_CCR2->B.CCR2 = (uint32_t)(TIM2_ARR->U * duty);
            break;
        case CH3N:
        case CH3P:
            TIM2_CCR3->B.CCR3 = (uint32_t)(TIM2_ARR->U * duty);
            break;
        case CH4:
            TIM2_CCR4->B.CCR4 = (uint32_t)(TIM2_ARR->U * duty);
            break;
        }
        break;
    }
    case PWM4:
    {        
        switch (pin->channel)
        {        
        case CH1N:
        case CH1P:
            TIM5_CCR1->B.CCR1 = (uint32_t)(TIM5_ARR->U * duty);
            break;
        case CH2N:
        case CH2P:
            TIM5_CCR2->B.CCR2 = (uint32_t)(TIM5_ARR->U * duty);
            break;
        case CH3N:
        case CH3P:
            TIM5_CCR3->B.CCR3 = (uint32_t)(TIM5_ARR->U * duty);
            break;
        case CH4:
            TIM5_CCR4->B.CCR4 = (uint32_t)(TIM5_ARR->U * duty);
            break;
        }
        break;
    }
    case PWM5:
    {        
        switch (pin->channel)
        {        
        case CH1N:
        case CH1P:
            TIM3_CCR1->B.CCR1 = (uint32_t)(TIM3_ARR->U * duty);
            break;
        case CH2N:
        case CH2P:
            TIM3_CCR2->B.CCR2 = (uint32_t)(TIM3_ARR->U * duty);
            break;
        case CH3N:
        case CH3P:
            TIM3_CCR3->B.CCR3 = (uint32_t)(TIM3_ARR->U * duty);
            break;
        case CH4:
            TIM3_CCR4->B.CCR4 = (uint32_t)(TIM3_ARR->U * duty);
            break;
        }
        break;
    }
    case PWM6:
    {        
        switch (pin->channel)
        {        
        case CH1N:
        case CH1P:
            TIM4_CCR1->B.CCR1 = (uint32_t)(TIM4_ARR->U * duty);
            break;
        case CH2N:
        case CH2P:
            TIM4_CCR2->B.CCR2 = (uint32_t)(TIM4_ARR->U * duty);
            break;
        case CH3N:
        case CH3P:
            TIM4_CCR3->B.CCR3 = (uint32_t)(TIM4_ARR->U * duty);
            break;
        case CH4:
            TIM4_CCR4->B.CCR4 = (uint32_t)(TIM4_ARR->U * duty);
            break;
        }
        break;
    }
    default:        break;
    }
}