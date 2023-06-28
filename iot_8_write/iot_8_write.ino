#include <ESP8266WiFi.h>   // **
 String apiKey = "Y8114V3686MJZWGR"  ;  // "Write API" key from ThingSpeak 
 const char *ssid =  "CAPSTONE" ;  // @Class ==> capstone" ;   // wifi SSID  
 const char *pass =  "87654321"  ;  // @Class ==> "87654321" ;  // wifi passwd  
 const char *server = "api.thingspeak.com" ; // Server 
 #define Bit_pin 5     // GPIO Pin_name 
 
 WiFiClient client;    // <==> WiFiServer server(80); // Web Server로 지정
 
 void setup()  { 
 Serial.begin(115200); 
 delay(1000); 
 Serial.print("Connecting to : "); 
 Serial.println(ssid); 
     
 WiFi.begin(ssid, pass);    // ** WiFi Start 
 while (WiFi.status() != WL_CONNECTED )  { 
   delay(2000); 
   Serial.println("....... not connected");   
   }
Serial.println(""); 
Serial.println("WiFi connected"); 
} 
 
 void loop()  {  
 int SW_1 = digitalRead(Bit_pin) ;   
   Serial.print("Bit : ") ;
   Serial.println(SW_1); 
 int CDS = analogRead(A0); //A0에 CDS값 받는다
   Serial.print("CDS Value : ") ;
   Serial.println(CDS); 
   Serial.println(" ") ; 
       
   if (client.connect(server,80)) { // connect to server (api.thingspeak.com) port 80 
      String postStr = apiKey ;     // apiKey += field1 += field2 .... 
      Serial.print("1 : ")    ; 
      Serial.println(postStr) ;     // just looking   
      postStr += "&field1="   ;     // &field1 --> Address of field1            
      postStr += String(SW_1) ;     // SW_1 Data         
      postStr += "&field2="   ;     // &field2 --> Address of field2     
      postStr += String(CDS)  ;     // CDS       
      postStr += "\r\n\r\n"   ; 
      Serial.print("2 : ")    ; 
      Serial.println(postStr) ;     // just looking       
     // Print data,followed by a carriage return and newline,to the server a client is connected to.
     client.print("POST /update HTTP/1.1\n");      
     client.print("Host: api.thingspeak.com\n"); 
     client.print("Connection: close\n"); 
     client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n"); 
     client.print("Content-Type: application/x-www-form-urlencoded\n"); 
     client.print("Content-Length: "); 
     client.print(postStr.length()); 
     client.print("\n\n"); 
     client.print(postStr);  
     // **    
     Serial.print("3 : ") ; Serial.println(postStr) ; 
     Serial.println(postStr.length()) ; 
     Serial.println(" ") ;         
     }   // if end 
     
     client.stop(); 
     Serial.println("Waiting..."); 
     delay(3000);  // thingspeak needs minimum 15 sec delay between updates 
   }  
