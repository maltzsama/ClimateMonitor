#include <Arduino.h>
#include <DHT.h>

const int dht_pin = A0;
const int dht_type = DHT22;

struct tempInfo{
  float temperature;
  float humity;
};

tempInfo getSensorData(DHT &dht);
