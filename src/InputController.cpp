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
			mCurrentInput = "GAME";
		}

		else if (prompt == "s") {
			mCurrentInput = "SETTINGS";
		}

		else {
			std::cout << "prompt was: " << prompt << std::endl;
			std::cout << "Sorry, that has not been implemented yet." << std::endl;
			std::cout << "Starting game." << std::endl;
			mCurrentInput = "GAME";
		}
	}

	if (game_state == "SETTINGS") {
		std::cin >> prompt;
		if (prompt == "r")
			mCurrentInput = "ROUNDS";
		else if (prompt == "p")
			mCurrentInput = "PEGS";
		else if (prompt == "c")
			mCurrentInput = "CODE_LENGTH";
		else if (prompt == "e")
			mCurrentInput = "MAIN_MENU";
	}

	if (game_state == "NEW_GAME") {
		std::cin >> prompt;
		if (prompt == "y") {
			mCurrentInput = "RESET";
		}
		if (prompt == "n") {
			mCurrentInput = "BREAK";
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
		mCurrentInput = "CHANGE_" + SettingToChange;
		mSecondInput = prompt;
	}
	else {
		mCurrentInput = "SETTINGS";
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

