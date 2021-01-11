#include "InputController.h"
#include "utility.h"

InputController::InputController() {

}

InputController::~InputController() {}

void InputController::handleInput(std::string game_state) {
	std::string prompt;
	if (game_state == "MAIN_MENU") {
		std::cin >> prompt;
		if (prompt == "b") {
			current_input_ = "GAME";
		}

		else if (prompt == "s") {
			current_input_ = "SETTINGS";
		}

		else {
			std::cout << "prompt was: " << prompt << std::endl;
			std::cout << "Sorry, that has not been implemented yet." << std::endl;
			std::cout << "Starting game." << std::endl;
			current_input_ = "GAME";
		}
	}

	if (game_state == "SETTINGS") {
		std::cin >> prompt;
		if (prompt == "r")
			current_input_ = "ROUNDS";
		else if (prompt == "p")
			current_input_ = "PEGS";
		else if (prompt == "c")
			current_input_ = "CODE_LENGTH";
		else if (prompt == "e")
			current_input_ = "MAIN_MENU";
	}

	if (game_state == "NEW_GAME") {
		std::cin >> prompt;
		if (prompt == "y") {
			current_input_ = "RESET";
		}
		if (prompt == "n") {
			current_input_ = "BREAK";
		}
	}

	if (game_state == "ROUNDS") {
		std::cin >> prompt;
		if (std::stoi(prompt) > MIN_ROUNDS && stoi(prompt) < MAX_ROUNDS) {
			confirmChange("rounds", prompt);
		}
	}

	if (game_state == "PEGS") {
		std::cin >> prompt;
		if (std::stoi(prompt) > MIN_PEGS && stoi(prompt) <= MAX_PEGS) {
			confirmChange("pegs", prompt);
		}
	}

	if (game_state == "CODE_LENGTH") {
		std::cin >> prompt;
		if (std::stoi(prompt) > MIN_CL && stoi(prompt) < MAX_CL) {
			confirmChange("code length", prompt);
		}
	}
}

std::string InputController::translateToMessage(std::string change) {
	if (change == "code length") {
		return "CODE_LENGTH";
	}
	if (change == "rounds") {
		return "ROUNDS";
	}
	if (change == "pegs") {
		return "PEGS";
	}
}

void InputController::confirmChange(std::string change, std::string prompt) {
	std::string confirm;
	std::cout << "Are you sure you want to change the number of " << change << " to " << prompt << "?" << std::endl;
	std::cin >> confirm;
	if (confirm == "y" || confirm == "yes") {
		std::string SettingToChange = translateToMessage(change);
		current_input_ = "CHANGE_" + SettingToChange;
		second_input_ = prompt;
	}
	else {
		current_input_ = "SETTINGS";
	}
}

// Checks whether the guess is the correct length and consists only of numerical values
bool InputController::validGuess(std::string s, int code_length, int pegs) {
	if (!(s.size() == code_length)) {
		return 0;
	}

	for (int i = 0; i < s.size(); i++) {
		if (!(isdigit(s[i]))) {
			return 0;
		}
		else {
			if (s[i] == '0' || utility::char_to_int(s[i]) > pegs) {
				return 0;
			}
		}
	}

	return 1;
}


std::string InputController::getGuess(int code_length, int pegs) {
	std::string current_guess;
	std::cin >> current_guess;
	while (!(validGuess(current_guess, code_length, pegs))) {
		std::cout << "That is not a valid guess." << std::endl;
		std::cout << "Guess must be of length " << code_length << ", and numbers must be 1-6." << std::endl;
		std::cout << "Please enter a guess." << std::endl;
		std::cin >> current_guess;
	}

	return current_guess;
}

