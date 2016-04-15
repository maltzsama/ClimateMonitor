#include <Arduino.h>
#include <DHT.h>

#define DHTTYPE DHT22   // define kind of sensor
int dht_pin = A0;       // define pin where sensor is connected

DHT dht(dht_pin, DHTTYPE);  // initialize pin

int main(){
  init();

  Serial.begin(9600);

  delay(1000);              // wait 1s
  dht.begin();              // start sensor

  Serial.println("Start");
  Serial.println("#######################");

  for(;;){
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    // Mostra os valores lidos, na serial
    Serial.print("Temp. = ");
    Serial.print(t);
    Serial.print(" C ");
    Serial.print("Um. = ");
    Serial.print(h);
    Serial.println(" % ");
    
    delay(2000);
  }

  return 0;
}
