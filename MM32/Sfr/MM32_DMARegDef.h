/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:43:27
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:07:04
 * @FilePath: \CODE\MM32\Sfr\MM32_DMARegDef.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_DMAREGDEF_H_
#define _MM32_DMAREGDEF_H_

#include "MM32_RegTypedef.h"

typedef struct _MM32_DMA_ISRBits
{
	Strict_32Bit	GIF1		:	1;
	Strict_32Bit	TCIF1		:	1;
	Strict_32Bit	HTIF1		:	1;
	Strict_32Bit	TEIF1		:	1;
	Strict_32Bit	GIF2		:	1;
	Strict_32Bit	TCIF2		:	1;
	Strict_32Bit	HTIF2		:	1;
	Strict_32Bit	TEIF2		:	1;
	Strict_32Bit	GIF3		:	1;
	Strict_32Bit	TCIF3		:	1;
	Strict_32Bit	HTIF3		:	1;
	Strict_32Bit	TEIF3		:	1;
	Strict_32Bit	GIF4		:	1;
	Strict_32Bit	TCIF4		:	1;
	Strict_32Bit	HTIF4		:	1;
	Strict_32Bit	TEIF4		:	1;
	Strict_32Bit	GIF5		:	1;
	Strict_32Bit	TCIF5		:	1;
	Strict_32Bit	HTIF5		:	1;
	Strict_32Bit	TEIF5		:	1;
	Strict_32Bit	GIF6		:	1;
	Strict_32Bit	TCIF6		:	1;
	Strict_32Bit	HTIF6		:	1;
	Strict_32Bit	TEIF6		:	1;
	Strict_32Bit	GIF7		:	1;
	Strict_32Bit	TCIF7		:	1;
	Strict_32Bit	HTIF7		:	1;
	Strict_32Bit	TEIF7		:	1;
	Strict_32Bit	_reserved_0		:	4;
}MM32_DMA_ISRBits;
typedef struct _MM32_DMA_IFCRBits
{
    Strict_32Bit	CGIF1		:	1;
    Strict_32Bit	CTCIF1		:	1;
    Strict_32Bit	CHTIF1		:	1;
    Strict_32Bit	CTEIF1		:	1;
    Strict_32Bit	CGIF2		:	1;
    Strict_32Bit	CTCIF2		:	1;
    Strict_32Bit	CHTIF2		:	1;
    Strict_32Bit	CTEIF2		:	1;
    Strict_32Bit	CGIF3		:	1;
    Strict_32Bit	CTCIF3		:	1;
    Strict_32Bit	CHTIF3		:	1;
    Strict_32Bit	CTEIF3		:	1;
    Strict_32Bit	CGIF4		:	1;
    Strict_32Bit	CTCIF4		:	1;
    Strict_32Bit	CHTIF4		:	1;
    Strict_32Bit	CTEIF4		:	1;
    Strict_32Bit	CGIF5		:	1;
    Strict_32Bit	CTCIF5		:	1;
    Strict_32Bit	CHTIF5		:	1;
    Strict_32Bit	CTEIF5		:	1;
    Strict_32Bit	CGIF6		:	1;
    Strict_32Bit	CTCIF6		:	1;
    Strict_32Bit	CHTIF6		:	1;
    Strict_32Bit	CTEIF6		:	1;
    Strict_32Bit	CGIF7		:	1;
    Strict_32Bit	CTCIF7		:	1;
    Strict_32Bit	CHTIF7		:	1;
    Strict_32Bit	CTEIF7		:	1;
    Strict_32Bit	_reserved_0		:	4;
}MM32_DMA_IFCRBits;
typedef struct _MM32_DMA_CCR1Bits
{
	Strict_32Bit	EN		:	1;
	Strict_32Bit	TCIE		:	1;
	Strict_32Bit	HTIE		:	1;
	Strict_32Bit	TEIE		:	1;
	Strict_32Bit	DIR		:	1;
	Strict_32Bit	CIRC		:	1;
	Strict_32Bit	PINC		:	1;
	Strict_32Bit	MINC		:	1;
	Strict_32Bit	PSIZE		:	2;
	Strict_32Bit	MSIZE		:	2;
	Strict_32Bit	PL		:	2;
	Strict_32Bit	MEM2MEM		:	1;
	Strict_32Bit	ARE		:	1;
	Strict_32Bit	_reserved_0		:	16;
}MM32_DMA_CCR1Bits;
typedef struct _MM32_DMA_CNDTR1Bits
{
	Strict_32Bit	NDT		:	16;
	Strict_32Bit	_reserved_0		:	16;
}MM32_DMA_CNDTR1Bits;
typedef struct _MM32_DMA_CPAR1Bits
{
	Strict_32Bit	PA		:	32;
}MM32_DMA_CPAR1Bits;
typedef struct _MM32_DMA_CMAR1Bits
{
	Strict_32Bit	MA		:	32;
}MM32_DMA_CMAR1Bits;
typedef struct _MM32_DMA_CCR2Bits
{
    Strict_32Bit	EN		:	1;
    Strict_32Bit	TCIE		:	1;
    Strict_32Bit	HTIE		:	1;
    Strict_32Bit	TEIE		:	1;
    Strict_32Bit	DIR		:	1;
    Strict_32Bit	CIRC		:	1;
    Strict_32Bit	PINC		:	1;
    Strict_32Bit	MINC		:	1;
    Strict_32Bit	PSIZE		:	2;
    Strict_32Bit	MSIZE		:	2;
    Strict_32Bit	PL		:	2;
    Strict_32Bit	MEM2MEM		:	1;
    Strict_32Bit	ARE		:	1;
    Strict_32Bit	_reserved_0		:	16;
}MM32_DMA_CCR2Bits;
typedef struct _MM32_DMA_CNDTR2Bits
{
    Strict_32Bit	NDT		:	16;
    Strict_32Bit	_reserved_0		:	16;
}MM32_DMA_CNDTR2Bits;
typedef struct _MM32_DMA_CPAR2Bits
{
        Strict_32Bit	PA		:	32;
}MM32_DMA_CPAR2Bits;
typedef struct _MM32_DMA_CMAR2Bits
{
        Strict_32Bit	MA		:	32;
}MM32_DMA_CMAR2Bits;
typedef struct _MM32_DMA_CCR3Bits
{
    Strict_32Bit	EN		:	1;
    Strict_32Bit	TCIE		:	1;
    Strict_32Bit	HTIE		:	1;
    Strict_32Bit	TEIE		:	1;
    Strict_32Bit	DIR		:	1;
    Strict_32Bit	CIRC		:	1;
    Strict_32Bit	PINC		:	1;
    Strict_32Bit	MINC		:	1;
    Strict_32Bit	PSIZE		:	2;
    Strict_32Bit	MSIZE		:	2;
    Strict_32Bit	PL		:	2;
    Strict_32Bit	MEM2MEM		:	1;
    Strict_32Bit	ARE		:	1;
    Strict_32Bit	_reserved_0		:	16;
}MM32_DMA_CCR3Bits;
typedef struct _MM32_DMA_CNDTR3Bits
{
    Strict_32Bit	NDT		:	16;
    Strict_32Bit	_reserved_0		:	16;
}MM32_DMA_CNDTR3Bits;
typedef struct _MM32_DMA_CPAR3Bits
{
        Strict_32Bit	PA		:	32;
}MM32_DMA_CPAR3Bits;
typedef struct _MM32_DMA_CMAR3Bits
{
        Strict_32Bit	MA		:	32;
}MM32_DMA_CMAR3Bits;
typedef struct _MM32_DMA_CCR4Bits
{
    Strict_32Bit	EN		:	1;
    Strict_32Bit	TCIE		:	1;
    Strict_32Bit	HTIE		:	1;
    Strict_32Bit	TEIE		:	1;
    Strict_32Bit	DIR		:	1;
    Strict_32Bit	CIRC		:	1;
    Strict_32Bit	PINC		:	1;
    Strict_32Bit	MINC		:	1;
    Strict_32Bit	PSIZE		:	2;
    Strict_32Bit	MSIZE		:	2;
    Strict_32Bit	PL		:	2;
    Strict_32Bit	MEM2MEM		:	1;
    Strict_32Bit	ARE		:	1;
    Strict_32Bit	_reserved_0		:	16;
}MM32_DMA_CCR4Bits;
typedef struct _MM32_DMA_CNDTR4Bits
{
    Strict_32Bit	NDT		:	16;
    Strict_32Bit	_reserved_0		:	16;
}MM32_DMA_CNDTR4Bits;
typedef struct _MM32_DMA_CPAR4Bits
{
        Strict_32Bit	PA		:	32;
}MM32_DMA_CPAR4Bits;
typedef struct _MM32_DMA_CMAR4Bits
{
        Strict_32Bit	MA		:	32;
}MM32_DMA_CMAR4Bits;
typedef struct _MM32_DMA_CCR5Bits
{
    Strict_32Bit	EN		:	1;
    Strict_32Bit	TCIE		:	1;
    Strict_32Bit	HTIE		:	1;
    Strict_32Bit	TEIE		:	1;
    Strict_32Bit	DIR		:	1;
    Strict_32Bit	CIRC		:	1;
    Strict_32Bit	PINC		:	1;
    Strict_32Bit	MINC		:	1;
    Strict_32Bit	PSIZE		:	2;
    Strict_32Bit	MSIZE		:	2;
    Strict_32Bit	PL		:	2;
    Strict_32Bit	MEM2MEM		:	1;
    Strict_32Bit	ARE		:	1;
    Strict_32Bit	_reserved_0		:	16;
}MM32_DMA_CCR5Bits;
typedef struct _MM32_DMA_CNDTR5Bits
{
    Strict_32Bit	NDT		:	16;
    Strict_32Bit	_reserved_0		:	16;
}MM32_DMA_CNDTR5Bits;
typedef struct _MM32_DMA_CPAR5Bits
{
        Strict_32Bit	PA		:	32;
}MM32_DMA_CPAR5Bits;
typedef struct _MM32_DMA_CMAR5Bits
{
        Strict_32Bit	MA		:	32;
}MM32_DMA_CMAR5Bits;
typedef struct _MM32_DMA_CCR6Bits
{
    Strict_32Bit	EN		:	1;
    Strict_32Bit	TCIE		:	1;
    Strict_32Bit	HTIE		:	1;
    Strict_32Bit	TEIE		:	1;
    Strict_32Bit	DIR		:	1;
    Strict_32Bit	CIRC		:	1;
    Strict_32Bit	PINC		:	1;
    Strict_32Bit	MINC		:	1;
    Strict_32Bit	PSIZE		:	2;
    Strict_32Bit	MSIZE		:	2;
    Strict_32Bit	PL		:	2;
    Strict_32Bit	MEM2MEM		:	1;
    Strict_32Bit	ARE		:	1;
    Strict_32Bit	_reserved_0		:	16;
}MM32_DMA_CCR6Bits;
typedef struct _MM32_DMA_CNDTR6Bits
{
    Strict_32Bit	NDT		:	16;
    Strict_32Bit	_reserved_0		:	16;
}MM32_DMA_CNDTR6Bits;
typedef struct _MM32_DMA_CPAR6Bits
{
        Strict_32Bit	PA		:	32;
}MM32_DMA_CPAR6Bits;
typedef struct _MM32_DMA_CMAR6Bits
{
        Strict_32Bit	MA		:	32;
}MM32_DMA_CMAR6Bits;
typedef struct _MM32_DMA_CCR7Bits
{
    Strict_32Bit	EN		:	1;
    Strict_32Bit	TCIE		:	1;
    Strict_32Bit	HTIE		:	1;
    Strict_32Bit	TEIE		:	1;
    Strict_32Bit	DIR		:	1;
    Strict_32Bit	CIRC		:	1;
    Strict_32Bit	PINC		:	1;
    Strict_32Bit	MINC		:	1;
    Strict_32Bit	PSIZE		:	2;
    Strict_32Bit	MSIZE		:	2;
    Strict_32Bit	PL		:	2;
    Strict_32Bit	MEM2MEM		:	1;
    Strict_32Bit	ARE		:	1;
    Strict_32Bit	_reserved_0		:	16;
}MM32_DMA_CCR7Bits;
typedef struct _MM32_DMA_CNDTR7Bits
{
    Strict_32Bit	NDT		:	16;
    Strict_32Bit	_reserved_0		:	16;
}MM32_DMA_CNDTR7Bits;
typedef struct _MM32_DMA_CPAR7Bits
{
        Strict_32Bit	PA		:	32;
}MM32_DMA_CPAR7Bits;
typedef struct _MM32_DMA_CMAR7Bits
{
        Strict_32Bit	MA		:	32;
}MM32_DMA_CMAR7Bits;
typedef union _MM32_DMA_ISR
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_ISRBits	B;
}MM32_DMA_ISR;
typedef union _MM32_DMA_IFCR
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_IFCRBits	B;
}MM32_DMA_IFCR;
typedef union _MM32_DMA_CCR1
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CCR1Bits	B;
}MM32_DMA_CCR1;
typedef union _MM32_DMA_CNDTR1
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CNDTR1Bits	B;
}MM32_DMA_CNDTR1;
typedef union _MM32_DMA_CPAR1
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CPAR1Bits	B;
}MM32_DMA_CPAR1;
typedef union _MM32_DMA_CMAR1
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CMAR1Bits	B;
}MM32_DMA_CMAR1;
typedef union _MM32_DMA_CCR2
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CCR2Bits	B;
}MM32_DMA_CCR2;
typedef union _MM32_DMA_CNDTR2
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CNDTR2Bits	B;
}MM32_DMA_CNDTR2;
typedef union _MM32_DMA_CPAR2
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CPAR2Bits	B;
}MM32_DMA_CPAR2;
typedef union _MM32_DMA_CMAR2
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CMAR2Bits	B;
}MM32_DMA_CMAR2;
typedef union _MM32_DMA_CCR3
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CCR3Bits	B;
}MM32_DMA_CCR3;
typedef union _MM32_DMA_CNDTR3
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CNDTR3Bits	B;
}MM32_DMA_CNDTR3;
typedef union _MM32_DMA_CPAR3
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CPAR3Bits	B;
}MM32_DMA_CPAR3;
typedef union _MM32_DMA_CMAR3
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CMAR3Bits	B;
}MM32_DMA_CMAR3;
typedef union _MM32_DMA_CCR4
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CCR4Bits	B;
}MM32_DMA_CCR4;
typedef union _MM32_DMA_CNDTR4
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CNDTR4Bits	B;
}MM32_DMA_CNDTR4;
typedef union _MM32_DMA_CPAR4
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CPAR4Bits	B;
}MM32_DMA_CPAR4;
typedef union _MM32_DMA_CMAR4
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CMAR4Bits	B;
}MM32_DMA_CMAR4;
typedef union _MM32_DMA_CCR5
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CCR5Bits	B;
}MM32_DMA_CCR5;
typedef union _MM32_DMA_CNDTR5
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CNDTR5Bits	B;
}MM32_DMA_CNDTR5;
typedef union _MM32_DMA_CPAR5
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CPAR5Bits	B;
}MM32_DMA_CPAR5;
typedef union _MM32_DMA_CMAR5
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CMAR5Bits	B;
}MM32_DMA_CMAR5;
typedef union _MM32_DMA_CCR6
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CCR6Bits	B;
}MM32_DMA_CCR6;
typedef union _MM32_DMA_CNDTR6
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CNDTR6Bits	B;
}MM32_DMA_CNDTR6;
typedef union _MM32_DMA_CPAR6
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CPAR6Bits	B;
}MM32_DMA_CPAR6;
typedef union _MM32_DMA_CMAR6
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CMAR6Bits	B;
}MM32_DMA_CMAR6;
typedef union _MM32_DMA_CCR7
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CCR7Bits	B;
}MM32_DMA_CCR7;
typedef union _MM32_DMA_CNDTR7
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CNDTR7Bits	B;
}MM32_DMA_CNDTR7;
typedef union _MM32_DMA_CPAR7
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CPAR7Bits	B;
}MM32_DMA_CPAR7;
typedef union _MM32_DMA_CMAR7
{
	uint32_t	U;
	int32_t	I;
        MM32_DMA_CMAR7Bits	B;
}MM32_DMA_CMAR7;
typedef struct _MM32_DMA
{
        MM32_DMA_ISR		ISR;
        MM32_DMA_IFCR		IFCR;
        MM32_DMA_CCR1		CCR1;
        MM32_DMA_CNDTR1		CNDTR1;
        MM32_DMA_CPAR1		CPAR1;
        MM32_DMA_CMAR1		CMAR1;
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
        MM32_DMA_CCR2		CCR2;
        MM32_DMA_CNDTR2		CNDTR2;
        MM32_DMA_CPAR2		CPAR2;
        MM32_DMA_CMAR2		CMAR2;
	unsigned char		_reserved_16;
	unsigned char		_reserved_17;
	unsigned char		_reserved_18;
	unsigned char		_reserved_19;
	unsigned char		_reserved_20;
	unsigned char		_reserved_21;
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
        MM32_DMA_CCR3		CCR3;
        MM32_DMA_CNDTR3		CNDTR3;
        MM32_DMA_CPAR3		CPAR3;
        MM32_DMA_CMAR3		CMAR3;
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
        MM32_DMA_CCR4		CCR4;
        MM32_DMA_CNDTR4		CNDTR4;
        MM32_DMA_CPAR4		CPAR4;
        MM32_DMA_CMAR4		CMAR4;
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
        MM32_DMA_CCR5		CCR5;
        MM32_DMA_CNDTR5		CNDTR5;
        MM32_DMA_CPAR5		CPAR5;
        MM32_DMA_CMAR5		CMAR5;
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
        MM32_DMA_CCR6		CCR6;
        MM32_DMA_CNDTR6		CNDTR6;
        MM32_DMA_CPAR6		CPAR6;
        MM32_DMA_CMAR6		CMAR6;
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
        MM32_DMA_CCR7		CCR7;
        MM32_DMA_CNDTR7		CNDTR7;
        MM32_DMA_CPAR7		CPAR7;
        MM32_DMA_CMAR7		CMAR7;
}MM32_DMA;
#endif
