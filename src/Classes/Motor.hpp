#ifndef MOTOR_HPP
#define MOTOR_HPP

class Motor{
public:
	/**
	* \brief Construtor do motor
	*/
	Motor(int step, int dir, int led, int delay);
	
	/**
	 * @brief Gira o motor, caso delay seja neg, o motor para
	 * 
	 * @param MOTOR_DIR 
	 * @param MOTOR_STEP 
	 */
	void spin(int& motor_dir, int& motor_step);

	/**
	* @brief Atualiza o delay de acordo com as temperaturas atual e alvo,
  * sendo delay sempre maior que 2ms //THEO: Acredito que 2ms não seja o minimo, podemos testar
	*
	* @param current_temp Temperatura atual
	* @param target_temp Temperatura alvo
	*/
	void update_delay(float current_temp, float target_temp);

	/**
	 * @brief acende e apaga o led
	 * 
	 * @param led_motor 
	 */
	// void led (int& led_motor);

private:
	int _step; //quantidade de passos
	int _dir; //sentido de giro 0 = AH, 1 = H
	int _led; 
	float _delay; //delay entre os passos
};

#endif //MOTOR_HPP
