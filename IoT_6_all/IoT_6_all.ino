#include <DHT.h>
#define DHTPIN 5
DHT dht(DHTPIN, DHT11);
int IR_IN=4;

void setup() {
  Serial.begin(115200);
  pinMode(IR_IN,INPUT);
  dht.begin();
}

void loop() {
   int Sensor_State=digitalRead(IR_IN);
   Serial.print(Sensor_State);
  
   if(Sensor_State==1)
    {Serial.println(" : Safe ");}
   else {Serial.println(" : Be Careful ");

  //--------------------
  int sensorValue=analogRead(A0);
  int LX_Value=sensorValue*1.4;

  Serial.print("cDs Value : ");
  Serial.println(sensorValue);

  Serial.print("LX Value(Not Read) : ");
  Serial.println(LX_Value);
  
  //-------------------------------
  float h=dht.readHumidity();
  float t=dht.readTemperature();

  Serial.print("Temperature Value: ");
  Serial.print(t);
  Serial.println("  'C");

  Serial.print("Humidity Value: ");
  Serial.print(h);
  Serial.println("  %\t");
  Serial.println(" ");
  delay(2000);
}
