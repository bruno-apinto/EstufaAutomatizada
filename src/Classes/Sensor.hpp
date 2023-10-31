#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "DHT.h"

//THEO: Essa classe é desnecessária, podemos retirá-la
class Sensor{
public:
	/**
	* \brief Construtor do sensor
	*/
	Sensor(int sensor);

	/**
	 * @brief lê a temperatura atual
	 * 
	 * @return temperatura atual 
	 */
	float get_temperature();

private:
	DHT _sensor;
	float current_temp;
};


#endif //SENSOR_HPP
