/*
------------------------------------------------------------------------------
~ File   : lcd_conf.h
~ Author : Majid Derhambakhsh
~ Version: V0.0.0
~ Created: 12/23/2019 10:23:00 AM
~ Brief  :
~ Support:
           E-Mail : Majid.Derhambakhsh@gmail.com (subject : Embedded Library Support)
           
           Github : https://github.com/Majid-Derhambakhsh
------------------------------------------------------------------------------
~ Description:    

~ Attention  :    

~ Changes    :    
------------------------------------------------------------------------------
*/

#ifndef __LCD_CONF_H_
#define __LCD_CONF_H_

/* ~~~~~~~~~~~~~~~~~~ Options ~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~ LCD Pin ~~~~~~ */
#define LCD_CS     A3
#define LCD_CD     A2
#define LCD_WR     A1
#define LCD_RD     A0
#define LCD_RESET  11

/* ~~~~~~ LCD RGB Color Code ~~~~~~ */
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define GRAY    0x6E7A

/* ~~~~~~ LCD Size ~~~~~~ */
#define _LCD_WIDTH  240
#define _LCD_HEIGHT 320

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#endif /* __LCD_CONF_H_ */
