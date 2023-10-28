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
	
	if (_delay < 0) {
		_step = 0;
  	}
	else {
		_step = _delay*1.0; //fator de multiplicação a definir
	}

}

void Motor::led (int LED, int& _step){

	if (_step =)
	digitalWrite(LED, HIGH);

}


void Motor::update_delay(float current_temp, float target_temp) {
	
	float diff = current_temp - target_temp;
	_delay = DELAY_US + diff*1000;
}
