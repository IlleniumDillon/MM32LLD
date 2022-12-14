/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-12-11 17:20:30
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-11 17:22:43
 * @FilePath: \CODE\MM32\Sfr\MM32_USBReg.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_USBREG_H_
#define _MM32_USBREG_H_

#include "MM32_RegBase.h"

#include "MM32_USBRegDef.h"

#define MOUDLE_USB		((MM32_USB*)USB_BASE)

#define USB_OTGISTAT		((MM32_USB_OTGISTAT*)(USB_BASE+0X10))

#define USB_OTGICTRL		((MM32_USB_OTGICTRL*)(USB_BASE+0X14))

#define USB_OTGSTAT		((MM32_USB_OTGSTAT*)(USB_BASE+0X18))

#define USB_OTGCTRL		((MM32_USB_OTGCTRL*)(USB_BASE+0X1C))

#define USB_INTSTAT		((MM32_USB_INTSTAT*)(USB_BASE+0X80))

#define USB_INTENB		((MM32_USB_INTENB*)(USB_BASE+0X84))

#define USB_ERRSTAT		((MM32_USB_ERRSTAT*)(USB_BASE+0X88))

#define USB_ERRENB		((MM32_USB_ERRENB*)(USB_BASE+0X8C))

#define USB_STAT		((MM32_USB_STAT*)(USB_BASE+0X90))

#define USB_CTL		((MM32_USB_CTL*)(USB_BASE+0X94))

#define USB_ADDR		((MM32_USB_ADDR*)(USB_BASE+0X98))

#define USB_BDTPAGE1		((MM32_USB_BDTPAGE1*)(USB_BASE+0X9C))

#define USB_FRMNUML		((MM32_USB_FRMNUML*)(USB_BASE+0XA0))

#define USB_FRMNUMH		((MM32_USB_FRMNUMH*)(USB_BASE+0XA4))

#define USB_TOKEN		((MM32_USB_TOKEN*)(USB_BASE+0XA8))

#define USB_SOFTHLD		((MM32_USB_SOFTHLD*)(USB_BASE+0XAC))

#define USB_BDTPAGE2		((MM32_USB_BDTPAGE2*)(USB_BASE+0XB0))

#define USB_BDTPAGE3		((MM32_USB_BDTPAGE3*)(USB_BASE+0XB4))

#define USB_EPCTL0		((MM32_USB_EPCTL0*)(USB_BASE+0XC0))

#define USB_EPCTL1		((MM32_USB_EPCTL1*)(USB_BASE+0XC4))

#define USB_EPCTL2		((MM32_USB_EPCTL2*)(USB_BASE+0XC8))

#define USB_EPCTL3		((MM32_USB_EPCTL3*)(USB_BASE+0XCC))

#define USB_EPCTL4		((MM32_USB_EPCTL4*)(USB_BASE+0XD0))

#define USB_EPCTL5		((MM32_USB_EPCTL5*)(USB_BASE+0XD4))

#define USB_EPCTL6		((MM32_USB_EPCTL6*)(USB_BASE+0XD8))

#define USB_EPCTL7		((MM32_USB_EPCTL7*)(USB_BASE+0XDC))

#define USB_EPCTL8		((MM32_USB_EPCTL8*)(USB_BASE+0XE0))

#define USB_EPCTL9		((MM32_USB_EPCTL9*)(USB_BASE+0XE4))

#define USB_EPCTL10		((MM32_USB_EPCTL10*)(USB_BASE+0XE8))

#define USB_EPCTL11		((MM32_USB_EPCTL11*)(USB_BASE+0XEC))

#define USB_EPCTL12		((MM32_USB_EPCTL12*)(USB_BASE+0XF0))

#define USB_EPCTL13		((MM32_USB_EPCTL13*)(USB_BASE+0XF4))

#define USB_EPCTL14		((MM32_USB_EPCTL14*)(USB_BASE+0XF8))

#define USB_EPCTL15		((MM32_USB_EPCTL15*)(USB_BASE+0XFC))

#endif