#include "DHTController.h"
#include <DHT.h>
#include <HardwareSerial.h>

float DHTController::getHumidity(){
  humidity = dht.readHumidity();
  Serial.print("Hum ");
  Serial.print(humidity);
  Serial.println(" um");
  return humidity;

}

float DHTController::getTemperature(){
  temperature = dht.readTemperature();
  Serial.print("Temp. = ");
  Serial.print(temperature);
  Serial.println(" C");
  return temperature;
}
