#include "main.h"

int main(){
  init();

  taskManager.StartTask(&taskReadTemperature); // start with turning it on
  // taskManager.StartTask(&barometerController);
  Serial.begin(9600);
  barometerController.OnStart();

  delay(1000);              // wait 1s
  dht.begin();              // start sensor

  Serial.println("Start");
  Serial.println("#######################");

  for(;;){
    taskManager.Loop();

  }

  return 0;
}

void OnReadTemperature(uint32_t deltaTime)
{
    idx++;
    digitalWrite(ledPin, idx%2);

    tempInfo data = getSensorData();
    // Show values in serial port and Bluetooth
    Serial.print("Temp. = ");
    Serial.print(data.temperature);
    Serial.print(" C ");
    Serial.print("Um. = ");
    Serial.print(data.humidity);
    Serial.println(" % ");

    barometerController.OnRead();

}

tempInfo getSensorData(){
  tempInfo x;
  x.humidity = dht.readHumidity();
  x.temperature = dht.readTemperature();
  return x;
}
