#include <Arduino.h>
#include <Task.h>
#include "BarometerController.h"
#include "DHTController.h"

static const uint8_t dhtPin = A0;
static const uint8_t dhtType = DHT22;
static const uint8_t ledPin = 13;
static const uint8_t timerRead = 10;
static const uint16_t barometerParam = 10085;
uint8_t idx = 0;

void OnReadTemperature(uint32_t deltaTime);

DHTController dhtController(dhtPin, dhtType);
BarometerController barometerController(barometerParam);

TaskManager taskManager;
FunctionTask taskReadTemperature(OnReadTemperature, MsToTaskTime(timerRead * 1000)); //read temperature in 1sec * timer
