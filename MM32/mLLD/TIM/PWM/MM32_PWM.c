/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-12-13 18:30:25
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-13 19:19:48
 * @FilePath: \CODE\MM32\mLLD\TIM\PWM\MM32_PWM.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "MM32_PWM.h"

void MM32PWM_pinInit(MM32PWM_Pin* pin, uint32_t freq)
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
        break;
    }
    case PWM3:
    {        
        MM32RCC_enableTIM2();        
        break;
    }
    case PWM4:
    {        
        MM32RCC_enableTIM5();        
        break;
    }
    case PWM5:
    {        
        MM32RCC_enableTIM3();        
        break;
    }
    case PWM6:
    {        
        MM32RCC_enableTIM4();        
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
        
        break;
    }
    case PWM3:
    {        
        
        break;
    }
    case PWM4:
    {        
        
        break;
    }
    case PWM5:
    {        
        
        break;
    }
    case PWM6:
    {        
        
        break;
    }
    default:        break;
    }
}