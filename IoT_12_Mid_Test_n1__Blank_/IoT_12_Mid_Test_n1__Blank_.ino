#include <ESP8266WiFi.h>   // **
 String apiKey = "XLSMHB4972KXZ856" ;   
 const char *ssid = "CAPSTONE" ; // {   }는 구역을 나타냄. 지울것
 const char *pass = "87654321"  ;   
 const char *server = "api.thingspeak.com" ;  

#include <DHT.h>   
#define DHTPIN 4        //  {   }는 구역을 나타냄. 지울것
DHT dht(DHTPIN, DHT11); 
 
WiFiClient client;    
 
 void setup()  { 
 Serial.begin(115200);
 pinMode(DHTPIN, INPUT );   // {   }는 구역을 나타냄. 지울것 
 dht.begin ( ) ; 
 delay(1000); 
 
 Serial.print("Connecting to : "); 
 Serial.println(ssid); 
     
 WiFi.begin(ssid, pass);      
 while (WiFi.status() != WL_CONNECTED )  { 
   delay(2000); 
   Serial.println("...... not connected");   
   }
   Serial.println(""); 
   Serial.println("WiFi connected"); 
   } 

 void loop()  {  
 float h = dht.readHumidity(); 
 float t = dht.readTemperature();
 Serial.print("Temp. Value : ") ;
 Serial.print(t);       // {   }는 구역을 나타냄. 지울것 
 Serial.println(" 'C");
   
 Serial.print("Hum. Value  : ") ;
 Serial.print( h );       // {   }는 구역을 나타냄. 지울것 
 Serial.println(" %\t");  
    
 int CDS = analogRead( A0 ); // {   }는 구역을 나타냄. 지울것 
   Serial.print("CDS Value : ") ;
   Serial.println( CDS );     // {   }는 구역을 나타냄. 지울것 
       
   if (client.connect(server,80)) {  
      String postStr = apiKey ;      
      Serial.print("1 : ")    ; 
      Serial.println(postStr) ;        
      postStr += "&field1="   ;                
      postStr += String(t) ;             
      postStr += "&field2="   ;      
      postStr += String(CDS)  ;  // {   }는 구역을 나타냄. 지울것    
      postStr += "\r\n\r\n"   ; 
      Serial.print("2 : ")    ; 
      Serial.println(postStr) ;          
     client.print("POST /update HTTP/1.1\n");      
     client.print("Host: api.thingspeak.com\n"); 
     client.print("Connection: close\n"); 
     client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n"); 
     client.print("Content-Type: application/x-www-form-urlencoded\n"); 
     client.print("Content-Length: "); 
     client.print(postStr.length()); 
     client.print("\n\n"); 
     client.print(postStr);   // **    
     Serial.println(postStr.length()) ;         
     }   
     client.stop(); 
     Serial.println("Waiting..."); 
     delay(3000);   
   }  
