/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:43:27
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:07:28
 * @FilePath: \CODE\MM32\Sfr\MM32_PWRRegDef.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_PWRREGDEF_H_
#define _MM32_PWRREGDEF_H_

#include "MM32_RegTypedef.h"

typedef struct _MM32_PWR_CR1Bits
{
	Strict_32Bit	LPDS		:	1;
	Strict_32Bit	PDDS		:	1;
	Strict_32Bit	_reserved_0		:	1;
	Strict_32Bit	CSBF		:	1;
	Strict_32Bit	_reserved_1		:	9;
	Strict_32Bit	LPR		:	1;
	Strict_32Bit	VOS		:	2;
	Strict_32Bit	_reserved_2		:	16;
}MM32_PWR_CR1Bits;
typedef struct _MM32_PWR_CSRBits
{
	Strict_32Bit	_reserved_0		:	1;
	Strict_32Bit	SBF		:	1;
	Strict_32Bit	_reserved_1		:	12;
	Strict_32Bit	VOSRDY		:	1;
	Strict_32Bit	_reaerved_2		:	17;
}MM32_PWR_CSRBits;
typedef struct _MM32_PWR_CR2Bits
{
	Strict_32Bit	EWUP0		:	1;
	Strict_32Bit	EWUP1		:	1;
	Strict_32Bit	EWUP2		:	1;
	Strict_32Bit	EWUP3		:	1;
	Strict_32Bit	EWUP4		:	1;
	Strict_32Bit	EWUP5		:	1;
	Strict_32Bit	_reaerved_0		:	26;
}MM32_PWR_CR2Bits;
typedef struct _MM32_PWR_CR3Bits
{
	Strict_32Bit	WP0		:	1;
	Strict_32Bit	WP1		:	1;
	Strict_32Bit	WP2		:	1;
	Strict_32Bit	WP3		:	1;
	Strict_32Bit	WP4		:	1;
	Strict_32Bit	WP5		:	1;
	Strict_32Bit	_reserved_0		:	26;
}MM32_PWR_CR3Bits;
typedef struct _MM32_PWR_CR4Bits
{
	Strict_32Bit	FILTSEL0		:	2;
	Strict_32Bit	FILTE0		:	2;
	Strict_32Bit	FILTF0		:	1;
	Strict_32Bit	_reserved_0		:	3;
	Strict_32Bit	FILTCNT0		:	8;
	Strict_32Bit	_reserved_1		:	16;
}MM32_PWR_CR4Bits;
typedef struct _MM32_PWR_CR5Bits
{
	Strict_32Bit	FILTSEL1		:	2;
	Strict_32Bit	FILTE1		:	2;
	Strict_32Bit	FILTF1		:	1;
	Strict_32Bit	_reserved_0		:	3;
	Strict_32Bit	FILTCNT1		:	8;
	Strict_32Bit	_reserved_1		:	16;
}MM32_PWR_CR5Bits;
typedef struct _MM32_PWR_CR6Bits
{
	Strict_32Bit	STDBY_FS_WK		:	3;
	Strict_32Bit	_reserved_0		:	29;
}MM32_PWR_CR6Bits;
typedef struct _MM32_PWR_SRBits
{
	Strict_32Bit	WUF0		:	1;
	Strict_32Bit	WUF1		:	1;
	Strict_32Bit	WUF2		:	1;
	Strict_32Bit	WUF3		:	1;
	Strict_32Bit	WUF4		:	1;
	Strict_32Bit	WUF5		:	1;
	Strict_32Bit	_reserved_0		:	26;
}MM32_PWR_SRBits;
typedef struct _MM32_PWR_SCRBits
{
	Strict_32Bit	CWUF0		:	1;
	Strict_32Bit	CWUF1		:	1;
	Strict_32Bit	CWUF2		:	1;
	Strict_32Bit	CWUF3		:	1;
	Strict_32Bit	CWUF4		:	1;
	Strict_32Bit	CWUF5		:	1;
	Strict_32Bit	_reserved_0		:	26;
}MM32_PWR_SCRBits;
typedef struct _MM32_PWR_CFGRBits
{
	Strict_32Bit	LSICALSEL		:	5;
	Strict_32Bit	LSICAL		:	5;
	Strict_32Bit	_reserved_0		:	22;
}MM32_PWR_CFGRBits;
typedef union _MM32_PWR_CR1
{
	uint32_t	U;
	int32_t	I;
	MM32_PWR_CR1Bits	B;
}MM32_PWR_CR1;
typedef union _MM32_PWR_CSR
{
	uint32_t	U;
	int32_t	I;
	MM32_PWR_CSRBits	B;
}MM32_PWR_CSR;
typedef union _MM32_PWR_CR2
{
	uint32_t	U;
	int32_t	I;
	MM32_PWR_CR2Bits	B;
}MM32_PWR_CR2;
typedef union _MM32_PWR_CR3
{
	uint32_t	U;
	int32_t	I;
	MM32_PWR_CR3Bits	B;
}MM32_PWR_CR3;
typedef union _MM32_PWR_CR4
{
	uint32_t	U;
	int32_t	I;
	MM32_PWR_CR4Bits	B;
}MM32_PWR_CR4;
typedef union _MM32_PWR_CR5
{
	uint32_t	U;
	int32_t	I;
	MM32_PWR_CR5Bits	B;
}MM32_PWR_CR5;
typedef union _MM32_PWR_CR6
{
	uint32_t	U;
	int32_t	I;
	MM32_PWR_CR6Bits	B;
}MM32_PWR_CR6;
typedef union _MM32_PWR_SR
{
	uint32_t	U;
	int32_t	I;
	MM32_PWR_SRBits	B;
}MM32_PWR_SR;
typedef union _MM32_PWR_SCR
{
	uint32_t	U;
	int32_t	I;
	MM32_PWR_SCRBits	B;
}MM32_PWR_SCR;
typedef union _MM32_PWR_CFGR
{
	uint32_t	U;
	int32_t	I;
	MM32_PWR_CFGRBits	B;
}MM32_PWR_CFGR;
typedef struct _MM32_PWR
{
	MM32_PWR_CR1		CR1;
	MM32_PWR_CSR		CSR;
	MM32_PWR_CR2		CR2;
	MM32_PWR_CR3		CR3;
	MM32_PWR_CR4		CR4;
	MM32_PWR_CR5		CR5;
	MM32_PWR_CR6		CR6;
	MM32_PWR_SR		SR;
	MM32_PWR_SCR		SCR;
	MM32_PWR_CFGR		CFGR;
}MM32_PWR;
#endif