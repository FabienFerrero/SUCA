#include <Wire.h>
#include "SHTSensor.h" // http://librarymanager/All#arduino_shtc3


#define UPDATES_PER_SECOND 100

SHTSensor sht;

void setup() {
  Serial.begin(115200);
   Wire.begin(5,6);
  sht.init();
  sht.setAccuracy(SHTSensor::SHT_ACCURACY_MEDIUM); // only supported by SHT3x


  Serial.println("Temperature:,Humidity:");   // Plot labels

}


void loop() {
    sht.readSample();
    Serial.print(sht.getTemperature());
    Serial.print(F(" "));
    Serial.println(sht.getHumidity());
    delay(1000);
}
