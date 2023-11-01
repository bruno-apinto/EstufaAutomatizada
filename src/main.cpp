#include <Arduino.h>

#include "DHT.h"

#include "Classes/Motor.hpp"
#include "Classes/Sensor.hpp"
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

Display display(TFT_CS, TFT_DC, 25, SELECT_BUTTON, DOWN_BUTTON, UP_BUTTON);
Motor motor(MOTOR_STEP, MOTOR_DIR, MOTOR_LED);
DHT sensor(25, DHT22);

void setup(){
	Serial.begin(115200);
}

void loop(){
	float current_temp = sensor.readTemperature();
	display.set_current_temp((int)current_temp);
	display.update();
	motor.update_delay(current_temp, (float)display.get_target());
	motor.spin();
}
