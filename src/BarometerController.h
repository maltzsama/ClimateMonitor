#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>
#include "HardwareSerial.h"

class BarometerController
{

public:
    BarometerController(uint16_t value) :
    bmp(Adafruit_BMP085_Unified(value)),
    temperature(0),
    pressure(0),
    hight(0)
    { };
    // bool OnStart(HardwareSerial &Serial);
    // bool OnStop(HardwareSerial &Serial);
    // void OnRead(HardwareSerial &Serial);
    bool OnStart();
    bool OnStop();
    void OnRead();

private:
  Adafruit_BMP085_Unified bmp;
  float temperature;
  float pressure;
  float hight;

};
