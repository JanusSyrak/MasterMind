#pragma once

#include <string>
#include <vector>

#include "InputController.h"

class StateManager {
public:
	StateManager();
	~StateManager();

	void pushState(std::string state);
	void popState();
	void changeState(std::string state);
	std::string getNextState(std::string, InputController*);

private:
	std::vector<std::string> states_;
};