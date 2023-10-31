#include "Arduino.h"

#include "Motor.hpp"

#define MIN_DELAY 2000 // Delay minimo
#define MAX_DELAY 10000 // Delay maximo

// Diferença de temperatura relativa ao delay maximo (para a regressão linear)
#define MAX_TEMP_DIFF 20.0

Motor::Motor(int step, int dir, int led, int delay):
		_step(step), _dir(dir), _led(led), _delay(delay) {

		pinMode(dir, OUTPUT);
		pinMode(step, OUTPUT);
}

void Motor::spin(int& motor_dir, int& motor_step) {
	//Se o delay for maior que o mínimo, o motor acionará
	if (_delay > 2000) { 
		digitalWrite(_led, HIGH);

		digitalWrite (motor_dir, HIGH);
		digitalWrite(motor_step, LOW);
		digitalWrite(motor_step, HIGH);

		delayMicroseconds(_delay);
	}
	else {
		digitalWrite(_led, LOW);
	}
	
}

// THEO: Acredito que não seja necessária essa função, podemos acender o led no spin
// BRUNO: Ao colocar o led no spin, achoq vai contra os principios da OO, pois as funções tem que 
// que ser exclusivas, devem realizar apenas 1 tarefa

/* void Motor::led (int LED){

	if (_step == 0){
		digitalWrite(LED, LOW);
	}
	else {
		digitalWrite(LED, HIGH);
	}

} */


void Motor::update_delay(float current_temp, float target_temp) {
	float m = (MAX_DELAY - MIN_DELAY)/MAX_TEMP_DIFF; // m = (y1 - y0)/(x1 - x0)
	_delay = MIN_DELAY + m*(current_temp - target_temp) ; // y = y0 + m(x - x0)
}
