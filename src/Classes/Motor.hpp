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
	void spin(int& MOTOR_DIR, int& MOTOR_STEP);

	/**
	* \brief Atualiza o delay de acordo com as temperaturas atual e alvo,
    * sendo delay sempre maior que 2000ms (2.0s)
	*
	* \param current_temp Temperatura atual
	* \param target_temp Temperatura alvo
	*/
	void update_delay(float current_temp, float target_temp);

	/**
	 * @brief acende e apaga o led
	 * 
	 * @param MOTOR_LED 
	 */
	void led (int& MOTOR_LED){}

private:
	float _step; //quantidade de passos
	int _dir; //sentido de giro
	int _led; 
	float _delay; //delay entre os passos
};

#endif //MOTOR_HPP