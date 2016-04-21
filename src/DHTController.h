#include <Arduino.h>
#include <DHT.h>

class DHTController{
  public:
    DHTController(uint8_t dhtPin, uint8_t dhtType):
    dht(dhtPin, dhtType),
    pin(dhtPin),
    type(dhtType),
    temperature(0),
    humidity(0)
    { dht.begin(); };
    float getTemperature();
    float getHumidity();

  private:
    const uint8_t pin;
    const uint8_t type;
    float temperature;
    float humidity;
    DHT dht;
};
