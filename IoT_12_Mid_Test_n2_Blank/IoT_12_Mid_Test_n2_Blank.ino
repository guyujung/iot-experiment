#include "ThingSpeak.h"  
#include <ESP8266WiFi.h>

char ssid[] = "CAPSTONE" ;  
char pass[] = "87654321" ;  
WiFiClient client;
unsigned long myChannelNumber = 1209936 ; // {   }는 구역을 나타냄. 지울것 
const char *myreadAPIKey = "MISA48YHDG3QBOVQ" ;      // {   }는 구역을 나타냄. 지울것 

void setup() {
  WiFi.begin (ssid, pass) ;
  Serial.begin(115200);       
  ThingSpeak.begin(client);   
  pinMode(16, OUTPUT) ;  // Red LED
  pinMode(14, OUTPUT) ;  // Green LED
 }

void loop() {
 int x = ThingSpeak.readIntField(myChannelNumber, 1 ) ;  // {   }는 구역을 나타냄. 지울것 
  Serial.print("Temp. : ");
  Serial.print(x) ;
  Serial.print("  ") ;
  if ( x < 18 ) { digitalWrite (16, HIGH) ; }  // 가반/다반 ( x < 18), 나반/라반/마반( x < 30), 
  else { digitalWrite (16, LOW) ; } 
  
  int y = ThingSpeak.readIntField(myChannelNumber, 2 ) ; // {   }는 구역을 나타냄. 지울것 
  Serial.print("CDS : ");
  Serial.println( y ) ;  // {   }는 구역을 나타냄. 지울것 
  if ( y < 900) { digitalWrite (14, HIGH) ; }  // 가반/나반 ( y < 400),  다반/라반/마반( y < 900), 
  else { digitalWrite (14, LOW) ; } 
  delay (3000) ; 
 }
