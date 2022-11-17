/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-02 20:59:49
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-02 21:07:27
 * @FilePath: \CODE\MM32\Sfr\MM32_TIM_2_5_RegDef.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_TIM_2_5REGDEF_H_
#define _MM32_TIM_2_5REGDEF_H_

#include "MM32_RegTypedef.h"

typedef struct _MM32_TIM_2_5_CR1Bits
{
	Strict_16Bit	CEN		:	1;
	Strict_16Bit	UDIS		:	1;
	Strict_16Bit	URS		:	1;
	Strict_16Bit	OPM		:	1;
	Strict_16Bit	DIR		:	1;
	Strict_16Bit	CMS		:	2;
	Strict_16Bit	APRE		:	1;
	Strict_16Bit	CKD		:	2;
	Strict_16Bit	_reserved_0		:	6;
}MM32_TIM_2_5_CR1Bits;
typedef struct _MM32_TIM_2_5_CR2Bits
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
}MM32_TIM_2_5_CR2Bits;
typedef struct _MM32_TIM_2_5_SMCRBits
{
	Strict_16Bit	SMS		:	3;
	Strict_16Bit	OCCS		:	1;
	Strict_16Bit	TS		:	3;
	Strict_16Bit	MSM		:	1;
	Strict_16Bit	ETF		:	4;
	Strict_16Bit	ETPS		:	2;
	Strict_16Bit	ECE		:	1;
	Strict_16Bit	ETP		:	1;
}MM32_TIM_2_5_SMCRBits;
typedef struct _MM32_TIM_2_5_DIERBits
{
	Strict_32Bit	UIE		:	1;
	Strict_32Bit	CC1IE		:	1;
	Strict_32Bit	CC2IE		:	1;
	Strict_32Bit	CC3IE		:	1;
	Strict_32Bit	CC4IE		:	1;
	Strict_32Bit	COMIE		:	1;
	Strict_32Bit	TIE		:	1;
	Strict_32Bit	BIE		:	1;
	Strict_32Bit	UDE		:	1;
	Strict_32Bit	CC1DE		:	1;
	Strict_32Bit	CC2DE		:	1;
	Strict_32Bit	CC3DE		:	1;
	Strict_32Bit	CC4DE		:	1;
	Strict_32Bit	COMDE		:	1;
	Strict_32Bit	TDE		:	1;
	Strict_32Bit	_reserved_0		:	1;
	Strict_32Bit	CC5IE		:	1;
	Strict_32Bit	CC5DE		:	1;
	Strict_32Bit	_reserved_1		:	14;
}MM32_TIM_2_5_DIERBits;
typedef struct _MM32_TIM_2_5_SRBits
{
	Strict_32Bit	UIF		:	1;
	Strict_32Bit	CC1IF		:	1;
	Strict_32Bit	CC2IF		:	1;
	Strict_32Bit	CC3IF		:	1;
	Strict_32Bit	CC4IF		:	1;
	Strict_32Bit	COMIF		:	1;
	Strict_32Bit	TIF		:	1;
	Strict_32Bit	BIF		:	1;
	Strict_32Bit	_reserved_0		:	1;
	Strict_32Bit	CC1OF		:	1;
	Strict_32Bit	CC2OF		:	1;
	Strict_32Bit	CC3OF		:	1;
	Strict_32Bit	CC4OF		:	1;
	Strict_32Bit	_reserved_1		:	3;
	Strict_32Bit	CC5IF		:	1;
	Strict_32Bit	_reserved_2		:	15;
}MM32_TIM_2_5_SRBits;
typedef struct _MM32_TIM_2_5_EGRBits
{
	Strict_32Bit	UG		:	1;
	Strict_32Bit	CC1G		:	1;
	Strict_32Bit	CC2G		:	1;
	Strict_32Bit	CC3G		:	1;
	Strict_32Bit	CC4G		:	1;
	Strict_32Bit	COMG		:	1;
	Strict_32Bit	TG		:	1;
	Strict_32Bit	BG		:	1;
	Strict_32Bit	_reserved_0		:	8;
	Strict_32Bit	CC5G		:	1;
	Strict_32Bit	_reserved_1		:	15;
}MM32_TIM_2_5_EGRBits;
typedef struct _MM32_TIM_2_5_CCMR1Bits
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
}MM32_TIM_2_5_CCMR1Bits;
typedef struct _MM32_TIM_2_5_CCMR2Bits
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
}MM32_TIM_2_5_CCMR2Bits;
typedef struct _MM32_TIM_2_5_CCERBits
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
}MM32_TIM_2_5_CCERBits;
typedef struct _MM32_TIM_2_5_CNTBits
{
	Strict_32Bit	CNT		:	32;
}MM32_TIM_2_5_CNTBits;
typedef struct _MM32_TIM_2_5_PSCBits
{
	Strict_16Bit	PSC		:	16;
}MM32_TIM_2_5_PSCBits;
typedef struct _MM32_TIM_2_5_ARRBits
{
	Strict_32Bit	ARR		:	32;
}MM32_TIM_2_5_ARRBits;
typedef struct _MM32_TIM_2_5_RCRBits
{
	Strict_16Bit	REP		:	8;
	Strict_16Bit	REP_CNT		:	8;
}MM32_TIM_2_5_RCRBits;
typedef struct _MM32_TIM_2_5_CCR1Bits
{
	Strict_32Bit	CCR1		:	32;
}MM32_TIM_2_5_CCR1Bits;
typedef struct _MM32_TIM_2_5_CCR2Bits
{
	Strict_32Bit	CCR2		:	32;
}MM32_TIM_2_5_CCR2Bits;
typedef struct _MM32_TIM_2_5_CCR3Bits
{
	Strict_32Bit	CCR3		:	32;
}MM32_TIM_2_5_CCR3Bits;
typedef struct _MM32_TIM_2_5_CCR4Bits
{
	Strict_32Bit	CCR4		:	32;
}MM32_TIM_2_5_CCR4Bits;
typedef struct _MM32_TIM_2_5_BDTRBits
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
}MM32_TIM_2_5_BDTRBits;
typedef struct _MM32_TIM_2_5_DCRBits
{
	Strict_16Bit	DBA		:	5;
	Strict_16Bit	_reserved_0		:	3;
	Strict_16Bit	DBL		:	5;
	Strict_16Bit	_reserved_1		:	3;
}MM32_TIM_2_5_DCRBits;
typedef struct _MM32_TIM_2_5_DMARBits
{
	Strict_16Bit	DMAB		:	16;
}MM32_TIM_2_5_DMARBits;
typedef struct _MM32_TIM_2_5_ORBits
{
	Strict_16Bit	ETR_RMP		:	2;
	Strict_16Bit	_reserved_0		:	4;
	Strict_16Bit	TI4_RMP		:	2;
	Strict_16Bit	_reserved_1		:	8;
}MM32_TIM_2_5_ORBits;
typedef struct _MM32_TIM_2_5_CCMR3Bits
{
	Strict_16Bit	_reserved_0		:	3;
	Strict_16Bit	OC5PE		:	1;
	Strict_16Bit	_reserved_1		:	12;
}MM32_TIM_2_5_CCMR3Bits;
typedef struct _MM32_TIM_2_5_CCR5Bits
{
	Strict_16Bit	CCR5		:	16;
}MM32_TIM_2_5_CCR5Bits;
typedef struct _MM32_TIM_2_5_PDERBits
{
	Strict_16Bit	CCDREPE		:	1;
	Strict_16Bit	CCR1_SHIFT_EN		:	1;
	Strict_16Bit	CCR2_SHIFT_EN		:	1;
	Strict_16Bit	CCR3_SHIFT_EN		:	1;
	Strict_16Bit	CCR4_SHIFT_EN		:	1;
	Strict_16Bit	CCR5_SHIFT_EN		:	1;
	Strict_16Bit	_reserved_0		:	10;
}MM32_TIM_2_5_PDERBits;
typedef struct _MM32_TIM_2_5_CCR1FALLBits
{
	Strict_16Bit	CCRFALL		:	16;
}MM32_TIM_2_5_CCR1FALLBits;
typedef struct _MM32_TIM_2_5_CCR2FALLBits
{
	Strict_16Bit	CCRFALL		:	16;
}MM32_TIM_2_5_CCR2FALLBits;
typedef struct _MM32_TIM_2_5_CCR3FALLBits
{
	Strict_16Bit	CCRFALL		:	16;
}MM32_TIM_2_5_CCR3FALLBits;
typedef struct _MM32_TIM_2_5_CCR4FALLBits
{
	Strict_16Bit	CCRFALL		:	16;
}MM32_TIM_2_5_CCR4FALLBits;
typedef struct _MM32_TIM_2_5_CCR5FALLBits
{
	Strict_16Bit	CCRFALL		:	16;
}MM32_TIM_2_5_CCR5FALLBits;
typedef union _MM32_TIM_2_5_CR1
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_2_5_CR1Bits	B;
}MM32_TIM_2_5_CR1;
typedef union _MM32_TIM_2_5_CR2
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_2_5_CR2Bits	B;
}MM32_TIM_2_5_CR2;
typedef union _MM32_TIM_2_5_SMCR
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_2_5_SMCRBits	B;
}MM32_TIM_2_5_SMCR;
typedef union _MM32_TIM_2_5_DIER
{
	uint32_t	U;
	int32_t	I;
	MM32_TIM_2_5_DIERBits	B;
}MM32_TIM_2_5_DIER;
typedef union _MM32_TIM_2_5_SR
{
	uint32_t	U;
	int32_t	I;
	MM32_TIM_2_5_SRBits	B;
}MM32_TIM_2_5_SR;
typedef union _MM32_TIM_2_5_EGR
{
	uint32_t	U;
	int32_t	I;
	MM32_TIM_2_5_EGRBits	B;
}MM32_TIM_2_5_EGR;
typedef union _MM32_TIM_2_5_CCMR1
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_2_5_CCMR1Bits	B;
}MM32_TIM_2_5_CCMR1;
typedef union _MM32_TIM_2_5_CCMR2
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_2_5_CCMR2Bits	B;
}MM32_TIM_2_5_CCMR2;
typedef union _MM32_TIM_2_5_CCER
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_2_5_CCERBits	B;
}MM32_TIM_2_5_CCER;
typedef union _MM32_TIM_2_5_CNT
{
	uint32_t	U;
	int32_t	I;
	MM32_TIM_2_5_CNTBits	B;
}MM32_TIM_2_5_CNT;
typedef union _MM32_TIM_2_5_PSC
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_2_5_PSCBits	B;
}MM32_TIM_2_5_PSC;
typedef union _MM32_TIM_2_5_ARR
{
	uint32_t	U;
	int32_t	I;
	MM32_TIM_2_5_ARRBits	B;
}MM32_TIM_2_5_ARR;
typedef union _MM32_TIM_2_5_RCR
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_2_5_RCRBits	B;
}MM32_TIM_2_5_RCR;
typedef union _MM32_TIM_2_5_CCR1
{
	uint32_t	U;
	int32_t	I;
	MM32_TIM_2_5_CCR1Bits	B;
}MM32_TIM_2_5_CCR1;
typedef union _MM32_TIM_2_5_CCR2
{
	uint32_t	U;
	int32_t	I;
	MM32_TIM_2_5_CCR2Bits	B;
}MM32_TIM_2_5_CCR2;
typedef union _MM32_TIM_2_5_CCR3
{
	uint32_t	U;
	int32_t	I;
	MM32_TIM_2_5_CCR3Bits	B;
}MM32_TIM_2_5_CCR3;
typedef union _MM32_TIM_2_5_CCR4
{
	uint32_t	U;
	int32_t	I;
	MM32_TIM_2_5_CCR4Bits	B;
}MM32_TIM_2_5_CCR4;
typedef union _MM32_TIM_2_5_BDTR
{
	uint32_t	U;
	int32_t	I;
	MM32_TIM_2_5_BDTRBits	B;
}MM32_TIM_2_5_BDTR;
typedef union _MM32_TIM_2_5_DCR
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_2_5_DCRBits	B;
}MM32_TIM_2_5_DCR;
typedef union _MM32_TIM_2_5_DMAR
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_2_5_DMARBits	B;
}MM32_TIM_2_5_DMAR;
typedef union _MM32_TIM_2_5_OR
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_2_5_ORBits	B;
}MM32_TIM_2_5_OR;
typedef union _MM32_TIM_2_5_CCMR3
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_2_5_CCMR3Bits	B;
}MM32_TIM_2_5_CCMR3;
typedef union _MM32_TIM_2_5_CCR5
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_2_5_CCR5Bits	B;
}MM32_TIM_2_5_CCR5;
typedef union _MM32_TIM_2_5_PDER
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_2_5_PDERBits	B;
}MM32_TIM_2_5_PDER;
typedef union _MM32_TIM_2_5_CCR1FALL
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_2_5_CCR1FALLBits	B;
}MM32_TIM_2_5_CCR1FALL;
typedef union _MM32_TIM_2_5_CCR2FALL
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_2_5_CCR2FALLBits	B;
}MM32_TIM_2_5_CCR2FALL;
typedef union _MM32_TIM_2_5_CCR3FALL
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_2_5_CCR3FALLBits	B;
}MM32_TIM_2_5_CCR3FALL;
typedef union _MM32_TIM_2_5_CCR4FALL
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_2_5_CCR4FALLBits	B;
}MM32_TIM_2_5_CCR4FALL;
typedef union _MM32_TIM_2_5_CCR5FALL
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_2_5_CCR5FALLBits	B;
}MM32_TIM_2_5_CCR5FALL;
typedef struct _MM32_TIM_2_5
{
	MM32_TIM_2_5_CR1		CR1;
	unsigned char		_reserved_0;
	unsigned char		_reserved_1;
	MM32_TIM_2_5_CR2		CR2;
	unsigned char		_reserved_2;
	unsigned char		_reserved_3;
	MM32_TIM_2_5_SMCR		SMCR;
	unsigned char		_reserved_4;
	unsigned char		_reserved_5;
	MM32_TIM_2_5_DIER		DIER;
	MM32_TIM_2_5_SR		SR;
	MM32_TIM_2_5_EGR		EGR;
	MM32_TIM_2_5_CCMR1		CCMR1;
	unsigned char		_reserved_6;
	unsigned char		_reserved_7;
	MM32_TIM_2_5_CCMR2		CCMR2;
	unsigned char		_reserved_8;
	unsigned char		_reserved_9;
	MM32_TIM_2_5_CCER		CCER;
	unsigned char		_reserved_10;
	unsigned char		_reserved_11;
	MM32_TIM_2_5_CNT		CNT;
	MM32_TIM_2_5_PSC		PSC;
	unsigned char		_reserved_12;
	unsigned char		_reserved_13;
	MM32_TIM_2_5_ARR		ARR;
	MM32_TIM_2_5_RCR		RCR;
	unsigned char		_reserved_14;
	unsigned char		_reserved_15;
	MM32_TIM_2_5_CCR1		CCR1;
	MM32_TIM_2_5_CCR2		CCR2;
	MM32_TIM_2_5_CCR3		CCR3;
	MM32_TIM_2_5_CCR4		CCR4;
	MM32_TIM_2_5_BDTR		BDTR;
	MM32_TIM_2_5_DCR		DCR;
	unsigned char		_reserved_16;
	unsigned char		_reserved_17;
	MM32_TIM_2_5_DMAR		DMAR;
	unsigned char		_reserved_18;
	unsigned char		_reserved_19;
	MM32_TIM_2_5_OR		OR;
	unsigned char		_reserved_20;
	unsigned char		_reserved_21;
	MM32_TIM_2_5_CCMR3		CCMR3;
	unsigned char		_reserved_22;
	unsigned char		_reserved_23;
	MM32_TIM_2_5_CCR5		CCR5;
	unsigned char		_reserved_24;
	unsigned char		_reserved_25;
	MM32_TIM_2_5_PDER		PDER;
	unsigned char		_reserved_26;
	unsigned char		_reserved_27;
	MM32_TIM_2_5_CCR1FALL		CCR1FALL;
	unsigned char		_reserved_28;
	unsigned char		_reserved_29;
	MM32_TIM_2_5_CCR2FALL		CCR2FALL;
	unsigned char		_reserved_30;
	unsigned char		_reserved_31;
	MM32_TIM_2_5_CCR3FALL		CCR3FALL;
	unsigned char		_reserved_32;
	unsigned char		_reserved_33;
	MM32_TIM_2_5_CCR4FALL		CCR4FALL;
	unsigned char		_reserved_34;
	unsigned char		_reserved_35;
	MM32_TIM_2_5_CCR5FALL		CCR5FALL;
}MM32_TIM_2_5;
#endif