/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-12-11 15:53:14
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-11 15:54:11
 * @FilePath: \CODE\MM32\Sfr\MM32_COMPRegDef.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_COMPREGDEF_H_
#define _MM32_COMPREGDEF_H_

#include "MM32_RegTypedef.h"

typedef struct _MM32_COMP_COMP1_CSRBits
{
	Strict_32Bit	EN		:	1;
	Strict_32Bit	_reserved_0		:	1;
	Strict_32Bit	MODE		:	2;
	Strict_32Bit	INM_SEL		:	2;
	Strict_32Bit	_reserved_1		:	1;
	Strict_32Bit	INP_SEL		:	2;
	Strict_32Bit	_reserved_2		:	1;
	Strict_32Bit	OUT_SEL		:	4;
	Strict_32Bit	_reserved_3		:	1;
	Strict_32Bit	POL		:	1;
	Strict_32Bit	HYST		:	2;
	Strict_32Bit	OFLT		:	3;
	Strict_32Bit	_reserved_4		:	9;
	Strict_32Bit	OUT		:	1;
	Strict_32Bit	LOCK		:	1;
}MM32_COMP_COMP1_CSRBits;
typedef struct _MM32_COMP_COMP2_CSRBits
{
	Strict_32Bit	EN		:	1;
	Strict_32Bit	_reserved_0		:	1;
	Strict_32Bit	MODE		:	2;
	Strict_32Bit	INM_SEL		:	2;
	Strict_32Bit	_reserved_1		:	1;
	Strict_32Bit	INP_SEL		:	2;
	Strict_32Bit	_reserved_2		:	1;
	Strict_32Bit	OUT_SEL		:	4;
	Strict_32Bit	_reserved_3		:	1;
	Strict_32Bit	POL		:	1;
	Strict_32Bit	HYST		:	2;
	Strict_32Bit	OFLT		:	3;
	Strict_32Bit	_reserved_4		:	9;
	Strict_32Bit	OUT		:	1;
	Strict_32Bit	LOCK		:	1;
}MM32_COMP_COMP2_CSRBits;
typedef struct _MM32_COMP_COMP_CRVBits
{
	Strict_32Bit	CRV_SEL		:	4;
	Strict_32Bit	CRV_EN		:	1;
	Strict_32Bit	CRV_SRC		:	1;
	Strict_32Bit	_reserved_0		:	26;
}MM32_COMP_COMP_CRVBits;
typedef struct _MM32_COMP_COMP1_POLLBits
{
	Strict_32Bit	POLL_EN		:	1;
	Strict_32Bit	POLL_CH		:	1;
	Strict_32Bit	FIXN		:	1;
	Strict_32Bit	_reserved_0		:	1;
	Strict_32Bit	PERIOD		:	3;
	Strict_32Bit	_reserved_1		:	1;
	Strict_32Bit	POUT		:	3;
	Strict_32Bit	_reserved_2		:	21;
}MM32_COMP_COMP1_POLLBits;
typedef struct _MM32_COMP_COMP2_POLLBits
{
	Strict_32Bit	POLL_EN		:	1;
	Strict_32Bit	POLL_CH		:	1;
	Strict_32Bit	FIXN		:	1;
	Strict_32Bit	_reserved_0		:	1;
	Strict_32Bit	PERIOD		:	3;
	Strict_32Bit	_reserved_1		:	1;
	Strict_32Bit	POUT		:	3;
	Strict_32Bit	_reserved_2		:	21;
}MM32_COMP_COMP2_POLLBits;
typedef union _MM32_COMP_COMP1_CSR
{
	uint32_t	U;
	int32_t	I;
	MM32_COMP_COMP1_CSRBits	B;
}MM32_COMP_COMP1_CSR;
typedef union _MM32_COMP_COMP2_CSR
{
	uint32_t	U;
	int32_t	I;
	MM32_COMP_COMP2_CSRBits	B;
}MM32_COMP_COMP2_CSR;
typedef union _MM32_COMP_COMP_CRV
{
	uint32_t	U;
	int32_t	I;
	MM32_COMP_COMP_CRVBits	B;
}MM32_COMP_COMP_CRV;
typedef union _MM32_COMP_COMP1_POLL
{
	uint32_t	U;
	int32_t	I;
	MM32_COMP_COMP1_POLLBits	B;
}MM32_COMP_COMP1_POLL;
typedef union _MM32_COMP_COMP2_POLL
{
	uint32_t	U;
	int32_t	I;
	MM32_COMP_COMP2_POLLBits	B;
}MM32_COMP_COMP2_POLL;
typedef struct _MM32_COMP
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
	MM32_COMP_COMP1_CSR		_CSR;
	MM32_COMP_COMP2_CSR		_CSR;
	unsigned char		_reserved_12;
	unsigned char		_reserved_13;
	unsigned char		_reserved_14;
	unsigned char		_reserved_15;
	MM32_COMP_COMP_CRV		_CRV;
	MM32_COMP_COMP1_POLL		_POLL;
	MM32_COMP_COMP2_POLL		_POLL;
}MM32_COMP;
#endif