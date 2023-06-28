
#include <ESP8266WiFi.h>
#include "ThingSpeak.h" // **

char ssid[] = "CAPSTONE" ;
char pass[] = "87654321" ;
WiFiClient client;
unsigned long mcn = 1899341; // mychannel number
const char *myreadAPIKey = "OA25QCNNOMLPS5O0";

void setup()  { 
  WiFi.begin(ssid, pass);    // ** WiFi Start 
  Serial.begin(115200);
  ThingSpeak.begin(client);
  pinMode(16, OUTPUT);
  pinMode(14, OUTPUT);
} 
 
 void loop()  {  
 int x = ThingSpeak.readIntField(mcn, 1);
 Serial.print("BIT : " );
 Serial.print(x);
 Serial.print(" ");
 if (x==1) { digitalWrite(16,HIGH);}
 else { digitalWrite(16, LOW);}
       
 int y = ThingSpeak.readIntField(mcn, 2);
 Serial.print("CDS : ");
 Serial.println(y);
 if (y <600) { digitalWrite(14, HIGH);}
 else {digitalWrite(14, LOW);}
 delay(3000);
 }
