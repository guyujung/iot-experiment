int IR_IN=4;
void setup() {
  Serial.begin(115200);
  pinMode(IR_IN, INPUT);
}

void loop() {
 int Sensor_State=digitalRead(IR_IN);
 Serial.print(Sensor_State);

 if(Sensor_State==1)
  {Serial.println(" : Safe ");}
 else {Serial.println(" : Be Careful ");}
 delay(1000);
}
