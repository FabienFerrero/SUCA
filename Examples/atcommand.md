# AT-COMMAND EXAMPLES
Space Université Côte d'Azur Board for Education

Version 0.2, October, 2023

Author: Fabien Ferrero, Manh Thao Nguyen, Trinh Le Huy, Xuan Minh

In these examples, the ATC (custom AT-COMMAND) are shown


# SHT temperature and humidity sensor

1. Activate the SHT sensor, type :
---        
ATC+SHT
---            
It returns : 

    ATC+SHT=1
    OK
    
2. Check temperature, type :

            
    ATC+TEMP=?
            
It returns a result in Celsius degree: 

     ATC+TEMP=xx.yy degree C
     OK

3. Check Humidity, type :

            
    ATC+HUM=?
            
It returns a result in percent of humidity :

    ATC+HUM=xx%
    OK

# KX023 Accelerometer sensor

1. Activate the KX023 sensor, type :


    ATC+KX023

It returns : 

    ATC+KX023=1
    OK
    
2. Check the accelerometer value on x-axis, type :


    ATC+AX=?
 
It returns the result in G unit : 

    ATC+AX=-x.yy
    OK

3. Check the accelerometer value on y-axis, type :

 
    ATC+AY=?
 
It returns the result in G unit : 

    ATC+AY=x.yy
    OK

4. Check the accelerometer value on z-axis, type :


    ATC+AZ=?

It returns the result in G unit : 

    ATC+AZ=x.yy
    OK

# L76F GNSS sensor

1. GNSS experiment needs to be run with a clear view on the sky to capture signal from GPS, Galileo or Beidu Satellite.
   

2. Activate the GNSS LDO, it power-on the L76F module, type :


    ATC+GPSON=1

It returns : 

    OK

3. The GNSS module will need up to 1 minute to obtain a position. If LED D1 (close to L76F) is blinking, the module get a fix.
   
4. Read the GPS value, type


    ATC+GPS

It returns : 

    ATC+GPS=1
    OK
    
5. Read the number of satellites in view, type : 


    ATC+GPSSAT=?

It returns the number of satellites available : 

    ATC+GPSSAT=x
    OK

6. Read the latitude, type : 


    ATC+GPSLAT=?

It returns the latitude in degreees : 

    ATC+GPSLAT=xx.yyyy
    OK

7. Read the Longitude, type : 


    ATC+GPSLON=?

It returns the longitude in degrees : 

    ATC+GPSLON=xx.yyyy
    OK

8. Read the Altitude, type : 


    ATC+GPSALT=?

It returns the altitude in meter : 

    ATC+GPSALT=xx.yyy
    OK

9. Read the Time, type : 


    ATC+GPSTIME=?

It returns the time in second in Epoch format : 

    ATC+GPSTIME=xxxxxxxxxx
    OK

# Battery Voltage

1. Request battery voltage level, type :


    ATC+BAT=?

It returns the battery voltage level in millivolt : 

    ATC+BAT=xxxx
    OK
    




# License

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

<img src="https://github.com/FabienFerrero/UCA21/blob/main/Doc/Pictures/UCA_logo.png">

Maintained by Fabien Ferrero and Trinh Le Huy
