/*
  user_config_override.h - user configuration overrides my_user_config.h for Tasmota

  Copyright (C) 2021  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the my_user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update my_user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/

/*
Examples :

// -- Master parameter control --------------------
#undef  CFG_HOLDER
#define CFG_HOLDER        4617                   // [Reset 1] Change this value to load SECTION1 configuration parameters to flash

// -- Setup your own Wifi settings  ---------------
#undef  STA_SSID1
#define STA_SSID1         "YourSSID"             // [Ssid1] Wifi SSID

#undef  STA_PASS1
#define STA_PASS1         "YourWifiPassword"     // [Password1] Wifi password

// -- Setup your own MQTT settings  ---------------
#undef  MQTT_HOST
#define MQTT_HOST         "your-mqtt-server.com" // [MqttHost]

#undef  MQTT_PORT
#define MQTT_PORT         1883                   // [MqttPort] MQTT port (10123 on CloudMQTT)

#undef  MQTT_USER
#define MQTT_USER         "YourMqttUser"         // [MqttUser] Optional user

#undef  MQTT_PASS
#define MQTT_PASS         "YourMqttPass"         // [MqttPassword] Optional password

// You might even pass some parameters from the command line ----------------------------
// Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

#ifdef MY_IP
#undef  WIFI_IP_ADDRESS
#define WIFI_IP_ADDRESS     MY_IP                // Set to 0.0.0.0 for using DHCP or enter a static IP address
#endif

#ifdef MY_GW
#undef  WIFI_GATEWAY
#define WIFI_GATEWAY        MY_GW                // if not using DHCP set Gateway IP address
#endif

#ifdef MY_DNS
#undef  WIFI_DNS
#define WIFI_DNS            MY_DNS               // If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif

#ifdef MY_DNS2
#undef  WIFI_DNS2
#define WIFI_DNS2           MY_DNS2              // If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif

// !!! Remember that your changes GOES AT THE BOTTOM OF THIS FILE right before the last #endif !!!
*/


#define USE_SR04                                 // Add support for HC-SR04 ultrasonic devices (+1k code)
 #define SR04_MAX_SENSOR_DISTANCE  500          // Set sensor max detection distance

 #define USE_INA219                             // [I2cDriver14] Enable INA219 (I2C address 0x40, 0x41 0x44 or 0x45) Low voltage and current sensor (+1k code)
   #define INA219_SHUNT_RESISTOR (0.100)        // 0.1 Ohm default shunt resistor, can be overriden in user_config_override or using Sensor13
 #define USE_INA226                             // [I2cDriver35] Enable INA226 (I2C address 0x40, 0x41 0x44 or 0x45) Low voltage and current sensor (+2k3 code)

#ifdef USE_ENERGY_SENSOR                        //能源统计相关固件
#undef USE_ENERGY_SENSOR
#endif


#undef USE_ENERGY_MARGIN_DETECTION              // Add support for Energy Margin detection (+1k6 code)
  #undef USE_ENERGY_POWER_LIMIT                 // Add additional support for Energy Power Limit detection (+1k2 code)
#undef USE_ENERGY_DUMMY                         // Add support for dummy Energy monitor allowing user values (+0k7 code)
#undef USE_HLW8012                              // Add support for HLW8012, BL0937 or HJL-01 Energy Monitor for Sonoff Pow and WolfBlitz
#undef USE_CSE7766                              // Add support for CSE7766 Energy Monitor for Sonoff S31 and Pow R2
#undef USE_PZEM004T                             // Add support for PZEM004T Energy monitor (+2k code)
#undef USE_PZEM_AC                              // Add support for PZEM014,016 Energy monitor (+1k1 code)
#undef USE_PZEM_DC                              // Add support for PZEM003,017 Energy monitor (+1k1 code)
#undef USE_MCP39F501                            // Add support for MCP39F501 Energy monitor as used in Shelly 2 (+3k1 code)
  #undef SDM72_SPEED                        // SDM72-Modbus RS485 serial speed (default: 9600 baud)
  #undef SDM120_SPEED                       // SDM120-Modbus RS485 serial speed (default: 2400 baud)
  #undef SDM230_SPEED                       // SDM230-Modbus RS485 serial speed (default: 9600 baud)
  #undef SDM630_SPEED                       // SDM630-Modbus RS485 serial speed (default: 9600 baud)
  #undef DDS2382_SPEED                  // Hiking DDS2382 Modbus RS485 serial speed (default: 9600 baud)
  #undef DDSU666_SPEED                      // Chint DDSU666 Modbus RS485 serial speed (default: 9600 baud)
  #undef SOLAXX1_SPEED                      // Solax X1 Modbus RS485 serial speed (default: 9600 baud)
  #undef LE01MR_SPEED                       // LE-01MR modbus baudrate (default: 9600)
  #undef LE01MR_ADDR                        // LE-01MR modbus address (default: 0x01)
#undef USE_BL09XX                               // Add support for various BL09XX Energy monitor as used in Blitzwolf SHP-10 or Sonoff Dual R3 v2 (+1k6 code)
  #undef IEM3000_SPEED                     // iEM3000-Modbus RS485 serial speed (default: 19200 baud)
  #undef IEM3000_ADDR               


#endif  // _USER_CONFIG_OVERRIDE_H_
