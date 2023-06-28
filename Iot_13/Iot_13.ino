#define trigPin 13
#define echoPin 12

void setup() {
  Serial.begin (115200);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin,HIGH);

  distance=duration*17/1000;

  if(distance>=200 || distance<=0)
  {Serial.println("거리를 측정할 수 없음");}
  else{
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(100);
}
  
