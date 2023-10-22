# SUCA
Space Université Côte d'Azur Board pour l' Education

Version 0.1, September, 2023

Auteurs Fabien Ferrero, Manh Thao Nguyen, Trinh Le Huy, Xuan Minh

Ce module a été développé à des fins éducatives pour soutenir des cours sur les logiciels embarqués, l'électronique numérique et analogique, les télécommunications, le traitement des signaux et l'Internet des objets (IoT).
La carte est basée sur un ESP32-C3 en tant que MCU principal pour le code utilisateur. L'ESP32-C3 utilise la COMMANDE-AT pour contrôler un module RAK3172.
Le RAK3172 intègre un transcepteur LoRaWAN et est également connecté à un module GNSS et différents capteurs.
Les différentes fonctionnalités peuvent être accessibles à l'aide de la COMMANDE-AT.

# Nouveautés
- Chargeur Lithium battery + JST-PH 2pin connecteur : MCP73831
- Accelerometeur : KXTJ3-1057
- Temp/Humidity capteur : SHTC3
- GNSS recepteur : LC76D
- Mode endormi optimisé à 5uA

Le terminal est fabriqué par RFThings.

<img src="https://github.com/FabienFerrero/SUCA/blob/main/Document/pic/bot.jpg">

# Wiring

<img src="https://github.com/FabienFerrero/SUCA/blob/main/Document/pic/bloc.jpg">


```
 ESP32-C3(BLE)     RAK3172 (LoRa)         
                   Module
 Rx1 (GPIO20) <----> Tx (GPIOX)          
 Tx1 (GPIO21) <----> Rx (GPIOX)          
  GPIO (D10) <----> LDO Enable RAK3172          

 
 ```
 
 <img src="https://github.com/FabienFerrero/SUCA/blob/main/Document/pic/top.jpg">
 
 
# Driver USB 
La carte utilise le microcontrôleur ESP32-C3 pour l'USB. Vous pourriez avoir besoin d'installer le pilote pour utiliser la carte :
https://sparks.gogo.co.nz/ch340.html


<img src="https://github.com/FabienFerrero/SUCA/blob/main/Document/pic/usb.jpg">



# Programmation du terminal - Gestionnaire de carte

 1. [Telechargé et installé le logicielArduino IDE](https://www.arduino.cc/en/Main/Software) (at least version v1.6.8)
 2. Lancer Arduino IDE
 3. Aller dans Fichiers/Preferences
  Ajouter : 
 ```
https://rfthings.github.io/ArduinoBoardManagerJSON/package_rfthings-esp32_index.json
 ```
 comme un "URL additionelle"
 
 4. Connectez votre terminal F210 à votre port USB
 5. Ouvrez le gestionnaire de carte depuis Outils -> Gestionnaire de carte et installez "RFTHings ESP32 Boards"
 6. Selectionnez ESP32 RFThings boards/RF210 depuis Outils -> Menu des cartes
 7. Selectionnez le port

# Schema

Le schema du PCB est disponible dans la section Schéma.
[RF210-C3](https://github.com/FabienFerrero/SUCA/blob/main/Schematic/RF210-C3.pdf)


# AT-COMMAND

Les AT-COMMAND LORA-WAN sont basé sur la plateforme RUI3 platform fourni par RAK : [RUI3 AT-COMMAND](https://docs.rakwireless.com/RUI3/Serial-Operating-Modes/AT-Command-Manual/#content)

Des commandes AT-COMMAND personalisée sont fournis pour acceder à des fonction spécifique à la carte. [ATC-COMMAND DOCUMENTATION](https://github.com/FabienFerrero/SUCA/blob/main/ATC_command.md)


# RAK3172mise à jour

Le RAK3172 peut être mise à jour pour supporter les dernières fonctionnalités.
Pour mettre à jour le RAK3172, vous pouvez suivre ce lien  : [RF210 RAK3172 firmware](https://github.com/XuanMinh201/RF210/tree/main)

# EXEMPLES

Des Exemples sont disponibles sur : [Example Readme](https://github.com/FabienFerrero/SUCA/blob/main/Examples/README.md)

# License


This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

<img src="https://github.com/FabienFerrero/UCA21/blob/main/Doc/Pictures/UCA_logo.png">

Maintained by Fabien Ferrero and Trinh Le Huy
