#include "Sensor.hpp"
#include "DHT.h"

class Sensor {

    Sensor::Sensor(int sensor): _sensor(DHT(sensor, DHT22)){}

    float Sensor::setTemperature() {
        current_temp = _sensor.readTemperature();
        return current_temp;
    }
}