#include "Display.hpp"

Display::Display(int tft_cs,
								 int tft_dc,
								 int current_temp,
								 int select,
								 int down, 
								 int up): 
	_tft(Adafruit_ILI9341(tft_cs, tft_dc)), 
	_target_temp(current_temp),
	_tela(1),
	_select(select),
	_down(down),
	_up(up) {}

void Display::main_screen() {

}

void Display::select_screen() {

}

void Display::update() {
	switch (_tela) {
		case 1:
			main_screen();
			break;

		case 2:
			select_screen();
			break;
	}
}

int Display::get_target(){
    return _target_temp;
}
