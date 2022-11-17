/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-31 10:33:40
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:08:03
 * @FilePath: \CODE\MM32\Sfr\MM32_UARTRegDef.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_UARTREGDEF_H_
#define _MM32_UARTREGDEF_H_

#include "MM32_RegTypedef.h"

typedef struct _MM32_UART_TDRBits
{
	Strict_32Bit	TXREG		:	9;
	Strict_32Bit	_reserved_0		:	23;
}MM32_UART_TDRBits;
typedef struct _MM32_UART_RDRBits
{
	Strict_32Bit	RXREG		:	9;
	Strict_32Bit	_reserved_0		:	23;
}MM32_UART_RDRBits;
typedef struct _MM32_UART_CSRBits
{
	Strict_32Bit	TXC		:	1;
	Strict_32Bit	RXAVL		:	1;
	Strict_32Bit	TXFULL		:	1;
	Strict_32Bit	TXEPT		:	1;
	Strict_32Bit	_reserved_0		:	28;
}MM32_UART_CSRBits;
typedef struct _MM32_UART_ISRBits
{
	Strict_32Bit	TX_INTF		:	1;
	Strict_32Bit	RX_INTF		:	1;
	Strict_32Bit	TXC_INTF		:	1;
	Strict_32Bit	RXOERR_INTF		:	1;
	Strict_32Bit	RXPERR_INTF		:	1;
	Strict_32Bit	RXFERR_INTF		:	1;
	Strict_32Bit	RXBRK_INTF		:	1;
	Strict_32Bit	TXBRK_INTF		:	1;
	Strict_32Bit	RXB8_INTF		:	1;
	Strict_32Bit	RXIDLE_INTF		:	1;
	Strict_32Bit	ABREND_INTF		:	1;
	Strict_32Bit	ABRERR_INTF		:	1;
	Strict_32Bit	_reserved_0		:	20;
}MM32_UART_ISRBits;
typedef struct _MM32_UART_IERBits
{
	Strict_32Bit	TX_IEN		:	1;
	Strict_32Bit	RX_IEN		:	1;
	Strict_32Bit	TXC_IEN		:	1;
	Strict_32Bit	RXOERR_IEN		:	1;
	Strict_32Bit	RXPERR_IEN		:	1;
	Strict_32Bit	RXFERR_IEN		:	1;
	Strict_32Bit	RXBRK_IEN		:	1;
	Strict_32Bit	TXBRK_IEN		:	1;
	Strict_32Bit	RXB8_IEN		:	1;
	Strict_32Bit	RXIDLE_IEN		:	1;
	Strict_32Bit	ABREND_IEN		:	1;
	Strict_32Bit	ABRERR_IEN		:	1;
	Strict_32Bit	_reserved_0		:	20;
}MM32_UART_IERBits;
typedef struct _MM32_UART_ICRBits
{
	Strict_32Bit	TX_ICLR		:	1;
	Strict_32Bit	RX_ICLR		:	1;
	Strict_32Bit	TXC_ICLR		:	1;
	Strict_32Bit	RXOERR_ICLR		:	1;
	Strict_32Bit	RXPERR_ICLR		:	1;
	Strict_32Bit	RXFERR_ICLR		:	1;
	Strict_32Bit	RXBRK_ICLR		:	1;
	Strict_32Bit	TXBRK_ICLR		:	1;
	Strict_32Bit	RXB8_ICLR		:	1;
	Strict_32Bit	RXIDLE_ICLR		:	1;
	Strict_32Bit	ABREND_ICLR		:	1;
	Strict_32Bit	ABRERR_ICLR		:	1;
	Strict_32Bit	_reserved_0		:	20;
}MM32_UART_ICRBits;
typedef struct _MM32_UART_GCRBits
{
	Strict_32Bit	UARTEN		:	1;
	Strict_32Bit	DMAMODE		:	1;
	Strict_32Bit	AUTOFLOWEN		:	1;
	Strict_32Bit	RXEN		:	1;
	Strict_32Bit	TXEN		:	1;
	Strict_32Bit	_reserved_0		:	2;
	Strict_32Bit	SELB8		:	1;
	Strict_32Bit	SWAP		:	1;
	Strict_32Bit	RXTOG		:	1;
	Strict_32Bit	TXTOG		:	1;
	Strict_32Bit	_reserved_1		:	21;
}MM32_UART_GCRBits;
typedef struct _MM32_UART_CCRBits
{
	Strict_32Bit	PEN		:	1;
	Strict_32Bit	PSEL		:	1;
	Strict_32Bit	SPB0		:	1;
	Strict_32Bit	BRK		:	1;
	Strict_32Bit	CHAR		:	2;
	Strict_32Bit	SPB1		:	1;
	Strict_32Bit	B8RXD		:	1;
	Strict_32Bit	B8TXD		:	1;
	Strict_32Bit	B8POL		:	1;
	Strict_32Bit	B8TOG		:	1;
	Strict_32Bit	B8EN		:	1;
	Strict_32Bit	RWU		:	1;
	Strict_32Bit	WAKE		:	1;
	Strict_32Bit	LIN		:	1;
	Strict_32Bit	_reserved_0		:	17;
}MM32_UART_CCRBits;
typedef struct _MM32_UART_BRRBits
{
	Strict_32Bit	DIV_Mantissa		:	16;
	Strict_32Bit	_reserved_0		:	16;
}MM32_UART_BRRBits;
typedef struct _MM32_UART_FRABits
{
	Strict_32Bit	DIV_Fraction		:	4;
	Strict_32Bit	_reserved_0		:	28;
}MM32_UART_FRABits;
typedef struct _MM32_UART_RXADDRBits
{
	Strict_32Bit	RXADDR		:	8;
	Strict_32Bit	_reserved_0		:	24;
}MM32_UART_RXADDRBits;
typedef struct _MM32_UART_RXMASKBits
{
	Strict_32Bit	RXMASK		:	8;
	Strict_32Bit	_reserved_0		:	24;
}MM32_UART_RXMASKBits;
typedef struct _MM32_UART_SCRBits
{
	Strict_32Bit	SCEN		:	1;
	Strict_32Bit	SCAEN		:	1;
	Strict_32Bit	NACK		:	1;
	Strict_32Bit	_reserved_0		:	1;
	Strict_32Bit	SCFCNT		:	8;
	Strict_32Bit	HDSEL		:	1;
	Strict_32Bit	_reserved_1		:	19;
}MM32_UART_SCRBits;
typedef struct _MM32_UART_IDLRBits
{
	Strict_32Bit	IDLR		:	16;
	Strict_32Bit	_reserved_0		:	16;
}MM32_UART_IDLRBits;
typedef struct _MM32_UART_ABRCRBits
{
	Strict_32Bit	Abren		:	1;
	Strict_32Bit	Abr_bitcnt		:	2;
	Strict_32Bit	Former_edge		:	1;
	Strict_32Bit	Latter_edge		:	1;
	Strict_32Bit	_reserved_0		:	27;
}MM32_UART_ABRCRBits;
typedef struct _MM32_UART_IRDABits
{
	Strict_32Bit	Siren		:	1;
	Strict_32Bit	Sirlp		:	1;
	Strict_32Bit	_reserved_0		:	6;
	Strict_32Bit	PSC_REG		:	8;
	Strict_32Bit	_reserved_1		:	16;
}MM32_UART_IRDABits;
typedef union _MM32_UART_TDR
{
	uint32_t	U;
	int32_t	I;
	MM32_UART_TDRBits	B;
}MM32_UART_TDR;
typedef union _MM32_UART_RDR
{
	uint32_t	U;
	int32_t	I;
	MM32_UART_RDRBits	B;
}MM32_UART_RDR;
typedef union _MM32_UART_CSR
{
	uint32_t	U;
	int32_t	I;
	MM32_UART_CSRBits	B;
}MM32_UART_CSR;
typedef union _MM32_UART_ISR
{
	uint32_t	U;
	int32_t	I;
	MM32_UART_ISRBits	B;
}MM32_UART_ISR;
typedef union _MM32_UART_IER
{
	uint32_t	U;
	int32_t	I;
	MM32_UART_IERBits	B;
}MM32_UART_IER;
typedef union _MM32_UART_ICR
{
	uint32_t	U;
	int32_t	I;
	MM32_UART_ICRBits	B;
}MM32_UART_ICR;
typedef union _MM32_UART_GCR
{
	uint32_t	U;
	int32_t	I;
	MM32_UART_GCRBits	B;
}MM32_UART_GCR;
typedef union _MM32_UART_CCR
{
	uint32_t	U;
	int32_t	I;
	MM32_UART_CCRBits	B;
}MM32_UART_CCR;
typedef union _MM32_UART_BRR
{
	uint32_t	U;
	int32_t	I;
	MM32_UART_BRRBits	B;
}MM32_UART_BRR;
typedef union _MM32_UART_FRA
{
	uint32_t	U;
	int32_t	I;
	MM32_UART_FRABits	B;
}MM32_UART_FRA;
typedef union _MM32_UART_RXADDR 
{
	uint32_t	U;
	int32_t	I;
	MM32_UART_RXADDRBits	B;
}MM32_UART_RXADDR ;
typedef union _MM32_UART_RXMASK 
{
	uint32_t	U;
	int32_t	I;
	MM32_UART_RXMASKBits	B;
}MM32_UART_RXMASK ;
typedef union _MM32_UART_SCR 
{
	uint32_t	U;
	int32_t	I;
	MM32_UART_SCRBits	B;
}MM32_UART_SCR ;
typedef union _MM32_UART_IDLR
{
	uint32_t	U;
	int32_t	I;
	MM32_UART_IDLRBits	B;
}MM32_UART_IDLR;
typedef union _MM32_UART_ABRCR
{
	uint32_t	U;
	int32_t	I;
	MM32_UART_ABRCRBits	B;
}MM32_UART_ABRCR;
typedef union _MM32_UART_IRDA
{
	uint32_t	U;
	int32_t	I;
	MM32_UART_IRDABits	B;
}MM32_UART_IRDA;
typedef struct _MM32_UART
{
	MM32_UART_TDR		TDR;
	MM32_UART_RDR		RDR;
	MM32_UART_CSR		CSR;
	MM32_UART_ISR		ISR;
	MM32_UART_IER		IER;
	MM32_UART_ICR		ICR;
	MM32_UART_GCR		GCR;
	MM32_UART_CCR		CCR;
	MM32_UART_BRR		BRR;
	MM32_UART_FRA		FRA;
	MM32_UART_RXADDR 		RXADDR ;
	MM32_UART_RXMASK 		RXMASK ;
	MM32_UART_SCR 		SCR ;
	MM32_UART_IDLR		IDLR;
	MM32_UART_ABRCR		ABRCR;
	MM32_UART_IRDA		IRDA;
}MM32_UART;
#endif