void setup() {
Serial.begin(115200);
}

void loop() {
 int sound=analogRead(A0);
 Serial.print("Sound Value : ");
 Serial.println(sound);

 Serial.println(" ");
 delay(500);

}
