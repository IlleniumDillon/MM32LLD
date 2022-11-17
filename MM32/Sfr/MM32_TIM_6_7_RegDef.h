/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-02 20:59:49
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-02 21:21:21
 * @FilePath: \CODE\MM32\Sfr\MM32_TIM_6_7_RegDef.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_TIM_6_7REGDEF_H_
#define _MM32_TIM_6_7REGDEF_H_

#include "MM32_RegTypedef.h"

typedef struct _MM32_TIM_6_7_CR1Bits
{
	Strict_16Bit	CEN		:	1;
	Strict_16Bit	UDIS		:	1;
	Strict_16Bit	URS		:	1;
	Strict_16Bit	OPM		:	1;
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	_reserved_1		:	2;
	Strict_16Bit	APRE		:	1;
	Strict_16Bit	_reserved_2		:	2;
	Strict_16Bit	_reserved_3		:	6;
}MM32_TIM_6_7_CR1Bits;
typedef struct _MM32_TIM_6_7_CR2Bits
{
	Strict_16Bit	CCPC		:	1;
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	CCUS		:	1;
	Strict_16Bit	CCDS		:	1;
	Strict_16Bit	MMS		:	3;
	Strict_16Bit	TI1S		:	1;
	Strict_16Bit	OIS1		:	1;
	Strict_16Bit	OIS1N		:	1;
	Strict_16Bit	OIS2		:	1;
	Strict_16Bit	OIS2N		:	1;
	Strict_16Bit	OIS3		:	1;
	Strict_16Bit	OIS3N		:	1;
	Strict_16Bit	OIS4		:	1;
	Strict_16Bit	_reserved_1		:	1;
}MM32_TIM_6_7_CR2Bits;
typedef struct _MM32_TIM_6_7_SMCRBits
{
	Strict_16Bit	SMS		:	3;
	Strict_16Bit	OCCS		:	1;
	Strict_16Bit	TS		:	3;
	Strict_16Bit	MSM		:	1;
	Strict_16Bit	ETF		:	4;
	Strict_16Bit	ETPS		:	2;
	Strict_16Bit	ECE		:	1;
	Strict_16Bit	ETP		:	1;
}MM32_TIM_6_7_SMCRBits;
typedef struct _MM32_TIM_6_7_DIERBits
{
	Strict_16Bit	UIE		:	1;
    Strict_32Bit	_reserved_0		:	7;
	Strict_16Bit	UDE		:	1;
	Strict_32Bit	_reserved_1		:	7;
}MM32_TIM_6_7_DIERBits;
typedef struct _MM32_TIM_6_7_SRBits
{
	Strict_16Bit	UIF		:	1;
	Strict_16Bit	_reserved_0		:	15;
}MM32_TIM_6_7_SRBits;
typedef struct _MM32_TIM_6_7_EGRBits
{
	Strict_16Bit	UG		:	1;
	Strict_16Bit	_reserved_0		:	15;
}MM32_TIM_6_7_EGRBits;
typedef struct _MM32_TIM_6_7_CCMR1Bits
{
	Strict_16Bit	CC1S		:	2;
	Strict_16Bit	OC1FE		:	1;
	Strict_16Bit	OC1PE		:	1;
	Strict_16Bit	OC1M		:	3;
	Strict_16Bit	OC1CE		:	1;
	Strict_16Bit	CC2S		:	2;
	Strict_16Bit	OC2FE		:	1;
	Strict_16Bit	OC2PE		:	1;
	Strict_16Bit	OC2M		:	3;
	Strict_16Bit	OC2CE		:	1;
}MM32_TIM_6_7_CCMR1Bits;
typedef struct _MM32_TIM_6_7_CCMR2Bits
{
	Strict_16Bit	CC3S		:	2;
	Strict_16Bit	OC3FE		:	1;
	Strict_16Bit	OC3PE		:	1;
	Strict_16Bit	OC3M		:	3;
	Strict_16Bit	OC3CE		:	1;
	Strict_16Bit	CC4S		:	2;
	Strict_16Bit	OC4FE		:	1;
	Strict_16Bit	OC4PE		:	1;
	Strict_16Bit	OC4M		:	3;
	Strict_16Bit	OC4CE		:	1;
}MM32_TIM_6_7_CCMR2Bits;
typedef struct _MM32_TIM_6_7_CCERBits
{
	Strict_16Bit	CC1E		:	1;
	Strict_16Bit	CC1P		:	1;
	Strict_16Bit	CC1NE		:	1;
	Strict_16Bit	CC1NP		:	1;
	Strict_16Bit	CC2E		:	1;
	Strict_16Bit	CC2P		:	1;
	Strict_16Bit	CC2NE		:	1;
	Strict_16Bit	CC2NP		:	1;
	Strict_16Bit	CC3E		:	1;
	Strict_16Bit	CC3P		:	1;
	Strict_16Bit	CC3NE		:	1;
	Strict_16Bit	CC3NP		:	1;
	Strict_16Bit	CC4E		:	1;
	Strict_16Bit	CC4P		:	1;
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	CC4NP		:	1;
}MM32_TIM_6_7_CCERBits;
typedef struct _MM32_TIM_6_7_CNTBits
{
	Strict_16Bit	CNT		:	16;
}MM32_TIM_6_7_CNTBits;
typedef struct _MM32_TIM_6_7_PSCBits
{
	Strict_16Bit	PSC		:	16;
}MM32_TIM_6_7_PSCBits;
typedef struct _MM32_TIM_6_7_ARRBits
{
	Strict_16Bit	ARR		:	16;
}MM32_TIM_6_7_ARRBits;
typedef struct _MM32_TIM_6_7_RCRBits
{
	Strict_16Bit	REP		:	8;
	Strict_16Bit	REP_CNT		:	8;
}MM32_TIM_6_7_RCRBits;
typedef struct _MM32_TIM_6_7_CCR1Bits
{
	Strict_32Bit	CCR1		:	32;
}MM32_TIM_6_7_CCR1Bits;
typedef struct _MM32_TIM_6_7_CCR2Bits
{
	Strict_32Bit	CCR2		:	32;
}MM32_TIM_6_7_CCR2Bits;
typedef struct _MM32_TIM_6_7_CCR3Bits
{
	Strict_32Bit	CCR3		:	32;
}MM32_TIM_6_7_CCR3Bits;
typedef struct _MM32_TIM_6_7_CCR4Bits
{
	Strict_32Bit	CCR4		:	32;
}MM32_TIM_6_7_CCR4Bits;
typedef struct _MM32_TIM_6_7_BDTRBits
{
	Strict_32Bit	DTG		:	8;
	Strict_32Bit	LOCK		:	2;
	Strict_32Bit	OSSI		:	1;
	Strict_32Bit	OSSR		:	1;
	Strict_32Bit	BKE		:	1;
	Strict_32Bit	BKP		:	1;
	Strict_32Bit	AOE		:	1;
	Strict_32Bit	MOE		:	1;
	Strict_32Bit	DOE		:	1;
	Strict_32Bit	_reserved_0		:	15;
}MM32_TIM_6_7_BDTRBits;
typedef struct _MM32_TIM_6_7_DCRBits
{
	Strict_16Bit	DBA		:	5;
	Strict_16Bit	_reserved_0		:	3;
	Strict_16Bit	DBL		:	5;
	Strict_16Bit	_reserved_1		:	3;
}MM32_TIM_6_7_DCRBits;
typedef struct _MM32_TIM_6_7_DMARBits
{
	Strict_16Bit	DMAB		:	16;
}MM32_TIM_6_7_DMARBits;
typedef struct _MM32_TIM_6_7_ORBits
{
	Strict_16Bit	ETR_RMP		:	2;
	Strict_16Bit	_reserved_0		:	4;
	Strict_16Bit	TI4_RMP		:	2;
	Strict_16Bit	_reserved_1		:	8;
}MM32_TIM_6_7_ORBits;
typedef struct _MM32_TIM_6_7_CCMR3Bits
{
	Strict_16Bit	_reserved_0		:	3;
	Strict_16Bit	OC5PE		:	1;
	Strict_16Bit	_reserved_1		:	12;
}MM32_TIM_6_7_CCMR3Bits;
typedef struct _MM32_TIM_6_7_CCR5Bits
{
	Strict_16Bit	CCR5		:	16;
}MM32_TIM_6_7_CCR5Bits;
typedef struct _MM32_TIM_6_7_PDERBits
{
	Strict_16Bit	CCDREPE		:	1;
	Strict_16Bit	CCR1_SHIFT_EN		:	1;
	Strict_16Bit	CCR2_SHIFT_EN		:	1;
	Strict_16Bit	CCR3_SHIFT_EN		:	1;
	Strict_16Bit	CCR4_SHIFT_EN		:	1;
	Strict_16Bit	CCR5_SHIFT_EN		:	1;
	Strict_16Bit	_reserved_0		:	10;
}MM32_TIM_6_7_PDERBits;
typedef struct _MM32_TIM_6_7_CCR1FALLBits
{
	Strict_16Bit	CCRFALL		:	16;
}MM32_TIM_6_7_CCR1FALLBits;
typedef struct _MM32_TIM_6_7_CCR2FALLBits
{
	Strict_16Bit	CCRFALL		:	16;
}MM32_TIM_6_7_CCR2FALLBits;
typedef struct _MM32_TIM_6_7_CCR3FALLBits
{
	Strict_16Bit	CCRFALL		:	16;
}MM32_TIM_6_7_CCR3FALLBits;
typedef struct _MM32_TIM_6_7_CCR4FALLBits
{
	Strict_16Bit	CCRFALL		:	16;
}MM32_TIM_6_7_CCR4FALLBits;
typedef struct _MM32_TIM_6_7_CCR5FALLBits
{
	Strict_16Bit	CCRFALL		:	16;
}MM32_TIM_6_7_CCR5FALLBits;
typedef union _MM32_TIM_6_7_CR1
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_CR1Bits	B;
}MM32_TIM_6_7_CR1;
typedef union _MM32_TIM_6_7_CR2
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_CR2Bits	B;
}MM32_TIM_6_7_CR2;
typedef union _MM32_TIM_6_7_SMCR
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_SMCRBits	B;
}MM32_TIM_6_7_SMCR;
typedef union _MM32_TIM_6_7_DIER
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_DIERBits	B;
}MM32_TIM_6_7_DIER;
typedef union _MM32_TIM_6_7_SR
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_SRBits	B;
}MM32_TIM_6_7_SR;
typedef union _MM32_TIM_6_7_EGR
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_EGRBits	B;
}MM32_TIM_6_7_EGR;
typedef union _MM32_TIM_6_7_CCMR1
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_CCMR1Bits	B;
}MM32_TIM_6_7_CCMR1;
typedef union _MM32_TIM_6_7_CCMR2
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_CCMR2Bits	B;
}MM32_TIM_6_7_CCMR2;
typedef union _MM32_TIM_6_7_CCER
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_CCERBits	B;
}MM32_TIM_6_7_CCER;
typedef union _MM32_TIM_6_7_CNT
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_CNTBits	B;
}MM32_TIM_6_7_CNT;
typedef union _MM32_TIM_6_7_PSC
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_PSCBits	B;
}MM32_TIM_6_7_PSC;
typedef union _MM32_TIM_6_7_ARR
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_ARRBits	B;
}MM32_TIM_6_7_ARR;
typedef union _MM32_TIM_6_7_RCR
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_RCRBits	B;
}MM32_TIM_6_7_RCR;
typedef union _MM32_TIM_6_7_CCR1
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_CCR1Bits	B;
}MM32_TIM_6_7_CCR1;
typedef union _MM32_TIM_6_7_CCR2
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_CCR2Bits	B;
}MM32_TIM_6_7_CCR2;
typedef union _MM32_TIM_6_7_CCR3
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_CCR3Bits	B;
}MM32_TIM_6_7_CCR3;
typedef union _MM32_TIM_6_7_CCR4
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_CCR4Bits	B;
}MM32_TIM_6_7_CCR4;
typedef union _MM32_TIM_6_7_BDTR
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_BDTRBits	B;
}MM32_TIM_6_7_BDTR;
typedef union _MM32_TIM_6_7_DCR
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_DCRBits	B;
}MM32_TIM_6_7_DCR;
typedef union _MM32_TIM_6_7_DMAR
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_DMARBits	B;
}MM32_TIM_6_7_DMAR;
typedef union _MM32_TIM_6_7_OR
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_ORBits	B;
}MM32_TIM_6_7_OR;
typedef union _MM32_TIM_6_7_CCMR3
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_CCMR3Bits	B;
}MM32_TIM_6_7_CCMR3;
typedef union _MM32_TIM_6_7_CCR5
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_CCR5Bits	B;
}MM32_TIM_6_7_CCR5;
typedef union _MM32_TIM_6_7_PDER
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_PDERBits	B;
}MM32_TIM_6_7_PDER;
typedef union _MM32_TIM_6_7_CCR1FALL
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_CCR1FALLBits	B;
}MM32_TIM_6_7_CCR1FALL;
typedef union _MM32_TIM_6_7_CCR2FALL
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_CCR2FALLBits	B;
}MM32_TIM_6_7_CCR2FALL;
typedef union _MM32_TIM_6_7_CCR3FALL
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_CCR3FALLBits	B;
}MM32_TIM_6_7_CCR3FALL;
typedef union _MM32_TIM_6_7_CCR4FALL
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_CCR4FALLBits	B;
}MM32_TIM_6_7_CCR4FALL;
typedef union _MM32_TIM_6_7_CCR5FALL
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_6_7_CCR5FALLBits	B;
}MM32_TIM_6_7_CCR5FALL;
typedef struct _MM32_TIM_6_7
{
	MM32_TIM_6_7_CR1		CR1;
	unsigned char		_reserved_0;
	unsigned char		_reserved_1;
	MM32_TIM_6_7_CR2		_reserved_CR2;
	unsigned char		_reserved_2;
	unsigned char		_reserved_3;
	MM32_TIM_6_7_SMCR		_reserved_SMCR;
	unsigned char		_reserved_4;
	unsigned char		_reserved_5;
	MM32_TIM_6_7_DIER		DIER;
    unsigned char		_reserved_45;
	unsigned char		_reserved_44;
	MM32_TIM_6_7_SR		SR;
    unsigned char		_reserved_43;
	unsigned char		_reserved_42;
	MM32_TIM_6_7_EGR		EGR;
    unsigned char		_reserved_41;
	unsigned char		_reserved_40;
	MM32_TIM_6_7_CCMR1		_reserved_CCMR1;
	unsigned char		_reserved_6;
	unsigned char		_reserved_7;
	MM32_TIM_6_7_CCMR2		_reserved_CCMR2;
	unsigned char		_reserved_8;
	unsigned char		_reserved_9;
	MM32_TIM_6_7_CCER		_reserved_CCER;
	unsigned char		_reserved_10;
	unsigned char		_reserved_11;
	MM32_TIM_6_7_CNT		CNT;
    unsigned char		_reserved_39;
	unsigned char		_reserved_38;
	MM32_TIM_6_7_PSC		PSC;
	unsigned char		_reserved_12;
	unsigned char		_reserved_13;
	MM32_TIM_6_7_ARR		ARR;
    unsigned char		_reserved_36;
	unsigned char		_reserved_37;
	MM32_TIM_6_7_RCR		_reserved_RCR;
	unsigned char		_reserved_14;
	unsigned char		_reserved_15;
	MM32_TIM_6_7_CCR1		_reserved_CCR1;
	MM32_TIM_6_7_CCR2		_reserved_CCR2;
	MM32_TIM_6_7_CCR3		_reserved_CCR3;
	MM32_TIM_6_7_CCR4		_reserved_CCR4;
	MM32_TIM_6_7_BDTR		_reserved_BDTR;
	MM32_TIM_6_7_DCR		_reserved_DCR;
	unsigned char		_reserved_16;
	unsigned char		_reserved_17;
	MM32_TIM_6_7_DMAR		_reserved_DMAR;
	unsigned char		_reserved_18;
	unsigned char		_reserved_19;
	MM32_TIM_6_7_OR		_reserved_OR;
	unsigned char		_reserved_20;
	unsigned char		_reserved_21;
	MM32_TIM_6_7_CCMR3		_reserved_CCMR3;
	unsigned char		_reserved_22;
	unsigned char		_reserved_23;
	MM32_TIM_6_7_CCR5		_reserved_CCR5;
	unsigned char		_reserved_24;
	unsigned char		_reserved_25;
	MM32_TIM_6_7_PDER		_reserved_PDER;
	unsigned char		_reserved_26;
	unsigned char		_reserved_27;
	MM32_TIM_6_7_CCR1FALL		_reserved_CCR1FALL;
	unsigned char		_reserved_28;
	unsigned char		_reserved_29;
	MM32_TIM_6_7_CCR2FALL		_reserved_CCR2FALL;
	unsigned char		_reserved_30;
	unsigned char		_reserved_31;
	MM32_TIM_6_7_CCR3FALL		_reserved_CCR3FALL;
	unsigned char		_reserved_32;
	unsigned char		_reserved_33;
	MM32_TIM_6_7_CCR4FALL		_reserved_CCR4FALL;
	unsigned char		_reserved_34;
	unsigned char		_reserved_35;
	MM32_TIM_6_7_CCR5FALL		_reserved_CCR5FALL;
}MM32_TIM_6_7;
#endif