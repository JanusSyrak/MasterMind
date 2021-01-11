#include "StateManager.h"

StateManager::StateManager()
{}

StateManager::~StateManager()
{}

void StateManager::pushState(std::string state)
{
	states_.push_back(state);
}

void StateManager::popState()
{
	states_.pop_back();
}

void StateManager::changeState(std::string state)
{
	states_.clear();
	states_.push_back(state);
}

std::string StateManager::getNextState(std::string game_state, InputController* input)
{
	std::string next_state = "";

	if (game_state == "ROUNDS") {
		next_state = "SETTINGS";
	}

	if (game_state == "PEGS") {
		next_state = "SETTINGS";
	}

	if (game_state == "CODE_LENGTH") {
		next_state = "SETTINGS";
	}

	if (game_state == "MAIN_MENU") {
		if (input->current_input_ == "SETTINGS") {
			next_state = "SETTINGS";
		}

		if (input->current_input_ == "HELP") {
			next_state = "HELP";
		}

		if (input->current_input_ == "NEW_GAME") {
			next_state = "NEW_GAME";
		}

		if (input->current_input_ == "GAME") {
			next_state = "GAME";
		}
	}

	if (game_state == "NEW_GAME") {
		if (input->current_input_ == "RESET") {
			next_state = "RESET";
		}
		if (input->current_input_ == "BREAK") {
			next_state = "BREAK";
		}
	}

	if (game_state == "SETTINGS") {
		if (input->current_input_ == "ROUNDS") {
			next_state = "ROUNDS";
		}
		if (input->current_input_ == "PEGS") {
			next_state = "PEGS";
		}
		if (input->current_input_ == "CODE_LENGTH") {
			next_state = "CODE_LENGTH";
		}
		if (input->current_input_ == "MAIN_MENU") {
			next_state = "MAIN_MENU";
		}
	}

	if (game_state == "WIN") {
		next_state = "NEW_GAME";
	}

	if (game_state == "LOSE") {
		next_state = "NEW_GAME";
	}

	return next_state;
}
