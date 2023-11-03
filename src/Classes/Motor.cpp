#include <Arduino.h>
#include <esp32-hal-gpio.h>
#include "Classes/Motor.hpp"

#define MIN_DELAY 2000 // Delay minimo
#define MAX_DELAY 10000 // Delay maximo

// Diferença de temperatura relativa ao delay maximo (para a regressão linear)
#define MAX_TEMP_DIFF 20.0

Motor::Motor(int step, int dir, int led): _step(step), _dir(dir), _led(led) {
	pinMode(_step, OUTPUT);
	pinMode(_dir, OUTPUT);
	pinMode(_led, OUTPUT);
}

void Motor::spin() {
	//Se o delay for maior que o mínimo, o motor acionará
	if (_delay > MIN_DELAY) {
		digitalWrite(_led, HIGH);

		digitalWrite (_dir, HIGH);
		digitalWrite(_step, LOW);
		digitalWrite(_step, HIGH);

		delayMicroseconds(_delay);
	}
	else {
		digitalWrite(_led, LOW);
	}
	
}

void Motor::update_delay(float current_temp, float target_temp) {
	float m = (MAX_DELAY - MIN_DELAY) / MAX_TEMP_DIFF; // m = (y1 - y0)/(x1 - x0)
	_delay = MIN_DELAY + m * (current_temp - target_temp); // y = y0 + m(x - x0)
}
