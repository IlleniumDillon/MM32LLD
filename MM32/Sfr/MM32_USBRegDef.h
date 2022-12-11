/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-12-11 17:20:30
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-11 17:22:47
 * @FilePath: \CODE\MM32\Sfr\MM32_USBRegDef.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_USBREGDEF_H_
#define _MM32_USBREGDEF_H_

#include "MM32_RegTypedef.h"

typedef struct _MM32_USB_OTGISTATBits
{
	Strict_16Bit	A_VBUS_VLD_CHG		:	1;
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	B_SESS_END_CHG		:	1;
	Strict_16Bit	SESS_VLD_CHG		:	1;
	Strict_16Bit	_reserved_1		:	1;
	Strict_16Bit	LINE_STATE_CHG		:	1;
	Strict_16Bit	MSEC_1		:	1;
	Strict_16Bit	ID_CHG		:	1;
	Strict_16Bit	_reserved_2		:	8;
}MM32_USB_OTGISTATBits;
typedef struct _MM32_USB_OTGICTRLBits
{
	Strict_16Bit	A_VBUS_VLD_EN		:	1;
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	B_SESS_END_EN		:	1;
	Strict_16Bit	SESS_VLD_EN		:	1;
	Strict_16Bit	_reserved_1		:	1;
	Strict_16Bit	LINE_STATE_EN		:	1;
	Strict_16Bit	MSEC_EN		:	1;
	Strict_16Bit	ID_EN		:	1;
	Strict_16Bit	_reserved_2		:	8;
}MM32_USB_OTGICTRLBits;
typedef struct _MM32_USB_OTGSTATBits
{
	Strict_16Bit	A_VBUS_VLD		:	1;
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	B_SESS_END		:	1;
	Strict_16Bit	SESS_VLD		:	1;
	Strict_16Bit	_reserved_1		:	1;
	Strict_16Bit	LINESTATE_STABLE		:	1;
	Strict_16Bit	_reserved_2		:	1;
	Strict_16Bit	ID		:	1;
	Strict_16Bit	_reserved_3		:	8;
}MM32_USB_OTGSTATBits;
typedef struct _MM32_USB_OTGCTRLBits
{
	Strict_16Bit	VBUS_DSCHG		:	1;
	Strict_16Bit	VBUS_CHG		:	1;
	Strict_16Bit	OTG_EN		:	1;
	Strict_16Bit	VBUS_ON		:	1;
	Strict_16Bit	DM_LOW		:	1;
	Strict_16Bit	DP_LOW		:	1;
	Strict_16Bit	DM_HIGH		:	1;
	Strict_16Bit	DP_HIGH		:	1;
	Strict_16Bit	_reserved_0		:	8;
}MM32_USB_OTGCTRLBits;
typedef struct _MM32_USB_INTSTATBits
{
	Strict_16Bit	USB_RST		:	1;
	Strict_16Bit	ERROR		:	1;
	Strict_16Bit	SOF_TOK		:	1;
	Strict_16Bit	TOK_DNE		:	1;
	Strict_16Bit	SLEEP		:	1;
	Strict_16Bit	RESUME		:	1;
	Strict_16Bit	ATTACH		:	1;
	Strict_16Bit	STALL		:	1;
	Strict_16Bit	_reserved_0		:	8;
}MM32_USB_INTSTATBits;
typedef struct _MM32_USB_INTENBBits
{
	Strict_16Bit	USB_RST		:	1;
	Strict_16Bit	ERROR		:	1;
	Strict_16Bit	SOF_TOK		:	1;
	Strict_16Bit	TOK_DNE		:	1;
	Strict_16Bit	SLEEP		:	1;
	Strict_16Bit	RESUME		:	1;
	Strict_16Bit	ATTACH		:	1;
	Strict_16Bit	STALL		:	1;
	Strict_16Bit	_reserved_0		:	8;
}MM32_USB_INTENBBits;
typedef struct _MM32_USB_ERRSTATBits
{
	Strict_16Bit	PID_ERR		:	1;
	Strict_16Bit	CRC5_EOF		:	1;
	Strict_16Bit	CRC16		:	1;
	Strict_16Bit	DFN8		:	1;
	Strict_16Bit	BTO_ERR		:	1;
	Strict_16Bit	DMA_ERR		:	1;
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	BTS_ERR		:	1;
	Strict_16Bit	_reserved_1		:	8;
}MM32_USB_ERRSTATBits;
typedef struct _MM32_USB_ERRENBBits
{
	Strict_16Bit	PID_ERR		:	1;
	Strict_16Bit	CRC5_EOF		:	1;
	Strict_16Bit	CRC16		:	1;
	Strict_16Bit	DFN8		:	1;
	Strict_16Bit	BTO_ERR		:	1;
	Strict_16Bit	DMA_ERR		:	1;
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	BTS_ERR		:	1;
	Strict_16Bit	_reserved_1		:	8;
}MM32_USB_ERRENBBits;
typedef struct _MM32_USB_STATBits
{
	Strict_16Bit	_reserved_0		:	2;
	Strict_16Bit	ODD		:	1;
	Strict_16Bit	TX		:	1;
	Strict_16Bit	ENDP		:	4;
	Strict_16Bit	_reserved_1		:	8;
}MM32_USB_STATBits;
typedef struct _MM32_USB_CTLBits
{
	Strict_16Bit	USB_EN		:	1;
	Strict_16Bit	ODD_RST		:	1;
	Strict_16Bit	RESUME		:	1;
	Strict_16Bit	HOST_MODE_EN		:	1;
	Strict_16Bit	RESET		:	1;
	Strict_16Bit	TxdSuspendTokenBusy		:	1;
	Strict_16Bit	SE0		:	1;
	Strict_16Bit	JSTATE		:	1;
	Strict_16Bit	_reserved_0		:	8;
}MM32_USB_CTLBits;
typedef struct _MM32_USB_ADDRBits
{
	Strict_16Bit	ADDR		:	7;
	Strict_16Bit	LS_EN		:	1;
	Strict_16Bit	_reserved_0		:	8;
}MM32_USB_ADDRBits;
typedef struct _MM32_USB_BDTPAGE1Bits
{
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	BDT_BA		:	7;
	Strict_16Bit	_reserved_0		:	8;
}MM32_USB_BDTPAGE1Bits;
typedef struct _MM32_USB_FRMNUMLBits
{
	Strict_16Bit	FRM		:	8;
	Strict_16Bit	_reserved_0		:	8;
}MM32_USB_FRMNUMLBits;
typedef struct _MM32_USB_FRMNUMHBits
{
	Strict_16Bit	FRM		:	3;
	Strict_16Bit	_reserved_0		:	13;
}MM32_USB_FRMNUMHBits;
typedef struct _MM32_USB_TOKENBits
{
	Strict_16Bit	TOKEN_ENDPT		:	4;
	Strict_16Bit	TOKEN_PID		:	4;
	Strict_16Bit	_reserved_0		:	8;
}MM32_USB_TOKENBits;
typedef struct _MM32_USB_SOFTHLDBits
{
	Strict_16Bit	CNT		:	8;
	Strict_16Bit	_reserved_0		:	8;
}MM32_USB_SOFTHLDBits;
typedef struct _MM32_USB_BDTPAGE2Bits
{
	Strict_16Bit	BDT_BA		:	8;
	Strict_16Bit	_reserved_0		:	8;
}MM32_USB_BDTPAGE2Bits;
typedef struct _MM32_USB_BDTPAGE3Bits
{
	Strict_16Bit	BDT_BA		:	8;
	Strict_16Bit	_reserved_0		:	8;
}MM32_USB_BDTPAGE3Bits;
typedef struct _MM32_USB_EPCTL0Bits
{
	Strict_16Bit	EP_HSHK		:	1;
	Strict_16Bit	EP_STALL		:	1;
	Strict_16Bit	EP_TX_EN		:	1;
	Strict_16Bit	EP_RX_EN		:	1;
	Strict_16Bit	EP_CTL_DIS		:	1;
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	RETRY_DIS		:	1;
	Strict_16Bit	HOST_WO_HUB		:	1;
	Strict_16Bit	_reserved_1		:	8;
}MM32_USB_EPCTL0Bits;
typedef struct _MM32_USB_EPCTL1Bits
{
	Strict_16Bit	EP_HSHK		:	1;
	Strict_16Bit	EP_STALL		:	1;
	Strict_16Bit	EP_TX_EN		:	1;
	Strict_16Bit	EP_RX_EN		:	1;
	Strict_16Bit	EP_CTL_DIS		:	1;
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	RETRY_DIS		:	1;
	Strict_16Bit	HOST_WO_HUB		:	1;
	Strict_16Bit	_reserved_1		:	8;
}MM32_USB_EPCTL1Bits;
typedef struct _MM32_USB_EPCTL2Bits
{
	Strict_16Bit	EP_HSHK		:	1;
	Strict_16Bit	EP_STALL		:	1;
	Strict_16Bit	EP_TX_EN		:	1;
	Strict_16Bit	EP_RX_EN		:	1;
	Strict_16Bit	EP_CTL_DIS		:	1;
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	RETRY_DIS		:	1;
	Strict_16Bit	HOST_WO_HUB		:	1;
	Strict_16Bit	_reserved_1		:	8;
}MM32_USB_EPCTL2Bits;
typedef struct _MM32_USB_EPCTL3Bits
{
	Strict_16Bit	EP_HSHK		:	1;
	Strict_16Bit	EP_STALL		:	1;
	Strict_16Bit	EP_TX_EN		:	1;
	Strict_16Bit	EP_RX_EN		:	1;
	Strict_16Bit	EP_CTL_DIS		:	1;
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	RETRY_DIS		:	1;
	Strict_16Bit	HOST_WO_HUB		:	1;
	Strict_16Bit	_reserved_1		:	8;
}MM32_USB_EPCTL3Bits;
typedef struct _MM32_USB_EPCTL4Bits
{
	Strict_16Bit	EP_HSHK		:	1;
	Strict_16Bit	EP_STALL		:	1;
	Strict_16Bit	EP_TX_EN		:	1;
	Strict_16Bit	EP_RX_EN		:	1;
	Strict_16Bit	EP_CTL_DIS		:	1;
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	RETRY_DIS		:	1;
	Strict_16Bit	HOST_WO_HUB		:	1;
	Strict_16Bit	_reserved_1		:	8;
}MM32_USB_EPCTL4Bits;
typedef struct _MM32_USB_EPCTL5Bits
{
	Strict_16Bit	EP_HSHK		:	1;
	Strict_16Bit	EP_STALL		:	1;
	Strict_16Bit	EP_TX_EN		:	1;
	Strict_16Bit	EP_RX_EN		:	1;
	Strict_16Bit	EP_CTL_DIS		:	1;
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	RETRY_DIS		:	1;
	Strict_16Bit	HOST_WO_HUB		:	1;
	Strict_16Bit	_reserved_1		:	8;
}MM32_USB_EPCTL5Bits;
typedef struct _MM32_USB_EPCTL6Bits
{
	Strict_16Bit	EP_HSHK		:	1;
	Strict_16Bit	EP_STALL		:	1;
	Strict_16Bit	EP_TX_EN		:	1;
	Strict_16Bit	EP_RX_EN		:	1;
	Strict_16Bit	EP_CTL_DIS		:	1;
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	RETRY_DIS		:	1;
	Strict_16Bit	HOST_WO_HUB		:	1;
	Strict_16Bit	_reserved_1		:	8;
}MM32_USB_EPCTL6Bits;
typedef struct _MM32_USB_EPCTL7Bits
{
	Strict_16Bit	EP_HSHK		:	1;
	Strict_16Bit	EP_STALL		:	1;
	Strict_16Bit	EP_TX_EN		:	1;
	Strict_16Bit	EP_RX_EN		:	1;
	Strict_16Bit	EP_CTL_DIS		:	1;
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	RETRY_DIS		:	1;
	Strict_16Bit	HOST_WO_HUB		:	1;
	Strict_16Bit	_reserved_1		:	8;
}MM32_USB_EPCTL7Bits;
typedef struct _MM32_USB_EPCTL8Bits
{
	Strict_16Bit	EP_HSHK		:	1;
	Strict_16Bit	EP_STALL		:	1;
	Strict_16Bit	EP_TX_EN		:	1;
	Strict_16Bit	EP_RX_EN		:	1;
	Strict_16Bit	EP_CTL_DIS		:	1;
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	RETRY_DIS		:	1;
	Strict_16Bit	HOST_WO_HUB		:	1;
	Strict_16Bit	_reserved_1		:	8;
}MM32_USB_EPCTL8Bits;
typedef struct _MM32_USB_EPCTL9Bits
{
	Strict_16Bit	EP_HSHK		:	1;
	Strict_16Bit	EP_STALL		:	1;
	Strict_16Bit	EP_TX_EN		:	1;
	Strict_16Bit	EP_RX_EN		:	1;
	Strict_16Bit	EP_CTL_DIS		:	1;
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	RETRY_DIS		:	1;
	Strict_16Bit	HOST_WO_HUB		:	1;
	Strict_16Bit	_reserved_1		:	8;
}MM32_USB_EPCTL9Bits;
typedef struct _MM32_USB_EPCTL10Bits
{
	Strict_16Bit	EP_HSHK		:	1;
	Strict_16Bit	EP_STALL		:	1;
	Strict_16Bit	EP_TX_EN		:	1;
	Strict_16Bit	EP_RX_EN		:	1;
	Strict_16Bit	EP_CTL_DIS		:	1;
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	RETRY_DIS		:	1;
	Strict_16Bit	HOST_WO_HUB		:	1;
	Strict_16Bit	_reserved_1		:	8;
}MM32_USB_EPCTL10Bits;
typedef struct _MM32_USB_EPCTL11Bits
{
	Strict_16Bit	EP_HSHK		:	1;
	Strict_16Bit	EP_STALL		:	1;
	Strict_16Bit	EP_TX_EN		:	1;
	Strict_16Bit	EP_RX_EN		:	1;
	Strict_16Bit	EP_CTL_DIS		:	1;
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	RETRY_DIS		:	1;
	Strict_16Bit	HOST_WO_HUB		:	1;
	Strict_16Bit	_reserved_1		:	8;
}MM32_USB_EPCTL11Bits;
typedef struct _MM32_USB_EPCTL12Bits
{
	Strict_16Bit	EP_HSHK		:	1;
	Strict_16Bit	EP_STALL		:	1;
	Strict_16Bit	EP_TX_EN		:	1;
	Strict_16Bit	EP_RX_EN		:	1;
	Strict_16Bit	EP_CTL_DIS		:	1;
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	RETRY_DIS		:	1;
	Strict_16Bit	HOST_WO_HUB		:	1;
	Strict_16Bit	_reserved_1		:	8;
}MM32_USB_EPCTL12Bits;
typedef struct _MM32_USB_EPCTL13Bits
{
	Strict_16Bit	EP_HSHK		:	1;
	Strict_16Bit	EP_STALL		:	1;
	Strict_16Bit	EP_TX_EN		:	1;
	Strict_16Bit	EP_RX_EN		:	1;
	Strict_16Bit	EP_CTL_DIS		:	1;
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	RETRY_DIS		:	1;
	Strict_16Bit	HOST_WO_HUB		:	1;
	Strict_16Bit	_reserved_1		:	8;
}MM32_USB_EPCTL13Bits;
typedef struct _MM32_USB_EPCTL14Bits
{
	Strict_16Bit	EP_HSHK		:	1;
	Strict_16Bit	EP_STALL		:	1;
	Strict_16Bit	EP_TX_EN		:	1;
	Strict_16Bit	EP_RX_EN		:	1;
	Strict_16Bit	EP_CTL_DIS		:	1;
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	RETRY_DIS		:	1;
	Strict_16Bit	HOST_WO_HUB		:	1;
	Strict_16Bit	_reserved_1		:	8;
}MM32_USB_EPCTL14Bits;
typedef struct _MM32_USB_EPCTL15Bits
{
	Strict_16Bit	EP_HSHK		:	1;
	Strict_16Bit	EP_STALL		:	1;
	Strict_16Bit	EP_TX_EN		:	1;
	Strict_16Bit	EP_RX_EN		:	1;
	Strict_16Bit	EP_CTL_DIS		:	1;
	Strict_16Bit	_reserved_0		:	1;
	Strict_16Bit	RETRY_DIS		:	1;
	Strict_16Bit	HOST_WO_HUB		:	1;
	Strict_16Bit	_reserved_1		:	8;
}MM32_USB_EPCTL15Bits;
typedef union _MM32_USB_OTGISTAT
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_OTGISTATBits	B;
}MM32_USB_OTGISTAT;
typedef union _MM32_USB_OTGICTRL
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_OTGICTRLBits	B;
}MM32_USB_OTGICTRL;
typedef union _MM32_USB_OTGSTAT
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_OTGSTATBits	B;
}MM32_USB_OTGSTAT;
typedef union _MM32_USB_OTGCTRL
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_OTGCTRLBits	B;
}MM32_USB_OTGCTRL;
typedef union _MM32_USB_INTSTAT
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_INTSTATBits	B;
}MM32_USB_INTSTAT;
typedef union _MM32_USB_INTENB
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_INTENBBits	B;
}MM32_USB_INTENB;
typedef union _MM32_USB_ERRSTAT
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_ERRSTATBits	B;
}MM32_USB_ERRSTAT;
typedef union _MM32_USB_ERRENB
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_ERRENBBits	B;
}MM32_USB_ERRENB;
typedef union _MM32_USB_STAT
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_STATBits	B;
}MM32_USB_STAT;
typedef union _MM32_USB_CTL
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_CTLBits	B;
}MM32_USB_CTL;
typedef union _MM32_USB_ADDR
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_ADDRBits	B;
}MM32_USB_ADDR;
typedef union _MM32_USB_BDTPAGE1
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_BDTPAGE1Bits	B;
}MM32_USB_BDTPAGE1;
typedef union _MM32_USB_FRMNUML
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_FRMNUMLBits	B;
}MM32_USB_FRMNUML;
typedef union _MM32_USB_FRMNUMH
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_FRMNUMHBits	B;
}MM32_USB_FRMNUMH;
typedef union _MM32_USB_TOKEN
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_TOKENBits	B;
}MM32_USB_TOKEN;
typedef union _MM32_USB_SOFTHLD
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_SOFTHLDBits	B;
}MM32_USB_SOFTHLD;
typedef union _MM32_USB_BDTPAGE2
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_BDTPAGE2Bits	B;
}MM32_USB_BDTPAGE2;
typedef union _MM32_USB_BDTPAGE3
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_BDTPAGE3Bits	B;
}MM32_USB_BDTPAGE3;
typedef union _MM32_USB_EPCTL0
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_EPCTL0Bits	B;
}MM32_USB_EPCTL0;
typedef union _MM32_USB_EPCTL1
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_EPCTL1Bits	B;
}MM32_USB_EPCTL1;
typedef union _MM32_USB_EPCTL2
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_EPCTL2Bits	B;
}MM32_USB_EPCTL2;
typedef union _MM32_USB_EPCTL3
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_EPCTL3Bits	B;
}MM32_USB_EPCTL3;
typedef union _MM32_USB_EPCTL4
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_EPCTL4Bits	B;
}MM32_USB_EPCTL4;
typedef union _MM32_USB_EPCTL5
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_EPCTL5Bits	B;
}MM32_USB_EPCTL5;
typedef union _MM32_USB_EPCTL6
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_EPCTL6Bits	B;
}MM32_USB_EPCTL6;
typedef union _MM32_USB_EPCTL7
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_EPCTL7Bits	B;
}MM32_USB_EPCTL7;
typedef union _MM32_USB_EPCTL8
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_EPCTL8Bits	B;
}MM32_USB_EPCTL8;
typedef union _MM32_USB_EPCTL9
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_EPCTL9Bits	B;
}MM32_USB_EPCTL9;
typedef union _MM32_USB_EPCTL10
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_EPCTL10Bits	B;
}MM32_USB_EPCTL10;
typedef union _MM32_USB_EPCTL11
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_EPCTL11Bits	B;
}MM32_USB_EPCTL11;
typedef union _MM32_USB_EPCTL12
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_EPCTL12Bits	B;
}MM32_USB_EPCTL12;
typedef union _MM32_USB_EPCTL13
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_EPCTL13Bits	B;
}MM32_USB_EPCTL13;
typedef union _MM32_USB_EPCTL14
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_EPCTL14Bits	B;
}MM32_USB_EPCTL14;
typedef union _MM32_USB_EPCTL15
{
	uint16_t	U;
	int16_t	I;
	MM32_USB_EPCTL15Bits	B;
}MM32_USB_EPCTL15;
typedef struct _MM32_USB
{
	unsigned char		_reserved_0;
	unsigned char		_reserved_1;
	unsigned char		_reserved_2;
	unsigned char		_reserved_3;
	unsigned char		_reserved_4;
	unsigned char		_reserved_5;
	unsigned char		_reserved_6;
	unsigned char		_reserved_7;
	unsigned char		_reserved_8;
	unsigned char		_reserved_9;
	unsigned char		_reserved_10;
	unsigned char		_reserved_11;
	unsigned char		_reserved_12;
	unsigned char		_reserved_13;
	unsigned char		_reserved_14;
	unsigned char		_reserved_15;
	MM32_USB_OTGISTAT		OTGISTAT;
	unsigned char		_reserved_16;
	unsigned char		_reserved_17;
	MM32_USB_OTGICTRL		OTGICTRL;
	unsigned char		_reserved_18;
	unsigned char		_reserved_19;
	MM32_USB_OTGSTAT		OTGSTAT;
	unsigned char		_reserved_20;
	unsigned char		_reserved_21;
	MM32_USB_OTGCTRL		OTGCTRL;
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
	unsigned char		_reserved_48;
	unsigned char		_reserved_49;
	unsigned char		_reserved_50;
	unsigned char		_reserved_51;
	unsigned char		_reserved_52;
	unsigned char		_reserved_53;
	unsigned char		_reserved_54;
	unsigned char		_reserved_55;
	unsigned char		_reserved_56;
	unsigned char		_reserved_57;
	unsigned char		_reserved_58;
	unsigned char		_reserved_59;
	unsigned char		_reserved_60;
	unsigned char		_reserved_61;
	unsigned char		_reserved_62;
	unsigned char		_reserved_63;
	unsigned char		_reserved_64;
	unsigned char		_reserved_65;
	unsigned char		_reserved_66;
	unsigned char		_reserved_67;
	unsigned char		_reserved_68;
	unsigned char		_reserved_69;
	unsigned char		_reserved_70;
	unsigned char		_reserved_71;
	unsigned char		_reserved_72;
	unsigned char		_reserved_73;
	unsigned char		_reserved_74;
	unsigned char		_reserved_75;
	unsigned char		_reserved_76;
	unsigned char		_reserved_77;
	unsigned char		_reserved_78;
	unsigned char		_reserved_79;
	unsigned char		_reserved_80;
	unsigned char		_reserved_81;
	unsigned char		_reserved_82;
	unsigned char		_reserved_83;
	unsigned char		_reserved_84;
	unsigned char		_reserved_85;
	unsigned char		_reserved_86;
	unsigned char		_reserved_87;
	unsigned char		_reserved_88;
	unsigned char		_reserved_89;
	unsigned char		_reserved_90;
	unsigned char		_reserved_91;
	unsigned char		_reserved_92;
	unsigned char		_reserved_93;
	unsigned char		_reserved_94;
	unsigned char		_reserved_95;
	unsigned char		_reserved_96;
	unsigned char		_reserved_97;
	unsigned char		_reserved_98;
	unsigned char		_reserved_99;
	unsigned char		_reserved_100;
	unsigned char		_reserved_101;
	unsigned char		_reserved_102;
	unsigned char		_reserved_103;
	unsigned char		_reserved_104;
	unsigned char		_reserved_105;
	unsigned char		_reserved_106;
	unsigned char		_reserved_107;
	unsigned char		_reserved_108;
	unsigned char		_reserved_109;
	unsigned char		_reserved_110;
	unsigned char		_reserved_111;
	unsigned char		_reserved_112;
	unsigned char		_reserved_113;
	unsigned char		_reserved_114;
	unsigned char		_reserved_115;
	unsigned char		_reserved_116;
	unsigned char		_reserved_117;
	unsigned char		_reserved_118;
	unsigned char		_reserved_119;
	MM32_USB_INTSTAT		INTSTAT;
	unsigned char		_reserved_120;
	unsigned char		_reserved_121;
	MM32_USB_INTENB		INTENB;
	unsigned char		_reserved_122;
	unsigned char		_reserved_123;
	MM32_USB_ERRSTAT		ERRSTAT;
	unsigned char		_reserved_124;
	unsigned char		_reserved_125;
	MM32_USB_ERRENB		ERRENB;
	unsigned char		_reserved_126;
	unsigned char		_reserved_127;
	MM32_USB_STAT		STAT;
	unsigned char		_reserved_128;
	unsigned char		_reserved_129;
	MM32_USB_CTL		CTL;
	unsigned char		_reserved_130;
	unsigned char		_reserved_131;
	MM32_USB_ADDR		ADDR;
	unsigned char		_reserved_132;
	unsigned char		_reserved_133;
	MM32_USB_BDTPAGE1		BDTPAGE1;
	unsigned char		_reserved_134;
	unsigned char		_reserved_135;
	MM32_USB_FRMNUML		FRMNUML;
	unsigned char		_reserved_136;
	unsigned char		_reserved_137;
	MM32_USB_FRMNUMH		FRMNUMH;
	unsigned char		_reserved_138;
	unsigned char		_reserved_139;
	MM32_USB_TOKEN		TOKEN;
	unsigned char		_reserved_140;
	unsigned char		_reserved_141;
	MM32_USB_SOFTHLD		SOFTHLD;
	unsigned char		_reserved_142;
	unsigned char		_reserved_143;
	MM32_USB_BDTPAGE2		BDTPAGE2;
	unsigned char		_reserved_144;
	unsigned char		_reserved_145;
	MM32_USB_BDTPAGE3		BDTPAGE3;
	unsigned char		_reserved_146;
	unsigned char		_reserved_147;
	unsigned char		_reserved_148;
	unsigned char		_reserved_149;
	unsigned char		_reserved_150;
	unsigned char		_reserved_151;
	unsigned char		_reserved_152;
	unsigned char		_reserved_153;
	unsigned char		_reserved_154;
	unsigned char		_reserved_155;
	MM32_USB_EPCTL0		EPCTL0;
	unsigned char		_reserved_156;
	unsigned char		_reserved_157;
	MM32_USB_EPCTL1		EPCTL1;
	unsigned char		_reserved_158;
	unsigned char		_reserved_159;
	MM32_USB_EPCTL2		EPCTL2;
	unsigned char		_reserved_160;
	unsigned char		_reserved_161;
	MM32_USB_EPCTL3		EPCTL3;
	unsigned char		_reserved_162;
	unsigned char		_reserved_163;
	MM32_USB_EPCTL4		EPCTL4;
	unsigned char		_reserved_164;
	unsigned char		_reserved_165;
	MM32_USB_EPCTL5		EPCTL5;
	unsigned char		_reserved_166;
	unsigned char		_reserved_167;
	MM32_USB_EPCTL6		EPCTL6;
	unsigned char		_reserved_168;
	unsigned char		_reserved_169;
	MM32_USB_EPCTL7		EPCTL7;
	unsigned char		_reserved_170;
	unsigned char		_reserved_171;
	MM32_USB_EPCTL8		EPCTL8;
	unsigned char		_reserved_172;
	unsigned char		_reserved_173;
	MM32_USB_EPCTL9		EPCTL9;
	unsigned char		_reserved_174;
	unsigned char		_reserved_175;
	MM32_USB_EPCTL10		EPCTL10;
	unsigned char		_reserved_176;
	unsigned char		_reserved_177;
	MM32_USB_EPCTL11		EPCTL11;
	unsigned char		_reserved_178;
	unsigned char		_reserved_179;
	MM32_USB_EPCTL12		EPCTL12;
	unsigned char		_reserved_180;
	unsigned char		_reserved_181;
	MM32_USB_EPCTL13		EPCTL13;
	unsigned char		_reserved_182;
	unsigned char		_reserved_183;
	MM32_USB_EPCTL14		EPCTL14;
	unsigned char		_reserved_184;
	unsigned char		_reserved_185;
	MM32_USB_EPCTL15		EPCTL15;
}MM32_USB;
#endif