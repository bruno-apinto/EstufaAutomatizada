#ifndef MOTOR_HPP
#define MOTOR_HPP

class Motor{
public:
	/**
	* \brief Construtor do motor
	*/
	Motor(int step, int dir, int led);
	/**
	* \brief Gira o motor de acordo com o delay
	* Caso o delay seja negativo, deixa o motor parado
	*/
	void spin();

	/**
	* \brief Atualiza o delay de acordo com as temperaturas atual e alvo
	*
	* \param current_temp Temperatura atual
	* \param target_temp Temperatura alvo
	*/
	void update_delay(int current_temp, int target_temp);

private:
	int _step;
	int _dir;
	int _led;
	int _delay;
};

#endif //MOTOR_HPP