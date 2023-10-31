#include "DHT.h"

#include "Sensor.hpp"

Sensor::Sensor(int sensor): _sensor(DHT(sensor, DHT22)){}

float Sensor::get_temperature() {
	return _sensor.readTemperature();
}
