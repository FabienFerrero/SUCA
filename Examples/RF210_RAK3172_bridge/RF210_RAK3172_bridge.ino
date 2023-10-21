/*
.d88888b  dP     dP  a88888b.  .d888888  
88.    "' 88     88 d8'   `88 d8'    88  
`Y88888b. 88     88 88        88aaaaa88a 
      `8b 88     88 88        88     88  
d8'   .8P Y8.   .8P Y8.   .88 88     88  
 Y88888P  `Y88888P'  Y88888P' 88     88  

   Author: fferrero, mtnguyen, lehuytrinh
   Code : RF210_RAK3172_bridge : Provide on ESP32 Serial port a direct access in write and read to Rak3172 module for AT Command mode

*/

// ESP32 C3 SERIAL1 (second UART)
HardwareSerial mySerial1(1);

int rxPin = 20;
int txPin = 21;

void setup()
{
  Serial.begin(115200);
  delay(1000);
  
  pinMode(txPin, OUTPUT);
  pinMode(rxPin, INPUT);
  pinMode(10, OUTPUT); //Rak enable
  pinMode(4, OUTPUT); // LED
  pinMode(1, OUTPUT); // GNSS enable
  digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);  

  digitalWrite(10, HIGH); // Switch on RAK3172 LDO
  delay(1000);
  mySerial1.begin(115200, SERIAL_8N1, rxPin, txPin);
  delay(1000);  
  mySerial1.println("ATE");
  delay(20);  
    while (mySerial1.available()){
      Serial.write(mySerial1.read()); // read it and send it out Serial (USB)
    }
  Serial.println("setup at command");

}

void loop()
{

  if (Serial.available()) {      // If anything comes in Serial (USB),

    mySerial1.write(Serial.read());   // read it and send it out mySerial1 (pins 0 & 1)

  }

  if (mySerial1.available()) {     // If anything comes in Serial1 (pins 0 & 1)

    Serial.write(mySerial1.read());   // read it and send it out Serial (USB)

  }

}
