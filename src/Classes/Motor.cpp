#include "Arduino.h"

#include "Motor.hpp"

#define DELAY_US 2000 //delay para o motor captar a borda de subida

Motor::Motor(int step, int dir, int led, int delay):
		_step(step), _dir(dir), _led(led), _delay(delay) {

		// pinMode(Motor, OUTPUT); // THEO: Essa linha tem um erro, o que é esse Motor?
}

void Motor::spin(int& motor_dir, int& motor_step) {
	
	//Se o delay for maior que o mínimo (2000), o motor acionará
	if(_delay > 2000){ 
		digitalWrite (motor_dir, HIGH);
		digitalWrite(motor_step, LOW);
		digitalWrite(motor_step, HIGH);
		delayMicroseconds(_delay); //THEO: Mudei para delayMicroseconds, é o usado no video
	}
	
}

// THEO: Acredito que não seja necessária essa função, podemos acender o led no spin
/* void Motor::led (int LED, int& _step){

	if (_step == 0){
		digitalWrite(LED, LOW);
	}
	else {
		digitalWrite(LED, HIGH);
	}

} */


void Motor::update_delay(float current_temp, float target_temp) {
	float diff = current_temp - target_temp;
	_delay = DELAY_US + diff*1000; // THEO: Quanto maior a diferença de temperatura maior o delay e menor a velocidade??
}
