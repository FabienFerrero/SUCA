# LoRaWAN activation with The Things Network examples
Space Université Côte d'Azur Board for Education

Version 0.2, October, 2023

Author: Fabien Ferrero, Manh Thao Nguyen, Trinh Le Huy, Xuan Minh

In these examples, the ABP using TTN is shown


# The Things Network LoRaWAN network server

1. Create an account on The Things Network website: https://www.thethingsnetwork.org/get-started?login
   Connect to Europe Cluster 
    
3. Connect to "Console. It is available on your profile in the left-up scrolling table.

4. Choose application

  <img src="../Document/pic/app_gw.png">

4. Click on + create an application
   
   <img src="../Document/pic/application.png">

6. Choose a name for your application and validate
   
   <img src="../Document/pic/create_app.png">
8. Click on + Register End device
   
   <img src="../Document/pic/register_ED.png">
10. Select "manual registration, and apply the different parameters shown in attached figure.
    
   <img src="../Document/pic/register.png">
12. Click on generate for dev_adr, NwkSKey and AppSKey. You can choose a custom name for "End device ID".
    
   <img src="../Document/pic/cred.png">
14. You get now your new device. you can copy the dev_adr, NwkSKey and AppSKey to your arduino code.
    
   <img src="../Document/pic/cred2.png">

   <img src="../Document/pic/code.png">
   
15. You can upload the code to RF210. A packet should come to your TTN dashboard.


# License

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

<img src="https://github.com/FabienFerrero/UCA21/blob/main/Doc/Pictures/UCA_logo.png">

Maintained by Fabien Ferrero and Trinh Le Huy
