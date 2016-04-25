#include "main.h"

int main(){
  init();

  Serial.begin(9600);
  barometerController.OnStart();
  delay(1000);              // wait 1s

  Serial.println("Start");
  Serial.println("#######################");

  taskManager.StartTask(&taskReadTemperature);

  for(;;){
    taskManager.Loop();

  }

  return 0;
}

void OnReadTemperature(uint32_t deltaTime)
{
    Serial.print("on read temperature ");
    Serial.print(idx);
    Serial.println("############");
    idx++;
    dhtController.getHumidity();
    dhtController.getTemperature();
    barometerController.OnRead();
}
