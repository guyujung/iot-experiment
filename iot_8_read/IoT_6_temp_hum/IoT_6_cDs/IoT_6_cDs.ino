void setup() {
  Serial.begin(115200);

}

void loop() {
  int sensorValue=analogRead(A0);
  int LX_Value=sensorValue*1.4;

  Serial.print("cDs Value : ");
  Serial.println(sensorValue);

  Serial.print("LX Value(Not Read) : ");
  Serial.println(LX_Value);

  Serial.println(" ");
  delay(1000);
}
