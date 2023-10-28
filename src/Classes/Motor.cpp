#include "Motor.hpp"
#include <ESP32>
#include "Display.hpp"
#include "Sensor.hpp"

#define DELAY_US 2000 //delay para o motor captar a borda de subida

int modulo (int x) {
	if (x<0) return (-1)*x;
	else return x;
}

Motor::Motor(int step, int dir, int led, int delay):
		_step(step), _dir(dir), _led(led), _delay(delay) {
			
		}

void Motor::spin() {
  
}

void Motor::update_delay(int current_temp, int target_temp) {

	float target = Display::getTarget();
	float diff = modulo(target - Sensor::setTemperature());

	_delay = DELAY_US + diff*1000;
}
