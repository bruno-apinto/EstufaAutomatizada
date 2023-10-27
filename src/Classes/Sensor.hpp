#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "DHT.h"

class Sensor{
public:
	/**
	* \brief Construtor do sensor
	*/
	Sensor (int sensor) {}
private:
	DHT _sensor;
};


#endif