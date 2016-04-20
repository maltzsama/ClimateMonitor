#include <Arduino.h>
#include <DHT.h>
#include <Task.h>
#include "BarometerController.h"

static const uint8_t dhtPin = A0;
static const uint8_t dhtType = DHT22;
static const uint8_t ledPin = 13;
static const uint8_t timerRead = 10;
uint8_t idx = 0;

DHT dht(dhtPin, dhtType);

void OnReadTemperature(uint32_t deltaTime);

FunctionTask taskReadTemperature(OnReadTemperature, MsToTaskTime(timerRead * 1000)); // turn on the led in 400ms
BarometerController barometerController(10085);

TaskManager taskManager;

struct tempInfo{
  float temperature;
  float humidity;
};

tempInfo getSensorData();
