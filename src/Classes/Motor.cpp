#include "Motor.hpp"
#include "Display.hpp"
#include "Sensor.hpp"

#define DELAY_US 2000 //delay para o motor captar a borda de subida

Motor::Motor(int step, int dir, int led, int delay):
		_step(step), _dir(dir), _led(led), _delay(delay) {

			pinMode(Motor, OUTPUT);
			delay(1000);

		}

void Motor::spin(int& MOTOR_DIR, int& MOTOR_STEP) {
	
	//Se o delay for maior que o mínimo (2000), o motor acionará
	if(_delay > 2000){
		digitalWrite (MOTOR_DIR, HIGH);
		digitalWrtite(MOTOR_STEP, LOW);
		digitalWrite(MOTOR_STEP, HIGH);
		delay(_delay);
	}
	
}

void Motor::led (int LED, int& _step){

	if (_step == 0){
		digitalWrite(LED, LOW);
	}
	else {
		digitalWrite(LED, HIGH);
	}

}


void Motor::update_delay(float current_temp, float target_temp) {
	
	float diff = current_temp - target_temp;
	_delay = DELAY_US + diff*1000;
}
