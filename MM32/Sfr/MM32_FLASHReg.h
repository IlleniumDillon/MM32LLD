/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:43:27
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:07:12
 * @FilePath: \CODE\MM32\Sfr\MM32_FLASHReg.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_FLASHREG_H_
#define _MM32_FLASHREG_H_

#include "MM32_RegBase.h"

#include "MM32_FLASHRegDef.h"

#define MOUDLE_FLASH		((MM32_FLASH*)FLASH_BASE)

#define FLASH_ACR		((MM32_FLASH_ACR*)(FLASH_BASE+0X00))

#define FLASH_KEYR		((MM32_FLASH_KEYR*)(FLASH_BASE+0X04))

#define FLASH_OPTKEYR		((MM32_FLASH_OPTKEYR*)(FLASH_BASE+0X08))

#define FLASH_SR		((MM32_FLASH_SR*)(FLASH_BASE+0X0C))

#define FLASH_CR		((MM32_FLASH_CR*)(FLASH_BASE+0X10))

#define FLASH_AR		((MM32_FLASH_AR*)(FLASH_BASE+0X14))

#define FLASH_OBR		((MM32_FLASH_OBR*)(FLASH_BASE+0X1C))

#define FLASH_WRPR1		((MM32_FLASH_WRPR1*)(FLASH_BASE+0X20))

#define FLASH_WRPR2		((MM32_FLASH_WRPR2*)(FLASH_BASE+0X24))

#define FLASH_WRPR3		((MM32_FLASH_WRPR3*)(FLASH_BASE+0X28))

#define FLASH_WRPR4		((MM32_FLASH_WRPR4*)(FLASH_BASE+0X2C))

#endif