void setup() {
Serial.begin(115200);
pinMode(15,OUTPUT);
}

void loop() {
 digitalWrite(15,HIGH);
 Serial.println("SW : HIGH ");
 delay(1000);

 digitalWrite(15,LOW);
 Serial.println("SW : LOW ");
 delay(1000);

}
