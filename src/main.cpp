#include <Arduino.h>
#include <DHT.h>

#include "Classes/Motor.hpp"
#include "Classes/Display.hpp"

//Definição da porta do sensor
#define SENSOR 25

//Definição das portas do motor e do LED
#define MOTOR_STEP 21
#define MOTOR_DIR 19
#define MOTOR_LED 33

//Definição das portas do display e dos botões
#define TFT_DC 32
#define TFT_CS 5

#define SELECT_BUTTON 2
#define UP_BUTTON 15
#define DOWN_BUTTON 4

Motor motor(MOTOR_STEP, MOTOR_DIR, MOTOR_LED);
DHT sensor(SENSOR, DHT22);
Display display(TFT_CS, TFT_DC, sensor.readTemperature(), 25, SELECT_BUTTON, DOWN_BUTTON, UP_BUTTON);

void setup(){
	Serial.begin(115200);
}

void loop(){
	float current_temp = sensor.readTemperature();
	display.set_previous_temp((int)current_temp);
	delay(500);
	current_temp = sensor.readTemperature();
	display.set_current_temp((int)current_temp);
	// motor.update_delay(current_temp, (float)display.get_target());
	motor.spin();
	display.update();
}

