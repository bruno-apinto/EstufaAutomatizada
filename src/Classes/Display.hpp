#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <Adafruit_ILI9341.h>

class Display{
public:
	/// @brief Inicializa o display
	Display(int tft_CS, int tft_DC, int current_temp, int atual_temp, int select, int down, int up);

	/// @brief Estilo usado para escrever os textos no display
	void design_display(int posicao_do_cursor, int size_titulo, char txt_1[], int size_texto, char txt_2[], char txt_3[]);

	/// @brief Tela inicial, pode acessar a tela de seleção de temp e a de temp atual
	void main_screen();

	/// @brief Mostra a temperatura atual e a alvo
	void real_time_temp();

	/// @brief Tela de seleção da temperatura alvo
	void select_screen();

	/// @brief Atualiza o valor da temperatura atual
	void update();

	/// @return A tela atual
	int get_tela();

	/// @return A temperatura alvo
	int get_target();

	/// @return A temperatura atual
	int get_atual_temp();

private:
	Adafruit_ILI9341 _tft; // controlador do display

	int _target_temp; // temperatura alvo
	int _atual_temp; // temperatura atual
	int _tela; // tela atual

	int _select; // botao de seleção
	int _down; // botao de ir para baixo
	int _up; // botao de ir para cima
};

#endif //DISPLAY_HPP
