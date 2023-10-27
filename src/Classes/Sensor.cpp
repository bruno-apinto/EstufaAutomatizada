#include "Sensor.hpp"
#include "DHT.h"

class Sensor {

    Sensor::Sensor(int sensor): _sensor(DHT(sensor, DHT22)){}

}