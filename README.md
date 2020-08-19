![Banner](Banner.jpg)

# IoT-Pulse-Oximeter
IoT Based 'Pulse Oximeter' With Arduino

### Version : 0.0.0

- #### Type : Embedded Software.

- #### Support : Arduino

- #### Program Language : Arduino

- #### Properties :

## How to use

### The IoT Pulse Oximeter system can be used as follows:   
#### 1.  Setup your thinger.io service:  
####   Youtube:
[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/p5sq3HfshbY/0.jpg)](https://www.youtube.com/watch?v=p5sq3HfshbY)

#### 2.  Config ESP8266 & thinger.io service in 'network_chip_conf.h' header, for example:  
   * Options:  
   
      ```c++
      /* ~~~~~~ Wi-Fi Config ~~~~~~ */
      #define SSID "Your access point SSID"
      #define SSID_PASSWORD "Your access point password"

      /* ~~~~~~ IoT Config ~~~~~~ */
      #define USERNAME "Your thinger.io User Name"
      #define DEVICE_ID "Device ID on thinger.io"
      #define DEVICE_CREDENTIAL "Device Credentials on thinger.io"
      
      ```
          
          
#### 3.  Compile and upload to ESP8266 & Arduino UNO.          
     
### Hardware:  
    
#### Developer: Majid Derhambakhsh

