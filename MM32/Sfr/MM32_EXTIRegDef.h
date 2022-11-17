/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:43:27
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:07:09
 * @FilePath: \CODE\MM32\Sfr\MM32_EXTIRegDef.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_EXTIREGDEF_H_
#define _MM32_EXTIREGDEF_H_

#include "MM32_RegTypedef.h"

typedef struct _MM32_EXTI_IMRBits
{
	Strict_32Bit	IMR		:	32;
}MM32_EXTI_IMRBits;
typedef struct _MM32_EXTI_EMRBits
{
	Strict_32Bit	EMR		:	32;
}MM32_EXTI_EMRBits;
typedef struct _MM32_EXTI_RTSRBits
{
	Strict_32Bit	TR		:	32;
}MM32_EXTI_RTSRBits;
typedef struct _MM32_EXTI_FTSRBits
{
	Strict_32Bit	TR		:	32;
}MM32_EXTI_FTSRBits;
typedef struct _MM32_EXTI_SWIERBits
{
	Strict_32Bit	SWIER		:	32;
}MM32_EXTI_SWIERBits;
typedef struct _MM32_EXTI_PRBits
{
	Strict_32Bit	PR		:	32;
}MM32_EXTI_PRBits;
typedef union _MM32_EXTI_IMR
{
	uint32_t	U;
	int32_t	I;
	MM32_EXTI_IMRBits	B;
}MM32_EXTI_IMR;
typedef union _MM32_EXTI_EMR
{
	uint32_t	U;
	int32_t	I;
	MM32_EXTI_EMRBits	B;
}MM32_EXTI_EMR;
typedef union _MM32_EXTI_RTSR
{
	uint32_t	U;
	int32_t	I;
	MM32_EXTI_RTSRBits	B;
}MM32_EXTI_RTSR;
typedef union _MM32_EXTI_FTSR
{
	uint32_t	U;
	int32_t	I;
	MM32_EXTI_FTSRBits	B;
}MM32_EXTI_FTSR;
typedef union _MM32_EXTI_SWIER
{
	uint32_t	U;
	int32_t	I;
	MM32_EXTI_SWIERBits	B;
}MM32_EXTI_SWIER;
typedef union _MM32_EXTI_PR
{
	uint32_t	U;
	int32_t	I;
	MM32_EXTI_PRBits	B;
}MM32_EXTI_PR;
typedef struct _MM32_EXTI
{
	MM32_EXTI_IMR		IMR;
	MM32_EXTI_EMR		EMR;
	MM32_EXTI_RTSR		RTSR;
	MM32_EXTI_FTSR		FTSR;
	MM32_EXTI_SWIER		SWIER;
	MM32_EXTI_PR		PR;
}MM32_EXTI;
#endif