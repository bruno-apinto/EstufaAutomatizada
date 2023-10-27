#include "DHT.h"

class Sensor{
public:
	/**
	* \brief Construtor do sensor
	*/
	Sensor(int sensor): _sensor(DHT(sensor, DHT22)){}
private:
	DHT _sensor;
};
