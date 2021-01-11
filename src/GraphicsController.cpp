#include "GraphicsController.h"

void GraphicsController::printCode(std::vector<int> code) {
	std::cout << "|";
	for (int i = 0; i < code.size(); i++) {
		std::cout << code[i] << "|";
	}
	std::cout << std::endl;
}


void GraphicsController::printHidden(int code_length) {
	std::cout << "|";
	for (int i = 0; i < code_length; i++) {
		std::cout << "?" << "|";
	}
	std::cout << std::endl;
}

void GraphicsController::render(Board& board, std::string game_state, std::vector<int> code)
{
	if (game_state == "GAME") {
		printHidden(code.size());
	}
	if (game_state == "LOSE") {
		printCode(code);
	}

	for (int i = board.getHeight() - 1; i >= 0; i--) {
		for (int j = 0; j < board.getWidth(); j++) {
			std::cout << "|" << board.getBoard()[i][j];
		}
		std::cout << "| ";
		for (int j = 0; j < board.getWidth(); j++) {
			std::cout << "|" << board.getComparison()[i][j];
		}
		std::cout << "|" << std::endl;
	}
}


void GraphicsController::displayMainScreenText()
{
	std::cout << "Welcome to MasterMind!" << std::endl;
	std::cout << "Enter 'b' in the prompt in order to begin the game." << std::endl;
	std::cout << "Enter 's' in the prompt to go to settings." << std::endl;
	std::cout << "Enter 'h' in the prompt to see help." << std::endl;
}

void GraphicsController::displayGraphics(Board& board, std::string game_state, std::vector<int> code, GameSettings& settings, int current_round)
{
	if (game_state == "ROUNDS") {
		displayRoundsText();
	}
	if (game_state == "PEGS") {
		displayPegsText();
	}
	if (game_state == "CODE_LENGTH") {
		displayCodeLengthText();
	}
	if (game_state == "MAIN_MENU") {
		displayMainScreenText();
	}

	if (game_state == "SETTINGS") {
		displaySettingsText(settings);
	}

	if (game_state == "HELP") {
		displayHelpText();
	}
	if (game_state == "NEW_GAME") {
		displayNewGameText();
	}
	
	if (game_state == "WIN") {
		displayWinText();
		render(board, game_state, code);
	}
	
	if (game_state == "LOSE") {
		displayLoseText();
		render(board, game_state, code);
	}

	if (game_state == "RESET") {

	}

	if (game_state == "BREAK") {

	}

	if (game_state == "GAME") {
		std::cout << "ROUND " + std::to_string(current_round) << std::endl;
		render(board, game_state, code);
	}
}

void GraphicsController::displaySettingsText(GameSettings& settings) {
	std::cout << "To change number of rounds, input 'r' in the prompt. (Current: " << settings.num_rounds_ << ")" << std::endl;
	std::cout << "To change the number of pegs, input 'p' in the prompt. (Current: " << settings.num_colors_ << ")" << std::endl;
	std::cout << "To change the code size, input 'c' in the prompt. (Current: " << settings.code_length_ << ")"<< std::endl;
	std::cout << "To return to the main menu, input 'e' in the prompt." << std::endl;
}

void GraphicsController::displayHelpText() {
	std::cout << "Help is not currently implemented." << std::endl;
}

void GraphicsController::displayNewGameText()
{
	std::cout << "Do you want to start a new game?" << std::endl;
}

void GraphicsController::displayWinText()
{
	std::cout << "Congratulations, you guessed the correct code!" << std::endl;
}

void GraphicsController::displayLoseText()
{
	std::cout << "YOU LOST!" << std::endl;
}

void GraphicsController::displayPegsText() {
	std::cout << "Enter the amount of different colored pegs you want." << std::endl;
}

void GraphicsController::displayRoundsText() {
	std::cout << "Enter the maximum number of rounds you want." << std::endl;
}

void GraphicsController::displayCodeLengthText() {
	std::cout << "Enter the code length that you want." << std::endl;
}
