# SUCA
Space Université Côte d'Azur Board for Education

Version 0.1, September, 2023

Author: Fabien Ferrero, Manh Thao Nguyen, Trinh Le Huy, Xuan Minh

This board was developed for education to support courses on embedded software, digital and analog electronic, telecommunication, signal processing and IoT.

# What's new
- Lithium battery charger + JST-PH 2pin connector : MCP73831
- Accelerometer sensor : KXTJ3-1057
- Temp/Humidity sensor : SHTC3
- Light sensor : LTR-303A
- GNSS receiver : LC76D
- Optimized sleep mode to 5uA

The board is fabricated by RFThings.

<img src="https://github.com/FabienFerrero/SUCA/blob/main/Document/pic/bot.jpg">

# Wiring

<img src="https://github.com/FabienFerrero/SUCA/blob/main/Document/pic/bloc.jpg">


```
 ESP32-C3(BLE)     RAK3172 (LoRa)          LC76D (GNSS)
                   Module
 Rx1 (GPIOX) <----> Tx (GPIOX)          
 Tx1 (GPIOX) <----> Rx (GPIOX)          
 MOSI  (D11) <----> MOSI          <---->
 3.3V        <----> Vcc
 
 ```
 
 <img src="https://github.com/FabienFerrero/SUCA/blob/main/Document/pic/top.jpg">
 
 
# USB Driver
The board is using ESP32-C3 MCU for USB. You may need to install the driver to use the board:
https://sparks.gogo.co.nz/ch340.html


<img src="https://github.com/FabienFerrero/SUCA/blob/main/Document/pic/usb.jpg">



# Board Programming - Board Manager

 1. [Download and install the Arduino IDE](https://www.arduino.cc/en/Main/Software) (at least version v1.6.8)
 2. Start the Arduino IDE
 3. Go into Preferences
  Add 
 ```
 https://rfthings.github.io/ArduinoBoardManagerJSON/package_rfthings-avr_index.json
 ```
 as an "Additional Board Manager URL"
 
 4. Open the Boards Manager from the Tools -> Board menu and install "RFTHings AVR Boards by RFThings Vietnam"
 5. Select your RFTHings UCA board from the Tools -> Board menu
 6. Select Board version "3.9 and newer : AT328PB" from the Tools -> Board menu
 7. Select the port

# Schematic

The schematic of the PCB is available in the Schematic section.
[RF210-C3] (https://github.com/FabienFerrero/SUCA/blob/main/Schematic/RF210-C3.pdf)


# License


This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

<img src="https://github.com/FabienFerrero/UCA21/blob/main/Doc/Pictures/UCA_logo.png">

Maintained by Fabien Ferrero and Trinh Le Huy
