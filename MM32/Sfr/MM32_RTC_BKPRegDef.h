/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:43:27
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:07:44
 * @FilePath: \CODE\MM32\Sfr\MM32_RTC_BKPRegDef.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_RTC_BKPREGDEF_H_
#define _MM32_RTC_BKPREGDEF_H_

#include "MM32_RegTypedef.h"

typedef struct _MM32_RTC_BKP_CRHBits
{
	Strict_16Bit	SECIE		:	1;
	Strict_16Bit	ALRIE		:	1;
	Strict_16Bit	OWIE		:	1;
	Strict_16Bit	_reserved_0		:	13;
}MM32_RTC_BKP_CRHBits;
typedef struct _MM32_RTC_BKP_CRLBits
{
	Strict_16Bit	SECF		:	1;
	Strict_16Bit	ALRF		:	1;
	Strict_16Bit	OWF		:	1;
	Strict_16Bit	RSF		:	1;
	Strict_16Bit	CNF		:	1;
	Strict_16Bit	RTOFF		:	1;
	Strict_16Bit	ALPEN		:	1;
	Strict_16Bit	_reserved_0		:	9;
}MM32_RTC_BKP_CRLBits;
typedef struct _MM32_RTC_BKP_PRLHBits
{
	Strict_16Bit	PRL		:	4;
	Strict_16Bit	_reserved_0		:	12;
}MM32_RTC_BKP_PRLHBits;
typedef struct _MM32_RTC_BKP_PRLLBits
{
	Strict_16Bit	PRL		:	16;
}MM32_RTC_BKP_PRLLBits;
typedef struct _MM32_RTC_BKP_DIVHBits
{
	Strict_16Bit	DIV		:	4;
	Strict_16Bit	_reserved_0		:	12;
}MM32_RTC_BKP_DIVHBits;
typedef struct _MM32_RTC_BKP_DIVLBits
{
	Strict_16Bit	DIV		:	16;
}MM32_RTC_BKP_DIVLBits;
typedef struct _MM32_RTC_BKP_CNTHBits
{
	Strict_16Bit	CNT		:	16;
}MM32_RTC_BKP_CNTHBits;
typedef struct _MM32_RTC_BKP_CNTLBits
{
	Strict_16Bit	CNT		:	16;
}MM32_RTC_BKP_CNTLBits;
typedef struct _MM32_RTC_BKP_ALRHBits
{
	Strict_16Bit	ALR		:	16;
}MM32_RTC_BKP_ALRHBits;
typedef struct _MM32_RTC_BKP_ALRLBits
{
	Strict_16Bit	ALR		:	16;
}MM32_RTC_BKP_ALRLBits;
typedef struct _MM32_RTC_BKP_MSRHBits
{
	Strict_16Bit	MSR		:	4;
	Strict_16Bit	_reserved_0		:	12;
}MM32_RTC_BKP_MSRHBits;
typedef struct _MM32_RTC_BKP_MSRLBits
{
	Strict_16Bit	MSR		:	16;
}MM32_RTC_BKP_MSRLBits;
typedef struct _MM32_RTC_BKP_LSE_CFGBits
{
	Strict_16Bit	LSE_TEST		:	4;
	Strict_16Bit	LSE_DR		:	2;
	Strict_16Bit	LSE_RFB_SEL		:	2;
	Strict_16Bit	LSE_IB		:	2;
	Strict_16Bit	_reserved_0		:	6;
}MM32_RTC_BKP_LSE_CFGBits;
typedef struct _MM32_RTC_BKP_BKP_RTCCRBits
{
	Strict_16Bit	CAL		:	7;
	Strict_16Bit	CCO		:	1;
	Strict_16Bit	ASOE		:	1;
	Strict_16Bit	ASOS		:	1;
	Strict_16Bit	_reserved_0		:	6;
}MM32_RTC_BKP_BKP_RTCCRBits;
typedef struct _MM32_RTC_BKP_BKP_CRBits
{
	Strict_16Bit	TPE		:	1;
	Strict_16Bit	TPAL		:	1;
	Strict_16Bit	_reserved_0		:	14;
}MM32_RTC_BKP_BKP_CRBits;
typedef struct _MM32_RTC_BKP_BKP_CSRBits
{
	Strict_16Bit	CTE		:	1;
	Strict_16Bit	CTI		:	1;
	Strict_16Bit	TPIE		:	1;
	Strict_16Bit	_reserved_0		:	5;
	Strict_16Bit	TEF		:	1;
	Strict_16Bit	TIF		:	1;
	Strict_16Bit	_reserved_1		:	6;
}MM32_RTC_BKP_BKP_CSRBits;
typedef struct _MM32_RTC_BKP_BKP_DR1Bits
{
	Strict_16Bit	BKP		:	16;
}MM32_RTC_BKP_BKP_DR1Bits;
typedef struct _MM32_RTC_BKP_BKP_DR2Bits
{
        Strict_16Bit	BKP		:	16;
}MM32_RTC_BKP_BKP_DR2Bits;
typedef struct _MM32_RTC_BKP_BKP_DR3Bits
{
        Strict_16Bit	BKP		:	16;
}MM32_RTC_BKP_BKP_DR3Bits;
typedef struct _MM32_RTC_BKP_BKP_DR4Bits
{
        Strict_16Bit	BKP		:	16;
}MM32_RTC_BKP_BKP_DR4Bits;
typedef struct _MM32_RTC_BKP_BKP_DR5Bits
{
        Strict_16Bit	BKP		:	16;
}MM32_RTC_BKP_BKP_DR5Bits;
typedef struct _MM32_RTC_BKP_BKP_DR6Bits
{
        Strict_16Bit	BKP		:	16;
}MM32_RTC_BKP_BKP_DR6Bits;
typedef struct _MM32_RTC_BKP_BKP_DR7Bits
{
        Strict_16Bit	BKP		:	16;
}MM32_RTC_BKP_BKP_DR7Bits;
typedef struct _MM32_RTC_BKP_BKP_DR8Bits
{
        Strict_16Bit	BKP		:	16;
}MM32_RTC_BKP_BKP_DR8Bits;
typedef struct _MM32_RTC_BKP_BKP_DR9Bits
{
        Strict_16Bit	BKP		:	16;
}MM32_RTC_BKP_BKP_DR9Bits;
typedef struct _MM32_RTC_BKP_BKP_DR10Bits
{
        Strict_16Bit	BKP		:	16;
}MM32_RTC_BKP_BKP_DR10Bits;
typedef struct _MM32_RTC_BKP_BKP_DR11Bits
{
        Strict_16Bit	BKP		:	16;
}MM32_RTC_BKP_BKP_DR11Bits;
typedef struct _MM32_RTC_BKP_BKP_DR12Bits
{
        Strict_16Bit	BKP		:	16;
}MM32_RTC_BKP_BKP_DR12Bits;
typedef struct _MM32_RTC_BKP_BKP_DR13Bits
{
        Strict_16Bit	BKP		:	16;
}MM32_RTC_BKP_BKP_DR13Bits;
typedef struct _MM32_RTC_BKP_BKP_DR14Bits
{
        Strict_16Bit	BKP		:	16;
}MM32_RTC_BKP_BKP_DR14Bits;
typedef struct _MM32_RTC_BKP_BKP_DR15Bits
{
        Strict_16Bit	BKP		:	16;
}MM32_RTC_BKP_BKP_DR15Bits;
typedef struct _MM32_RTC_BKP_BKP_DR16Bits
{
        Strict_16Bit	BKP		:	16;
}MM32_RTC_BKP_BKP_DR16Bits;
typedef struct _MM32_RTC_BKP_BKP_DR17Bits
{
        Strict_16Bit	BKP		:	16;
}MM32_RTC_BKP_BKP_DR17Bits;
typedef struct _MM32_RTC_BKP_BKP_DR18Bits
{
        Strict_16Bit	BKP		:	16;
}MM32_RTC_BKP_BKP_DR18Bits;
typedef struct _MM32_RTC_BKP_BKP_DR19Bits
{
        Strict_16Bit	BKP		:	16;
}MM32_RTC_BKP_BKP_DR19Bits;
typedef struct _MM32_RTC_BKP_BKP_DR20Bits
{
        Strict_16Bit	BKP		:	16;
}MM32_RTC_BKP_BKP_DR20Bits;
typedef union _MM32_RTC_BKP_CRH
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_CRHBits	B;
}MM32_RTC_BKP_CRH;
typedef union _MM32_RTC_BKP_CRL
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_CRLBits	B;
}MM32_RTC_BKP_CRL;
typedef union _MM32_RTC_BKP_PRLH
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_PRLHBits	B;
}MM32_RTC_BKP_PRLH;
typedef union _MM32_RTC_BKP_PRLL
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_PRLLBits	B;
}MM32_RTC_BKP_PRLL;
typedef union _MM32_RTC_BKP_DIVH
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_DIVHBits	B;
}MM32_RTC_BKP_DIVH;
typedef union _MM32_RTC_BKP_DIVL
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_DIVLBits	B;
}MM32_RTC_BKP_DIVL;
typedef union _MM32_RTC_BKP_CNTH
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_CNTHBits	B;
}MM32_RTC_BKP_CNTH;
typedef union _MM32_RTC_BKP_CNTL
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_CNTLBits	B;
}MM32_RTC_BKP_CNTL;
typedef union _MM32_RTC_BKP_ALRH
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_ALRHBits	B;
}MM32_RTC_BKP_ALRH;
typedef union _MM32_RTC_BKP_ALRL
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_ALRLBits	B;
}MM32_RTC_BKP_ALRL;
typedef union _MM32_RTC_BKP_MSRH
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_MSRHBits	B;
}MM32_RTC_BKP_MSRH;
typedef union _MM32_RTC_BKP_MSRL
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_MSRLBits	B;
}MM32_RTC_BKP_MSRL;
typedef union _MM32_RTC_BKP_LSE_CFG
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_LSE_CFGBits	B;
}MM32_RTC_BKP_LSE_CFG;
typedef union _MM32_RTC_BKP_BKP_RTCCR
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_BKP_RTCCRBits	B;
}MM32_RTC_BKP_BKP_RTCCR;
typedef union _MM32_RTC_BKP_BKP_CR
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_BKP_CRBits	B;
}MM32_RTC_BKP_BKP_CR;
typedef union _MM32_RTC_BKP_BKP_CSR
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_BKP_CSRBits	B;
}MM32_RTC_BKP_BKP_CSR;
typedef union _MM32_RTC_BKP_BKP_DR1
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_BKP_DR1Bits	B;
}MM32_RTC_BKP_BKP_DR1;
typedef union _MM32_RTC_BKP_BKP_DR2
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_BKP_DR2Bits	B;
}MM32_RTC_BKP_BKP_DR2;
typedef union _MM32_RTC_BKP_BKP_DR3
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_BKP_DR3Bits	B;
}MM32_RTC_BKP_BKP_DR3;
typedef union _MM32_RTC_BKP_BKP_DR4
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_BKP_DR4Bits	B;
}MM32_RTC_BKP_BKP_DR4;
typedef union _MM32_RTC_BKP_BKP_DR5
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_BKP_DR5Bits	B;
}MM32_RTC_BKP_BKP_DR5;
typedef union _MM32_RTC_BKP_BKP_DR6
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_BKP_DR6Bits	B;
}MM32_RTC_BKP_BKP_DR6;
typedef union _MM32_RTC_BKP_BKP_DR7
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_BKP_DR7Bits	B;
}MM32_RTC_BKP_BKP_DR7;
typedef union _MM32_RTC_BKP_BKP_DR8
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_BKP_DR8Bits	B;
}MM32_RTC_BKP_BKP_DR8;
typedef union _MM32_RTC_BKP_BKP_DR9
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_BKP_DR9Bits	B;
}MM32_RTC_BKP_BKP_DR9;
typedef union _MM32_RTC_BKP_BKP_DR10
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_BKP_DR10Bits	B;
}MM32_RTC_BKP_BKP_DR10;
typedef union _MM32_RTC_BKP_BKP_DR11
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_BKP_DR11Bits	B;
}MM32_RTC_BKP_BKP_DR11;
typedef union _MM32_RTC_BKP_BKP_DR12
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_BKP_DR12Bits	B;
}MM32_RTC_BKP_BKP_DR12;
typedef union _MM32_RTC_BKP_BKP_DR13
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_BKP_DR13Bits	B;
}MM32_RTC_BKP_BKP_DR13;
typedef union _MM32_RTC_BKP_BKP_DR14
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_BKP_DR14Bits	B;
}MM32_RTC_BKP_BKP_DR14;
typedef union _MM32_RTC_BKP_BKP_DR15
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_BKP_DR15Bits	B;
}MM32_RTC_BKP_BKP_DR15;
typedef union _MM32_RTC_BKP_BKP_DR16
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_BKP_DR16Bits	B;
}MM32_RTC_BKP_BKP_DR16;
typedef union _MM32_RTC_BKP_BKP_DR17
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_BKP_DR17Bits	B;
}MM32_RTC_BKP_BKP_DR17;
typedef union _MM32_RTC_BKP_BKP_DR18
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_BKP_DR18Bits	B;
}MM32_RTC_BKP_BKP_DR18;
typedef union _MM32_RTC_BKP_BKP_DR19
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_BKP_DR19Bits	B;
}MM32_RTC_BKP_BKP_DR19;
typedef union _MM32_RTC_BKP_BKP_DR20
{
	uint16_t	U;
	int16_t	I;
	MM32_RTC_BKP_BKP_DR20Bits	B;
}MM32_RTC_BKP_BKP_DR20;
typedef struct _MM32_RTC_BKP
{
	MM32_RTC_BKP_CRH		CRH;
	unsigned char		_reserved_0;
	unsigned char		_reserved_1;
	MM32_RTC_BKP_CRL		CRL;
	unsigned char		_reserved_2;
	unsigned char		_reserved_3;
	MM32_RTC_BKP_PRLH		PRLH;
	unsigned char		_reserved_4;
	unsigned char		_reserved_5;
	MM32_RTC_BKP_PRLL		PRLL;
	unsigned char		_reserved_6;
	unsigned char		_reserved_7;
	MM32_RTC_BKP_DIVH		DIVH;
	unsigned char		_reserved_8;
	unsigned char		_reserved_9;
	MM32_RTC_BKP_DIVL		DIVL;
	unsigned char		_reserved_10;
	unsigned char		_reserved_11;
	MM32_RTC_BKP_CNTH		CNTH;
	unsigned char		_reserved_12;
	unsigned char		_reserved_13;
	MM32_RTC_BKP_CNTL		CNTL;
	unsigned char		_reserved_14;
	unsigned char		_reserved_15;
	MM32_RTC_BKP_ALRH		ALRH;
	unsigned char		_reserved_16;
	unsigned char		_reserved_17;
	MM32_RTC_BKP_ALRL		ALRL;
	unsigned char		_reserved_18;
	unsigned char		_reserved_19;
	MM32_RTC_BKP_MSRH		MSRH;
	unsigned char		_reserved_20;
	unsigned char		_reserved_21;
	MM32_RTC_BKP_MSRL		MSRL;
	unsigned char		_reserved_22;
	unsigned char		_reserved_23;
	unsigned char		_reserved_24;
	unsigned char		_reserved_25;
	unsigned char		_reserved_26;
	unsigned char		_reserved_27;
	unsigned char		_reserved_28;
	unsigned char		_reserved_29;
	unsigned char		_reserved_30;
	unsigned char		_reserved_31;
	unsigned char		_reserved_32;
	unsigned char		_reserved_33;
	unsigned char		_reserved_34;
	unsigned char		_reserved_35;
	MM32_RTC_BKP_LSE_CFG		_CFG;
	unsigned char		_reserved_36;
	unsigned char		_reserved_37;
	MM32_RTC_BKP_BKP_RTCCR		_RTCCR;
	unsigned char		_reserved_38;
	unsigned char		_reserved_39;
	MM32_RTC_BKP_BKP_CR		_CR;
	unsigned char		_reserved_40;
	unsigned char		_reserved_41;
	MM32_RTC_BKP_BKP_CSR		_CSR;
	unsigned char		_reserved_42;
	unsigned char		_reserved_43;
	unsigned char		_reserved_44;
	unsigned char		_reserved_45;
	unsigned char		_reserved_46;
	unsigned char		_reserved_47;
	MM32_RTC_BKP_BKP_DR1		_DR1;
	unsigned char		_reserved_48;
	unsigned char		_reserved_49;
	MM32_RTC_BKP_BKP_DR2		_DR2;
	unsigned char		_reserved_50;
	unsigned char		_reserved_51;
	MM32_RTC_BKP_BKP_DR3		_DR3;
	unsigned char		_reserved_52;
	unsigned char		_reserved_53;
	MM32_RTC_BKP_BKP_DR4		_DR4;
	unsigned char		_reserved_54;
	unsigned char		_reserved_55;
	MM32_RTC_BKP_BKP_DR5		_DR5;
	unsigned char		_reserved_56;
	unsigned char		_reserved_57;
	MM32_RTC_BKP_BKP_DR6		_DR6;
	unsigned char		_reserved_58;
	unsigned char		_reserved_59;
	MM32_RTC_BKP_BKP_DR7		_DR7;
	unsigned char		_reserved_60;
	unsigned char		_reserved_61;
	MM32_RTC_BKP_BKP_DR8		_DR8;
	unsigned char		_reserved_62;
	unsigned char		_reserved_63;
	MM32_RTC_BKP_BKP_DR9		_DR9;
	unsigned char		_reserved_64;
	unsigned char		_reserved_65;
	MM32_RTC_BKP_BKP_DR10		_DR10;
	unsigned char		_reserved_66;
	unsigned char		_reserved_67;
	MM32_RTC_BKP_BKP_DR11		_DR11;
	unsigned char		_reserved_68;
	unsigned char		_reserved_69;
	MM32_RTC_BKP_BKP_DR12		_DR12;
	unsigned char		_reserved_70;
	unsigned char		_reserved_71;
	MM32_RTC_BKP_BKP_DR13		_DR13;
	unsigned char		_reserved_72;
	unsigned char		_reserved_73;
	MM32_RTC_BKP_BKP_DR14		_DR14;
	unsigned char		_reserved_74;
	unsigned char		_reserved_75;
	MM32_RTC_BKP_BKP_DR15		_DR15;
	unsigned char		_reserved_76;
	unsigned char		_reserved_77;
	MM32_RTC_BKP_BKP_DR16		_DR16;
	unsigned char		_reserved_78;
	unsigned char		_reserved_79;
	MM32_RTC_BKP_BKP_DR17		_DR17;
	unsigned char		_reserved_80;
	unsigned char		_reserved_81;
	MM32_RTC_BKP_BKP_DR18		_DR18;
	unsigned char		_reserved_82;
	unsigned char		_reserved_83;
	MM32_RTC_BKP_BKP_DR19		_DR19;
	unsigned char		_reserved_84;
	unsigned char		_reserved_85;
	MM32_RTC_BKP_BKP_DR20		_DR20;
}MM32_RTC_BKP;
#endif
