#include <MicroNMEA.h>

#define DATA_INTERVAL 5000 //ms

// ESP32 C3 mySerial1 (second UART)
HardwareSerial mySerial1(1);

int rxPin = 3;
int txPin = 7;

int timezone = 7 ;

int  year; int mon; int day; int hr; int minute; double sec;
String* PRN;

char nmeaBuffer[100];
MicroNMEA nmea(nmeaBuffer, sizeof(nmeaBuffer));
String revString;
char revChar[100];
int len = 0;


uint32_t quectelDelayTime = 500;
unsigned long currentMillis = 0, getSensorDataPrevMillis = 0, getGPSPrevMillis = 0;
bool _flag = false;

void setup()
{
  Serial.begin(115200);
  delay(1000);
 Serial.println("GNSS test");
  
  pinMode(txPin, OUTPUT);
  pinMode(rxPin, INPUT);
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

   currentMillis = millis();
  
  // Parse data from Quectel
  if (currentMillis - getGPSPrevMillis > quectelDelayTime)
  {
    getGPSPrevMillis = currentMillis; 
    quectel_getData(revString, revChar, len);
  }
  // Print sensor & gps data
  if (currentMillis - getSensorDataPrevMillis > DATA_INTERVAL)
  {
    getSensorDataPrevMillis = currentMillis;
    // GPS
    GPS_showData();
    
    Serial.println("**********************************************");
  }

  
}


void quectel_getData(String _revString, char* _revChar, int _len)
{
  while (mySerial1.available())
  { 
    _revString = mySerial1.readStringUntil(0x0D);
   // Serial.println(_revString);
    _len = _revString.length() + 1;
    _revString.toCharArray(_revChar, _len);
    for(int i = 0; i < _len; i++){
   //   Serial.print(*(_revChar + i));
      nmea.process(*(_revChar + i));
    }
  }
  quectelDelayTime = 5; // 5ms (Minimum delay time for slave to prepare the next NMEA packet is 2ms)
}


unsigned long unixTimestamp(int year, int month, int day, int hour, int min, int sec) {
  const short days_since_beginning_of_year[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
  int leap_years = ((year - 1) - 1968) / 4
                   - ((year - 1) - 1900) / 100
                   + ((year - 1) - 1600) / 400;
  long days_since_1970 = (year - 1970) * 365 + leap_years
                         + days_since_beginning_of_year[month - 1] + day - 1;
  if ( (month > 2) && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) )
    days_since_1970 += 1; /* +leap day, if year is a leap year */
  return sec + 60 * ( min + 60 * (hour + 24 * days_since_1970) );
}
void GPS_showData(void)
{ /*
  Serial.print("Valid fix: ");
  Serial.println(nmea.isValid() ? "yes" : "no");
  if(nmea.isValid()){ */
    Serial.print("Nav. system: ");
   if (nmea.getNavSystem())
      Serial.print(nmea.getNavSystem());
    else
      Serial.print("none");
    Serial.print(", Sat in view: ");
    Serial.println(nmea.getNumSatellites());
    
    double latitude = nmea.getLatitude();
    double longitude = nmea.getLongitude();
    long alt;
    
    Serial.print("GPS position: ");
    Serial.print(latitude / 1.0e6, 4);
    Serial.print(", ");
    Serial.print(longitude / 1.0e6, 4);
     Serial.print(", ");
    if (nmea.getAltitude(alt)){
      Serial.println(alt / 1000., 3);}
      
    Serial.print("Speed: ");
    Serial.println(nmea.getSpeed() / 1000., 3);
    Serial.print("Course: ");
    Serial.println(nmea.getCourse() / 1000., 3); 

     

    uint32_t unixt = unixTimestamp(nmea.getYear(), nmea.getMonth(), nmea.getDay(), nmea.getHour(), nmea.getMinute(), nmea.getSecond());
    Serial.print("  Unix time GPS: ");
    Serial.println(unixt);    
    
}
