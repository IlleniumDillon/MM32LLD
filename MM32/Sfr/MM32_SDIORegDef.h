#ifndef _MM32_SDIOREGDEF_H_
#define _MM32_SDIOREGDEF_H_

#include "MM32_RegTypedef.h"

typedef struct _MM32_SDIO_CTRLBits
{
	Strict_32Bit	OPMSEL		:	1;
	Strict_32Bit	SELSM		:	1;
	Strict_32Bit	OUTM		:	1;
	Strict_32Bit	CLKSP		:	3;
	Strict_32Bit	SELPTSM		:	1;
	Strict_32Bit	DATWT		:	1;
	Strict_32Bit	MDEN		:	1;
	Strict_32Bit	INTEN		:	1;
	Strict_32Bit	RDWTEN		:	1;
	Strict_32Bit	_reserved_0		:	21;
}MM32_SDIO_CTRLBits;
typedef struct _MM32_SDIO_IOBits
{
	Strict_32Bit	AUTODATTR		:	1;
	Strict_32Bit	TRANSFDIR		:	1;
	Strict_32Bit	AUTOTR		:	1;
	Strict_32Bit	RESPCMDSEL		:	1;
	Strict_32Bit	CID_CSDRD		:	1;
	Strict_32Bit	PCLKG		:	1;
	Strict_32Bit	ENRRESP		:	1;
	Strict_32Bit	AUTOCLKG		:	1;
	Strict_32Bit	CMDCH		:	1;
	Strict_32Bit	CMDAF		:	1;
	Strict_32Bit	_reserved_0		:	22;
}MM32_SDIO_IOBits;
typedef struct _MM32_SDIO_BYTECNTBits
{
	Strict_32Bit	CNT		:	16;
	Strict_32Bit	_reserved_0		:	16;
}MM32_SDIO_BYTECNTBits;
typedef struct _MM32_SDIO_TRBLOCKCNTBits
{
	Strict_32Bit	CNT		:	16;
	Strict_32Bit	_reserved_0		:	16;
}MM32_SDIO_TRBLOCKCNTBits;
typedef struct _MM32_SDIO_CRCCTLBits
{
	Strict_32Bit	DAT_CRCE		:	1;
	Strict_32Bit	CMD_CRCE		:	1;
	Strict_32Bit	DAT_CRCS		:	2;
	Strict_32Bit	ENRDMB		:	1;
	Strict_32Bit	ENCHK		:	1;
	Strict_32Bit	DAT_CRCEN		:	1;
	Strict_32Bit	CMD_CRCEN		:	1;
	Strict_32Bit	_reserved_0		:	24;
}MM32_SDIO_CRCCTLBits;
typedef struct _MM32_SDIO_CMDCRCBits
{
	Strict_32Bit	CMD_CRCV		:	7;
	Strict_32Bit	_reserved_0		:	25;
}MM32_SDIO_CMDCRCBits;
typedef struct _MM32_SDIO_DATCRCBits
{
	Strict_32Bit	DAT_CRC		:	16;
	Strict_32Bit	_reserved_0		:	16;
}MM32_SDIO_DATCRCBits;
typedef struct _MM32_SDIO_PORTBits
{
	Strict_32Bit	NTCR		:	4;
	Strict_32Bit	AUTONTEN		:	1;
	Strict_32Bit	PDATS		:	1;
	Strict_32Bit	PCMDS		:	1;
	Strict_32Bit	PCLKS		:	1;
	Strict_32Bit	_reserved_0		:	24;
}MM32_SDIO_PORTBits;
typedef struct _MM32_SDIO_INTENBits
{
	Strict_32Bit	CMDDINTEN		:	1;
	Strict_32Bit	DATDINTEN		:	1;
	Strict_32Bit	DATEINTEN		:	1;
	Strict_32Bit	CMDEINTEN		:	1;
	Strict_32Bit	MBDINTEN		:	1;
	Strict_32Bit	MBTINTEN		:	1;
	Strict_32Bit	CRTINTEN		:	1;
	Strict_32Bit	CRCINTEN		:	1;
	Strict_32Bit	D1INTEN		:	1;
	Strict_32Bit	_reserved_0		:	23;
}MM32_SDIO_INTENBits;
typedef struct _MM32_SDIO_INTSTABits
{
	Strict_32Bit	CMDDMC		:	1;
	Strict_32Bit	DATDMC		:	1;
	Strict_32Bit	DATEMC		:	1;
	Strict_32Bit	CMDEMC		:	1;
	Strict_32Bit	MBDMC		:	1;
	Strict_32Bit	MBTMC		:	1;
	Strict_32Bit	CRNTMC		:	1;
	Strict_32Bit	CRCEMC		:	1;
	Strict_32Bit	D1MC		:	1;
	Strict_32Bit	_reserved_0		:	23;
}MM32_SDIO_INTSTABits;
typedef struct _MM32_SDIO_CARDSELBits
{
	Strict_32Bit	TSCALE		:	6;
	Strict_32Bit	ENPCLK		:	1;
	Strict_32Bit	CTREN		:	1;
	Strict_32Bit	_reserved_0		:	24;
}MM32_SDIO_CARDSELBits;
typedef struct _MM32_SDIO_SIGBits
{
	Strict_32Bit	PDAT0S		:	1;
	Strict_32Bit	PDAT1S		:	1;
	Strict_32Bit	PDAT2S		:	1;
	Strict_32Bit	PDAT3S		:	1;
	Strict_32Bit	CRC_STATUS		:	3;
	Strict_32Bit	PCMDS		:	1;
	Strict_32Bit	_reserved_0		:	24;
}MM32_SDIO_SIGBits;
typedef struct _MM32_SDIO_IOMBCTLBits
{
	Strict_32Bit	SPMBDTR		:	1;
	Strict_32Bit	SMBDTD		:	1;
	Strict_32Bit	PAUTOTR		:	1;
	Strict_32Bit	PCLKP		:	1;
	Strict_32Bit	BTSSEL		:	2;
	Strict_32Bit	NTSSEL		:	2;
	Strict_32Bit	_reserved_0		:	24;
}MM32_SDIO_IOMBCTLBits;
typedef struct _MM32_SDIO_BLOCKCNTBits
{
	Strict_32Bit	BCNT		:	16;
	Strict_32Bit	_reserved_0		:	16;
}MM32_SDIO_BLOCKCNTBits;
typedef struct _MM32_SDIO_TIMEOUTCNTBits
{
	Strict_32Bit	DTCNT		:	8;
	Strict_32Bit	_reserved_0		:	24;
}MM32_SDIO_TIMEOUTCNTBits;
typedef struct _MM32_SDIO_CMDBUF0Bits
{
	Strict_32Bit	DAT		:	8;
	Strict_32Bit	_reserved_0		:	24;
}MM32_SDIO_CMDBUF0Bits;
typedef struct _MM32_SDIO_CMDBUF1Bits
{
    Strict_32Bit	DAT		:	8;
    Strict_32Bit	_reserved_0		:	24;
}MM32_SDIO_CMDBUF1Bits;
typedef struct _MM32_SDIO_CMDBUF2Bits
{
    Strict_32Bit	DAT		:	8;
    Strict_32Bit	_reserved_0		:	24;
}MM32_SDIO_CMDBUF2Bits;
typedef struct _MM32_SDIO_CMDBUF3Bits
{
    Strict_32Bit	DAT		:	8;
    Strict_32Bit	_reserved_0		:	24;
}MM32_SDIO_CMDBUF3Bits;
typedef struct _MM32_SDIO_CMDBUF4Bits
{
    Strict_32Bit	DAT		:	8;
    Strict_32Bit	_reserved_0		:	24;
}MM32_SDIO_CMDBUF4Bits;
typedef struct _MM32_SDIO_CMDBUF5Bits
{
    Strict_32Bit	DAT		:	8;
    Strict_32Bit	_reserved_0		:	24;
}MM32_SDIO_CMDBUF5Bits;
typedef struct _MM32_SDIO_CMDBUF6Bits
{
    Strict_32Bit	DAT		:	8;
    Strict_32Bit	_reserved_0		:	24;
}MM32_SDIO_CMDBUF6Bits;
typedef struct _MM32_SDIO_CMDBUF7Bits
{
    Strict_32Bit	DAT		:	8;
    Strict_32Bit	_reserved_0		:	24;
}MM32_SDIO_CMDBUF7Bits;
typedef struct _MM32_SDIO_CMDBUF8Bits
{
    Strict_32Bit	DAT		:	8;
    Strict_32Bit	_reserved_0		:	24;
}MM32_SDIO_CMDBUF8Bits;
typedef struct _MM32_SDIO_CMDBUF9Bits
{
    Strict_32Bit	DAT		:	8;
    Strict_32Bit	_reserved_0		:	24;
}MM32_SDIO_CMDBUF9Bits;
typedef struct _MM32_SDIO_CMDBUF10Bits
{
    Strict_32Bit	DAT		:	8;
    Strict_32Bit	_reserved_0		:	24;
}MM32_SDIO_CMDBUF10Bits;
typedef struct _MM32_SDIO_CMDBUF11Bits
{
    Strict_32Bit	DAT		:	8;
    Strict_32Bit	_reserved_0		:	24;
}MM32_SDIO_CMDBUF11Bits;
typedef struct _MM32_SDIO_CMDBUF12Bits
{
    Strict_32Bit	DAT		:	8;
    Strict_32Bit	_reserved_0		:	24;
}MM32_SDIO_CMDBUF12Bits;
typedef struct _MM32_SDIO_CMDBUF13Bits
{
    Strict_32Bit	DAT		:	8;
    Strict_32Bit	_reserved_0		:	24;
}MM32_SDIO_CMDBUF13Bits;
typedef struct _MM32_SDIO_CMDBUF14Bits
{
    Strict_32Bit	DAT		:	8;
    Strict_32Bit	_reserved_0		:	24;
}MM32_SDIO_CMDBUF14Bits;
typedef struct _MM32_SDIO_CMDBUF15Bits
{
    Strict_32Bit	DAT		:	8;
    Strict_32Bit	_reserved_0		:	24;
}MM32_SDIO_CMDBUF15Bits;
typedef struct _MM32_SDIO_BUFCTLBits
{
	Strict_32Bit	DBF		:	1;
	Strict_32Bit	DBE		:	1;
	Strict_32Bit	DBML		:	8;
	Strict_32Bit	DMAHEN		:	1;
	Strict_32Bit	SBAD		:	1;
	Strict_32Bit	DFIFOSM		:	1;
	Strict_32Bit	_reserved_0		:	1;
	Strict_32Bit	DRM		:	1;
	Strict_32Bit	DBFEN		:	1;
	Strict_32Bit	_reserved_1		:	16;
}MM32_SDIO_BUFCTLBits;
typedef union _MM32_SDIO_CTRL
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_CTRLBits	B;
}MM32_SDIO_CTRL;
typedef union _MM32_SDIO_IO
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_IOBits	B;
}MM32_SDIO_IO;
typedef union _MM32_SDIO_BYTECNT
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_BYTECNTBits	B;
}MM32_SDIO_BYTECNT;
typedef union _MM32_SDIO_TRBLOCKCNT
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_TRBLOCKCNTBits	B;
}MM32_SDIO_TRBLOCKCNT;
typedef union _MM32_SDIO_CRCCTL
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_CRCCTLBits	B;
}MM32_SDIO_CRCCTL;
typedef union _MM32_SDIO_CMDCRC
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_CMDCRCBits	B;
}MM32_SDIO_CMDCRC;
typedef union _MM32_SDIO_DATCRC
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_DATCRCBits	B;
}MM32_SDIO_DATCRC;
typedef union _MM32_SDIO_PORT
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_PORTBits	B;
}MM32_SDIO_PORT;
typedef union _MM32_SDIO_INTEN
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_INTENBits	B;
}MM32_SDIO_INTEN;
typedef union _MM32_SDIO_INTSTA
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_INTSTABits	B;
}MM32_SDIO_INTSTA;
typedef union _MM32_SDIO_CARDSEL
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_CARDSELBits	B;
}MM32_SDIO_CARDSEL;
typedef union _MM32_SDIO_SIG
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_SIGBits	B;
}MM32_SDIO_SIG;
typedef union _MM32_SDIO_IOMBCTL
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_IOMBCTLBits	B;
}MM32_SDIO_IOMBCTL;
typedef union _MM32_SDIO_BLOCKCNT
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_BLOCKCNTBits	B;
}MM32_SDIO_BLOCKCNT;
typedef union _MM32_SDIO_TIMEOUTCNT
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_TIMEOUTCNTBits	B;
}MM32_SDIO_TIMEOUTCNT;
typedef union _MM32_SDIO_CMDBUF0
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_CMDBUF0Bits	B;
}MM32_SDIO_CMDBUF0;
typedef union _MM32_SDIO_CMDBUF1
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_CMDBUF1Bits	B;
}MM32_SDIO_CMDBUF1;
typedef union _MM32_SDIO_CMDBUF2
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_CMDBUF2Bits	B;
}MM32_SDIO_CMDBUF2;
typedef union _MM32_SDIO_CMDBUF3
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_CMDBUF3Bits	B;
}MM32_SDIO_CMDBUF3;
typedef union _MM32_SDIO_CMDBUF4
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_CMDBUF4Bits	B;
}MM32_SDIO_CMDBUF4;
typedef union _MM32_SDIO_CMDBUF5
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_CMDBUF5Bits	B;
}MM32_SDIO_CMDBUF5;
typedef union _MM32_SDIO_CMDBUF6
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_CMDBUF6Bits	B;
}MM32_SDIO_CMDBUF6;
typedef union _MM32_SDIO_CMDBUF7
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_CMDBUF7Bits	B;
}MM32_SDIO_CMDBUF7;
typedef union _MM32_SDIO_CMDBUF8
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_CMDBUF8Bits	B;
}MM32_SDIO_CMDBUF8;
typedef union _MM32_SDIO_CMDBUF9
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_CMDBUF9Bits	B;
}MM32_SDIO_CMDBUF9;
typedef union _MM32_SDIO_CMDBUF10
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_CMDBUF10Bits	B;
}MM32_SDIO_CMDBUF10;
typedef union _MM32_SDIO_CMDBUF11
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_CMDBUF11Bits	B;
}MM32_SDIO_CMDBUF11;
typedef union _MM32_SDIO_CMDBUF12
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_CMDBUF12Bits	B;
}MM32_SDIO_CMDBUF12;
typedef union _MM32_SDIO_CMDBUF13
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_CMDBUF13Bits	B;
}MM32_SDIO_CMDBUF13;
typedef union _MM32_SDIO_CMDBUF14
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_CMDBUF14Bits	B;
}MM32_SDIO_CMDBUF14;
typedef union _MM32_SDIO_CMDBUF15
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_CMDBUF15Bits	B;
}MM32_SDIO_CMDBUF15;
typedef union _MM32_SDIO_BUFCTL
{
	uint32_t	U;
	int32_t	I;
	MM32_SDIO_BUFCTLBits	B;
}MM32_SDIO_BUFCTL;
typedef struct _MM32_SDIO
{
	MM32_SDIO_CTRL		CTRL;
	MM32_SDIO_IO		IO;
	MM32_SDIO_BYTECNT		BYTECNT;
	MM32_SDIO_TRBLOCKCNT		TRBLOCKCNT;
	MM32_SDIO_CRCCTL		CRCCTL;
	MM32_SDIO_CMDCRC		CMDCRC;
	MM32_SDIO_DATCRC		DATCRC;
	unsigned char		_reserved_0;
	unsigned char		_reserved_1;
	unsigned char		_reserved_2;
	unsigned char		_reserved_3;
	MM32_SDIO_PORT		PORT;
	MM32_SDIO_INTEN		INTEN;
	MM32_SDIO_INTSTA		INTSTA;
	MM32_SDIO_CARDSEL		CARDSEL;
	MM32_SDIO_SIG		SIG;
	MM32_SDIO_IOMBCTL		IOMBCTL;
	MM32_SDIO_BLOCKCNT		BLOCKCNT;
	MM32_SDIO_TIMEOUTCNT		TIMEOUTCNT;
	MM32_SDIO_CMDBUF0		CMDBUF0;
	MM32_SDIO_CMDBUF1		CMDBUF1;
	MM32_SDIO_CMDBUF2		CMDBUF2;
	MM32_SDIO_CMDBUF3		CMDBUF3;
	MM32_SDIO_CMDBUF4		CMDBUF4;
	MM32_SDIO_CMDBUF5		CMDBUF5;
	MM32_SDIO_CMDBUF6		CMDBUF6;
	MM32_SDIO_CMDBUF7		CMDBUF7;
	MM32_SDIO_CMDBUF8		CMDBUF8;
	MM32_SDIO_CMDBUF9		CMDBUF9;
	MM32_SDIO_CMDBUF10		CMDBUF10;
	MM32_SDIO_CMDBUF11		CMDBUF11;
	MM32_SDIO_CMDBUF12		CMDBUF12;
	MM32_SDIO_CMDBUF13		CMDBUF13;
	MM32_SDIO_CMDBUF14		CMDBUF14;
	MM32_SDIO_CMDBUF15		CMDBUF15;
	MM32_SDIO_BUFCTL		BUFCTL;
}MM32_SDIO;
#endif
