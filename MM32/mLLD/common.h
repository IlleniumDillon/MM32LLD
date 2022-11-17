/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-01 22:08:29
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-02 20:38:16
 * @FilePath: \CODE\MM32\mLLD\common.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _COMMON_H_
#define _COMMON_H_

#define __MPU_PRESENT               (0)                                     ///< Cortex-M3 does not provide a MPU present or not
#ifndef __NVIC_PRIO_BITS
#define __NVIC_PRIO_BITS            (4)                                     ///< Cortex-M3 uses 4 Bits for the Priority Levels
//#warning "__NVIC_PRIO_BITS not defined in device header file; using default!"
#endif

#define __Vendor_SysTickConfig      (0)                                     ///< Set to 1 if different SysTick Config is used


////////////////////////////////////////////////////////////////////////////////
/// @brief  MM32 MCU Interrupt Handle
////////////////////////////////////////////////////////////////////////////////
typedef enum IRQn {
    NonMaskableInt_IRQn             = -14,                                  ///< 2 Non Maskable Interrupt
    MemoryManagement_IRQn           = -12,                                  ///< 4 Cortex-M3 Memory Management Interrupt
    BusFault_IRQn                   = -11,                                  ///< 5 Cortex-M3 Bus Fault Interrupt
    UsageFault_IRQn                 = -10,                                  ///< 6 Cortex-M3 Usage Fault Interrupt
    SVCall_IRQn                     = -5,                                   ///< 11 Cortex-M3 SV Call Interrupt
    DebugMonitor_IRQn               = -4,                                   ///< 12 Cortex-M3 Debug Monitor Interrupt
    PendSV_IRQn                     = -2,                                   ///< 14 Cortex-M3 Pend SV Interrupt
    SysTick_IRQn                    = -1,                                   ///< 15 Cortex-M3 System Tick Interrupt

    WWDG_IWDG_IRQn                      = 0,                                     ///< Watchdog interrupt
    WWDG_IRQn                           = 0,                                     ///< Watchdog interrupt
    PVD_IRQn                            = 1,                                     ///< (PVD) Interrupt
    TAMPER_IRQn                         = 2,                                     ///< Intrusion detection interrupted
    RTC_IRQn                            = 3,                                     ///< Real-time clock (RTC) global interrupt
    FLASH_IRQn                          = 4,                                     ///< Flash global interrupt
    RCC_CRS_IRQn                        = 5,                                     ///< RCC and CRS global interrupt
    EXTI0_IRQn                          = 6,                                     ///< EXTI line 0 interrupt
    EXTI1_IRQn                          = 7,                                     ///< EXTI line 1 interrupt
    EXTI2_IRQn                          = 8,                                     ///< EXTI line 2 interrupt
    EXTI3_IRQn                          = 9,                                     ///< EXTI line 3 interrupted
    EXTI4_IRQn                          = 10,                                    ///< EXTI line 4 interrupt
    DMA1_Channel1_IRQn                  = 11,                                    ///< DMA1 channel 1 global interrupt
    DMA1_Channel2_IRQn                  = 12,                                    ///< DMA1 channel 2 global interrupt
    DMA1_Channel3_IRQn                  = 13,                                    ///< DMA1 channel 3 global interrupt
    DMA1_Channel4_IRQn                  = 14,                                    ///< DMA1 channel 4 global interrupt
    DMA1_Channel5_IRQn                  = 15,                                    ///< DMA1 channel 5 global interrupt
    DMA1_Channel6_IRQn                  = 16,                                    ///< DMA1 channel 6 global interrupt
    DMA1_Channel7_IRQn                  = 17,                                    ///< DMA1 channel 7 global interrupt
    ADC1_IRQn                           = 18,                                    ///< ADC1 global interrupt
    ADC1_2_IRQn                         = 18,                                    ///< ADC1&ADC2 global interrupt
    ADC2_IRQn                           = 18,                                    ///< ADC2 global interrupt
    FlashCache_IRQn                     = 19,                                    ///< FlashCache outage
    CAN1_RX_IRQn                        = 21,                                    ///< CAN1 receive interrupt
    CAN_IRQn                            = 21,                                    ///< CAN interrupt
    EXTI9_5_IRQn                        = 23,                                    ///< EXTI line [9: 5] interrupted
    TIM1_BRK_IRQn                       = 24,                                    ///< TIM1 disconnect interrupt
    TIM1_UP_IRQn                        = 25,                                    ///< TIM1 update interrupt
    IM1_TRG_COM_IRQn                    = 26,                                    ///< TIM1 trigger and communication interrupt
    TIM1_CC_IRQn                        = 27,                                    ///< TIM1 capture compare interrupt
    TIM2_IRQn                           = 28,                                    ///< TIM2 global interrupt
    TIM3_IRQn                           = 29,                                    ///< TIM3 global interrupt
    TIM4_IRQn                           = 30,                                    ///< TIM4 global interrupt
    I2C1_IRQn                           = 31,                                    ///< I2C1 global interrupt
    I2C2_IRQn                           = 33,                                    ///< I2C2 global interrupt
    SPI1_IRQn                           = 35,                                    ///< SPI1 global interrupt
    SPI2_IRQn                           = 36,                                    ///< SPI2 global interrupt
    UART1_IRQn                          = 37,                                    ///< UART1 global interrupt
    UART2_IRQn                          = 38,                                    ///< UART2 global interrupt
    UART3_IRQn                          = 39,                                    ///< UART3 global interrupt
    EXTI15_10_IRQn                      = 40,                                    ///< EXTI line [15: 10] interrupted
    RTCAlarm_IRQn                       = 41,                                    ///< RTC alarm connected to EXTI interrupted
    USB_WKUP_IRQn                       = 42,                                    ///< Wake-up interrupt from USB connected to EXTI
    TIM8_BRK_IRQn                       = 43,                                    ///< TIM8 brake interruption
    TIM8_UP_IRQn                        = 44,                                    ///< TIM8 update interrupt
    TIM8_TRG_COM_IRQn                   = 45,                                    ///< TIM8 trigger, communication interrupt
    TIM8_CC_IRQn                        = 46,                                    ///< TIM8 capture compare interrupt
    ADC3_IRQn                           = 47,                                    ///< ADC3 global interrupt
    SDIO_IRQn                           = 49,                                    ///< SDIO global interrupt
    TIM5_IRQn                           = 50,                                    ///< TIM5 global interrupt
    SPI3_IRQn                           = 51,                                    ///< SPI3 global interrupt
    UART4_IRQn                          = 52,                                    ///< UART4 global interrupt
    UART5_IRQn                          = 53,                                    ///< UART5 global interrupt
    TIM6_IRQn                           = 54,                                    ///< TIM6 global interrupt
    TIM7_IRQn                           = 55,                                    ///< TIM7 global interrupt
    DMA2_Channel1_IRQn                  = 56,                                    ///< DMA2 channel 1 global interrupt
    DMA2_Channel2_IRQn                  = 57,                                    ///< DMA2 channel 2 global interrupt
    DMA2_Channel3_IRQn                  = 58,                                    ///< DMA2 channel 3 global interrupt
    DMA2_Channel4_IRQn                  = 59,                                    ///< DMA2 channel 4 global interrupt
    DMA2_Channel5_IRQn                  = 60,                                    ///< DMA2 channel 5 global interrupt
    ETHERNET_MAC_IRQn                   = 61,                                    ///< ETHERNET global interrupt
    COMP1_2_IRQn                        = 64,                                  ///< Comparator 1/2 interrupt connected to EXTI
    USB_FS_IRQn                         = 67,                                  ///< USB FS global interrupt
    UART6_IRQn                          = 71,                                  ///< UART6 global interrupt
    UART7_IRQn                          = 82,                                  ///< UART7 global interrupt
    UART8_IRQn                          = 83,                                  ///< UART8 global interrupt
} IRQn_Type;

#include <core_cm3.h>

void nvic_init(IRQn_Type irqn, uint8_t preemption_priority, uint8_t sub_priority, uint8_t status);
void nvic_interrput_enable (void);
void nvic_interrput_disable (void);

void systick_delay (uint32_t time);
void systick_delay_ms(uint32_t ms);

void systick_timing(uint32_t time);

void systick_start (void);
uint32_t systick_getval(void);

#endif