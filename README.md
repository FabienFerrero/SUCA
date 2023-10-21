# SUCA
Space Université Côte d'Azur Board for Education

Version 0.1, September, 2023

Author: Fabien Ferrero, Manh Thao Nguyen, Trinh Le Huy, Xuan Minh

This board was developed for education to support courses on embedded software, digital and analog electronic, telecommunication, signal processing and IoT.
The terminal is based on a ESP32-C3 as a main MCU for user code. The ESP32-C3 is using [AT-COMMAND](#AT-COMMAND) to control a RAK3172 module.
The RAK3172 integrate a LoRaWAN transciever and is also connected to a GNSS module and different sensors.
The different features can be accessed using AT-COMMAND. 

# What's new
- Lithium battery charger + JST-PH 2pin connector : MCP73831
- Accelerometer sensor : KXTJ3-1057
- Temp/Humidity sensor : SHTC3
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
 3. Go into File/Preferences
  Add 
 ```
https://rfthings.github.io/ArduinoBoardManagerJSON/package_rfthings-esp32_index.json
 ```
 as an "Additional Board Manager URL"
 
 4. Open the Boards Manager from the Tools -> Board menu and install "RFTHings ESP32 Boards"
 5. Select 'RF210' from the Tools -> Board menu
 7. Select the port

# Schematic

The schematic of the PCB is available in the Schematic section.
[RF210-C3](https://github.com/FabienFerrero/SUCA/blob/main/Schematic/RF210-C3.pdf)


# AT-COMMAND

The LORA-WAN AT-COMMAND are based on the RUI3 platform provided by RAK : [RUI3 AT-COMMAND](https://docs.rakwireless.com/RUI3/Serial-Operating-Modes/AT-Command-Manual/#content)

Additional custom AT-COMMAND are provided to access to the specific feature of SUCA board. [ATC-COMMAND DOCUMENTATION](https://github.com/FabienFerrero/SUCA/blob/main/ATC_command.md)


# RAK3172 FIRMWARE UPDATE

The RAK3172 module must be updated to support the latest features.
The process for update can be found on this link : [RF210 RAK3172 firmware](https://github.com/XuanMinh201/RF210/tree/main)

# EXAMPLES
Several examples are available on : [Example Readme](https://github.com/FabienFerrero/SUCA/blob/main/Examples/README.md))

# License


This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

<img src="https://github.com/FabienFerrero/UCA21/blob/main/Doc/Pictures/UCA_logo.png">

Maintained by Fabien Ferrero and Trinh Le Huy
