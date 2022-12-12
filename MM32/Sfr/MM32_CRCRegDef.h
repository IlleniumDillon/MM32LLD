/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-12-11 15:53:14
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-11 15:54:23
 * @FilePath: \CODE\MM32\Sfr\MM32_CRCRegDef.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_CRCREGDEF_H_
#define _MM32_CRCREGDEF_H_

#include "MM32_RegTypedef.h"

typedef struct _MM32_CRC_DRBits
{
	Strict_32Bit	DR		:	32;
}MM32_CRC_DRBits;
typedef struct _MM32_CRC_IDRBits
{
	Strict_32Bit	IDR		:	8;
	Strict_32Bit	_reserved_0		:	24;
}MM32_CRC_IDRBits;
typedef struct _MM32_CRC_CRBits
{
	Strict_32Bit	RST		:	1;
	Strict_32Bit	AS		:	1;
	Strict_32Bit	ISIZE		:	2;
	Strict_32Bit	IES		:	1;
	Strict_32Bit	OES		:	1;
	Strict_32Bit	_reserved_0		:	26;
}MM32_CRC_CRBits;
typedef struct _MM32_CRC_MIRBits
{
	Strict_32Bit	MIR		:	32;
}MM32_CRC_MIRBits;
typedef union _MM32_CRC_DR
{
	uint32_t	U;
	int32_t	I;
	MM32_CRC_DRBits	B;
}MM32_CRC_DR;
typedef union _MM32_CRC_IDR
{
	uint32_t	U;
	int32_t	I;
	MM32_CRC_IDRBits	B;
}MM32_CRC_IDR;
typedef union _MM32_CRC_CR
{
	uint32_t	U;
	int32_t	I;
	MM32_CRC_CRBits	B;
}MM32_CRC_CR;
typedef union _MM32_CRC_MIR
{
	uint32_t	U;
	int32_t	I;
	MM32_CRC_MIRBits	B;
}MM32_CRC_MIR;
typedef struct _MM32_CRC
{
	MM32_CRC_DR		DR;
	MM32_CRC_IDR		IDR;
	MM32_CRC_CR		CR;
	MM32_CRC_MIR		MIR;
}MM32_CRC;
#endif