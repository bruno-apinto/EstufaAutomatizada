#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "Adafruit_ILI9341.h"

class Display{
public:
	/**
	* @brief Construtor do display
	*/
	Display(int tft_cs, int tft_dc, int current_temp,
				 int select, int down, int up);

	/**
	* @brief Tela principal
	* Mostra a temperatura atual e a alvo, o cursor fica fixo na opção
	* de ir para a tela de seleção
	*/
	void main_screen();

	/**
	* @brief Tela de seleção da temperatura alvo
	*/
	void select_screen();	

	/**
	* @brief Define a tela a ser mostrada baseado na variavel tela
	*/
	void update();

	/**
	 * @brief Retorna o valor da temperatura alvo
	 * 
	 * @return _target_temp 
	 */
	int get_target();

private:
	Adafruit_ILI9341 _tft; /// controlador do display
	int _target_temp; /// temperatura alvo
	int _tela; /// tela atual

	int _select; /// botao de seleção
	int _down; /// botao de ir para baixo
	int _up; /// botao de ir para cima
};

#endif //DISPLAY_HPP
