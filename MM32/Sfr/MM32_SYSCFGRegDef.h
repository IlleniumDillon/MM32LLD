/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:43:27
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:07:53
 * @FilePath: \CODE\MM32\Sfr\MM32_SYSCFGRegDef.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_SYSCFGREGDEF_H_
#define _MM32_SYSCFGREGDEF_H_

#include "MM32_RegTypedef.h"

typedef struct _MM32_SYSCFG_CFGR1Bits
{
	Strict_32Bit	MEM_MODE		:	2;
	Strict_32Bit	_reserved_0		:	14;
	Strict_32Bit	_reserved_1		:	12;
	Strict_32Bit	FC_ODATAEN		:	1;
	Strict_32Bit	FC_MODESEL		:	2;
	Strict_32Bit	_reserved_2		:	1;
}MM32_SYSCFG_CFGR1Bits;
typedef struct _MM32_SYSCFG_EXTICR1Bits
{
	Strict_32Bit	EXTI0		:	4;
	Strict_32Bit	EXTI1		:	4;
	Strict_32Bit	EXTI2		:	4;
	Strict_32Bit	EXTI3		:	4;
	Strict_32Bit	_reserved_0		:	16;
}MM32_SYSCFG_EXTICR1Bits;
typedef struct _MM32_SYSCFG_EXTICR2Bits
{
	Strict_32Bit	EXTI4		:	4;
	Strict_32Bit	EXTI5		:	4;
	Strict_32Bit	EXTI6		:	4;
	Strict_32Bit	EXTI7		:	4;
	Strict_32Bit	_reserved_0		:	16;
}MM32_SYSCFG_EXTICR2Bits;
typedef struct _MM32_SYSCFG_EXTICR3Bits
{
	Strict_32Bit	EXTI8		:	4;
	Strict_32Bit	EXTI9		:	4;
	Strict_32Bit	EXTI10		:	4;
	Strict_32Bit	EXTI11		:	4;
	Strict_32Bit	_reserved_0		:	16;
}MM32_SYSCFG_EXTICR3Bits;
typedef struct _MM32_SYSCFG_EXTICR4Bits
{
	Strict_32Bit	EXTI12		:	4;
	Strict_32Bit	EXTI13		:	4;
	Strict_32Bit	EXTI14		:	4;
	Strict_32Bit	EXTI15		:	4;
	Strict_32Bit	_reserved_0		:	16;
}MM32_SYSCFG_EXTICR4Bits;
typedef struct _MM32_SYSCFG_CFGR2Bits
{
	Strict_32Bit	_reserved_0		:	16;
	Strict_32Bit	I2C1_MODE_SEL		:	1;
	Strict_32Bit	I2C2_MODE_SEL		:	1;
	Strict_32Bit	_reserved_1		:	2;
	Strict_32Bit	ENET_MII_RMII_SEL		:	1;
	Strict_32Bit	ENET_SPD_SEL		:	1;
	Strict_32Bit	_reserved_2		:	10;
}MM32_SYSCFG_CFGR2Bits;
typedef struct _MM32_SYSCFG_PDETCSRBits
{
	Strict_32Bit	PVDE		:	1;
	Strict_32Bit	PLS		:	4;
	Strict_32Bit	PVDO		:	1;
	Strict_32Bit	_reserved_0		:	5;
	Strict_32Bit	VBAT_DIV3_EN		:	1;
	Strict_32Bit	_reserved_1		:	20;
}MM32_SYSCFG_PDETCSRBits;
typedef struct _MM32_SYSCFG_VOSDLYBits
{
	Strict_32Bit	VOSDLY_CNT		:	10;
	Strict_32Bit	_reserved_0		:	22;
}MM32_SYSCFG_VOSDLYBits;
typedef union _MM32_SYSCFG_CFGR1
{
	uint32_t	U;
	int32_t	I;
	MM32_SYSCFG_CFGR1Bits	B;
}MM32_SYSCFG_CFGR1;
typedef union _MM32_SYSCFG_EXTICR1
{
	uint32_t	U;
	int32_t	I;
	MM32_SYSCFG_EXTICR1Bits	B;
}MM32_SYSCFG_EXTICR1;
typedef union _MM32_SYSCFG_EXTICR2
{
	uint32_t	U;
	int32_t	I;
	MM32_SYSCFG_EXTICR2Bits	B;
}MM32_SYSCFG_EXTICR2;
typedef union _MM32_SYSCFG_EXTICR3
{
	uint32_t	U;
	int32_t	I;
	MM32_SYSCFG_EXTICR3Bits	B;
}MM32_SYSCFG_EXTICR3;
typedef union _MM32_SYSCFG_EXTICR4
{
	uint32_t	U;
	int32_t	I;
	MM32_SYSCFG_EXTICR4Bits	B;
}MM32_SYSCFG_EXTICR4;
typedef union _MM32_SYSCFG_CFGR2
{
	uint32_t	U;
	int32_t	I;
	MM32_SYSCFG_CFGR2Bits	B;
}MM32_SYSCFG_CFGR2;
typedef union _MM32_SYSCFG_PDETCSR
{
	uint32_t	U;
	int32_t	I;
	MM32_SYSCFG_PDETCSRBits	B;
}MM32_SYSCFG_PDETCSR;
typedef union _MM32_SYSCFG_VOSDLY
{
	uint32_t	U;
	int32_t	I;
	MM32_SYSCFG_VOSDLYBits	B;
}MM32_SYSCFG_VOSDLY;
typedef struct _MM32_SYSCFG
{
	MM32_SYSCFG_CFGR1		CFGR1;
	unsigned char		_reserved_0;
	unsigned char		_reserved_1;
	unsigned char		_reserved_2;
	unsigned char		_reserved_3;
	MM32_SYSCFG_EXTICR1		EXTICR1;
	MM32_SYSCFG_EXTICR2		EXTICR2;
	MM32_SYSCFG_EXTICR3		EXTICR3;
	MM32_SYSCFG_EXTICR4		EXTICR4;
	MM32_SYSCFG_CFGR2		CFGR2;
	MM32_SYSCFG_PDETCSR		PDETCSR;
	MM32_SYSCFG_VOSDLY		VOSDLY;
}MM32_SYSCFG;
#endif