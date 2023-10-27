#include "Adafruit_ILI9341.h"

class Display{
public:
	/**
	* \brief Construtor do display
	*/
	Display(int tft_cs, int tft_dc, int current_temp, int select, int down, int up);
		/*
		_tft(Adafruit_ILI9341(tft_cs, tft_dc)),
		_target_temp(current_temp),
		_tela(1),
		_select(select),
		_down(down),
		_up(up){}
 		 */

	/**
	* \brief Tela principal
	* Mostra a temperatura atual e a alvo, o cursor fica fixo na opção
	* de ir para a tela de seleção
	*/
	void main_screen(int *tela, float current_temp, float target_temp);

	/**
	* \brief Tela de seleção da temperatura alvo, retorna o temperatura alvo
	*/
	float select_screen(int *tela, float target_temp);	

	/**
	* \brief Define a tela a ser mostrada baseado na variavel tela
	*/
	// void update();  // Não entendi pra que esse procedimento

private:
	Adafruit_ILI9341 _tft; /// controlador do display
	int _target_temp; /// temperatura alvo
	int _tela; /// tela atual
	
	int _select; /// botao de seleção
	int _down; /// botao de ir para baixo
	int _up; /// botao de ir para cima
};
