#include <ArduinoRobotMotorBoard.h>
#include <EasyTransfer2.h>
#include <LineFollow.h>
#include <Multiplexer.h>

/*
------------------------------------------------------------------------------
~ File   : network_chip_conf.h
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

#ifndef __NETWORK_CHIP_CONF_H_
#define __NETWORK_CHIP_CONF_H_

/* ~~~~~~~~~~~~~~~~~~ Options ~~~~~~~~~~~~~~~~~~ */
/* ~~~~~~ Wi-Fi Config ~~~~~~ */
#define SSID "Your access point SSID"
#define SSID_PASSWORD "Your access point password"

/* ~~~~~~ IoT Config ~~~~~~ */
#define USERNAME "Your thinger.io User Name"
#define DEVICE_ID "Device ID on thinger.io"
#define DEVICE_CREDENTIAL "Device Credentials on thinger.io"

/* ~~~~~~ Usart Config ~~~~~~ */
#define _USART_BAUDRATE 115200

/* ~~~~~~ Buffer Control ~~~~~~ */
#define _BPM_DATA    'B'
#define _SPO2_DATA   'S'
#define _LINE_FEED   10
#define _BUFF_LENGTH 10

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#endif /* __NETWORK_CHIP_CONF_H_ */
