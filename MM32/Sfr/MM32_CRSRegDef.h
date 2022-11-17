/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:43:27
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:06:51
 * @FilePath: \CODE\MM32\Sfr\MM32_CRSRegDef.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_CRSREGDEF_H_
#define _MM32_CRSREGDEF_H_

#include "MM32_RegTypedef.h"

typedef struct _MM32_CRS_CRBits
{
	Strict_32Bit	SYNCOKIE		:	1;
	Strict_32Bit	SYNCWARNIE		:	1;
	Strict_32Bit	ERRIE		:	1;
	Strict_32Bit	ESYNCIE		:	1;
	Strict_32Bit	_reserved_0		:	1;
	Strict_32Bit	CEN		:	1;
	Strict_32Bit	AUTOTRIMEN		:	1;
	Strict_32Bit	SWSYNC		:	1;
	Strict_32Bit	TRIM		:	10;
	Strict_32Bit	_reserved_1		:	14;
}MM32_CRS_CRBits;
typedef struct _MM32_CRS_CFGRBits
{
	Strict_32Bit	RELOAD		:	16;
	Strict_32Bit	FELIM		:	8;
	Strict_32Bit	SYNCDIV		:	3;
	Strict_32Bit	_reserved_0		:	1;
	Strict_32Bit	SYNCSRC		:	2;
	Strict_32Bit	_reserved_1		:	1;
	Strict_32Bit	SYNCPOL		:	1;
}MM32_CRS_CFGRBits;
typedef struct _MM32_CRS_ISRBits
{
	Strict_32Bit	SYNCOKF		:	1;
	Strict_32Bit	SYNCWARNF		:	1;
	Strict_32Bit	ERRF		:	1;
	Strict_32Bit	ESYNCF		:	1;
	Strict_32Bit	_reserved_0		:	4;
	Strict_32Bit	SYNCERR		:	1;
	Strict_32Bit	SYNCMISS		:	1;
	Strict_32Bit	TRIMOVF		:	1;
	Strict_32Bit	_reserved_1		:	4;
	Strict_32Bit	FEDIR		:	1;
	Strict_32Bit	FECAP		:	16;
}MM32_CRS_ISRBits;
typedef struct _MM32_CRS_ICRBits
{
	Strict_32Bit	SYNCOKC		:	1;
	Strict_32Bit	SYNCWARNC		:	1;
	Strict_32Bit	ERRC		:	1;
	Strict_32Bit	ESYNCC		:	1;
	Strict_32Bit	_reserved_0		:	12;
}MM32_CRS_ICRBits;
typedef union _MM32_CRS_CR
{
	uint32_t	U;
	int32_t	I;
	MM32_CRS_CRBits	B;
}MM32_CRS_CR;
typedef union _MM32_CRS_CFGR
{
	uint32_t	U;
	int32_t	I;
	MM32_CRS_CFGRBits	B;
}MM32_CRS_CFGR;
typedef union _MM32_CRS_ISR
{
	uint32_t	U;
	int32_t	I;
	MM32_CRS_ISRBits	B;
}MM32_CRS_ISR;
typedef union _MM32_CRS_ICR
{
	uint32_t	U;
	int32_t	I;
	MM32_CRS_ICRBits	B;
}MM32_CRS_ICR;
typedef struct _MM32_CRS
{
	MM32_CRS_CR		CR;
	MM32_CRS_CFGR		CFGR;
	MM32_CRS_ISR		ISR;
	MM32_CRS_ICR		ICR;
}MM32_CRS;
#endif