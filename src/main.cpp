#include "main.h"

int main(){
  init();

  DHT dht(dht_pin, dht_type);  // initialize pin

  Serial.begin(9600);

  delay(1000);              // wait 1s
  dht.begin();              // start sensor

  Serial.println("Start");
  Serial.println("#######################");

  for(;;){

    tempInfo data = getSensorData(dht);
    // cli.getData();

    // Mostra os valores lidos, na serial
    Serial.print("Temp. = ");
    Serial.print(data.temperature);
    Serial.print(" C ");
    Serial.print("Um. = ");
    Serial.print(data.humity);
    Serial.println(" % ");

    delay(2000);            //wait 2s to new read
  }

  return 0;
}

tempInfo getSensorData(DHT &dht){
  tempInfo x;
  x.humity = dht.readHumidity();
  x.temperature = dht.readTemperature();
  return x;
}
