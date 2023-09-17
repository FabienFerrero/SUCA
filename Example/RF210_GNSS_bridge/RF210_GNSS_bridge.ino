// ESP32 C3 SERIAL1 (second UART)
HardwareSerial mySerial1(1);

int rxPin = 3;
int txPin = 7;

void setup()
{
  Serial.begin(9600);
  delay(1000);
 Serial.println("GNSS test");
  
  pinMode(txPin, OUTPUT);
  pinMode(rxPin, INPUT);
  //pinMode(7, OUTPUT);
  pinMode(10, OUTPUT);
    pinMode(4, OUTPUT); 
    pinMode(1, OUTPUT);

  digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);  

    digitalWrite(1, HIGH);   // switch on GPS
  mySerial1.begin(9600, SERIAL_8N1, rxPin, txPin);
  digitalWrite(10, LOW); // switch off RAK
  delay(5000);
 
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
