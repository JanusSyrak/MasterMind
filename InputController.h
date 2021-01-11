#ifndef INPUTCONTROLLER_H_
#define INPUTCONTROLLER_H_

#include <iostream>
#include <string>

#include "GameSettings.h"

class InputController {
public:
	InputController();
	~InputController();

	void handleInput(std::string game_state);
	void confirmChange(std::string, std::string);
	std::string translateToMessage(std::string change);

	bool validGuess(std::string, int, int);
	std::string getGuess(int, int);

	std::string current_input_;
	std::string second_input_;
};

#endif // INPUTCONTROLLER_H_