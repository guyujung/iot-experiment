#include <DHT.h>
#define DHTPIN 5

DHT dht(DHTPIN, DHT11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h=dht.readHumidity();
  float t=dht.readTemperature();

  Serial.print("Temperature Value: ");
  Serial.print(t);
  Serial.print("  'C");

  Serial.print("Humidity Value: ");
  Serial.print(h);
  Serial.print("  %\t");

  delay(2000);
}
