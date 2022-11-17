/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:43:27
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:07:14
 * @FilePath: \CODE\MM32\Sfr\MM32_FLASHRegDef.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_FLASHREGDEF_H_
#define _MM32_FLASHREGDEF_H_

#include "MM32_RegTypedef.h"

typedef struct _MM32_FLASH_ACRBits
{
	Strict_32Bit	LATENCY		:	3;
	Strict_32Bit	_reserved_0		:	1;
	Strict_32Bit	PRFTBE		:	1;
	Strict_32Bit	PRFTBS		:	1;
	Strict_32Bit	_reserved_1		:	26;
}MM32_FLASH_ACRBits;
typedef struct _MM32_FLASH_KEYRBits
{
	Strict_32Bit	FKEYR		:	32;
}MM32_FLASH_KEYRBits;
typedef struct _MM32_FLASH_OPTKEYRBits
{
	Strict_32Bit	OPTKEYR		:	32;
}MM32_FLASH_OPTKEYRBits;
typedef struct _MM32_FLASH_SRBits
{
	Strict_32Bit	BSY		:	1;
	Strict_32Bit	_reserved_0		:	1;
	Strict_32Bit	PGERR		:	1;
	Strict_32Bit	_reserved_1		:	1;
	Strict_32Bit	WRPRTERR		:	1;
	Strict_32Bit	EOP		:	1;
	Strict_32Bit	_reserved_2		:	26;
}MM32_FLASH_SRBits;
typedef struct _MM32_FLASH_CRBits
{
	Strict_32Bit	PG		:	1;
	Strict_32Bit	PER		:	1;
	Strict_32Bit	MER		:	1;
	Strict_32Bit	_reserved_0		:	1;
	Strict_32Bit	OPTPG		:	1;
	Strict_32Bit	OPTER		:	1;
	Strict_32Bit	STRT		:	1;
	Strict_32Bit	LOCK		:	1;
	Strict_32Bit	_reserved_1		:	1;
	Strict_32Bit	OPTWRE		:	1;
	Strict_32Bit	_reserved_2		:	22;
}MM32_FLASH_CRBits;
typedef struct _MM32_FLASH_ARBits
{
	Strict_32Bit	FAR		:	32;
}MM32_FLASH_ARBits;
typedef struct _MM32_FLASH_OBRBits
{
	Strict_32Bit	OPTERR		:	1;
	Strict_32Bit	_reserved_0		:	1;
	Strict_32Bit	WDG_SW		:	1;
	Strict_32Bit	nRST_STOP		:	1;
	Strict_32Bit	nRST_STDBY		:	1;
	Strict_32Bit	_reserved_1		:	5;
	Strict_32Bit	Data0		:	8;
	Strict_32Bit	Data1		:	8;
	Strict_32Bit	_reserved_2		:	6;
}MM32_FLASH_OBRBits;
typedef struct _MM32_FLASH_WRPR1Bits
{
	Strict_32Bit	WRP		:	32;
}MM32_FLASH_WRPR1Bits;
typedef struct _MM32_FLASH_WRPR2Bits
{
	Strict_32Bit	WRP		:	32;
}MM32_FLASH_WRPR2Bits;
typedef struct _MM32_FLASH_WRPR3Bits
{
	Strict_32Bit	WRP		:	32;
}MM32_FLASH_WRPR3Bits;
typedef struct _MM32_FLASH_WRPR4Bits
{
	Strict_32Bit	WRP		:	32;
}MM32_FLASH_WRPR4Bits;
typedef union _MM32_FLASH_ACR
{
	uint32_t	U;
	int32_t	I;
	MM32_FLASH_ACRBits	B;
}MM32_FLASH_ACR;
typedef union _MM32_FLASH_KEYR
{
	uint32_t	U;
	int32_t	I;
	MM32_FLASH_KEYRBits	B;
}MM32_FLASH_KEYR;
typedef union _MM32_FLASH_OPTKEYR
{
	uint32_t	U;
	int32_t	I;
	MM32_FLASH_OPTKEYRBits	B;
}MM32_FLASH_OPTKEYR;
typedef union _MM32_FLASH_SR
{
	uint32_t	U;
	int32_t	I;
	MM32_FLASH_SRBits	B;
}MM32_FLASH_SR;
typedef union _MM32_FLASH_CR
{
	uint32_t	U;
	int32_t	I;
	MM32_FLASH_CRBits	B;
}MM32_FLASH_CR;
typedef union _MM32_FLASH_AR
{
	uint32_t	U;
	int32_t	I;
	MM32_FLASH_ARBits	B;
}MM32_FLASH_AR;
typedef union _MM32_FLASH_OBR
{
	uint32_t	U;
	int32_t	I;
	MM32_FLASH_OBRBits	B;
}MM32_FLASH_OBR;
typedef union _MM32_FLASH_WRPR1
{
	uint32_t	U;
	int32_t	I;
	MM32_FLASH_WRPR1Bits	B;
}MM32_FLASH_WRPR1;
typedef union _MM32_FLASH_WRPR2
{
	uint32_t	U;
	int32_t	I;
	MM32_FLASH_WRPR2Bits	B;
}MM32_FLASH_WRPR2;
typedef union _MM32_FLASH_WRPR3
{
	uint32_t	U;
	int32_t	I;
	MM32_FLASH_WRPR3Bits	B;
}MM32_FLASH_WRPR3;
typedef union _MM32_FLASH_WRPR4
{
	uint32_t	U;
	int32_t	I;
	MM32_FLASH_WRPR4Bits	B;
}MM32_FLASH_WRPR4;
typedef struct _MM32_FLASH
{
	MM32_FLASH_ACR		ACR;
	MM32_FLASH_KEYR		KEYR;
	MM32_FLASH_OPTKEYR		OPTKEYR;
	MM32_FLASH_SR		SR;
	MM32_FLASH_CR		CR;
	MM32_FLASH_AR		AR;
	unsigned char		_reserved_0;
	unsigned char		_reserved_1;
	unsigned char		_reserved_2;
	unsigned char		_reserved_3;
	MM32_FLASH_OBR		OBR;
	MM32_FLASH_WRPR1		WRPR1;
	MM32_FLASH_WRPR2		WRPR2;
	MM32_FLASH_WRPR3		WRPR3;
	MM32_FLASH_WRPR4		WRPR4;
}MM32_FLASH;
#endif