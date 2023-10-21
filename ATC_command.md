# SUCA
Space Université Côte d'Azur Board for Education

Version 0.1, September, 2023

Author: Fabien Ferrero, Manh Thao Nguyen, Trinh Le Huy, Xuan Minh

# ATC-COMMAND

The LORA-WAN AT-COMMAND are based on the RUI3 platform provided by RAK : [RUI3 AT-COMMAND](https://docs.rakwireless.com/RUI3/Serial-Operating-Modes/AT-Command-Manual/#content)

Additional custom AT-COMMAND are provided to access to the specific feature of SUCA board.

## General purpose
*	ATC+VERSION? : return version of the ATC firmware

## Temperature-Humidity (SHT-C3)
*	ATC+SHT : Init SHT sensor, need to be activitated to measure temperature and humidity
*	ATC+TEMP=? : return the value of temperature with 0.01° resolution, return 0 if not available
*	ATC+HUM=? return the value of humidity with 1% resolution, return 0 if not available

## Accelerometer (KX023-1025-FR)
*	ATC+KX023 : Init KX023 sensor, need to be activated to measure acceleration
*	ATC+AX=? : return the value of X acceleration with 0.01G resolution, return 0 if not available
*	ATC+AY=? : return the value of Y acceleration with 0.01G resolution, return 0 if not available
*	ATC+AZ? : return the value of Z acceleration with 0.01G resolution, return 0 if not available
## GPS (LC76F)
*	ATC+GPS? : return 1 if LC76F is available, return 0 of not
*	ATC+GPSPW=? : 1:0 Turn ON GPS LDO/ Turn OFF GPS LDO, return OK
*	ATC+GPSSAT=? : return number of satellite available
*	ATC+GPSTIME=? : return GPS time in EPOCH format, 0 if not available
*	ATC+GPSLAT=? : return GPS Latitude, 0 if not available
*	ATC+GPSLON=? : return GPS Longitude, 0 if not available
*	ATC+GPSALT=? : return GPS Altitude, 0 if not available
## Battery voltage
*	ATC+BAT=? : return battery voltage in mv, 0 if not available


# License


This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

<img src="https://github.com/FabienFerrero/UCA21/blob/main/Doc/Pictures/UCA_logo.png">

Maintained by Fabien Ferrero and Trinh Le Huy
