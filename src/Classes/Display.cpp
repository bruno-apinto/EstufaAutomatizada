#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <SPI.h>
#include <Arduino.h>
#include "Display.hpp"

Display::Display(int tft_CS, int tft_DC, int current_temp, int target_temp, int select, int down, int up): _tft(Adafruit_ILI9341(tft_CS, tft_DC)) {
	
	_tft.begin();
	_tft.setTextColor(ILI9341_WHITE);
	_tft.setTextSize(2);
	_tft.setRotation(1);
	_tft.fillScreen(ILI9341_BLACK);
	
	_tela = 1;
	
	pinMode(down, INPUT_PULLUP);
	pinMode(select, INPUT_PULLUP);
	pinMode(up, INPUT_PULLUP);
	
	_select = select;
	_down = down;
	_up = up;

	_target_temp = target_temp;
	_current_temp = current_temp;
}

void Display::design_display_1(int posicao_do_cursor, int size_titulo, char txt_1[], int size_texto, char txt_2[], char txt_3[]) {
	_tft.setCursor(0,0);
	_tft.setTextSize(size_titulo);
	_tft.println("");
	_tft.print("");
	_tft.println(txt_1);
	_tft.setTextSize(size_texto);
	_tft.println("");
	_tft.println("");

	if (posicao_do_cursor == 2) {
		_tft.write(16);
		_tft.print(" ");
	} else {
		_tft.print("  ");
	}
	_tft.println(txt_2);
	_tft.println("");

	if (posicao_do_cursor == 3) {
		_tft.write(16);
		_tft.print(" ");
	} else {
		_tft.print("  ");
	}
	_tft.println(txt_3);
}

void Display::design_display_2(int escolha) {
	_tft.setCursor(0,0);
	_tft.setTextSize(3);
	_tft.println("");
	_tft.print("  Temperatura");
	_tft.setTextSize(4);
	_tft.println(": ");
	_tft.println("");

	_tft.setTextSize(5);
	if (escolha == 1) {
		if (_current_temp != _previous_temp) {
			_tft.fillRect(10, 60, 300, 100, ILI9341_BLACK);
		}
		_tft.print("   " + String(_current_temp));
	} else if (escolha == 2) {
		_tft.print("   " + String(_target_temp));
	}
	_tft.setTextSize(2);
	_tft.print(" o");
	_tft.setTextSize(5);
	_tft.println("C");
	_tft.println("");
	_tft.setTextSize(2);
	_tft.write(16);
	_tft.println(" Voltar");
}

void Display::main_screen() {
		if (_posicao_do_cursor == 2) {
			design_display_1(_posicao_do_cursor, 3, "Estufa Automatica", 2, "Definir temp. ideal", "Temp. em tempo real");
		}

		if (_posicao_do_cursor == 3) {
			design_display_1(_posicao_do_cursor, 3, "Estufa Automatica", 2, "Definir temp. ideal", "Temp. em tempo real");
		}

		if (!digitalRead(_up) && _posicao_do_cursor != 2) {
			_posicao_do_cursor --;
			_tft.fillRect(0, 45, 12, 130, ILI9341_BLACK);
		}

		if (!digitalRead(_down) && _posicao_do_cursor != 3) {
			_posicao_do_cursor ++;
			_tft.fillRect(0, 45, 12, 130, ILI9341_BLACK);
		}

		if (!digitalRead(_select)) {
			_tela = _posicao_do_cursor;
			_posicao_do_cursor = 2;
			_tft.fillScreen(ILI9341_BLACK);
		}
}

void Display::real_time_temp() {
		design_display_2(1);

		if (!digitalRead(_select)) {
			_tela = 1;
			_tft.fillScreen(ILI9341_BLACK);
		}
}

void Display::select_screen() {
	design_display_2(2);

	_tft.setCursor(65,86);
	_tft.write(24);
	_tft.setCursor(65,109);
	_tft.write(25);

	if (!digitalRead(_up)) {
		_target_temp ++;
		_tft.fillRect(90, 60, 150, 100, ILI9341_BLACK);
	}

	if (!digitalRead(_down)) {
		_target_temp --;
		_tft.fillRect(90, 60, 150, 100, ILI9341_BLACK);
	}

	if (!digitalRead(_select)) {
		_tela = 1;
		_tft.fillScreen(ILI9341_BLACK);
	}
}

void Display::update() {
	switch (_tela) {
		case 1: {
			main_screen();	
			break;
		}
		case 2: {
			select_screen();
			break;
		}
		case 3:	{
			real_time_temp();
			break;
		}
	}
}

int Display::get_target() {
	return _target_temp;
}

void Display::set_current_temp(int current_temp){
	_current_temp = current_temp;
}

void Display::set_previous_temp(int previous_temp){
	_previous_temp = previous_temp;
}

