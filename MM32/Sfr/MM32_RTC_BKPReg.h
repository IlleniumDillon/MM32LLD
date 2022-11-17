/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:43:27
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:07:41
 * @FilePath: \CODE\MM32\Sfr\MM32_RTC_BKPReg.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_RTC_BKPREG_H_
#define _MM32_RTC_BKPREG_H_

#include "MM32_RegBase.h"

#include "MM32_RTC_BKPRegDef.h"

#define MOUDLE_RTC_BKP		((MM32_RTC_BKP*)RTC_BKP_BASE)

#define RTC_BKP_CRH		((MM32_RTC_BKP_CRH*)(RTC_BKP_BASE+0X00))

#define RTC_BKP_CRL		((MM32_RTC_BKP_CRL*)(RTC_BKP_BASE+0X04))

#define RTC_BKP_PRLH		((MM32_RTC_BKP_PRLH*)(RTC_BKP_BASE+0X08))

#define RTC_BKP_PRLL		((MM32_RTC_BKP_PRLL*)(RTC_BKP_BASE+0X0C))

#define RTC_BKP_DIVH		((MM32_RTC_BKP_DIVH*)(RTC_BKP_BASE+0X10))

#define RTC_BKP_DIVL		((MM32_RTC_BKP_DIVL*)(RTC_BKP_BASE+0X14))

#define RTC_BKP_CNTH		((MM32_RTC_BKP_CNTH*)(RTC_BKP_BASE+0X18))

#define RTC_BKP_CNTL		((MM32_RTC_BKP_CNTL*)(RTC_BKP_BASE+0X1C))

#define RTC_BKP_ALRH		((MM32_RTC_BKP_ALRH*)(RTC_BKP_BASE+0X20))

#define RTC_BKP_ALRL		((MM32_RTC_BKP_ALRL*)(RTC_BKP_BASE+0X24))

#define RTC_BKP_MSRH		((MM32_RTC_BKP_MSRH*)(RTC_BKP_BASE+0X28))

#define RTC_BKP_MSRL		((MM32_RTC_BKP_MSRL*)(RTC_BKP_BASE+0X2C))

#define RTC_BKP_LSE_CFG		((MM32_RTC_BKP_LSE_CFG*)(RTC_BKP_BASE+0X3C))

#define RTC_BKP_BKP_RTCCR		((MM32_RTC_BKP_BKP_RTCCR*)(RTC_BKP_BASE+0X40))

#define RTC_BKP_BKP_CR		((MM32_RTC_BKP_BKP_CR*)(RTC_BKP_BASE+0X44))

#define RTC_BKP_BKP_CSR		((MM32_RTC_BKP_BKP_CSR*)(RTC_BKP_BASE+0X48))

#define RTC_BKP_BKP_DR1		((MM32_RTC_BKP_BKP_DR1*)(RTC_BKP_BASE+0X50))

#define RTC_BKP_BKP_DR2		((MM32_RTC_BKP_BKP_DR2*)(RTC_BKP_BASE+0X54))

#define RTC_BKP_BKP_DR3		((MM32_RTC_BKP_BKP_DR3*)(RTC_BKP_BASE+0X58))

#define RTC_BKP_BKP_DR4		((MM32_RTC_BKP_BKP_DR4*)(RTC_BKP_BASE+0X5C))

#define RTC_BKP_BKP_DR5		((MM32_RTC_BKP_BKP_DR5*)(RTC_BKP_BASE+0X60))

#define RTC_BKP_BKP_DR6		((MM32_RTC_BKP_BKP_DR6*)(RTC_BKP_BASE+0X64))

#define RTC_BKP_BKP_DR7		((MM32_RTC_BKP_BKP_DR7*)(RTC_BKP_BASE+0X68))

#define RTC_BKP_BKP_DR8		((MM32_RTC_BKP_BKP_DR8*)(RTC_BKP_BASE+0X6C))

#define RTC_BKP_BKP_DR9		((MM32_RTC_BKP_BKP_DR9*)(RTC_BKP_BASE+0X70))

#define RTC_BKP_BKP_DR10		((MM32_RTC_BKP_BKP_DR10*)(RTC_BKP_BASE+0X74))

#define RTC_BKP_BKP_DR11		((MM32_RTC_BKP_BKP_DR11*)(RTC_BKP_BASE+0X78))

#define RTC_BKP_BKP_DR12		((MM32_RTC_BKP_BKP_DR12*)(RTC_BKP_BASE+0X7C))

#define RTC_BKP_BKP_DR13		((MM32_RTC_BKP_BKP_DR13*)(RTC_BKP_BASE+0X80))

#define RTC_BKP_BKP_DR14		((MM32_RTC_BKP_BKP_DR14*)(RTC_BKP_BASE+0X84))

#define RTC_BKP_BKP_DR15		((MM32_RTC_BKP_BKP_DR15*)(RTC_BKP_BASE+0X88))

#define RTC_BKP_BKP_DR16		((MM32_RTC_BKP_BKP_DR16*)(RTC_BKP_BASE+0X8C))

#define RTC_BKP_BKP_DR17		((MM32_RTC_BKP_BKP_DR17*)(RTC_BKP_BASE+0X90))

#define RTC_BKP_BKP_DR18		((MM32_RTC_BKP_BKP_DR18*)(RTC_BKP_BASE+0X94))

#define RTC_BKP_BKP_DR19		((MM32_RTC_BKP_BKP_DR19*)(RTC_BKP_BASE+0X98))

#define RTC_BKP_BKP_DR20		((MM32_RTC_BKP_BKP_DR20*)(RTC_BKP_BASE+0X9C))

#endif