/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-12-11 15:53:14
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-11 15:56:12
 * @FilePath: \CODE\MM32\Sfr\MM32_FSMCRegDef.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_FSMCREGDEF_H_
#define _MM32_FSMCREGDEF_H_

#include "MM32_RegTypedef.h"

typedef struct _MM32_FSMC_SMSKR0Bits
{
	Strict_32Bit	MEM_SIZE		:	5;
	Strict_32Bit	MEM_TYPE		:	3;
	Strict_32Bit	REG_SELECT		:	3;
	Strict_32Bit	_reserved_0		:	21;
}MM32_FSMC_SMSKR0Bits;
typedef struct _MM32_FSMC_SMSKR1Bits
{
	Strict_32Bit	MEM_SIZE		:	5;
	Strict_32Bit	MEM_TYPE		:	3;
	Strict_32Bit	REG_SELECT		:	3;
	Strict_32Bit	_reserved_0		:	21;
}MM32_FSMC_SMSKR1Bits;
typedef struct _MM32_FSMC_SMSKR2Bits
{
	Strict_32Bit	MEM_SIZE		:	5;
	Strict_32Bit	MEM_TYPE		:	3;
	Strict_32Bit	REG_SELECT		:	3;
	Strict_32Bit	_reserved_0		:	21;
}MM32_FSMC_SMSKR2Bits;
typedef struct _MM32_FSMC_SMSKR3Bits
{
	Strict_32Bit	MEM_SIZE		:	5;
	Strict_32Bit	MEM_TYPE		:	3;
	Strict_32Bit	REG_SELECT		:	3;
	Strict_32Bit	_reserved_0		:	21;
}MM32_FSMC_SMSKR3Bits;
typedef struct _MM32_FSMC_SMTMGR_SET0Bits
{
	Strict_32Bit	T_RC		:	6;
	Strict_32Bit	T_AS		:	2;
	Strict_32Bit	T_WR		:	2;
	Strict_32Bit	T_WP		:	6;
	Strict_32Bit	_reserved_0		:	10;
	Strict_32Bit	READY_MODE		:	1;
	Strict_32Bit	_reserved_1		:	1;
	Strict_32Bit	SM_READ_PIPE		:	2;
	Strict_32Bit	_reserved_2		:	2;
}MM32_FSMC_SMTMGR_SET0Bits;
typedef struct _MM32_FSMC_SMTMGR_SET1Bits
{
	Strict_32Bit	T_RC		:	6;
	Strict_32Bit	T_AS		:	2;
	Strict_32Bit	T_WR		:	2;
	Strict_32Bit	T_WP		:	6;
	Strict_32Bit	_reserved_0		:	10;
	Strict_32Bit	READY_MODE		:	1;
	Strict_32Bit	_reserved_1		:	1;
	Strict_32Bit	SM_READ_PIPE		:	2;
	Strict_32Bit	_reserved_2		:	2;
}MM32_FSMC_SMTMGR_SET1Bits;
typedef struct _MM32_FSMC_SMTMGR_SET2Bits
{
	Strict_32Bit	T_RC		:	6;
	Strict_32Bit	T_AS		:	2;
	Strict_32Bit	T_WR		:	2;
	Strict_32Bit	T_WP		:	6;
	Strict_32Bit	_reserved_0		:	10;
	Strict_32Bit	READY_MODE		:	1;
	Strict_32Bit	_reserved_1		:	1;
	Strict_32Bit	SM_READ_PIPE		:	2;
	Strict_32Bit	_reserved_2		:	2;
}MM32_FSMC_SMTMGR_SET2Bits;
typedef struct _MM32_FSMC_SMCTLRBits
{
	Strict_32Bit	FLASH_RP		:	1;
	Strict_32Bit	_reserved_0		:	6;
	Strict_32Bit	SM_DW0		:	3;
	Strict_32Bit	SM_DW1		:	3;
	Strict_32Bit	SM_DW2		:	3;
	Strict_32Bit	_reserved_1		:	16;
}MM32_FSMC_SMCTLRBits;
typedef union _MM32_FSMC_SMSKR0
{
	uint32_t	U;
	int32_t	I;
	MM32_FSMC_SMSKR0Bits	B;
}MM32_FSMC_SMSKR0;
typedef union _MM32_FSMC_SMSKR1
{
	uint32_t	U;
	int32_t	I;
	MM32_FSMC_SMSKR1Bits	B;
}MM32_FSMC_SMSKR1;
typedef union _MM32_FSMC_SMSKR2
{
	uint32_t	U;
	int32_t	I;
	MM32_FSMC_SMSKR2Bits	B;
}MM32_FSMC_SMSKR2;
typedef union _MM32_FSMC_SMSKR3
{
	uint32_t	U;
	int32_t	I;
	MM32_FSMC_SMSKR3Bits	B;
}MM32_FSMC_SMSKR3;
typedef union _MM32_FSMC_SMTMGR_SET0
{
	uint32_t	U;
	int32_t	I;
	MM32_FSMC_SMTMGR_SET0Bits	B;
}MM32_FSMC_SMTMGR_SET0;
typedef union _MM32_FSMC_SMTMGR_SET1
{
	uint32_t	U;
	int32_t	I;
	MM32_FSMC_SMTMGR_SET1Bits	B;
}MM32_FSMC_SMTMGR_SET1;
typedef union _MM32_FSMC_SMTMGR_SET2
{
	uint32_t	U;
	int32_t	I;
	MM32_FSMC_SMTMGR_SET2Bits	B;
}MM32_FSMC_SMTMGR_SET2;
typedef union _MM32_FSMC_SMCTLR
{
	uint32_t	U;
	int32_t	I;
	MM32_FSMC_SMCTLRBits	B;
}MM32_FSMC_SMCTLR;
typedef struct _MM32_FSMC
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
	MM32_FSMC_SMSKR0		SMSKR0;
	MM32_FSMC_SMSKR1		SMSKR1;
	MM32_FSMC_SMSKR2		SMSKR2;
	MM32_FSMC_SMSKR3		SMSKR3;
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
	unsigned char		_reserved_120;
	unsigned char		_reserved_121;
	unsigned char		_reserved_122;
	unsigned char		_reserved_123;
	unsigned char		_reserved_124;
	unsigned char		_reserved_125;
	unsigned char		_reserved_126;
	unsigned char		_reserved_127;
	unsigned char		_reserved_128;
	unsigned char		_reserved_129;
	unsigned char		_reserved_130;
	unsigned char		_reserved_131;
	MM32_FSMC_SMTMGR_SET0		_SET0;
	MM32_FSMC_SMTMGR_SET1		_SET1;
	MM32_FSMC_SMTMGR_SET2		_SET2;
	unsigned char		_reserved_132;
	unsigned char		_reserved_133;
	unsigned char		_reserved_134;
	unsigned char		_reserved_135;
	MM32_FSMC_SMCTLR		SMCTLR;
}MM32_FSMC;
#endif