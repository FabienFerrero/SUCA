# SUCA EXAMPLES
Space Université Côte d'Azur Board for Education

Version 0.2, October, 2023

Author: Fabien Ferrero, Manh Thao Nguyen, Trinh Le Huy, Xuan Minh

In these examples, the main terminal features are showcased

Before starting Examples, the Arduino IDE and board manager should be installed as described in main Readme document :
[Main](main/readme.md)

# 1/ AT-COMMAND example

*  Dip Switch 2 has to be in ESP32-C3 mode to connect UART between ESP32-C3 and RAK3172

*  Open in Arduini IDE [Examples/RF210_RAK3172_bridge/RF210_RAK3172_bridge.ino](/Examples/RF210_RAK3172_bridge/RF210_RAK3172_bridge.ino)

*  Click on the upload button in Arduino IDE

* Open Serial Monitor with 115200 baud

* Type AT-Command in "Message" text box.

* For a step by step tutorial, follow this training : [atcommand](atcommand.md)

# 2/ LoRaWAN Activation by Personalization example

*  If you are not familiar with LoRaWAN, useful information is available on :   [https://www.univ-smb.fr/lorawan/en/free-book/](https://www.univ-smb.fr/lorawan/en/free-book/)

*  Open in Arduini IDE [Examples/RF210_ABP/RF210_ABP.ino](/Examples/RF210_ABP/RF210_ABP.ino)  , the code is simply providing the different AT-COMMAND to set a LoRaWan ABP transmission.

*  Update the DevAdr, NWKkey and AppsKey credential and click on upload button in Arduino IDE

*  For a step by step tutorial with TTN LoRaWAN network, follow this training : [abp_ttn](abp_ttn.md)

# License

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

<img src="https://github.com/FabienFerrero/UCA21/blob/main/Doc/Pictures/UCA_logo.png">

Maintained by Fabien Ferrero and Trinh Le Huy
