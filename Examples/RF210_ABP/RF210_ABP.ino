// ESP32 C3 SERIAL1 (second UART)
HardwareSerial mySerial1(1);

int rxPin = 20;
int txPin = 21;

String devAddr = "00000000";
String nwkkey = "000000000000000000000000000000000";
String appskey = "000000000000000000000000000000000";


void setup()
{
  Serial.begin(115200);
  delay(1000);
 Serial.println("ABP test");
  
  pinMode(txPin, OUTPUT);
  pinMode(rxPin, INPUT);

  pinMode(10, OUTPUT); //Rak enable
  pinMode(4, OUTPUT); // LED


  digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);  

    digitalWrite(10, HIGH); // Switch on RAK
    delay(1000);
  mySerial1.begin(115200, SERIAL_8N1, rxPin, txPin);
  delay(1000);  
  

   Serial.println("Setup at command");
  mySerial1.println("AT+NJM=0"); // Set ABP
  delay(200);
  mySerial1.println("AT+NWM=1"); // Set LoRaWan mode
  delay(300); 
  mySerial1.println("AT+BAND=9");// Set AS923-2 frequency band
  delay(200);
  //Serial.printf("Dev ADR = %s \n", devAddr);
  //mySerial1.printf("AT+DEVADDR=%s\n",devAddr);
  mySerial1.printf("AT+DEVADDR=");
  mySerial1.println(devAddr);
  delay(200);
  mySerial1.printf("AT+NWKSKEY=");
  mySerial1.println(nwkkey);
  delay(200);  
  mySerial1.printf("AT+APPSKEY=");
  mySerial1.println(appskey);
  delay(200);
   if (mySerial1.available())
  { // If anything comes in Serial1 (pins 4 & 5)
    while (mySerial1.available())
      Serial.write(mySerial1.read()); // read it and send it out Serial (USB)
  }
  delay(1000);

}

void loop()
{

unsigned char mydata[4];
mydata[0] = 0x1; // CH1
mydata[1] = 0x67; // Temp
mydata[2] = 0xFF;
mydata[3] = 0xFF;

char str[32] = "";
array_to_string(mydata, 4, str);

mySerial1.printf("AT+SEND=3:");
mySerial1.println(str);
   delay(5300);
  if (mySerial1.available())
  { // If anything comes in Serial1 (pins 4 & 5)
    while (mySerial1.available())
      Serial.write(mySerial1.read()); // read it and send it out Serial (USB)
  }
  Serial.println("AT set complete with downlink");
  delay(30000);
  Serial.println("Uplink");
}



void array_to_string(byte array[], unsigned int len, char buffer[])
{
    for (unsigned int i = 0; i < len; i++)
    {
        byte nib1 = (array[i] >> 4) & 0x0F;
        byte nib2 = (array[i] >> 0) & 0x0F;
        buffer[i*2+0] = nib1  < 0xA ? '0' + nib1  : 'A' + nib1  - 0xA;
        buffer[i*2+1] = nib2  < 0xA ? '0' + nib2  : 'A' + nib2  - 0xA;
    }
    buffer[len*2] = '\0';
}
