/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-12-11 15:53:14
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-11 15:54:04
 * @FilePath: \CODE\MM32\Sfr\MM32_COMPReg.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_COMPREG_H_
#define _MM32_COMPREG_H_

#include "MM32_RegBase.h"

#include "MM32_COMPRegDef.h"

#define MOUDLE_COMP		((MM32_COMP*)COMP_BASE)

#define COMP_COMP1_CSR		((MM32_COMP_COMP1_CSR*)(COMP_BASE+0x0C))

#define COMP_COMP2_CSR		((MM32_COMP_COMP2_CSR*)(COMP_BASE+0x10))

#define COMP_COMP_CRV		((MM32_COMP_COMP_CRV*)(COMP_BASE+0x18))

#define COMP_COMP1_POLL		((MM32_COMP_COMP1_POLL*)(COMP_BASE+0x1C))

#define COMP_COMP2_POLL		((MM32_COMP_COMP2_POLL*)(COMP_BASE+0x20))

#endif