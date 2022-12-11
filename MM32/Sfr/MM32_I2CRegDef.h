/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-12-11 15:28:04
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-11 15:29:37
 * @FilePath: \CODE\MM32\Sfr\MM32_I2CRegDef.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_I2CREGDEF_H_
#define _MM32_I2CREGDEF_H_

#include "MM32_RegTypedef.h"

typedef struct _MM32_I2C_CRBits
{
	Strict_32Bit	MASTER		:	1;
	Strict_32Bit	SPEED		:	2;
	Strict_32Bit	SLAVE10		:	1;
	Strict_32Bit	MASTER10		:	1;
	Strict_32Bit	REPEN		:	1;
	Strict_32Bit	DISSLAVE		:	1;
	Strict_32Bit	STOPINT		:	1;
	Strict_32Bit	EMPINT		:	1;
	Strict_32Bit	STOP		:	1;
	Strict_32Bit	RESTART		:	1;
	Strict_32Bit	SLV_TX_ABRT_DIS		:	1;
	Strict_32Bit	_reserved_0		:	20;
}MM32_I2C_CRBits;
typedef struct _MM32_I2C_TARBits
{
	Strict_32Bit	ADDR		:	10;
	Strict_32Bit	GC		:	1;
	Strict_32Bit	SPECIAL		:	1;
	Strict_32Bit	_reserved_0		:	20;
}MM32_I2C_TARBits;
typedef struct _MM32_I2C_SARBits
{
	Strict_32Bit	ADDR		:	10;
	Strict_32Bit	_reserved_0		:	22;
}MM32_I2C_SARBits;
typedef struct _MM32_I2C_DRBits
{
	Strict_32Bit	DAT		:	8;
	Strict_32Bit	CMD		:	1;
	Strict_32Bit	_reserved_0		:	23;
}MM32_I2C_DRBits;
typedef struct _MM32_I2C_SSHRBits
{
	Strict_32Bit	CNT		:	16;
	Strict_32Bit	_reserved_0		:	16;
}MM32_I2C_SSHRBits;
typedef struct _MM32_I2C_SSLRBits
{
	Strict_32Bit	CNT		:	16;
	Strict_32Bit	_reserved_0		:	16;
}MM32_I2C_SSLRBits;
typedef struct _MM32_I2C_FSHRBits
{
	Strict_32Bit	CNT		:	16;
	Strict_32Bit	_reserved_0		:	16;
}MM32_I2C_FSHRBits;
typedef struct _MM32_I2C_FSLRBits
{
	Strict_32Bit	CNT		:	16;
	Strict_32Bit	_reserved_0		:	16;
}MM32_I2C_FSLRBits;
typedef struct _MM32_I2C_ISRBits
{
	Strict_32Bit	RX_UNDER		:	1;
	Strict_32Bit	RX_OVER		:	1;
	Strict_32Bit	RX_FULL		:	1;
	Strict_32Bit	TX_OVER		:	1;
	Strict_32Bit	TX_EMPTY		:	1;
	Strict_32Bit	RD_REQ		:	1;
	Strict_32Bit	TX_ABRT		:	1;
	Strict_32Bit	RX_DONE		:	1;
	Strict_32Bit	ACTIV		:	1;
	Strict_32Bit	STOP		:	1;
	Strict_32Bit	START		:	1;
	Strict_32Bit	GC		:	1;
	Strict_32Bit	_reserved_0		:	20;
}MM32_I2C_ISRBits;
typedef struct _MM32_I2C_IMRBits
{
	Strict_32Bit	RX_UNDER		:	1;
	Strict_32Bit	RX_OVER		:	1;
	Strict_32Bit	RX_FULL		:	1;
	Strict_32Bit	TX_OVER		:	1;
	Strict_32Bit	TX_EMPTY		:	1;
	Strict_32Bit	RD_REQ		:	1;
	Strict_32Bit	TX_ABRT		:	1;
	Strict_32Bit	RX_DONE		:	1;
	Strict_32Bit	ACTIV		:	1;
	Strict_32Bit	STOP		:	1;
	Strict_32Bit	START		:	1;
	Strict_32Bit	GC		:	1;
	Strict_32Bit	_reserved_0		:	20;
}MM32_I2C_IMRBits;
typedef struct _MM32_I2C_RAWISRBits
{
	Strict_32Bit	RX_UNDER		:	1;
	Strict_32Bit	RX_OVER		:	1;
	Strict_32Bit	RX_FULL		:	1;
	Strict_32Bit	TX_OVER		:	1;
	Strict_32Bit	TX_EMPTY		:	1;
	Strict_32Bit	RD_REQ		:	1;
	Strict_32Bit	TX_ABRT		:	1;
	Strict_32Bit	RX_DONE		:	1;
	Strict_32Bit	ACTIV		:	1;
	Strict_32Bit	STOP		:	1;
	Strict_32Bit	START		:	1;
	Strict_32Bit	GC		:	1;
	Strict_32Bit	_reserved_0		:	20;
}MM32_I2C_RAWISRBits;
typedef struct _MM32_I2C_RXTLRBits
{
	Strict_32Bit	TL		:	8;
	Strict_32Bit	_reserved_0		:	24;
}MM32_I2C_RXTLRBits;
typedef struct _MM32_I2C_TXTLRBits
{
	Strict_32Bit	TL		:	8;
	Strict_32Bit	_reserved_0		:	24;
}MM32_I2C_TXTLRBits;
typedef struct _MM32_I2C_ICRBits
{
	Strict_32Bit	ICR		:	1;
	Strict_32Bit	_reserved_0		:	31;
}MM32_I2C_ICRBits;
typedef struct _MM32_I2C_RX_UNDERBits
{
	Strict_32Bit	RX_UNDER		:	1;
	Strict_32Bit	_reserved_0		:	31;
}MM32_I2C_RX_UNDERBits;
typedef struct _MM32_I2C_RX_OVERBits
{
	Strict_32Bit	RX_OVER		:	1;
	Strict_32Bit	_reserved_0		:	31;
}MM32_I2C_RX_OVERBits;
typedef struct _MM32_I2C_TX_OVERBits
{
	Strict_32Bit	TX_OVER		:	1;
	Strict_32Bit	_reserved_0		:	31;
}MM32_I2C_TX_OVERBits;
typedef struct _MM32_I2C_RD_REQBits
{
	Strict_32Bit	RD_REQ		:	1;
	Strict_32Bit	_reserved_0		:	31;
}MM32_I2C_RD_REQBits;
typedef struct _MM32_I2C_TX_ABRTBits
{
	Strict_32Bit	TX_ABRT		:	1;
	Strict_32Bit	_reserved_0		:	31;
}MM32_I2C_TX_ABRTBits;
typedef struct _MM32_I2C_RX_DONEBits
{
	Strict_32Bit	RX_DONE		:	1;
	Strict_32Bit	_reserved_0		:	31;
}MM32_I2C_RX_DONEBits;
typedef struct _MM32_I2C_ACTIVBits
{
	Strict_32Bit	ACTIV		:	1;
	Strict_32Bit	_reserved_0		:	31;
}MM32_I2C_ACTIVBits;
typedef struct _MM32_I2C_STOPBits
{
	Strict_32Bit	STOP		:	1;
	Strict_32Bit	_reserved_0		:	31;
}MM32_I2C_STOPBits;
typedef struct _MM32_I2C_STARTBits
{
	Strict_32Bit	START		:	1;
	Strict_32Bit	_reserved_0		:	31;
}MM32_I2C_STARTBits;
typedef struct _MM32_I2C_GCBits
{
	Strict_32Bit	GC		:	1;
	Strict_32Bit	_reserved_0		:	31;
}MM32_I2C_GCBits;
typedef struct _MM32_I2C_ENRBits
{
	Strict_32Bit	ENABLE		:	1;
	Strict_32Bit	ABORT		:	1;
	Strict_32Bit	_reserved_0		:	30;
}MM32_I2C_ENRBits;
typedef struct _MM32_I2C_SRBits
{
	Strict_32Bit	ACTIV		:	1;
	Strict_32Bit	TFNF		:	1;
	Strict_32Bit	TFE		:	1;
	Strict_32Bit	RFNE		:	1;
	Strict_32Bit	RFF		:	1;
	Strict_32Bit	MST_ACTIV		:	1;
	Strict_32Bit	SLV_ACTIV		:	1;
	Strict_32Bit	_reserved_0		:	25;
}MM32_I2C_SRBits;
typedef struct _MM32_I2C_TXFLRBits
{
	Strict_32Bit	CNT		:	2;
	Strict_32Bit	_reserved_0		:	30;
}MM32_I2C_TXFLRBits;
typedef struct _MM32_I2C_RXFLRBits
{
	Strict_32Bit	CNT		:	2;
	Strict_32Bit	_reserved_0		:	30;
}MM32_I2C_RXFLRBits;
typedef struct _MM32_I2C_HOLDBits
{
	Strict_32Bit	TX_HOLD		:	16;
	Strict_32Bit	RX_HOLD		:	8;
	Strict_32Bit	_reserved_0		:	8;
}MM32_I2C_HOLDBits;
typedef struct _MM32_I2C_DMABits
{
	Strict_32Bit	RXEN		:	1;
	Strict_32Bit	TXEN		:	1;
	Strict_32Bit	_reserved_0		:	30;
}MM32_I2C_DMABits;
typedef struct _MM32_I2C_SETUPBits
{
	Strict_32Bit	CNT		:	8;
	Strict_32Bit	_reserved_0		:	24;
}MM32_I2C_SETUPBits;
typedef struct _MM32_I2C_GCRBits
{
	Strict_32Bit	GC		:	1;
	Strict_32Bit	_reserved_0		:	31;
}MM32_I2C_GCRBits;
typedef struct _MM32_I2C_SLVMASKBits
{
	Strict_32Bit	MASK		:	10;
	Strict_32Bit	_reserved_0		:	22;
}MM32_I2C_SLVMASKBits;
typedef struct _MM32_I2C_SLVRCVADDRBits
{
	Strict_32Bit	ADDR		:	10;
	Strict_32Bit	_reserved_0		:	22;
}MM32_I2C_SLVRCVADDRBits;
typedef union _MM32_I2C_CR
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_CRBits	B;
}MM32_I2C_CR;
typedef union _MM32_I2C_TAR
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_TARBits	B;
}MM32_I2C_TAR;
typedef union _MM32_I2C_SAR
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_SARBits	B;
}MM32_I2C_SAR;
typedef union _MM32_I2C_DR
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_DRBits	B;
}MM32_I2C_DR;
typedef union _MM32_I2C_SSHR
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_SSHRBits	B;
}MM32_I2C_SSHR;
typedef union _MM32_I2C_SSLR
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_SSLRBits	B;
}MM32_I2C_SSLR;
typedef union _MM32_I2C_FSHR
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_FSHRBits	B;
}MM32_I2C_FSHR;
typedef union _MM32_I2C_FSLR
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_FSLRBits	B;
}MM32_I2C_FSLR;
typedef union _MM32_I2C_ISR
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_ISRBits	B;
}MM32_I2C_ISR;
typedef union _MM32_I2C_IMR
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_IMRBits	B;
}MM32_I2C_IMR;
typedef union _MM32_I2C_RAWISR
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_RAWISRBits	B;
}MM32_I2C_RAWISR;
typedef union _MM32_I2C_RXTLR
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_RXTLRBits	B;
}MM32_I2C_RXTLR;
typedef union _MM32_I2C_TXTLR
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_TXTLRBits	B;
}MM32_I2C_TXTLR;
typedef union _MM32_I2C_ICR
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_ICRBits	B;
}MM32_I2C_ICR;
typedef union _MM32_I2C_RX_UNDER
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_RX_UNDERBits	B;
}MM32_I2C_RX_UNDER;
typedef union _MM32_I2C_RX_OVER
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_RX_OVERBits	B;
}MM32_I2C_RX_OVER;
typedef union _MM32_I2C_TX_OVER
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_TX_OVERBits	B;
}MM32_I2C_TX_OVER;
typedef union _MM32_I2C_RD_REQ
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_RD_REQBits	B;
}MM32_I2C_RD_REQ;
typedef union _MM32_I2C_TX_ABRT
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_TX_ABRTBits	B;
}MM32_I2C_TX_ABRT;
typedef union _MM32_I2C_RX_DONE
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_RX_DONEBits	B;
}MM32_I2C_RX_DONE;
typedef union _MM32_I2C_ACTIV
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_ACTIVBits	B;
}MM32_I2C_ACTIV;
typedef union _MM32_I2C_STOP
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_STOPBits	B;
}MM32_I2C_STOP;
typedef union _MM32_I2C_START
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_STARTBits	B;
}MM32_I2C_START;
typedef union _MM32_I2C_GC
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_GCBits	B;
}MM32_I2C_GC;
typedef union _MM32_I2C_ENR
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_ENRBits	B;
}MM32_I2C_ENR;
typedef union _MM32_I2C_SR
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_SRBits	B;
}MM32_I2C_SR;
typedef union _MM32_I2C_TXFLR
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_TXFLRBits	B;
}MM32_I2C_TXFLR;
typedef union _MM32_I2C_RXFLR
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_RXFLRBits	B;
}MM32_I2C_RXFLR;
typedef union _MM32_I2C_HOLD
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_HOLDBits	B;
}MM32_I2C_HOLD;
typedef union _MM32_I2C_DMA
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_DMABits	B;
}MM32_I2C_DMA;
typedef union _MM32_I2C_SETUP
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_SETUPBits	B;
}MM32_I2C_SETUP;
typedef union _MM32_I2C_GCR
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_GCRBits	B;
}MM32_I2C_GCR;
typedef union _MM32_I2C_SLVMASK
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_SLVMASKBits	B;
}MM32_I2C_SLVMASK;
typedef union _MM32_I2C_SLVRCVADDR
{
	uint32_t	U;
	int32_t	I;
	MM32_I2C_SLVRCVADDRBits	B;
}MM32_I2C_SLVRCVADDR;
typedef struct _MM32_I2C
{
	MM32_I2C_CR		CR;
	MM32_I2C_TAR		TAR;
	MM32_I2C_SAR		SAR;
	unsigned char		_reserved_0;
	unsigned char		_reserved_1;
	unsigned char		_reserved_2;
	unsigned char		_reserved_3;
	MM32_I2C_DR		DR;
	MM32_I2C_SSHR		SSHR;
	MM32_I2C_SSLR		SSLR;
	MM32_I2C_FSHR		FSHR;
	MM32_I2C_FSLR		FSLR;
	unsigned char		_reserved_4;
	unsigned char		_reserved_5;
	unsigned char		_reserved_6;
	unsigned char		_reserved_7;
	unsigned char		_reserved_8;
	unsigned char		_reserved_9;
	unsigned char		_reserved_10;
	unsigned char		_reserved_11;
	MM32_I2C_ISR		ISR;
	MM32_I2C_IMR		IMR;
	MM32_I2C_RAWISR		RAWISR;
	MM32_I2C_RXTLR		RXTLR;
	MM32_I2C_TXTLR		TXTLR;
	MM32_I2C_ICR		ICR;
	MM32_I2C_RX_UNDER		_UNDER;
	MM32_I2C_RX_OVER		_OVER;
	MM32_I2C_TX_OVER		_OVER;
	MM32_I2C_RD_REQ		_REQ;
	MM32_I2C_TX_ABRT		_ABRT;
	MM32_I2C_RX_DONE		_DONE;
	MM32_I2C_ACTIV		ACTIV;
	MM32_I2C_STOP		STOP;
	MM32_I2C_START		START;
	MM32_I2C_GC		GC;
	MM32_I2C_ENR		ENR;
	MM32_I2C_SR		SR;
	MM32_I2C_TXFLR		TXFLR;
	MM32_I2C_RXFLR		RXFLR;
	MM32_I2C_HOLD		HOLD;
	unsigned char		_reserved_12;
	unsigned char		_reserved_13;
	unsigned char		_reserved_14;
	unsigned char		_reserved_15;
	unsigned char		_reserved_16;
	unsigned char		_reserved_17;
	unsigned char		_reserved_18;
	unsigned char		_reserved_19;
	MM32_I2C_DMA		DMA;
	unsigned char		_reserved_20;
	unsigned char		_reserved_21;
	unsigned char		_reserved_22;
	unsigned char		_reserved_23;
	unsigned char		_reserved_24;
	unsigned char		_reserved_25;
	unsigned char		_reserved_26;
	unsigned char		_reserved_27;
	MM32_I2C_SETUP		SETUP;
	MM32_I2C_GCR		GCR;
	unsigned char		_reserved_28;
	unsigned char		_reserved_29;
	unsigned char		_reserved_30;
	unsigned char		_reserved_31;
	unsigned char		_reserved_32;
	unsigned char		_reserved_33;
	unsigned char		_reserved_34;
	unsigned char		_reserved_35;
	unsigned char		_reserved_36;
	unsigned char		_reserved_37;
	unsigned char		_reserved_38;
	unsigned char		_reserved_39;
	unsigned char		_reserved_40;
	unsigned char		_reserved_41;
	unsigned char		_reserved_42;
	unsigned char		_reserved_43;
	unsigned char		_reserved_44;
	unsigned char		_reserved_45;
	unsigned char		_reserved_46;
	unsigned char		_reserved_47;
	MM32_I2C_SLVMASK		SLVMASK;
	MM32_I2C_SLVRCVADDR		SLVRCVADDR;
}MM32_I2C;
#endif