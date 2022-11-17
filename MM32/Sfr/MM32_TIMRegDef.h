/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-31 10:33:40
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:07:58
 * @FilePath: \CODE\MM32\Sfr\MM32_TIMRegDef.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_TIMREGDEF_H_
#define _MM32_TIMREGDEF_H_

#include "MM32_RegTypedef.h"

typedef struct _MM32_TIM_CR1Bits
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
}MM32_TIM_CR1Bits;
typedef struct _MM32_TIM_CR2Bits
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
}MM32_TIM_CR2Bits;
typedef struct _MM32_TIM_SMCRBits
{
	Strict_16Bit	SMS		:	3;
	Strict_16Bit	OCCS		:	1;
	Strict_16Bit	TS		:	3;
	Strict_16Bit	MSM		:	1;
	Strict_16Bit	ETF		:	4;
	Strict_16Bit	ETPS		:	2;
	Strict_16Bit	ECE		:	1;
	Strict_16Bit	ETP		:	1;
}MM32_TIM_SMCRBits;
typedef struct _MM32_TIM_DIERBits
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
}MM32_TIM_DIERBits;
typedef struct _MM32_TIM_SRBits
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
}MM32_TIM_SRBits;
typedef struct _MM32_TIM_EGRBits
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
}MM32_TIM_EGRBits;
typedef struct _MM32_TIM_CCMR1Bits
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
}MM32_TIM_CCMR1Bits;
typedef struct _MM32_TIM_CCMR2Bits
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
}MM32_TIM_CCMR2Bits;
typedef struct _MM32_TIM_CCERBits
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
}MM32_TIM_CCERBits;
typedef struct _MM32_TIM_CNTBits
{
	Strict_32Bit	CNT		:	32;
}MM32_TIM_CNTBits;
typedef struct _MM32_TIM_PSCBits
{
	Strict_16Bit	PSC		:	16;
}MM32_TIM_PSCBits;
typedef struct _MM32_TIM_ARRBits
{
	Strict_32Bit	ARR		:	32;
}MM32_TIM_ARRBits;
typedef struct _MM32_TIM_RCRBits
{
	Strict_16Bit	REP		:	8;
	Strict_16Bit	REP_CNT		:	8;
}MM32_TIM_RCRBits;
typedef struct _MM32_TIM_CCR1Bits
{
	Strict_32Bit	CCR1		:	32;
}MM32_TIM_CCR1Bits;
typedef struct _MM32_TIM_CCR2Bits
{
	Strict_32Bit	CCR2		:	32;
}MM32_TIM_CCR2Bits;
typedef struct _MM32_TIM_CCR3Bits
{
	Strict_32Bit	CCR3		:	32;
}MM32_TIM_CCR3Bits;
typedef struct _MM32_TIM_CCR4Bits
{
	Strict_32Bit	CCR4		:	32;
}MM32_TIM_CCR4Bits;
typedef struct _MM32_TIM_BDTRBits
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
}MM32_TIM_BDTRBits;
typedef struct _MM32_TIM_DCRBits
{
	Strict_16Bit	DBA		:	5;
	Strict_16Bit	_reserved_0		:	3;
	Strict_16Bit	DBL		:	5;
	Strict_16Bit	_reserved_1		:	3;
}MM32_TIM_DCRBits;
typedef struct _MM32_TIM_DMARBits
{
	Strict_16Bit	DMAB		:	16;
}MM32_TIM_DMARBits;
typedef struct _MM32_TIM_ORBits
{
	Strict_16Bit	ETR_RMP		:	2;
	Strict_16Bit	_reserved_0		:	4;
	Strict_16Bit	TI4_RMP		:	2;
	Strict_16Bit	_reserved_1		:	8;
}MM32_TIM_ORBits;
typedef struct _MM32_TIM_CCMR3Bits
{
	Strict_16Bit	_reserved_0		:	3;
	Strict_16Bit	OC5PE		:	1;
	Strict_16Bit	_reserved_1		:	12;
}MM32_TIM_CCMR3Bits;
typedef struct _MM32_TIM_CCR5Bits
{
	Strict_16Bit	CCR5		:	16;
}MM32_TIM_CCR5Bits;
typedef struct _MM32_TIM_PDERBits
{
	Strict_16Bit	CCDREPE		:	1;
	Strict_16Bit	CCR1_SHIFT_EN		:	1;
	Strict_16Bit	CCR2_SHIFT_EN		:	1;
	Strict_16Bit	CCR3_SHIFT_EN		:	1;
	Strict_16Bit	CCR4_SHIFT_EN		:	1;
	Strict_16Bit	CCR5_SHIFT_EN		:	1;
	Strict_16Bit	_reserved_0		:	10;
}MM32_TIM_PDERBits;
typedef struct _MM32_TIM_CCR1FALLBits
{
	Strict_16Bit	CCRFALL		:	16;
}MM32_TIM_CCR1FALLBits;
typedef struct _MM32_TIM_CCR2FALLBits
{
	Strict_16Bit	CCRFALL		:	16;
}MM32_TIM_CCR2FALLBits;
typedef struct _MM32_TIM_CCR3FALLBits
{
	Strict_16Bit	CCRFALL		:	16;
}MM32_TIM_CCR3FALLBits;
typedef struct _MM32_TIM_CCR4FALLBits
{
	Strict_16Bit	CCRFALL		:	16;
}MM32_TIM_CCR4FALLBits;
typedef struct _MM32_TIM_CCR5FALLBits
{
	Strict_16Bit	CCRFALL		:	16;
}MM32_TIM_CCR5FALLBits;
typedef union _MM32_TIM_CR1
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_CR1Bits	B;
}MM32_TIM_CR1;
typedef union _MM32_TIM_CR2
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_CR2Bits	B;
}MM32_TIM_CR2;
typedef union _MM32_TIM_SMCR
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_SMCRBits	B;
}MM32_TIM_SMCR;
typedef union _MM32_TIM_DIER
{
	uint32_t	U;
	int32_t	I;
	MM32_TIM_DIERBits	B;
}MM32_TIM_DIER;
typedef union _MM32_TIM_SR
{
	uint32_t	U;
	int32_t	I;
	MM32_TIM_SRBits	B;
}MM32_TIM_SR;
typedef union _MM32_TIM_EGR
{
	uint32_t	U;
	int32_t	I;
	MM32_TIM_EGRBits	B;
}MM32_TIM_EGR;
typedef union _MM32_TIM_CCMR1
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_CCMR1Bits	B;
}MM32_TIM_CCMR1;
typedef union _MM32_TIM_CCMR2
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_CCMR2Bits	B;
}MM32_TIM_CCMR2;
typedef union _MM32_TIM_CCER
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_CCERBits	B;
}MM32_TIM_CCER;
typedef union _MM32_TIM_CNT
{
	uint32_t	U;
	int32_t	I;
	MM32_TIM_CNTBits	B;
}MM32_TIM_CNT;
typedef union _MM32_TIM_PSC
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_PSCBits	B;
}MM32_TIM_PSC;
typedef union _MM32_TIM_ARR
{
	uint32_t	U;
	int32_t	I;
	MM32_TIM_ARRBits	B;
}MM32_TIM_ARR;
typedef union _MM32_TIM_RCR
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_RCRBits	B;
}MM32_TIM_RCR;
typedef union _MM32_TIM_CCR1
{
	uint32_t	U;
	int32_t	I;
	MM32_TIM_CCR1Bits	B;
}MM32_TIM_CCR1;
typedef union _MM32_TIM_CCR2
{
	uint32_t	U;
	int32_t	I;
	MM32_TIM_CCR2Bits	B;
}MM32_TIM_CCR2;
typedef union _MM32_TIM_CCR3
{
	uint32_t	U;
	int32_t	I;
	MM32_TIM_CCR3Bits	B;
}MM32_TIM_CCR3;
typedef union _MM32_TIM_CCR4
{
	uint32_t	U;
	int32_t	I;
	MM32_TIM_CCR4Bits	B;
}MM32_TIM_CCR4;
typedef union _MM32_TIM_BDTR
{
	uint32_t	U;
	int32_t	I;
	MM32_TIM_BDTRBits	B;
}MM32_TIM_BDTR;
typedef union _MM32_TIM_DCR
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_DCRBits	B;
}MM32_TIM_DCR;
typedef union _MM32_TIM_DMAR
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_DMARBits	B;
}MM32_TIM_DMAR;
typedef union _MM32_TIM_OR
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_ORBits	B;
}MM32_TIM_OR;
typedef union _MM32_TIM_CCMR3
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_CCMR3Bits	B;
}MM32_TIM_CCMR3;
typedef union _MM32_TIM_CCR5
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_CCR5Bits	B;
}MM32_TIM_CCR5;
typedef union _MM32_TIM_PDER
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_PDERBits	B;
}MM32_TIM_PDER;
typedef union _MM32_TIM_CCR1FALL
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_CCR1FALLBits	B;
}MM32_TIM_CCR1FALL;
typedef union _MM32_TIM_CCR2FALL
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_CCR2FALLBits	B;
}MM32_TIM_CCR2FALL;
typedef union _MM32_TIM_CCR3FALL
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_CCR3FALLBits	B;
}MM32_TIM_CCR3FALL;
typedef union _MM32_TIM_CCR4FALL
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_CCR4FALLBits	B;
}MM32_TIM_CCR4FALL;
typedef union _MM32_TIM_CCR5FALL
{
	uint16_t	U;
	int16_t	I;
	MM32_TIM_CCR5FALLBits	B;
}MM32_TIM_CCR5FALL;
typedef struct _MM32_TIM
{
	MM32_TIM_CR1		CR1;
	unsigned char		_reserved_0;
	unsigned char		_reserved_1;
	MM32_TIM_CR2		CR2;
	unsigned char		_reserved_2;
	unsigned char		_reserved_3;
	MM32_TIM_SMCR		SMCR;
	unsigned char		_reserved_4;
	unsigned char		_reserved_5;
	MM32_TIM_DIER		DIER;
	MM32_TIM_SR		SR;
	MM32_TIM_EGR		EGR;
	MM32_TIM_CCMR1		CCMR1;
	unsigned char		_reserved_6;
	unsigned char		_reserved_7;
	MM32_TIM_CCMR2		CCMR2;
	unsigned char		_reserved_8;
	unsigned char		_reserved_9;
	MM32_TIM_CCER		CCER;
	unsigned char		_reserved_10;
	unsigned char		_reserved_11;
	MM32_TIM_CNT		CNT;
	MM32_TIM_PSC		PSC;
	unsigned char		_reserved_12;
	unsigned char		_reserved_13;
	MM32_TIM_ARR		ARR;
	MM32_TIM_RCR		RCR;
	unsigned char		_reserved_14;
	unsigned char		_reserved_15;
	MM32_TIM_CCR1		CCR1;
	MM32_TIM_CCR2		CCR2;
	MM32_TIM_CCR3		CCR3;
	MM32_TIM_CCR4		CCR4;
	MM32_TIM_BDTR		BDTR;
	MM32_TIM_DCR		DCR;
	unsigned char		_reserved_16;
	unsigned char		_reserved_17;
	MM32_TIM_DMAR		DMAR;
	unsigned char		_reserved_18;
	unsigned char		_reserved_19;
	MM32_TIM_OR		OR;
	unsigned char		_reserved_20;
	unsigned char		_reserved_21;
	MM32_TIM_CCMR3		CCMR3;
	unsigned char		_reserved_22;
	unsigned char		_reserved_23;
	MM32_TIM_CCR5		CCR5;
	unsigned char		_reserved_24;
	unsigned char		_reserved_25;
	MM32_TIM_PDER		PDER;
	unsigned char		_reserved_26;
	unsigned char		_reserved_27;
	MM32_TIM_CCR1FALL		CCR1FALL;
	unsigned char		_reserved_28;
	unsigned char		_reserved_29;
	MM32_TIM_CCR2FALL		CCR2FALL;
	unsigned char		_reserved_30;
	unsigned char		_reserved_31;
	MM32_TIM_CCR3FALL		CCR3FALL;
	unsigned char		_reserved_32;
	unsigned char		_reserved_33;
	MM32_TIM_CCR4FALL		CCR4FALL;
	unsigned char		_reserved_34;
	unsigned char		_reserved_35;
	MM32_TIM_CCR5FALL		CCR5FALL;
}MM32_TIM;
#endif