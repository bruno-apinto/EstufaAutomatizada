#ifndef MOTOR_HPP
#define MOTOR_HPP

class Motor{
public:
	/// @brief Construtor do motor
	Motor(int step, int dir, int led);
	
	/// @brief Gira o motor, caso delay seja neg, o motor para
	void spin();

	/// @brief Atualiza o delay de acordo com as temperaturas atual e alvo,
  ///        sendo delay sempre maior que 2ms
	/// @param current_temp Temperatura atual
	/// @param target_temp Temperatura alvo
	void update_delay(float current_temp, float target_temp);

private:
	int _step; //quantidade de passos
	int _dir; //sentido de giro 0 = AH, 1 = H
	int _led; 
	float _delay; //delay entre os passos
};

#endif //MOTOR_HPP
