#include <DHT.h>
#include <DHT_U.h>

int sensor = 2;
int temperatureLed = 3;
int humidityLed = 4;
int temperature;
int humidity;

DHT dht(sensor, DHT11);

void setup(){
  Serial.begin(9600);
  dht.begin();
}

void loop(){
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  Serial.print("T: ");
  Serial.print(temperature);
  Serial.print(" - H: ");
  Serial.println(humidity);

  if(temperature > 30) {
      digitalWrite(temperatureLed, HIGH);
  } else {
      digitalWrite(temperatureLed, LOW);
  }
  
  if(humidity > 70) {
      digitalWrite(humidityLed, HIGH);
  } else {
      digitalWrite(humidityLed, LOW);
  }
  
  delay(1000);
}
