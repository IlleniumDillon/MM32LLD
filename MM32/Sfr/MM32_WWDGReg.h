/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:43:27
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:08:05
 * @FilePath: \CODE\MM32\Sfr\MM32_WWDGReg.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_WWDGREG_H_
#define _MM32_WWDGREG_H_

#include "MM32_RegBase.h"

#include "MM32_WWDGRegDef.h"

#define MOUDLE_WWDG		((MM32_WWDG*)WWDG_BASE)

#define WWDG_CR		((MM32_WWDG_CR*)(WWDG_BASE+0X00))

#define WWDG_CFGR		((MM32_WWDG_CFGR*)(WWDG_BASE+0X04))

#define WWDG_SR		((MM32_WWDG_SR*)(WWDG_BASE+0X08))

#endif