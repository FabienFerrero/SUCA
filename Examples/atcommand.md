# AT-COMMAND EXAMPLES
Space Université Côte d'Azur Board for Education

Version 0.2, October, 2023

Author: Fabien Ferrero, Manh Thao Nguyen, Trinh Le Huy, Xuan Minh

In these examples, the ATC (custom AT-COMMAND) are shown


# SHT temperature and humidity sensor

1. Activate the SHT sensor, type :

```
ATC+SHT
```
It returns : 

    ATC+SHT=1
    OK
    
2. Check temperature, type :

   ```
   ATC+TEMP=?
    ```
It returns a result in Celsius degree: 

    ATC+TEMP=xx.yy degree C
    OK

4. Check Humidity, type :

      ```
   ATC+HUM=?
    ```
It returns a result in percent of humidity :

    ATC+HUM=xx%
    OK

# KX023 Accelerometer sensor

1. Activate the KX023 sensor, type :

```
ATC+KX023
```
It returns : 

    ATC+KX023=1
    OK
    
2. Check the accelerometer value on x-axis, type :

   ```
   ATC+AX=?
    ```
It returns the result in G unit : 

    ATC+AX=-x.yy
    OK

3. Check the accelerometer value on y-axis, type :

   ```
   ATC+AY=?
    ```
It returns the result in G unit : 

    ATC+AY=x.yy
    OK

4. Check the accelerometer value on z-axis, type :

   ```
   ATC+AZ=?
    ```
It returns the result in G unit : 

    ATC+AZ=x.yy
    OK

# L76F GNSS sensor
    




# License

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

<img src="https://github.com/FabienFerrero/UCA21/blob/main/Doc/Pictures/UCA_logo.png">

Maintained by Fabien Ferrero and Trinh Le Huy
