#include <Arduino.h>

#include "Classes/Motor.hpp"
#include "Classes/Sensor.hpp"
#include "Classes/Display.hpp"

//Definição das portas do motor e do LED
#define MOTOR_STEP 26
#define MOTOR_DIR 25
#define MOTOR_LED 12

Display *tft;

void setup(){
	Serial.begin(115200);

	pinMode(MOTOR_DIR, OUTPUT);
  	pinMode(MOTOR_STEP, OUTPUT);
	pinMode(MOTOR_LED, OUTPUT);
	
	//Construção de um instância da classe Display
	tft = new Display(5, 32, 25, 2, 4, 15);
}

void loop(){
	switch (tft->get_tela()) {
    		case 1: {
      			tft->main_screen();
      			break;
    		}
    		case 2: {
      			tft->select_screen();
      			break;
    		}
    		case 3: {
      			tft->real_time_temp();
      			break;
    		}
	}
}
