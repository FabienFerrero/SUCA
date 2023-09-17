#include "Adafruit_SHTC3.h"
#include <Kionix_KX023.h>

Adafruit_SHTC3 shtc3 = Adafruit_SHTC3();

KX023 myIMU;
float kx_x, kx_y, kx_z;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
  Serial.println("serial???");
  while (!Serial) {
    delay(10); // wait for serial port to open
  }

  Serial.println("SHTC3 test");
  if (! shtc3.begin()) {
    Serial.println("Couldn't find SHTC3");
    //while (1) delay(1);
  }
  Serial.println("Found SHTC3 sensor");


  if (myIMU.begin())
  {
    Serial.println("Could not find KX023-1025? Check wiring");
  }
  else
  {
    Serial.println("KX023-1025: OK");
  }

  myIMU.configContinuousReading(LOWPOWER, RANGE_8G, DATARATE_100HZ);

}

void loop() {

  sensors_event_t humidity, temp;

  shtc3.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data

  Serial.print("Temperature: "); Serial.print(temp.temperature); Serial.println(" degrees C");
  Serial.print("Humidity: "); Serial.print(humidity.relative_humidity); Serial.println("% rH");


  myIMU.readAcceleration(&kx_x, &kx_y, &kx_z);
  Serial.print("KX023-1025: ");
  Serial.print(kx_x);
  Serial.print(", ");
  Serial.print(kx_y);
  Serial.print(", ");
  Serial.print(kx_z);
  Serial.println("");


  delay(1000);

  // put your main code here, to run repeatedly:


}
