#include "BarometerController.h"

bool BarometerController::OnStart(){

  if (!bmp.begin()){
    return false;
  }
  sensor_t sensor;
  bmp.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" hPa");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" hPa");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" hPa");
  Serial.println("------------------------------------");
  Serial.println("");

  delay(500);
  return true;
}

bool BarometerController::OnStop(){
    Serial.println("------------------------------------");
    Serial.println("Ended sensor monitor.");
    Serial.println("------------------------------------");
    return true;
}

void BarometerController::OnRead(){
  sensors_event_t event;
  bmp.getEvent(&event);

  if (event.pressure)
  {
    pressure = event.pressure;
    bmp.getTemperature(&temperature);
    float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;
    hight = bmp.pressureToAltitude(seaLevelPressure, event.pressure);
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");
    Serial.print("Altitude:    ");
    Serial.print(bmp.pressureToAltitude(seaLevelPressure, event.pressure));
    Serial.println(" m");
    Serial.print("Pressure:    ");
    Serial.print(event.pressure);
    Serial.println(" hPa");

  }
}
