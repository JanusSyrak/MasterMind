#include "StateManager.h"

StateManager::StateManager()
{}

StateManager::~StateManager()
{}

void StateManager::pushState(std::string state)
{
	mStates.push_back(state);
}

void StateManager::popState()
{
	mStates.pop_back();
}

void StateManager::changeState(std::string state)
{
	mStates.clear();
	mStates.push_back(state);
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
		if (input->mCurrentInput == "SETTINGS") {
			next_state = "SETTINGS";
		}

		if (input->mCurrentInput == "HELP") {
			next_state = "HELP";
		}

		if (input->mCurrentInput == "NEW_GAME") {
			next_state = "NEW_GAME";
		}

		if (input->mCurrentInput == "GAME") {
			next_state = "GAME";
		}
	}

	if (game_state == "NEW_GAME") {
		if (input->mCurrentInput == "RESET") {
			next_state = "RESET";
		}
		if (input->mCurrentInput == "BREAK") {
			next_state = "BREAK";
		}
	}

	if (game_state == "SETTINGS") {
		if (input->mCurrentInput == "ROUNDS") {
			next_state = "ROUNDS";
		}
		if (input->mCurrentInput == "PEGS") {
			next_state = "PEGS";
		}
		if (input->mCurrentInput == "CODE_LENGTH") {
			next_state = "CODE_LENGTH";
		}
		if (input->mCurrentInput == "MAIN_MENU") {
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
