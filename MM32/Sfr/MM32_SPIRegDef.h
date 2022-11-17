/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-31 10:33:40
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:07:48
 * @FilePath: \CODE\MM32\Sfr\MM32_SPIRegDef.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_SPIREGDEF_H_
#define _MM32_SPIREGDEF_H_

#include "MM32_RegTypedef.h"

typedef struct _MM32_SPI_TXREGBits
{
	Strict_32Bit	TXREG		:	32;
}MM32_SPI_TXREGBits;
typedef struct _MM32_SPI_RXREGBits
{
	Strict_32Bit	RXREG		:	32;
}MM32_SPI_RXREGBits;
typedef struct _MM32_SPI_CSTATBits
{
	Strict_32Bit	TXEPT		:	1;
	Strict_32Bit	RXAVL		:	1;
	Strict_32Bit	TXFULL		:	1;
	Strict_32Bit	RXAVL_4BYTE		:	1;
	Strict_32Bit	TXFADDR		:	4;
	Strict_32Bit	RXFADDR		:	4;
	Strict_32Bit	BUSY		:	1;
	Strict_32Bit	CHSIDE		:	1;
	Strict_32Bit	_reserved_0		:	18;
}MM32_SPI_CSTATBits;
typedef struct _MM32_SPI_INTSTATBits
{
	Strict_32Bit	TX_INTF		:	1;
	Strict_32Bit	RX_INTF		:	1;
	Strict_32Bit	UNDERRUN_INTF		:	1;
	Strict_32Bit	RXOERR_INTF		:	1;
	Strict_32Bit	RXMATCH_INTF		:	1;
	Strict_32Bit	RXFULL_INTF		:	1;
	Strict_32Bit	TXEPT_INTF		:	1;
	Strict_32Bit	FRE_INTF		:	1;
	Strict_32Bit	_reserved_0		:	24;
}MM32_SPI_INTSTATBits;
typedef struct _MM32_SPI_INTENBits
{
	Strict_32Bit	TX_IEN		:	1;
	Strict_32Bit	RX_IEN		:	1;
	Strict_32Bit	UNDERRUN_IEN		:	1;
	Strict_32Bit	RXOERR_IEN		:	1;
	Strict_32Bit	RXMATCH_IEN		:	1;
	Strict_32Bit	RXFULL_IEN		:	1;
	Strict_32Bit	TXEPT_IEN		:	1;
	Strict_32Bit	FRE_IEN		:	1;
	Strict_32Bit	_reserved_0		:	24;
}MM32_SPI_INTENBits;
typedef struct _MM32_SPI_INTCLRBits
{
	Strict_32Bit	TX_ICLR		:	1;
	Strict_32Bit	RX_ICLR		:	1;
	Strict_32Bit	UNDERRUN_ICLR		:	1;
	Strict_32Bit	RXOERR_ICLR		:	1;
	Strict_32Bit	RXMATCH_ICLR		:	1;
	Strict_32Bit	RXFULL_ICLR		:	1;
	Strict_32Bit	TXEPT_ICLR		:	1;
	Strict_32Bit	FRE_ICLR		:	1;
	Strict_32Bit	_reserved_0		:	24;
}MM32_SPI_INTCLRBits;
typedef struct _MM32_SPI_GCTLBits
{
	Strict_32Bit	SPIEN		:	1;
	Strict_32Bit	INTEN		:	1;
	Strict_32Bit	MODE		:	1;
	Strict_32Bit	TXEN		:	1;
	Strict_32Bit	RXEN		:	1;
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	DMAMODE		:	1;
	Strict_32Bit	NSS		:	1;
	Strict_32Bit	DW8_32		:	1;
	Strict_32Bit	_reserved_1		:	1;
	Strict_32Bit	PAD_SEL		:	5;
	Strict_32Bit	_reserved_2		:	14;
}MM32_SPI_GCTLBits;
typedef struct _MM32_SPI_CCTLBits
{
	Strict_32Bit	CPHA		:	1;
	Strict_32Bit	CPOL		:	1;
	Strict_32Bit	LSBFE		:	1;
	Strict_32Bit	SPILEN		:	1;
	Strict_32Bit	RXEDGE		:	1;
	Strict_32Bit	TXEDGE		:	1;
	Strict_32Bit	CPHASEL		:	1;
	Strict_32Bit	_reserved_0		:	25;
}MM32_SPI_CCTLBits;
typedef struct _MM32_SPI_SPBRGBits
{
	Strict_32Bit	SPBRG		:	16;
	Strict_32Bit	_reserved_0		:	16;
}MM32_SPI_SPBRGBits;
typedef struct _MM32_SPI_RXDNRBits
{
	Strict_32Bit	RXDNR		:	16;
	Strict_32Bit	_reserved_0		:	16;
}MM32_SPI_RXDNRBits;
typedef struct _MM32_SPI_NSSRBits
{
	Strict_32Bit	NSS		:	1;
	Strict_32Bit	_reserved_0		:	31;
}MM32_SPI_NSSRBits;
typedef struct _MM32_SPI_EXTCTLBits
{
	Strict_32Bit	EXTLEN		:	5;
	Strict_32Bit	_reserved_0		:	27;
}MM32_SPI_EXTCTLBits;
typedef struct _MM32_SPI_I2SCFGRBits
{
	Strict_32Bit	CHLEN		:	1;
	Strict_32Bit	DATLEN		:	2;
	Strict_32Bit	_reserved_0		:	1;
	Strict_32Bit	I2SSTD		:	2;
	Strict_32Bit	PCMSYN		:	1;
	Strict_32Bit	_reserved_1		:	3;
	Strict_32Bit	SPI_I2S		:	1;
	Strict_32Bit	MCKOE		:	1;
	Strict_32Bit	_reserved_2		:	4;
	Strict_32Bit	I2SDIV		:	9;
	Strict_32Bit	_reserved_3		:	7;
}MM32_SPI_I2SCFGRBits;
typedef union _MM32_SPI_TXREG
{
	uint32_t	U;
	int32_t	I;
	MM32_SPI_TXREGBits	B;
}MM32_SPI_TXREG;
typedef union _MM32_SPI_RXREG
{
	uint32_t	U;
	int32_t	I;
	MM32_SPI_RXREGBits	B;
}MM32_SPI_RXREG;
typedef union _MM32_SPI_CSTAT
{
	uint32_t	U;
	int32_t	I;
	MM32_SPI_CSTATBits	B;
}MM32_SPI_CSTAT;
typedef union _MM32_SPI_INTSTAT
{
	uint32_t	U;
	int32_t	I;
	MM32_SPI_INTSTATBits	B;
}MM32_SPI_INTSTAT;
typedef union _MM32_SPI_INTEN
{
	uint32_t	U;
	int32_t	I;
	MM32_SPI_INTENBits	B;
}MM32_SPI_INTEN;
typedef union _MM32_SPI_INTCLR
{
	uint32_t	U;
	int32_t	I;
	MM32_SPI_INTCLRBits	B;
}MM32_SPI_INTCLR;
typedef union _MM32_SPI_GCTL
{
	uint32_t	U;
	int32_t	I;
	MM32_SPI_GCTLBits	B;
}MM32_SPI_GCTL;
typedef union _MM32_SPI_CCTL
{
	uint32_t	U;
	int32_t	I;
	MM32_SPI_CCTLBits	B;
}MM32_SPI_CCTL;
typedef union _MM32_SPI_SPBRG
{
	uint32_t	U;
	int32_t	I;
	MM32_SPI_SPBRGBits	B;
}MM32_SPI_SPBRG;
typedef union _MM32_SPI_RXDNR
{
	uint32_t	U;
	int32_t	I;
	MM32_SPI_RXDNRBits	B;
}MM32_SPI_RXDNR;
typedef union _MM32_SPI_NSSR
{
	uint32_t	U;
	int32_t	I;
	MM32_SPI_NSSRBits	B;
}MM32_SPI_NSSR;
typedef union _MM32_SPI_EXTCTL
{
	uint32_t	U;
	int32_t	I;
	MM32_SPI_EXTCTLBits	B;
}MM32_SPI_EXTCTL;
typedef union _MM32_SPI_I2SCFGR
{
	uint32_t	U;
	int32_t	I;
	MM32_SPI_I2SCFGRBits	B;
}MM32_SPI_I2SCFGR;
typedef struct _MM32_SPI
{
	MM32_SPI_TXREG		TXREG;
	MM32_SPI_RXREG		RXREG;
	MM32_SPI_CSTAT		CSTAT;
	MM32_SPI_INTSTAT		INTSTAT;
	MM32_SPI_INTEN		INTEN;
	MM32_SPI_INTCLR		INTCLR;
	MM32_SPI_GCTL		GCTL;
	MM32_SPI_CCTL		CCTL;
	MM32_SPI_SPBRG		SPBRG;
	MM32_SPI_RXDNR		RXDNR;
	MM32_SPI_NSSR		NSSR;
	MM32_SPI_EXTCTL		EXTCTL;
	MM32_SPI_I2SCFGR		I2SCFGR;
}MM32_SPI;
#endif