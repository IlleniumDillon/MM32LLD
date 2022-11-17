/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:43:27
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:07:33
 * @FilePath: \CODE\MM32\Sfr\MM32_RCCRegDef.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_RCCREGDEF_H_
#define _MM32_RCCREGDEF_H_

#include "MM32_RegTypedef.h"

typedef struct _MM32_RCC_CRBits
{
	Strict_32Bit	HSION		:	1;
	Strict_32Bit	HSIRDY		:	1;
	Strict_32Bit	_reserved_0		:	9;
	Strict_32Bit	HSIDIV		:	3;
	Strict_32Bit	_reserved_1		:	2;
	Strict_32Bit	HSEON		:	1;
	Strict_32Bit	HSERDY		:	1;
	Strict_32Bit	HSEBYP		:	1;
	Strict_32Bit	CSSON		:	1;
	Strict_32Bit	_reserved_2		:	4;
	Strict_32Bit	PLLON		:	1;
	Strict_32Bit	PLLRDY		:	1;
	Strict_32Bit	_reserved_3		:	6;
}MM32_RCC_CRBits;
typedef struct _MM32_RCC_CFGRBits
{
	Strict_32Bit	SW		:	2;
	Strict_32Bit	SWS		:	2;
	Strict_32Bit	HPRE		:	4;
	Strict_32Bit	PPRE1		:	3;
	Strict_32Bit	PPRE2		:	3;
	Strict_32Bit	_reserved_0		:	8;
	Strict_32Bit	USBPRE		:	2;
	Strict_32Bit	MCO		:	3;
	Strict_32Bit	_reserved_1		:	5;
}MM32_RCC_CFGRBits;
typedef struct _MM32_RCC_CIRBits
{
	Strict_32Bit	LSIRDYF		:	1;
	Strict_32Bit	LSERDYF		:	1;
	Strict_32Bit	HSIRDYF		:	1;
	Strict_32Bit	HSERDYF		:	1;
	Strict_32Bit	PLLRDYF		:	1;
	Strict_32Bit	_reserved_0		:	2;
	Strict_32Bit	CSSF		:	1;
	Strict_32Bit	LSIRDYIE		:	1;
	Strict_32Bit	LSERDYIE		:	1;
	Strict_32Bit	HSIRDYIE		:	1;
	Strict_32Bit	HSERDYIE		:	1;
	Strict_32Bit	PLLRDYIE		:	1;
	Strict_32Bit	_reserved_1		:	3;
	Strict_32Bit	LSIRDYC		:	1;
	Strict_32Bit	LSERDYC		:	1;
	Strict_32Bit	HSIRDYC		:	1;
	Strict_32Bit	HSERDYC		:	1;
	Strict_32Bit	PLLRDYC		:	1;
	Strict_32Bit	_reserved_2		:	2;
	Strict_32Bit	CSSC		:	1;
	Strict_32Bit	_reserved_3		:	8;
}MM32_RCC_CIRBits;
typedef struct _MM32_RCC_AHB3RSTRBits
{
	Strict_32Bit	FSMC		:	1;
	Strict_32Bit	_reserved_0		:	31;
}MM32_RCC_AHB3RSTRBits;
typedef struct _MM32_RCC_AHB2RSTRBits
{
	Strict_32Bit	_reserved_0		:	7;
	Strict_32Bit	USBOTGFS		:	1;
	Strict_32Bit	_reserved_1		:	24;
}MM32_RCC_AHB2RSTRBits;
typedef struct _MM32_RCC_AHB1RSTRBits
{
	Strict_32Bit	GPIOA		:	1;
	Strict_32Bit	GPIOB		:	1;
	Strict_32Bit	GPIOC		:	1;
	Strict_32Bit	GPIOD		:	1;
	Strict_32Bit	GPIOE		:	1;
	Strict_32Bit	GPIOF		:	1;
	Strict_32Bit	GPIOG		:	1;
	Strict_32Bit	GPIOH		:	1;
	Strict_32Bit	_reserved_0		:	2;
	Strict_32Bit	SDIO		:	1;
	Strict_32Bit	_reserved_1		:	1;
	Strict_32Bit	CRC		:	1;
	Strict_32Bit	_reserved_2		:	8;
	Strict_32Bit	DMA1		:	1;
	Strict_32Bit	DMA2		:	1;
	Strict_32Bit	_reserved_3		:	9;
}MM32_RCC_AHB1RSTRBits;
typedef struct _MM32_RCC_APB2RSTRBits
{
	Strict_32Bit	TIM1		:	1;
	Strict_32Bit	TIM8		:	1;
	Strict_32Bit	_reserved_0		:	2;
	Strict_32Bit	UART1		:	1;
	Strict_32Bit	UART6		:	1;
	Strict_32Bit	_reserved_1		:	2;
	Strict_32Bit	ADC1		:	1;
	Strict_32Bit	ADC2		:	1;
	Strict_32Bit	ADC3		:	1;
	Strict_32Bit	_reserved_2		:	1;
	Strict_32Bit	SPI1		:	1;
	Strict_32Bit	_reserved_3		:	1;
	Strict_32Bit	SYSCFG		:	1;
	Strict_32Bit	COMP		:	1;
	Strict_32Bit	_reserved_4		:	16;
}MM32_RCC_APB2RSTRBits;
typedef struct _MM32_RCC_APB1RSTRBits
{
	Strict_32Bit	TIM2		:	1;
	Strict_32Bit	TIM3		:	1;
	Strict_32Bit	TIM4		:	1;
	Strict_32Bit	TIM5		:	1;
	Strict_32Bit	TIM6		:	1;
	Strict_32Bit	TIM7		:	1;
	Strict_32Bit	_reserved_0		:	5;
	Strict_32Bit	WWDG		:	1;
	Strict_32Bit	_reserved_1		:	2;
	Strict_32Bit	SPI2		:	1;
	Strict_32Bit	SPI3		:	1;
	Strict_32Bit	_reserved_2		:	1;
	Strict_32Bit	UART2		:	1;
	Strict_32Bit	UART3		:	1;
	Strict_32Bit	UART4		:	1;
	Strict_32Bit	UART5		:	1;
	Strict_32Bit	I2C1		:	1;
	Strict_32Bit	I2C2		:	1;
	Strict_32Bit	_reserved_3		:	1;
	Strict_32Bit	CRS		:	1;
	Strict_32Bit	CAN		:	1;
	Strict_32Bit	_reserved_4		:	1;
	Strict_32Bit	BKP		:	1;
	Strict_32Bit	PWR		:	1;
	Strict_32Bit	DAC		:	1;
	Strict_32Bit	UART7		:	1;
	Strict_32Bit	UART8		:	1;
}MM32_RCC_APB1RSTRBits;
typedef struct _MM32_RCC_AHB3ENRBits
{
	Strict_32Bit	FSMC		:	1;
	Strict_32Bit	_reserved_0		:	31;
}MM32_RCC_AHB3ENRBits;
typedef struct _MM32_RCC_AHB2ENRBits
{
	Strict_32Bit	_reserved_0		:	7;
	Strict_32Bit	USBOTGFS		:	1;
	Strict_32Bit	_resereved_1		:	24;
}MM32_RCC_AHB2ENRBits;
typedef struct _MM32_RCC_AHB1ENRBits
{
	Strict_32Bit	GPIOA		:	1;
	Strict_32Bit	GPIOB		:	1;
	Strict_32Bit	GPIOC		:	1;
	Strict_32Bit	GPIOD		:	1;
	Strict_32Bit	GPIOE		:	1;
	Strict_32Bit	GPIOF		:	1;
	Strict_32Bit	GPIOG		:	1;
	Strict_32Bit	GPIOH		:	1;
	Strict_32Bit	_reserved_0		:	2;
	Strict_32Bit	SDIO		:	1;
	Strict_32Bit	_reserved_1		:	1;
	Strict_32Bit	CRC		:	1;
	Strict_32Bit	FLASH		:	1;
	Strict_32Bit	SRAM		:	1;
	Strict_32Bit	_reserved_2		:	6;
	Strict_32Bit	DMA1		:	1;
	Strict_32Bit	DMA2		:	1;
	Strict_32Bit	_reserved_3		:	9;
}MM32_RCC_AHB1ENRBits;
typedef struct _MM32_RCC_APB2ENRBits
{
	Strict_32Bit	TIM1		:	1;
	Strict_32Bit	TIM8		:	1;
	Strict_32Bit	_reserved_0		:	2;
	Strict_32Bit	UART1		:	1;
	Strict_32Bit	UART6		:	1;
	Strict_32Bit	_reserved_1		:	2;
	Strict_32Bit	ADC1		:	1;
	Strict_32Bit	ADC2		:	1;
	Strict_32Bit	ADC3		:	1;
	Strict_32Bit	_reserved_2		:	1;
	Strict_32Bit	SPI1		:	1;
	Strict_32Bit	_reserved_3		:	1;
	Strict_32Bit	SYSCFG		:	1;
	Strict_32Bit	COMP		:	1;
	Strict_32Bit	_reserved_4		:	16;
}MM32_RCC_APB2ENRBits;
typedef struct _MM32_RCC_APB1ENRBits
{
	Strict_32Bit	TIM2		:	1;
	Strict_32Bit	TIM3		:	1;
	Strict_32Bit	TIM4		:	1;
	Strict_32Bit	TIM5		:	1;
	Strict_32Bit	TIM6		:	1;
	Strict_32Bit	TIM7		:	1;
	Strict_32Bit	_reserved_0		:	5;
	Strict_32Bit	WWDG		:	1;
	Strict_32Bit	_reserved_1		:	2;
	Strict_32Bit	SPI2		:	1;
	Strict_32Bit	SPI3		:	1;
	Strict_32Bit	_reserved_2		:	1;
	Strict_32Bit	UART2		:	1;
	Strict_32Bit	UART3		:	1;
	Strict_32Bit	UART4		:	1;
	Strict_32Bit	UART5		:	1;
	Strict_32Bit	I2C1		:	1;
	Strict_32Bit	I2C2		:	1;
	Strict_32Bit	_reserved_3		:	1;
	Strict_32Bit	CRS		:	1;
	Strict_32Bit	CAN		:	1;
	Strict_32Bit	_reserved_4		:	1;
	Strict_32Bit	BKP		:	1;
	Strict_32Bit	PWR_DBG		:	1;
	Strict_32Bit	DAC		:	1;
	Strict_32Bit	UART7		:	1;
	Strict_32Bit	UART8		:	1;
}MM32_RCC_APB1ENRBits;
typedef struct _MM32_RCC_BDCRBits
{
	Strict_32Bit	LSEON		:	1;
	Strict_32Bit	LSERDY		:	1;
	Strict_32Bit	LSEBYP		:	1;
	Strict_32Bit	_reserved_0		:	5;
	Strict_32Bit	RTCSEL		:	2;
	Strict_32Bit	_reserved_1		:	5;
	Strict_32Bit	RTCEN		:	1;
	Strict_32Bit	BDRST		:	1;
	Strict_32Bit	_reserved_2		:	7;
	Strict_32Bit	DBP		:	1;
	Strict_32Bit	_reserved_3		:	7;
}MM32_RCC_BDCRBits;
typedef struct _MM32_RCC_CSRBits
{
	Strict_32Bit	LSION		:	1;
	Strict_32Bit	LSIRDY		:	1;
	Strict_32Bit	_reserved_0		:	3;
	Strict_32Bit	LSIOE		:	1;
	Strict_32Bit	PVDRSTEN		:	1;
	Strict_32Bit	LOCKUPEN		:	1;
	Strict_32Bit	_reserved_1		:	14;
	Strict_32Bit	PVDRSTF		:	1;
	Strict_32Bit	LOCKUPF		:	1;
	Strict_32Bit	RMVF		:	1;
	Strict_32Bit	_reserved_2		:	1;
	Strict_32Bit	PINRSTF		:	1;
	Strict_32Bit	PORRSTF		:	1;
	Strict_32Bit	SFTRSTF		:	1;
	Strict_32Bit	IWDGRSTF		:	1;
	Strict_32Bit	WWDGRSTF		:	1;
	Strict_32Bit	LPWRRSTF		:	1;
}MM32_RCC_CSRBits;
typedef struct _MM32_RCC_SYSCFGBits
{
	Strict_32Bit	PROG_CHECK_EN		:	1;
	Strict_32Bit	_reserved_0		:	1;
	Strict_32Bit	DATAPREFETCH		:	1;
	Strict_32Bit	_reserved_1		:	5;
	Strict_32Bit	HSE_RFB_SEL		:	2;
	Strict_32Bit	_reserved_2		:	4;
	Strict_32Bit	HSELPFEN		:	1;
	Strict_32Bit	_reserved_3		:	17;
}MM32_RCC_SYSCFGBits;
typedef struct _MM32_RCC_CFGR2Bits
{
	Strict_32Bit	TIMADV_CKSEL		:	1;
	Strict_32Bit	TIMADV_PRE		:	3;
	Strict_32Bit	_reserved_0		:	12;
	Strict_32Bit	APB1_CLK_HV_PRE		:	4;
	Strict_32Bit	_reserved_1		:	12;
}MM32_RCC_CFGR2Bits;
typedef struct _MM32_RCC_ICSCRBits
{
	Strict_32Bit	TRIM_CRS_SEL		:	1;
	Strict_32Bit	_reserved_0		:	31;
}MM32_RCC_ICSCRBits;
typedef struct _MM32_RCC_PLLCFGRBits
{
	Strict_32Bit	PLLSRC		:	1;
	Strict_32Bit	PLLXTPRE		:	1;
	Strict_32Bit	PLL_ICTRL		:	2;
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	PLLDIV		:	3;
	Strict_32Bit	_reserved_1		:	5;
	Strict_32Bit	PLLMUL		:	7;
	Strict_32Bit	_reserved_2		:	9;
}MM32_RCC_PLLCFGRBits;
typedef union _MM32_RCC_CR
{
	uint32_t	U;
	int32_t	I;
	MM32_RCC_CRBits	B;
}MM32_RCC_CR;
typedef union _MM32_RCC_CFGR
{
	uint32_t	U;
	int32_t	I;
	MM32_RCC_CFGRBits	B;
}MM32_RCC_CFGR;
typedef union _MM32_RCC_CIR
{
	uint32_t	U;
	int32_t	I;
	MM32_RCC_CIRBits	B;
}MM32_RCC_CIR;
typedef union _MM32_RCC_AHB3RSTR
{
	uint32_t	U;
	int32_t	I;
	MM32_RCC_AHB3RSTRBits	B;
}MM32_RCC_AHB3RSTR;
typedef union _MM32_RCC_AHB2RSTR
{
	uint32_t	U;
	int32_t	I;
	MM32_RCC_AHB2RSTRBits	B;
}MM32_RCC_AHB2RSTR;
typedef union _MM32_RCC_AHB1RSTR
{
	uint32_t	U;
	int32_t	I;
	MM32_RCC_AHB1RSTRBits	B;
}MM32_RCC_AHB1RSTR;
typedef union _MM32_RCC_APB2RSTR
{
	uint32_t	U;
	int32_t	I;
	MM32_RCC_APB2RSTRBits	B;
}MM32_RCC_APB2RSTR;
typedef union _MM32_RCC_APB1RSTR
{
	uint32_t	U;
	int32_t	I;
	MM32_RCC_APB1RSTRBits	B;
}MM32_RCC_APB1RSTR;
typedef union _MM32_RCC_AHB3ENR
{
	uint32_t	U;
	int32_t	I;
	MM32_RCC_AHB3ENRBits	B;
}MM32_RCC_AHB3ENR;
typedef union _MM32_RCC_AHB2ENR
{
	uint32_t	U;
	int32_t	I;
	MM32_RCC_AHB2ENRBits	B;
}MM32_RCC_AHB2ENR;
typedef union _MM32_RCC_AHB1ENR
{
	uint32_t	U;
	int32_t	I;
	MM32_RCC_AHB1ENRBits	B;
}MM32_RCC_AHB1ENR;
typedef union _MM32_RCC_APB2ENR
{
	uint32_t	U;
	int32_t	I;
	MM32_RCC_APB2ENRBits	B;
}MM32_RCC_APB2ENR;
typedef union _MM32_RCC_APB1ENR
{
	uint32_t	U;
	int32_t	I;
	MM32_RCC_APB1ENRBits	B;
}MM32_RCC_APB1ENR;
typedef union _MM32_RCC_BDCR
{
	uint32_t	U;
	int32_t	I;
	MM32_RCC_BDCRBits	B;
}MM32_RCC_BDCR;
typedef union _MM32_RCC_CSR
{
	uint32_t	U;
	int32_t	I;
	MM32_RCC_CSRBits	B;
}MM32_RCC_CSR;
typedef union _MM32_RCC_SYSCFG
{
	uint32_t	U;
	int32_t	I;
	MM32_RCC_SYSCFGBits	B;
}MM32_RCC_SYSCFG;
typedef union _MM32_RCC_CFGR2
{
	uint32_t	U;
	int32_t	I;
	MM32_RCC_CFGR2Bits	B;
}MM32_RCC_CFGR2;
typedef union _MM32_RCC_ICSCR
{
	uint32_t	U;
	int32_t	I;
	MM32_RCC_ICSCRBits	B;
}MM32_RCC_ICSCR;
typedef union _MM32_RCC_PLLCFGR
{
	uint32_t	U;
	int32_t	I;
	MM32_RCC_PLLCFGRBits	B;
}MM32_RCC_PLLCFGR;
typedef struct _MM32_RCC
{
	MM32_RCC_CR		CR;
	MM32_RCC_CFGR		CFGR;
	MM32_RCC_CIR		CIR;
	MM32_RCC_AHB3RSTR		AHB3RSTR;
	MM32_RCC_AHB2RSTR		AHB2RSTR;
	MM32_RCC_AHB1RSTR		AHB1RSTR;
	MM32_RCC_APB2RSTR		APB2RSTR;
	MM32_RCC_APB1RSTR		APB1RSTR;
	MM32_RCC_AHB3ENR		AHB3ENR;
	MM32_RCC_AHB2ENR		AHB2ENR;
	MM32_RCC_AHB1ENR		AHB1ENR;
	MM32_RCC_APB2ENR		APB2ENR;
	MM32_RCC_APB1ENR		APB1ENR;
	MM32_RCC_BDCR		BDCR;
	MM32_RCC_CSR		CSR;
	MM32_RCC_SYSCFG		SYSCFG;
	MM32_RCC_CFGR2		CFGR2;
	MM32_RCC_ICSCR		ICSCR;
	MM32_RCC_PLLCFGR		PLLCFGR;
}MM32_RCC;
#endif