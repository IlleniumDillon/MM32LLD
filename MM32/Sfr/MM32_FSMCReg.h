/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-12-11 15:53:14
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-11 15:56:09
 * @FilePath: \CODE\MM32\Sfr\MM32_FSMCReg.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_FSMCREG_H_
#define _MM32_FSMCREG_H_

#include "MM32_RegBase.h"

#include "MM32_FSMCRegDef.h"

#define MOUDLE_FSMC		((MM32_FSMC*)FSMC_BASE)

#define FSMC_SMSKR0		((MM32_FSMC_SMSKR0*)(FSMC_BASE+0x54))

#define FSMC_SMSKR1		((MM32_FSMC_SMSKR1*)(FSMC_BASE+0x58))

#define FSMC_SMSKR2		((MM32_FSMC_SMSKR2*)(FSMC_BASE+0x5C))

#define FSMC_SMSKR3		((MM32_FSMC_SMSKR3*)(FSMC_BASE+0x60))

#define FSMC_SMTMGR_SET0		((MM32_FSMC_SMTMGR_SET0*)(FSMC_BASE+0x94))

#define FSMC_SMTMGR_SET1		((MM32_FSMC_SMTMGR_SET1*)(FSMC_BASE+0x98))

#define FSMC_SMTMGR_SET2		((MM32_FSMC_SMTMGR_SET2*)(FSMC_BASE+0x9C))

#define FSMC_SMCTLR		((MM32_FSMC_SMCTLR*)(FSMC_BASE+0xA4))

#endif