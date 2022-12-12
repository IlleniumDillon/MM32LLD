/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-12-11 19:56:08
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-12 15:18:32
 * @FilePath: \CODE\MM32\mLLD\ADC\MM32_ADCDMA.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "MM32_ADCDMA.h"

//各个ADC通道DMA传输完成标志
uint8_t ADC1_DMADone = 0;
uint8_t ADC2_DMADone = 0;
uint8_t ADC3_DMADone = 0;

/// @brief 初始化ADC模块用于DMA传输
/// @param pin ADC引脚结构体
void _ADCDMA_moudleInit(MM32ADC_Pin pin)
{
    //ADC模块指针
    MM32_ADC* moudle = (MM32_ADC*)pin.moudle;

    //使能对应的ADC模块
    switch (pin.moudle)
    {
    case ADC1:        MM32RCC_enableADC1();        break;
    case ADC2:        MM32RCC_enableADC2();        break;
    case ADC3:        MM32RCC_enableADC3();        break;
    default:        return;
    }

    //配置引脚属性
    MM32GPIO_setPinConfig(pin.port,pin.pin,pin.conf);

    //配置ADC模块时钟频率
    moudle->ADCFG.B.ADCPREH = 4;
    moudle->ADCFG.B.ADCPREL = 0;

    //使能对应通道
    moudle->ADCHS.U |= 0x1 << pin.ch;
    //配置为连续扫描模式
    moudle->ADCR.B.ADMD = 2;
    //使能DMA请求
    moudle->ADCR.B.DMAEN = 1;
    //ADC转换使能
    moudle->ADCFG.B.ADEN = 1;
}

void MM32ADCDMA_pinInit(MM32ADC_Pin pin, void* dataPtr, uint16_t size)
{
    //DMA模块指针
    MM32_DMA* moudle = NULL;
    //DMA控制寄存器
    MM32_DMA_CCR1* CCR;
    //DMA计数寄存器
    MM32_DMA_CNDTR1* CNDTR;
    //DMA外设地址寄存器
    MM32_DMA_CPAR1* CPAR;
    //DMA存储器地址寄存器
    MM32_DMA_CMAR1* CMAR;
    //ADC外设地址
    uint32_t PADDR;

    //根据ADC通道配置DMA通道和完成中断
    switch (pin.moudle)
    {
    case ADC1:
    {        
        MM32RCC_enableDMA1();
        /*MM32_DMA* */moudle = MOUDLE_DMA1;
        /*MM32_DMA_CCR1* */CCR = (MM32_DMA_CCR1*)DMA1_DMA_CCR1;
        /*MM32_DMA_CNDTR1* */CNDTR = (MM32_DMA_CNDTR1*)DMA1_DMA_CNDTR1;
        /*MM32_DMA_CPAR1* */CPAR = (MM32_DMA_CPAR1*)DMA1_DMA_CPAR1;
        /*MM32_DMA_CMAR1* */CMAR = (MM32_DMA_CMAR1*)DMA1_DMA_CMAR1;
        /*uint32_t */PADDR = (uint32_t)ADC1_ADDR0 + 0X04 * pin.ch;        
        nvic_init(DMA1_Channel1_IRQn,20,0,1);
        
        break;
    }
    case ADC2:
    {       
        MM32RCC_enableDMA1();
        /*MM32_DMA* */moudle = MOUDLE_DMA1;
        /*MM32_DMA_CCR2* */CCR = (MM32_DMA_CCR1*)DMA1_DMA_CCR2;
        /*MM32_DMA_CNDTR2* */CNDTR = (MM32_DMA_CNDTR1*)DMA1_DMA_CNDTR2;
        /*MM32_DMA_CPAR2* */CPAR = (MM32_DMA_CPAR1*)DMA1_DMA_CPAR2;
        /*MM32_DMA_CMAR2* */CMAR = (MM32_DMA_CMAR1*)DMA1_DMA_CMAR2;
        /*uint32_t */PADDR = (uint32_t)ADC2_ADDR0 + 0X04 * pin.ch;        
        nvic_init(DMA1_Channel2_IRQn,19,0,1);
        
        break;
    }
    case ADC3:
    {        
        MM32RCC_enableDMA2();
        /*MM32_DMA* */moudle = MOUDLE_DMA2;
        /*MM32_DMA_CCR5* */CCR = (MM32_DMA_CCR1*)DMA2_DMA_CCR5;
        /*MM32_DMA_CNDTR5* */CNDTR = (MM32_DMA_CNDTR1*)DMA2_DMA_CNDTR5;
        /*MM32_DMA_CPAR5* */CPAR = (MM32_DMA_CPAR1*)DMA2_DMA_CPAR5;
        /*MM32_DMA_CMAR5* */CMAR = (MM32_DMA_CMAR1*)DMA2_DMA_CMAR5;
        /*uint32_t */PADDR = (uint32_t)ADC3_ADDR0 + 0X04 * pin.ch;        
        nvic_init(DMA2_Channel5_IRQn,22,0,1);
        
        break;
    }
    default:        return;
    }
    
    //使能自动重装载
    CCR->B.ARE = 1;
    //设置高优先级
    CCR->B.PL = 2;
    //存储器数据宽度16bit
    CCR->B.MSIZE = 1;
    //外设数据宽度32bit
    CCR->B.PSIZE = 2;
    //存储器地址递增
    CCR->B.MINC = 1;
    //从外设读
    CCR->B.DIR = 0;
    //使能传输完成中断
    CCR->B.TCIE = 1;

    //设置DMA计数器
    CNDTR->B.NDT = size;
    //外设地址
    CPAR->B.PA = PADDR;
    //存储器地址
    CMAR->B.MA = (uint32_t)dataPtr;
    
    //使能DMA通道
    CCR->B.EN = 1;
    
    //配置ADC引脚
    _ADCDMA_moudleInit(pin);
}

void MM32ADCDMA_startADCDMA(MM32ADC_Pin pin)
{
    //ADC模块指针
    MM32_ADC* moudle = (MM32_ADC*)pin.moudle;
    //DMA控制寄存器
    //MM32_DMA_CCR1* CCR;
    switch (pin.moudle)
    {
    case ADC1:
    {        
        MM32_DMA_CCR1* CCR = (MM32_DMA_CCR1*)DMA1_DMA_CCR1;
        CCR->B.EN = 1;
        break;
    }
    case ADC2:
    {       
        MM32_DMA_CCR2* CCR = (MM32_DMA_CCR2*)DMA1_DMA_CCR2;
        CCR->B.EN = 1;
        break;
    }
    case ADC3:
    {        
        MM32_DMA_CCR5* CCR = (MM32_DMA_CCR5*)DMA2_DMA_CCR5;
        CCR->B.EN = 1;
        break;
    }
    default:        return;
    }
    //DMA使能传输
    //CCR->B.EN = 1;
    //ADC开始转换
    moudle->ADCR.B.ADST = 1;
}

void MM32ADCDMA_stopADCDMA(MM32ADC_Pin pin)
{
    //ADC模块指针
    MM32_ADC* moudle = (MM32_ADC*)pin.moudle;
    //ADC停止转换
    moudle->ADCR.B.ADST = 0;
    MM32_DMA_CCR1* CCR;
    switch (pin.moudle)
    {
    case ADC1:        
        CCR = (MM32_DMA_CCR1*)DMA1_DMA_CCR1;
    break;
    case ADC2:       
        CCR = (MM32_DMA_CCR1*)DMA1_DMA_CCR2;
    break;
    case ADC3:        
        CCR = (MM32_DMA_CCR1*)DMA2_DMA_CCR5;
    break;
    default:        return;
    }
    //DMA停止传输并重装载影子寄存器
    CCR->B.EN = 0;
}