#ifndef _MM32_DACREGDEF_H_
#define _MM32_DACREGDEF_H_

#include "MM32_RegTypedef.h"

typedef struct _MM32_DAC_CRBits
{
	Strict_32Bit	EN1		:	1;
	Strict_32Bit	BOFF1		:	1;
	Strict_32Bit	TEN1		:	1;
	Strict_32Bit	TSEL1		:	3;
	Strict_32Bit	WAVE1		:	2;
	Strict_32Bit	MAMP1		:	4;
	Strict_32Bit	DMA_EN1		:	1;
	Strict_32Bit	_reserved_0		:	3;
	Strict_32Bit	EN2		:	1;
	Strict_32Bit	BOFF2		:	1;
	Strict_32Bit	TEN2		:	1;
	Strict_32Bit	TSEL2		:	3;
	Strict_32Bit	WAVE2		:	2;
	Strict_32Bit	MAMP2		:	4;
	Strict_32Bit	DMA_EN2		:	1;
	Strict_32Bit	_reserved_1		:	3;
}MM32_DAC_CRBits;
typedef struct _MM32_DAC_SWTRIGRBits
{
	Strict_32Bit	SW_TRIG1		:	1;
	Strict_32Bit	SW_TRIG2		:	1;
	Strict_32Bit	_reserved_0		:	6;
	Strict_32Bit	DAC_PRE		:	7;
	Strict_32Bit	_reserved_1		:	17;
}MM32_DAC_SWTRIGRBits;
typedef struct _MM32_DAC_DHR12R1Bits
{
	Strict_32Bit	DACC1DHR		:	12;
	Strict_32Bit	_reserved_0		:	20;
}MM32_DAC_DHR12R1Bits;
typedef struct _MM32_DAC_DHR12L1Bits
{
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	DACC1DHR		:	12;
	Strict_32Bit	_reserved_1		:	16;
}MM32_DAC_DHR12L1Bits;
typedef struct _MM32_DAC_DHR8R1Bits
{
	Strict_32Bit	DACC1DHR		:	8;
	Strict_32Bit	_reserved_0		:	24;
}MM32_DAC_DHR8R1Bits;
typedef struct _MM32_DAC_DHR12R2Bits
{
	Strict_32Bit	DACC2DHR		:	12;
	Strict_32Bit	_reserved_0		:	20;
}MM32_DAC_DHR12R2Bits;
typedef struct _MM32_DAC_DHR12L2Bits
{
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	DACC2DHR		:	12;
	Strict_32Bit	_reserved_1		:	16;
}MM32_DAC_DHR12L2Bits;
typedef struct _MM32_DAC_DHR8R2Bits
{
	Strict_32Bit	DACC2DHR		:	8;
	Strict_32Bit	_reserved_0		:	24;
}MM32_DAC_DHR8R2Bits;
typedef struct _MM32_DAC_DHR12RDBits
{
	Strict_32Bit	DACC1DHR		:	12;
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	DACC2DHR		:	12;
	Strict_32Bit	_reserved_1		:	4;
}MM32_DAC_DHR12RDBits;
typedef struct _MM32_DAC_DHR12LDBits
{
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	DACC1DHR		:	12;
	Strict_32Bit	_reserved_1		:	4;
	Strict_32Bit	DACC2DHR		:	12;
}MM32_DAC_DHR12LDBits;
typedef struct _MM32_DAC_DHR8RDBits
{
	Strict_32Bit	DACC1DHR		:	8;
	Strict_32Bit	DACC2DHR		:	8;
	Strict_32Bit	_reserved_0		:	16;
}MM32_DAC_DHR8RDBits;
typedef struct _MM32_DAC_DOR1Bits
{
	Strict_32Bit	DACC1DOR		:	12;
	Strict_32Bit	_reserved_0		:	20;
}MM32_DAC_DOR1Bits;
typedef struct _MM32_DAC_DOR2Bits
{
	Strict_32Bit	DACC2DOR		:	12;
	Strict_32Bit	_reserved_0		:	20;
}MM32_DAC_DOR2Bits;
typedef union _MM32_DAC_CR
{
	uint32_t	U;
	int32_t	I;
	MM32_DAC_CRBits	B;
}MM32_DAC_CR;
typedef union _MM32_DAC_SWTRIGR
{
	uint32_t	U;
	int32_t	I;
	MM32_DAC_SWTRIGRBits	B;
}MM32_DAC_SWTRIGR;
typedef union _MM32_DAC_DHR12R1 
{
	uint32_t	U;
	int32_t	I;
	MM32_DAC_DHR12R1Bits	B;
}MM32_DAC_DHR12R1 ;
typedef union _MM32_DAC_DHR12L1
{
	uint32_t	U;
	int32_t	I;
	MM32_DAC_DHR12L1Bits	B;
}MM32_DAC_DHR12L1;
typedef union _MM32_DAC_DHR8R1
{
	uint32_t	U;
	int32_t	I;
	MM32_DAC_DHR8R1Bits	B;
}MM32_DAC_DHR8R1;
typedef union _MM32_DAC_DHR12R2
{
	uint32_t	U;
	int32_t	I;
	MM32_DAC_DHR12R2Bits	B;
}MM32_DAC_DHR12R2;
typedef union _MM32_DAC_DHR12L2
{
	uint32_t	U;
	int32_t	I;
	MM32_DAC_DHR12L2Bits	B;
}MM32_DAC_DHR12L2;
typedef union _MM32_DAC_DHR8R2
{
	uint32_t	U;
	int32_t	I;
	MM32_DAC_DHR8R2Bits	B;
}MM32_DAC_DHR8R2;
typedef union _MM32_DAC_DHR12RD
{
	uint32_t	U;
	int32_t	I;
	MM32_DAC_DHR12RDBits	B;
}MM32_DAC_DHR12RD;
typedef union _MM32_DAC_DHR12LD
{
	uint32_t	U;
	int32_t	I;
	MM32_DAC_DHR12LDBits	B;
}MM32_DAC_DHR12LD;
typedef union _MM32_DAC_DHR8RD
{
	uint32_t	U;
	int32_t	I;
	MM32_DAC_DHR8RDBits	B;
}MM32_DAC_DHR8RD;
typedef union _MM32_DAC_DOR1
{
	uint32_t	U;
	int32_t	I;
	MM32_DAC_DOR1Bits	B;
}MM32_DAC_DOR1;
typedef union _MM32_DAC_DOR2
{
	uint32_t	U;
	int32_t	I;
	MM32_DAC_DOR2Bits	B;
}MM32_DAC_DOR2;
typedef struct _MM32_DAC
{
	MM32_DAC_CR		CR;
	MM32_DAC_SWTRIGR		SWTRIGR;
	MM32_DAC_DHR12R1 		DHR12R1 ;
	MM32_DAC_DHR12L1		DHR12L1;
	MM32_DAC_DHR8R1		DHR8R1;
	MM32_DAC_DHR12R2		DHR12R2;
	MM32_DAC_DHR12L2		DHR12L2;
	MM32_DAC_DHR8R2		DHR8R2;
	MM32_DAC_DHR12RD		DHR12RD;
	MM32_DAC_DHR12LD		DHR12LD;
	MM32_DAC_DHR8RD		DHR8RD;
	MM32_DAC_DOR1		DOR1;
	MM32_DAC_DOR2		DOR2;
}MM32_DAC;
#endif