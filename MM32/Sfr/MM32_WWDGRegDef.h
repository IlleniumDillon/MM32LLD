/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:43:27
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:08:08
 * @FilePath: \CODE\MM32\Sfr\MM32_WWDGRegDef.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_WWDGREGDEF_H_
#define _MM32_WWDGREGDEF_H_

#include "MM32_RegTypedef.h"

typedef struct _MM32_WWDG_CRBits
{
	Strict_32Bit	T		:	7;
	Strict_32Bit	WDGA		:	1;
	Strict_32Bit	_reserved_0		:	24;
}MM32_WWDG_CRBits;
typedef struct _MM32_WWDG_CFGRBits
{
	Strict_32Bit	W		:	7;
	Strict_32Bit	WDGTB		:	2;
	Strict_32Bit	EWI		:	1;
	Strict_32Bit	_reserved_0		:	22;
}MM32_WWDG_CFGRBits;
typedef struct _MM32_WWDG_SRBits
{
	Strict_32Bit	EWIF		:	1;
	Strict_32Bit	_reserved_0		:	31;
}MM32_WWDG_SRBits;
typedef union _MM32_WWDG_CR
{
	uint32_t	U;
	int32_t	I;
	MM32_WWDG_CRBits	B;
}MM32_WWDG_CR;
typedef union _MM32_WWDG_CFGR
{
	uint32_t	U;
	int32_t	I;
	MM32_WWDG_CFGRBits	B;
}MM32_WWDG_CFGR;
typedef union _MM32_WWDG_SR
{
	uint32_t	U;
	int32_t	I;
	MM32_WWDG_SRBits	B;
}MM32_WWDG_SR;
typedef struct _MM32_WWDG
{
	MM32_WWDG_CR		CR;
	MM32_WWDG_CFGR		CFGR;
	MM32_WWDG_SR		SR;
}MM32_WWDG;
#endif