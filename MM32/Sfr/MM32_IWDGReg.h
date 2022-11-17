/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:43:27
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:07:21
 * @FilePath: \CODE\MM32\Sfr\MM32_IWDGReg.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_IWDGREG_H_
#define _MM32_IWDGREG_H_

#include "MM32_RegBase.h"

#include "MM32_IWDGRegDef.h"

#define MOUDLE_IWDG		((MM32_IWDG*)IWDG_BASE)

#define IWDG_KR		((MM32_IWDG_KR*)(IWDG_BASE+0X00))

#define IWDG_PR		((MM32_IWDG_PR*)(IWDG_BASE+0X04))

#define IWDG_RLR		((MM32_IWDG_RLR*)(IWDG_BASE+0X08))

#define IWDG_SR		((MM32_IWDG_SR*)(IWDG_BASE+0X0C))

#define IWDG_CR		((MM32_IWDG_CR*)(IWDG_BASE+0X10))

#define IWDG_IGEN		((MM32_IWDG_IGEN*)(IWDG_BASE+0X14))

#define IWDG_CNT		((MM32_IWDG_CNT*)(IWDG_BASE+0X18))

#define IWDG_PS		((MM32_IWDG_PS*)(IWDG_BASE+0X1C))

#endif