#ifndef _MM32_ADCREGDEF_H_
#define _MM32_ADCREGDEF_H_

#include "MM32_RegTypedef.h"

typedef struct _MM32_ADC_ADDATABits
{
	Strict_32Bit	DATA		:	16;
	Strict_32Bit	CHANNELSEL		:	4;
	Strict_32Bit	OVERRUN		:	1;
	Strict_32Bit	VALID		:	1;
	Strict_32Bit	_reserved_0		:	10;
}MM32_ADC_ADDATABits;
typedef struct _MM32_ADC_ADCFGBits
{
	Strict_32Bit	ADEN		:	1;
	Strict_32Bit	AWDEN		:	1;
	Strict_32Bit	TSEN		:	1;
	Strict_32Bit	VSEN		:	1;
	Strict_32Bit	ADCPREH		:	3;
	Strict_32Bit	RSLTCTL		:	3;
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	ADCPREL		:	1;
	Strict_32Bit	_reserved_1		:	1;
	Strict_32Bit	JAWDEN		:	1;
	Strict_32Bit	_reserved_2		:	15;
}MM32_ADC_ADCFGBits;
typedef struct _MM32_ADC_ADCRBits
{
	Strict_32Bit	EOSIE		:	1;
	Strict_32Bit	AWDIE		:	1;
	Strict_32Bit	TRGEN		:	1;
	Strict_32Bit	DMAEN		:	1;
	Strict_32Bit	TRGSELL		:	3;
	Strict_32Bit	_reserved_0		:	1;
	Strict_32Bit	ADST		:	1;
	Strict_32Bit	ADMD		:	2;
	Strict_32Bit	ALIGN		:	1;
	Strict_32Bit	CMPCH		:	4;
	Strict_32Bit	SCANDIR		:	1;
	Strict_32Bit	TRGSELH		:	2;
	Strict_32Bit	TRGSHIFT		:	3;
	Strict_32Bit	_reserved_1		:	2;
	Strict_32Bit	TRG_EDGE		:	2;
	Strict_32Bit	EOSMPIE		:	1;
	Strict_32Bit	EOCIE		:	1;
	Strict_32Bit	_reserved_2		:	4;
}MM32_ADC_ADCRBits;
typedef struct _MM32_ADC_ADCHSBits
{
	Strict_32Bit	CHEN0		:	1;
	Strict_32Bit	CHEN1		:	1;
	Strict_32Bit	CHEN2		:	1;
	Strict_32Bit	CHEN3		:	1;
	Strict_32Bit	CHEN4		:	1;
	Strict_32Bit	CHEN5		:	1;
	Strict_32Bit	CHEN6		:	1;
	Strict_32Bit	CHEN7		:	1;
	Strict_32Bit	CHEN8		:	1;
	Strict_32Bit	CHEN9		:	1;
	Strict_32Bit	CHEN10		:	1;
	Strict_32Bit	CHEN11		:	1;
	Strict_32Bit	CHEN12		:	1;
	Strict_32Bit	CHEN13		:	1;
	Strict_32Bit	CHENTS		:	1;
	Strict_32Bit	CHENVS		:	1;
	Strict_32Bit	_reserved_0		:	16;
}MM32_ADC_ADCHSBits;
typedef struct _MM32_ADC_ADCMPRBits
{
	Strict_32Bit	CMPLDATA		:	12;
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	CMPHDATA		:	12;
	Strict_32Bit	_reserved_1		:	4;
}MM32_ADC_ADCMPRBits;
typedef struct _MM32_ADC_ADSTABits
{
	Strict_32Bit	EOSIF		:	1;
	Strict_32Bit	AWDIF		:	1;
	Strict_32Bit	BUSY		:	1;
	Strict_32Bit	_reserved_0		:	1;
	Strict_32Bit	CHANNEL		:	4;
	Strict_32Bit	VALID		:	12;
	Strict_32Bit	OVERRUN		:	12;
}MM32_ADC_ADSTABits;
typedef struct _MM32_ADC_ADDR0Bits
{
	Strict_32Bit	DATA		:	16;
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	OVERRUN		:	1;
	Strict_32Bit	VAILD		:	1;
	Strict_32Bit	_reserved_1		:	10;
}MM32_ADC_ADDR0Bits;
typedef struct _MM32_ADC_ADDR1Bits
{
	Strict_32Bit	DATA		:	16;
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	OVERRUN		:	1;
	Strict_32Bit	VAILD		:	1;
	Strict_32Bit	_reserved_1		:	10;
}MM32_ADC_ADDR1Bits;
typedef struct _MM32_ADC_ADDR2Bits
{
	Strict_32Bit	DATA		:	16;
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	OVERRUN		:	1;
	Strict_32Bit	VAILD		:	1;
	Strict_32Bit	_reserved_1		:	10;
}MM32_ADC_ADDR2Bits;
typedef struct _MM32_ADC_ADDR3Bits
{
	Strict_32Bit	DATA		:	16;
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	OVERRUN		:	1;
	Strict_32Bit	VAILD		:	1;
	Strict_32Bit	_reserved_1		:	10;
}MM32_ADC_ADDR3Bits;
typedef struct _MM32_ADC_ADDR4Bits
{
	Strict_32Bit	DATA		:	16;
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	OVERRUN		:	1;
	Strict_32Bit	VAILD		:	1;
	Strict_32Bit	_reserved_1		:	10;
}MM32_ADC_ADDR4Bits;
typedef struct _MM32_ADC_ADDR5Bits
{
	Strict_32Bit	DATA		:	16;
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	OVERRUN		:	1;
	Strict_32Bit	VAILD		:	1;
	Strict_32Bit	_reserved_1		:	10;
}MM32_ADC_ADDR5Bits;
typedef struct _MM32_ADC_ADDR6Bits
{
	Strict_32Bit	DATA		:	16;
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	OVERRUN		:	1;
	Strict_32Bit	VAILD		:	1;
	Strict_32Bit	_reserved_1		:	10;
}MM32_ADC_ADDR6Bits;
typedef struct _MM32_ADC_ADDR7Bits
{
	Strict_32Bit	DATA		:	16;
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	OVERRUN		:	1;
	Strict_32Bit	VAILD		:	1;
	Strict_32Bit	_reserved_1		:	10;
}MM32_ADC_ADDR7Bits;
typedef struct _MM32_ADC_ADDR8Bits
{
	Strict_32Bit	DATA		:	16;
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	OVERRUN		:	1;
	Strict_32Bit	VAILD		:	1;
	Strict_32Bit	_reserved_1		:	10;
}MM32_ADC_ADDR8Bits;
typedef struct _MM32_ADC_ADDR9Bits
{
	Strict_32Bit	DATA		:	16;
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	OVERRUN		:	1;
	Strict_32Bit	VAILD		:	1;
	Strict_32Bit	_reserved_1		:	10;
}MM32_ADC_ADDR9Bits;
typedef struct _MM32_ADC_ADDR10Bits
{
	Strict_32Bit	DATA		:	16;
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	OVERRUN		:	1;
	Strict_32Bit	VAILD		:	1;
	Strict_32Bit	_reserved_1		:	10;
}MM32_ADC_ADDR10Bits;
typedef struct _MM32_ADC_ADDR11Bits
{
	Strict_32Bit	DATA		:	16;
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	OVERRUN		:	1;
	Strict_32Bit	VAILD		:	1;
	Strict_32Bit	_reserved_1		:	10;
}MM32_ADC_ADDR11Bits;
typedef struct _MM32_ADC_ADDR12Bits
{
	Strict_32Bit	DATA		:	16;
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	OVERRUN		:	1;
	Strict_32Bit	VAILD		:	1;
	Strict_32Bit	_reserved_1		:	10;
}MM32_ADC_ADDR12Bits;
typedef struct _MM32_ADC_ADDR13Bits
{
	Strict_32Bit	DATA		:	16;
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	OVERRUN		:	1;
	Strict_32Bit	VAILD		:	1;
	Strict_32Bit	_reserved_1		:	10;
}MM32_ADC_ADDR13Bits;
typedef struct _MM32_ADC_ADDR14Bits
{
	Strict_32Bit	DATA		:	16;
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	OVERRUN		:	1;
	Strict_32Bit	VAILD		:	1;
	Strict_32Bit	_reserved_1		:	10;
}MM32_ADC_ADDR14Bits;
typedef struct _MM32_ADC_ADDR15Bits
{
	Strict_32Bit	DATA		:	16;
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	OVERRUN		:	1;
	Strict_32Bit	VAILD		:	1;
	Strict_32Bit	_reserved_1		:	10;
}MM32_ADC_ADDR15Bits;
typedef struct _MM32_ADC_ADSTA_EXTBits
{
	Strict_32Bit	VALID		:	4;
	Strict_32Bit	OVERRUN		:	4;
	Strict_32Bit	_reserved_0		:	8;
	Strict_32Bit	EOSMPIF		:	1;
	Strict_32Bit	EOCIF		:	1;
	Strict_32Bit	JEOSMPIF		:	1;
	Strict_32Bit	JEOCIF		:	1;
	Strict_32Bit	JEOSIF		:	1;
	Strict_32Bit	JBUSY		:	1;
	Strict_32Bit	_reserved_1		:	10;
}MM32_ADC_ADSTA_EXTBits;
typedef struct _MM32_ADC_CHANY0Bits
{
	Strict_32Bit	CHANY_SEL0		:	4;
	Strict_32Bit	CHANY_SEL1		:	4;
	Strict_32Bit	CHANY_SEL2		:	4;
	Strict_32Bit	CHANY_SEL3		:	4;
	Strict_32Bit	CHANY_SEL4		:	4;
	Strict_32Bit	CHANY_SEL5		:	4;
	Strict_32Bit	CHANY_SEL6		:	4;
	Strict_32Bit	CHANY_SEL7		:	4;
}MM32_ADC_CHANY0Bits;
typedef struct _MM32_ADC_CHANY1Bits
{
	Strict_32Bit	CHANY_SEL8		:	4;
	Strict_32Bit	CHANY_SEL9		:	4;
	Strict_32Bit	CHANY_SEL10		:	4;
	Strict_32Bit	CHANY_SEL11		:	4;
	Strict_32Bit	CHANY_SEL12		:	4;
	Strict_32Bit	CHANY_SEL13		:	4;
	Strict_32Bit	CHANY_SEL14		:	4;
	Strict_32Bit	CHANY_SEL15		:	4;
}MM32_ADC_CHANY1Bits;
typedef struct _MM32_ADC_ANY_CFGBits
{
	Strict_32Bit	CHANY_NUM		:	4;
	Strict_32Bit	_reserved_0		:	28;
}MM32_ADC_ANY_CFGBits;
typedef struct _MM32_ADC_ANY_CRBits
{
	Strict_32Bit	CHANY_MDEN		:	1;
	Strict_32Bit	JCEN		:	1;
	Strict_32Bit	JEOSMPIE		:	1;
	Strict_32Bit	JEOCIE		:	1;
	Strict_32Bit	JEOSIE		:	1;
	Strict_32Bit	JAUTO		:	1;
	Strict_32Bit	JADST		:	1;
	Strict_32Bit	JTRGEN		:	1;
	Strict_32Bit	JTRGSEL		:	5;
	Strict_32Bit	JTRGSHIFT		:	3;
	Strict_32Bit	JTRG_EDGE		:	2;
	Strict_32Bit	_reserved_0		:	14;
}MM32_ADC_ANY_CRBits;
typedef struct _MM32_ADC_SMPR1Bits
{
	Strict_32Bit	SAMP0		:	4;
	Strict_32Bit	SAMP1		:	4;
	Strict_32Bit	SAMP2		:	4;
	Strict_32Bit	SAMP3		:	4;
	Strict_32Bit	SAMP4		:	4;
	Strict_32Bit	SAMP5		:	4;
	Strict_32Bit	SAMP6		:	4;
	Strict_32Bit	SAMP7		:	4;
}MM32_ADC_SMPR1Bits;
typedef struct _MM32_ADC_SMPR2Bits
{
	Strict_32Bit	SAMP8		:	4;
	Strict_32Bit	SAMP9		:	4;
	Strict_32Bit	SAMP10		:	4;
	Strict_32Bit	SAMP11		:	4;
	Strict_32Bit	SAMP12		:	4;
	Strict_32Bit	SAMP13		:	4;
	Strict_32Bit	SAMP14		:	4;
	Strict_32Bit	SAMP15		:	4;
}MM32_ADC_SMPR2Bits;
typedef struct _MM32_ADC_JOFR0Bits
{
	Strict_32Bit	JOFFSET		:	12;
	Strict_32Bit	_reserved_0		:	20;
}MM32_ADC_JOFR0Bits;
typedef struct _MM32_ADC_JOFR1Bits
{
	Strict_32Bit	JOFFSET		:	12;
	Strict_32Bit	_reserved_0		:	20;
}MM32_ADC_JOFR1Bits;
typedef struct _MM32_ADC_JOFR2Bits
{
	Strict_32Bit	JOFFSET		:	12;
	Strict_32Bit	_reserved_0		:	20;
}MM32_ADC_JOFR2Bits;
typedef struct _MM32_ADC_JOFR3Bits
{
	Strict_32Bit	JOFFSET		:	12;
	Strict_32Bit	_reserved_0		:	20;
}MM32_ADC_JOFR3Bits;
typedef struct _MM32_ADC_JSQRBits
{
	Strict_32Bit	JSQ0		:	5;
	Strict_32Bit	JSQ1		:	5;
	Strict_32Bit	JSQ2		:	5;
	Strict_32Bit	JSQ3		:	5;
	Strict_32Bit	JNUM		:	2;
	Strict_32Bit	_reserved_0		:	10;
}MM32_ADC_JSQRBits;
typedef struct _MM32_ADC_JADDATABits
{
	Strict_32Bit	JDATA		:	16;
	Strict_32Bit	JCHANNELSEL		:	4;
	Strict_32Bit	_reserved_0		:	1;
	Strict_32Bit	JOVERRUN		:	1;
	Strict_32Bit	JVALID		:	1;
	Strict_32Bit	_reserved_1		:	9;
}MM32_ADC_JADDATABits;
typedef struct _MM32_ADC_JDR0Bits
{
	Strict_32Bit	JDATA		:	16;
	Strict_32Bit	_reserved_0		:	5;
	Strict_32Bit	JOVERRUN		:	1;
	Strict_32Bit	JVALID		:	1;
	Strict_32Bit	_reserved_1		:	9;
}MM32_ADC_JDR0Bits;
typedef struct _MM32_ADC_JDR1Bits
{
	Strict_32Bit	JDATA		:	16;
	Strict_32Bit	_reserved_0		:	5;
	Strict_32Bit	JOVERRUN		:	1;
	Strict_32Bit	JVALID		:	1;
	Strict_32Bit	_reserved_1		:	9;
}MM32_ADC_JDR1Bits;
typedef struct _MM32_ADC_JDR2Bits
{
	Strict_32Bit	JDATA		:	16;
	Strict_32Bit	_reserved_0		:	5;
	Strict_32Bit	JOVERRUN		:	1;
	Strict_32Bit	JVALID		:	1;
	Strict_32Bit	_reserved_1		:	9;
}MM32_ADC_JDR2Bits;
typedef struct _MM32_ADC_JDR3Bits
{
	Strict_32Bit	JDATA		:	16;
	Strict_32Bit	_reserved_0		:	5;
	Strict_32Bit	JOVERRUN		:	1;
	Strict_32Bit	JVALID		:	1;
	Strict_32Bit	_reserved_1		:	9;
}MM32_ADC_JDR3Bits;
typedef union _MM32_ADC_ADDATA
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ADDATABits	B;
}MM32_ADC_ADDATA;
typedef union _MM32_ADC_ADCFG
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ADCFGBits	B;
}MM32_ADC_ADCFG;
typedef union _MM32_ADC_ADCR
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ADCRBits	B;
}MM32_ADC_ADCR;
typedef union _MM32_ADC_ADCHS
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ADCHSBits	B;
}MM32_ADC_ADCHS;
typedef union _MM32_ADC_ADCMPR
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ADCMPRBits	B;
}MM32_ADC_ADCMPR;
typedef union _MM32_ADC_ADSTA
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ADSTABits	B;
}MM32_ADC_ADSTA;
typedef union _MM32_ADC_ADDR0
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ADDR0Bits	B;
}MM32_ADC_ADDR0;
typedef union _MM32_ADC_ADDR1
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ADDR1Bits	B;
}MM32_ADC_ADDR1;
typedef union _MM32_ADC_ADDR2
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ADDR2Bits	B;
}MM32_ADC_ADDR2;
typedef union _MM32_ADC_ADDR3
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ADDR3Bits	B;
}MM32_ADC_ADDR3;
typedef union _MM32_ADC_ADDR4
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ADDR4Bits	B;
}MM32_ADC_ADDR4;
typedef union _MM32_ADC_ADDR5
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ADDR5Bits	B;
}MM32_ADC_ADDR5;
typedef union _MM32_ADC_ADDR6
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ADDR6Bits	B;
}MM32_ADC_ADDR6;
typedef union _MM32_ADC_ADDR7
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ADDR7Bits	B;
}MM32_ADC_ADDR7;
typedef union _MM32_ADC_ADDR8
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ADDR8Bits	B;
}MM32_ADC_ADDR8;
typedef union _MM32_ADC_ADDR9
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ADDR9Bits	B;
}MM32_ADC_ADDR9;
typedef union _MM32_ADC_ADDR10
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ADDR10Bits	B;
}MM32_ADC_ADDR10;
typedef union _MM32_ADC_ADDR11
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ADDR11Bits	B;
}MM32_ADC_ADDR11;
typedef union _MM32_ADC_ADDR12
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ADDR12Bits	B;
}MM32_ADC_ADDR12;
typedef union _MM32_ADC_ADDR13
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ADDR13Bits	B;
}MM32_ADC_ADDR13;
typedef union _MM32_ADC_ADDR14
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ADDR14Bits	B;
}MM32_ADC_ADDR14;
typedef union _MM32_ADC_ADDR15
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ADDR15Bits	B;
}MM32_ADC_ADDR15;
typedef union _MM32_ADC_ADSTA_EXT
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ADSTA_EXTBits	B;
}MM32_ADC_ADSTA_EXT;
typedef union _MM32_ADC_CHANY0
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_CHANY0Bits	B;
}MM32_ADC_CHANY0;
typedef union _MM32_ADC_CHANY1
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_CHANY1Bits	B;
}MM32_ADC_CHANY1;
typedef union _MM32_ADC_ANY_CFG
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ANY_CFGBits	B;
}MM32_ADC_ANY_CFG;
typedef union _MM32_ADC_ANY_CR
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_ANY_CRBits	B;
}MM32_ADC_ANY_CR;
typedef union _MM32_ADC_SMPR1
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_SMPR1Bits	B;
}MM32_ADC_SMPR1;
typedef union _MM32_ADC_SMPR2
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_SMPR2Bits	B;
}MM32_ADC_SMPR2;
typedef union _MM32_ADC_JOFR0
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_JOFR0Bits	B;
}MM32_ADC_JOFR0;
typedef union _MM32_ADC_JOFR1
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_JOFR1Bits	B;
}MM32_ADC_JOFR1;
typedef union _MM32_ADC_JOFR2
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_JOFR2Bits	B;
}MM32_ADC_JOFR2;
typedef union _MM32_ADC_JOFR3
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_JOFR3Bits	B;
}MM32_ADC_JOFR3;
typedef union _MM32_ADC_JSQR
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_JSQRBits	B;
}MM32_ADC_JSQR;
typedef union _MM32_ADC_JADDATA
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_JADDATABits	B;
}MM32_ADC_JADDATA;
typedef union _MM32_ADC_JDR0
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_JDR0Bits	B;
}MM32_ADC_JDR0;
typedef union _MM32_ADC_JDR1
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_JDR1Bits	B;
}MM32_ADC_JDR1;
typedef union _MM32_ADC_JDR2
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_JDR2Bits	B;
}MM32_ADC_JDR2;
typedef union _MM32_ADC_JDR3
{
	uint32_t	U;
	int32_t	I;
	MM32_ADC_JDR3Bits	B;
}MM32_ADC_JDR3;
typedef struct _MM32_ADC
{
	MM32_ADC_ADDATA		ADDATA;
	MM32_ADC_ADCFG		ADCFG;
	MM32_ADC_ADCR		ADCR;
	MM32_ADC_ADCHS		ADCHS;
	MM32_ADC_ADCMPR		ADCMPR;
	MM32_ADC_ADSTA		ADSTA;
	MM32_ADC_ADDR0		ADDR0;
	MM32_ADC_ADDR1		ADDR1;
	MM32_ADC_ADDR2		ADDR2;
	MM32_ADC_ADDR3		ADDR3;
	MM32_ADC_ADDR4		ADDR4;
	MM32_ADC_ADDR5		ADDR5;
	MM32_ADC_ADDR6		ADDR6;
	MM32_ADC_ADDR7		ADDR7;
	MM32_ADC_ADDR8		ADDR8;
	MM32_ADC_ADDR9		ADDR9;
	MM32_ADC_ADDR10		ADDR10;
	MM32_ADC_ADDR11		ADDR11;
	MM32_ADC_ADDR12		ADDR12;
	MM32_ADC_ADDR13		ADDR13;
	MM32_ADC_ADDR14		ADDR14;
	MM32_ADC_ADDR15		ADDR15;
	MM32_ADC_ADSTA_EXT		_EXT;
	MM32_ADC_CHANY0		CHANY0;
	MM32_ADC_CHANY1		CHANY1;
	MM32_ADC_ANY_CFG		_CFG;
	MM32_ADC_ANY_CR		_CR;
	unsigned char		_reserved_0;
	unsigned char		_reserved_1;
	unsigned char		_reserved_2;
	unsigned char		_reserved_3;
	MM32_ADC_SMPR1		SMPR1;
	MM32_ADC_SMPR2		SMPR2;
	unsigned char		_reserved_4;
	unsigned char		_reserved_5;
	unsigned char		_reserved_6;
	unsigned char		_reserved_7;
	MM32_ADC_JOFR0		JOFR0;
	MM32_ADC_JOFR1		JOFR1;
	MM32_ADC_JOFR2		JOFR2;
	MM32_ADC_JOFR3		JOFR3;
	MM32_ADC_JSQR		JSQR;
	MM32_ADC_JADDATA		JADDATA;
	unsigned char		_reserved_8;
	unsigned char		_reserved_9;
	unsigned char		_reserved_10;
	unsigned char		_reserved_11;
	unsigned char		_reserved_12;
	unsigned char		_reserved_13;
	unsigned char		_reserved_14;
	unsigned char		_reserved_15;
	unsigned char		_reserved_16;
	unsigned char		_reserved_17;
	unsigned char		_reserved_18;
	unsigned char		_reserved_19;
	unsigned char		_reserved_20;
	unsigned char		_reserved_21;
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
	MM32_ADC_JDR0		JDR0;
	MM32_ADC_JDR1		JDR1;
	MM32_ADC_JDR2		JDR2;
	MM32_ADC_JDR3		JDR3;
}MM32_ADC;
#endif