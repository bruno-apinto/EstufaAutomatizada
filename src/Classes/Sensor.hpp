#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "DHT.h"

class Sensor{
public:
	/**
	* \brief Construtor do sensor
	*/
	Sensor (int sensor) {}

	/**
	 * @brief lê a temperatura atual
	 * 
	 * @return temperatura atual 
	 */
	float setTemperature() {}

private:
	DHT _sensor;
	float _temperatura;
};


#endif