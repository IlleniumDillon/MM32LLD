/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:43:27
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:06:48
 * @FilePath: \CODE\MM32\Sfr\MM32_CRSReg.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_CRSREG_H_
#define _MM32_CRSREG_H_

#include "MM32_RegBase.h"

#include "MM32_CRSRegDef.h"

#define MOUDLE_CRS		((MM32_CRS*)CRS_BASE)

#define CRS_CR		((MM32_CRS_CR*)(CRS_BASE+0X00))

#define CRS_CFGR		((MM32_CRS_CFGR*)(CRS_BASE+0X04))

#define CRS_ISR		((MM32_CRS_ISR*)(CRS_BASE+0X08))

#define CRS_ICR		((MM32_CRS_ICR*)(CRS_BASE+0X0C))

#endif