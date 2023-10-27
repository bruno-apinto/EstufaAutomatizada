#include "Arduino.h"

#include "Classes/Motor.hpp"
#include "Classes/Sensor.hpp"
#include "Classes/Display.hpp"

//Definição das portas do motor e do LED
#define MOTOR_STEP 26
#define MOTOR_DIR 25
#define MOTOR_LED 12

//Definição das portas do display e dos botões
#define TFT_DC 32
#define TFT_CS 5

#define selectButton 2
#define leftButton 15
#define rightButton 4

void setup(){
	Serial.begin(115200);
}

void loop(){

}
