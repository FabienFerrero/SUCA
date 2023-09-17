// ESP32 C3 SERIAL1 (second UART)
HardwareSerial mySerial1(1);

int rxPin = 20;
int txPin = 21;

void setup()
{
  Serial.begin(115200);
  delay(1000);
 Serial.println("ABP test");
  
  pinMode(txPin, OUTPUT);
  pinMode(rxPin, INPUT);
  pinMode(7, OUTPUT);
  pinMode(10, OUTPUT);
    pinMode(4, OUTPUT); 
    pinMode(1, OUTPUT);

    digitalWrite(1, LOW);   // switch off GPS
  mySerial1.begin(115200, SERIAL_8N1, rxPin, txPin);
  digitalWrite(10, HIGH);
  delay(5000);
  mySerial1.println("ATE");
  delay(20);
  
    while (mySerial1.available()){
      Serial.write(mySerial1.read()); // read it and send it out Serial (USB)
    }
  Serial.println("setup at command");
  mySerial1.println("AT+NWM=1");
  delay(200);
  mySerial1.println("AT+NJM=0");
  delay(200);

  mySerial1.println("AT+CLASS=A");
  delay(200);

  mySerial1.println("AT+BAND=4");
  delay(200);

  Serial.println("Set EU868");

  mySerial1.println("AT+DEVADDR=260B8F3A");
  delay(200);

  Serial.println("Dev ADR = 260B8F3A ");

  mySerial1.println("AT+APPSKEY=BF2E0A2E28B5E5378408C3864C138A57");
  delay(200);


  mySerial1.println("AT+NWKSKEY=784E918B1A403743889FB445E8261895");
  delay(200);

  mySerial1.println("AT+SEND=12:112233");
  delay(10000);


}

void loop()
{

  Serial.println("Loop");
   digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);  
  
  digitalWrite(7, HIGH);
  mySerial1.println("AT+SEND=3:68656c6c6f");
   delay(5300);
  if (mySerial1.available())
  { // If anything comes in Serial1 (pins 4 & 5)
    while (mySerial1.available())
      Serial.write(mySerial1.read()); // read it and send it out Serial (USB)
  }
  Serial.println("AT set complete with downlink");
  delay(5000);


  Serial.println("Uplink");

}
