/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:43:27
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:07:19
 * @FilePath: \CODE\MM32\Sfr\MM32_GPIORegDef.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_GPIOREGDEF_H_
#define _MM32_GPIOREGDEF_H_

#include "MM32_RegTypedef.h"

typedef struct _MM32_GPIO_CRLBits
{
	Strict_32Bit	MODE0		:	2;
	Strict_32Bit	CNF0		:	2;
	Strict_32Bit	MODE1		:	2;
	Strict_32Bit	CNF1		:	2;
	Strict_32Bit	MODE2		:	2;
	Strict_32Bit	CNF2		:	2;
	Strict_32Bit	MODE3		:	2;
	Strict_32Bit	CNF3		:	2;
	Strict_32Bit	MODE4		:	2;
	Strict_32Bit	CNF4		:	2;
	Strict_32Bit	MODE5		:	2;
	Strict_32Bit	CNF5		:	2;
	Strict_32Bit	MODE6		:	2;
	Strict_32Bit	CNF6		:	2;
	Strict_32Bit	MODE7		:	2;
	Strict_32Bit	CNF7		:	2;
}MM32_GPIO_CRLBits;
typedef struct _MM32_GPIO_CRHBits
{
	Strict_32Bit	MODE8		:	2;
	Strict_32Bit	CNF8		:	2;
	Strict_32Bit	MODE9		:	2;
	Strict_32Bit	CNF9		:	2;
	Strict_32Bit	MODE10		:	2;
	Strict_32Bit	CNF10		:	2;
	Strict_32Bit	MODE11		:	2;
	Strict_32Bit	CNF11		:	2;
	Strict_32Bit	MODE12		:	2;
	Strict_32Bit	CNF12		:	2;
	Strict_32Bit	MODE13		:	2;
	Strict_32Bit	CNF13		:	2;
	Strict_32Bit	MODE14		:	2;
	Strict_32Bit	CNF14		:	2;
	Strict_32Bit	MODE15		:	2;
	Strict_32Bit	CNF15		:	2;
}MM32_GPIO_CRHBits;
typedef struct _MM32_GPIO_IDRBits
{
	Strict_32Bit	IDRY		:	16;
	Strict_32Bit	_reserved_0		:	16;
}MM32_GPIO_IDRBits;
typedef struct _MM32_GPIO_ODRBits
{
	Strict_32Bit	ODRY		:	16;
	Strict_32Bit	_reserved_0		:	16;
}MM32_GPIO_ODRBits;
typedef struct _MM32_GPIO_BSRRBits
{
	Strict_32Bit	BSY		:	16;
	Strict_32Bit	BRY		:	16;
}MM32_GPIO_BSRRBits;
typedef struct _MM32_GPIO_BRRBits
{
	Strict_32Bit	BRY		:	16;
	Strict_32Bit	_reserved_0		:	16;
}MM32_GPIO_BRRBits;
typedef struct _MM32_GPIO_LCKRBits
{
	Strict_32Bit	LCKY		:	16;
	Strict_32Bit	LCKK		:	1;
	Strict_32Bit	_reserved_0		:	15;
}MM32_GPIO_LCKRBits;
typedef struct _MM32_GPIO_DCRBits
{
	Strict_32Bit	PX0		:	2;
	Strict_32Bit	PX1		:	2;
	Strict_32Bit	PX2		:	2;
	Strict_32Bit	PX3		:	2;
	Strict_32Bit	PX4		:	2;
	Strict_32Bit	PX5		:	2;
	Strict_32Bit	PX6		:	2;
	Strict_32Bit	PX7		:	2;
	Strict_32Bit	PX8		:	2;
	Strict_32Bit	PX9		:	2;
	Strict_32Bit	PX10		:	2;
	Strict_32Bit	PX11		:	2;
	Strict_32Bit	PX12		:	2;
	Strict_32Bit	PX13		:	2;
	Strict_32Bit	PX14		:	2;
	Strict_32Bit	PX15		:	2;
}MM32_GPIO_DCRBits;
typedef struct _MM32_GPIO_AFRLBits
{
	Strict_32Bit	AFR0		:	4;
	Strict_32Bit	AFR1		:	4;
	Strict_32Bit	AFR2		:	4;
	Strict_32Bit	AFR3		:	4;
	Strict_32Bit	AFR4		:	4;
	Strict_32Bit	AFR5		:	4;
	Strict_32Bit	AFR6		:	4;
	Strict_32Bit	AFR7		:	4;
}MM32_GPIO_AFRLBits;
typedef struct _MM32_GPIO_AFRHBits
{
	Strict_32Bit	AFR8		:	4;
	Strict_32Bit	AFR9		:	4;
	Strict_32Bit	AFR10		:	4;
	Strict_32Bit	AFR11		:	4;
	Strict_32Bit	AFR12		:	4;
	Strict_32Bit	AFR13		:	4;
	Strict_32Bit	AFR14		:	4;
	Strict_32Bit	AFR15		:	4;
}MM32_GPIO_AFRHBits;
typedef union _MM32_GPIO_CRL
{
	uint32_t	U;
	int32_t	I;
	MM32_GPIO_CRLBits	B;
}MM32_GPIO_CRL;
typedef union _MM32_GPIO_CRH
{
	uint32_t	U;
	int32_t	I;
	MM32_GPIO_CRHBits	B;
}MM32_GPIO_CRH;
typedef union _MM32_GPIO_IDR
{
	uint32_t	U;
	int32_t	I;
	MM32_GPIO_IDRBits	B;
}MM32_GPIO_IDR;
typedef union _MM32_GPIO_ODR
{
	uint32_t	U;
	int32_t	I;
	MM32_GPIO_ODRBits	B;
}MM32_GPIO_ODR;
typedef union _MM32_GPIO_BSRR
{
	uint32_t	U;
	int32_t	I;
	MM32_GPIO_BSRRBits	B;
}MM32_GPIO_BSRR;
typedef union _MM32_GPIO_BRR
{
	uint32_t	U;
	int32_t	I;
	MM32_GPIO_BRRBits	B;
}MM32_GPIO_BRR;
typedef union _MM32_GPIO_LCKR
{
	uint32_t	U;
	int32_t	I;
	MM32_GPIO_LCKRBits	B;
}MM32_GPIO_LCKR;
typedef union _MM32_GPIO_DCR
{
	uint32_t	U;
	int32_t	I;
	MM32_GPIO_DCRBits	B;
}MM32_GPIO_DCR;
typedef union _MM32_GPIO_AFRL
{
	uint32_t	U;
	int32_t	I;
	MM32_GPIO_AFRLBits	B;
}MM32_GPIO_AFRL;
typedef union _MM32_GPIO_AFRH
{
	uint32_t	U;
	int32_t	I;
	MM32_GPIO_AFRHBits	B;
}MM32_GPIO_AFRH;
typedef struct _MM32_GPIO
{
	MM32_GPIO_CRL		CRL;
	MM32_GPIO_CRH		CRH;
	MM32_GPIO_IDR		IDR;
	MM32_GPIO_ODR		ODR;
	MM32_GPIO_BSRR		BSRR;
	MM32_GPIO_BRR		BRR;
	MM32_GPIO_LCKR		LCKR;
	MM32_GPIO_DCR		DCR;
	MM32_GPIO_AFRL		AFRL;
	MM32_GPIO_AFRH		AFRH;
}MM32_GPIO;
#endif