#include <Arduino.h>
#include <DHT.h>
#include <Task.h>

const uint8_t dhtPin = A0;
const uint8_t dhtType = DHT22;
const uint8_t ledPin = 13;
const uint8_t timerRead = 10;
uint8_t idx = 0;

DHT dht(dhtPin, dhtType);

// foreward delcare functions passed to task constructors now required
void OnReadTemperature(uint32_t deltaTime);

FunctionTask taskReadTemperature(OnReadTemperature, MsToTaskTime(timerRead * 1000)); // turn on the led in 400ms

TaskManager taskManager;

struct tempInfo{
  float temperature;
  float humidity;
};

tempInfo getSensorData();
