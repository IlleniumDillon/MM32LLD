/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:43:27
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:07:51
 * @FilePath: \CODE\MM32\Sfr\MM32_SYSCFGReg.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_SYSCFGREG_H_
#define _MM32_SYSCFGREG_H_

#include "MM32_RegBase.h"

#include "MM32_SYSCFGRegDef.h"

#define MOUDLE_SYSCFG		((MM32_SYSCFG*)SYSCFG_BASE)

#define SYSCFG_CFGR1		((MM32_SYSCFG_CFGR1*)(SYSCFG_BASE+0X00))

#define SYSCFG_EXTICR1		((MM32_SYSCFG_EXTICR1*)(SYSCFG_BASE+0X08))

#define SYSCFG_EXTICR2		((MM32_SYSCFG_EXTICR2*)(SYSCFG_BASE+0X0C))

#define SYSCFG_EXTICR3		((MM32_SYSCFG_EXTICR3*)(SYSCFG_BASE+0X10))

#define SYSCFG_EXTICR4		((MM32_SYSCFG_EXTICR4*)(SYSCFG_BASE+0X14))

#define SYSCFG_CFGR2		((MM32_SYSCFG_CFGR2*)(SYSCFG_BASE+0X18))

#define SYSCFG_PDETCSR		((MM32_SYSCFG_PDETCSR*)(SYSCFG_BASE+0X1C))

#define SYSCFG_VOSDLY		((MM32_SYSCFG_VOSDLY*)(SYSCFG_BASE+0X20))

#endif