/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:43:27
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:07:26
 * @FilePath: \CODE\MM32\Sfr\MM32_PWRReg.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_PWRREG_H_
#define _MM32_PWRREG_H_

#include "MM32_RegBase.h"

#include "MM32_PWRRegDef.h"

#define MOUDLE_PWR		((MM32_PWR*)PWR_BASE)

#define PWR_CR1		((MM32_PWR_CR1*)(PWR_BASE+0X00))

#define PWR_CSR		((MM32_PWR_CSR*)(PWR_BASE+0X04))

#define PWR_CR2		((MM32_PWR_CR2*)(PWR_BASE+0X08))

#define PWR_CR3		((MM32_PWR_CR3*)(PWR_BASE+0X0C))

#define PWR_CR4		((MM32_PWR_CR4*)(PWR_BASE+0X10))

#define PWR_CR5		((MM32_PWR_CR5*)(PWR_BASE+0X14))

#define PWR_CR6		((MM32_PWR_CR6*)(PWR_BASE+0X18))

#define PWR_SR		((MM32_PWR_SR*)(PWR_BASE+0X1C))

#define PWR_SCR		((MM32_PWR_SCR*)(PWR_BASE+0X20))

#define PWR_CFGR		((MM32_PWR_CFGR*)(PWR_BASE+0X24))

#endif