/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:43:27
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:07:24
 * @FilePath: \CODE\MM32\Sfr\MM32_IWDGRegDef.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_IWDGREGDEF_H_
#define _MM32_IWDGREGDEF_H_

#include "MM32_RegTypedef.h"

typedef struct _MM32_IWDG_KRBits
{
	Strict_32Bit	KEY		:	16;
	Strict_32Bit	_reserved_0		:	16;
}MM32_IWDG_KRBits;
typedef struct _MM32_IWDG_PRBits
{
	Strict_32Bit	PR		:	3;
	Strict_32Bit	_reserved_0		:	29;
}MM32_IWDG_PRBits;
typedef struct _MM32_IWDG_RLRBits
{
	Strict_32Bit	RL		:	12;
	Strict_32Bit	_reserved_0		:	20;
}MM32_IWDG_RLRBits;
typedef struct _MM32_IWDG_SRBits
{
	Strict_32Bit	PVU		:	1;
	Strict_32Bit	RVU		:	1;
	Strict_32Bit	IVU		:	1;
	Strict_32Bit	UPDATE		:	1;
	Strict_32Bit	_reserved_0		:	28;
}MM32_IWDG_SRBits;
typedef struct _MM32_IWDG_CRBits
{
	Strict_32Bit	IRQ_SEL		:	1;
	Strict_32Bit	IRQ_CLR		:	1;
	Strict_32Bit	_reserved_0		:	30;
}MM32_IWDG_CRBits;
typedef struct _MM32_IWDG_IGENBits
{
	Strict_32Bit	IGEN		:	12;
	Strict_32Bit	_reserved_0		:	20;
}MM32_IWDG_IGENBits;
typedef struct _MM32_IWDG_CNTBits
{
	Strict_32Bit	IWDG_CNT		:	12;
	Strict_32Bit	_reserved_0		:	20;
}MM32_IWDG_CNTBits;
typedef struct _MM32_IWDG_PSBits
{
	Strict_32Bit	IWDG_PS		:	8;
	Strict_32Bit	_reserved_0		:	24;
}MM32_IWDG_PSBits;
typedef union _MM32_IWDG_KR
{
	uint32_t	U;
	int32_t	I;
	MM32_IWDG_KRBits	B;
}MM32_IWDG_KR;
typedef union _MM32_IWDG_PR
{
	uint32_t	U;
	int32_t	I;
	MM32_IWDG_PRBits	B;
}MM32_IWDG_PR;
typedef union _MM32_IWDG_RLR
{
	uint32_t	U;
	int32_t	I;
	MM32_IWDG_RLRBits	B;
}MM32_IWDG_RLR;
typedef union _MM32_IWDG_SR
{
	uint32_t	U;
	int32_t	I;
	MM32_IWDG_SRBits	B;
}MM32_IWDG_SR;
typedef union _MM32_IWDG_CR
{
	uint32_t	U;
	int32_t	I;
	MM32_IWDG_CRBits	B;
}MM32_IWDG_CR;
typedef union _MM32_IWDG_IGEN
{
	uint32_t	U;
	int32_t	I;
	MM32_IWDG_IGENBits	B;
}MM32_IWDG_IGEN;
typedef union _MM32_IWDG_CNT
{
	uint32_t	U;
	int32_t	I;
	MM32_IWDG_CNTBits	B;
}MM32_IWDG_CNT;
typedef union _MM32_IWDG_PS
{
	uint32_t	U;
	int32_t	I;
	MM32_IWDG_PSBits	B;
}MM32_IWDG_PS;
typedef struct _MM32_IWDG
{
	MM32_IWDG_KR		KR;
	MM32_IWDG_PR		PR;
	MM32_IWDG_RLR		RLR;
	MM32_IWDG_SR		SR;
	MM32_IWDG_CR		CR;
	MM32_IWDG_IGEN		IGEN;
	MM32_IWDG_CNT		CNT;
	MM32_IWDG_PS		PS;
}MM32_IWDG;
#endif