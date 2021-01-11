#include "GameController.h"


void GameController::reset() {
	game_state_ = "GAME";
	current_round_ = 1;
	board_->init();
	generateCode();
}

GameController::GameController() {
	game_state_ = "MAIN_MENU";
	current_round_ = 1;
	settings_ = new GameSettings();
	board_ = new Board(settings_->code_length_, settings_->num_rounds_);
	input_ = new InputController();
	state_manager_ = new StateManager();

	generateCode();
}

GameController::~GameController() {
}


void GameController::generateCode() {
	std::vector<int> _code;
	std::random_device rd;
	for (int i = 0; i < settings_->code_length_; i++) {
		_code.push_back(rd() % settings_->num_colors_ + 1);
	}
	code_ = _code;
}


int GameController::roundsLeft() {
	return settings_->num_rounds_ - current_round_ + 1;
}

void GameController::increaseRound() {
	current_round_++;
}

void GameController::updateState() {
	game_state_ = state_manager_->getNextState(game_state_, input_);
}

void GameController::executeState() {
	if (input_->current_input_ == "CHANGE_ROUNDS") {
		setNumRounds(stoi(input_->second_input_));
	}

	if (input_->current_input_ == "CHANGE_PEGS") {
		setNumPegs(stoi(input_->second_input_));
	}

	if (input_->current_input_ == "CODE_LENGTH") {
		setCodeLength(stoi(input_->second_input_));
	}
}


void GameController::mainLoop()
{
	while (1) {
		if (game_state_ == "RESET") {
			reset();
		}

		if (game_state_ == "BREAK") {
			break;
		}

		if (game_state_ == "GAME") {
			graphics_->displayGraphics(*board_, game_state_, code_, *settings_, getCurrentRound());

			std::cout << "Please enter a guess." << std::endl;

			std::string current_guess = input_->getGuess(settings_->code_length_, settings_->num_colors_);

			Code guess(current_guess);

			std::vector<int> comparison = guess.compare(getCode());

			getBoard()->setBoardRow(getCurrentRound() - 1, utility::to_vector(current_guess));
			getBoard()->setCompRow(getCurrentRound() - 1, comparison);

			if (utility::sum(comparison) == 8) {
				game_state_ = "WIN";
			}
			else if (roundsLeft() == 1) {
				game_state_ = "LOSE";
			}
			else {
				std::cout << std::endl;
				increaseRound();
			}
		}

		else {
			graphics_->displayGraphics(*board_, game_state_, code_, *settings_, getCurrentRound());
			input_->handleInput(game_state_);
			executeState();
			updateState();
		}
	}
}


void GameController::setNumRounds(int rounds) {
	settings_->setRounds(rounds);
	board_->setHeight(rounds);
	board_->init();
}


void GameController::setCodeLength(int len)
{
	settings_->setCodeLength(len);
	generateCode();
	board_->setWidth(len);
	board_->init();
}

void GameController::setNumPegs(int colors)
{
	settings_->setColors(colors);
}

int GameController::getCodeLength() { return settings_->code_length_; }
Board* GameController::getBoard() { return board_; }
int GameController::getNumColors() { return settings_->num_colors_; }
std::vector<int> GameController::getCode() { return code_; }
int GameController::getCurrentRound() { return current_round_; }
int GameController::getNumRounds() { return settings_->num_rounds_; }

InputController* GameController::getInputController()
{
	return input_;
}

std::string GameController::getGameState()
{
	return game_state_;
}
