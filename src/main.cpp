#include <Arduino.h>
#include "DHT.h"

#include "Classes/Motor.hpp"
#include "Classes/Sensor.hpp"
#include "Classes/Display.hpp"

//Definição das portas do motor e do LED
#define MOTOR_STEP 26
#define MOTOR_DIR 25
#define MOTOR_LED 12

//ponteiro pra Display
Display *tft;

//objeto sensor
DHT _sensor(DHT(sensor, DHT22));
float current_temp_ = _sensor.readTemperature();

void setup(){
	Serial.begin(115200);

	pinMode(MOTOR_DIR, OUTPUT);
  	pinMode(MOTOR_STEP, OUTPUT);
	pinMode(MOTOR_LED, OUTPUT);
	
	//Construção de um instância da classe Display
	tft = new Display(5, 32, current_temp_, 2, 4, 15);
		// 4 -botao baixo
		// 2 - selecionar
		// 15 - botao cima
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
