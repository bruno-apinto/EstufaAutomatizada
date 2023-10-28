#include "Sensor.hpp"
#include "DHT.h"

class Sensor {

    Sensor::Sensor(int sensor): _sensor(DHT(sensor, DHT22)){}

    float Sensor::setTemperature() {
        _temperatura = _sensor.readTemperature();
        return _temperatura;
    }
}