/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:43:27
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:07:31
 * @FilePath: \CODE\MM32\Sfr\MM32_RCCReg.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_RCCREG_H_
#define _MM32_RCCREG_H_

#include "MM32_RegBase.h"

#include "MM32_RCCRegDef.h"

#define MOUDLE_RCC		((MM32_RCC*)RCC_BASE)

#define RCC_CR		((MM32_RCC_CR*)(RCC_BASE+0X00))

#define RCC_CFGR		((MM32_RCC_CFGR*)(RCC_BASE+0X04))

#define RCC_CIR		((MM32_RCC_CIR*)(RCC_BASE+0X08))

#define RCC_AHB3RSTR		((MM32_RCC_AHB3RSTR*)(RCC_BASE+0X0C))

#define RCC_AHB2RSTR		((MM32_RCC_AHB2RSTR*)(RCC_BASE+0X10))

#define RCC_AHB1RSTR		((MM32_RCC_AHB1RSTR*)(RCC_BASE+0X14))

#define RCC_APB2RSTR		((MM32_RCC_APB2RSTR*)(RCC_BASE+0X18))

#define RCC_APB1RSTR		((MM32_RCC_APB1RSTR*)(RCC_BASE+0X1C))

#define RCC_AHB3ENR		((MM32_RCC_AHB3ENR*)(RCC_BASE+0X20))

#define RCC_AHB2ENR		((MM32_RCC_AHB2ENR*)(RCC_BASE+0X24))

#define RCC_AHB1ENR		((MM32_RCC_AHB1ENR*)(RCC_BASE+0X28))

#define RCC_APB2ENR		((MM32_RCC_APB2ENR*)(RCC_BASE+0X2C))

#define RCC_APB1ENR		((MM32_RCC_APB1ENR*)(RCC_BASE+0X30))

#define RCC_BDCR		((MM32_RCC_BDCR*)(RCC_BASE+0X34))

#define RCC_CSR		((MM32_RCC_CSR*)(RCC_BASE+0X38))

#define RCC_SYSCFG		((MM32_RCC_SYSCFG*)(RCC_BASE+0X3C))

#define RCC_CFGR2		((MM32_RCC_CFGR2*)(RCC_BASE+0X40))

#define RCC_ICSCR		((MM32_RCC_ICSCR*)(RCC_BASE+0X44))

#define RCC_PLLCFGR		((MM32_RCC_PLLCFGR*)(RCC_BASE+0X48))

#endif