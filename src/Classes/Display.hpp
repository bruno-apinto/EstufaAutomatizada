#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <Adafruit_ILI9341.h>

class Display{
public:
	/// @brief Inicializa o display
	Display(int tft_CS, int tft_DC, int current_temp, int select, int down, int up);

	/// @brief Tela inicial, mostra a temperatura atual e a alvo
	void main_screen();

	/// @brief Tela de seleção da temperatura alvo
	void select_screen();

	/// @brief Atualiza o valor da temperatura atual
	void update();

	/// @return A tela atual
	int get_tela();

	/// @return A temperatura alvo
	int get_target();

private:
	Adafruit_ILI9341 _tft; // controlador do display

	int _target_temp; // temperatura alvo
	int _tela; // tela atual

	int _select; // botao de seleção
	int _down; // botao de ir para baixo
	int _up; // botao de ir para cima
};

#endif //DISPLAY_HPP
