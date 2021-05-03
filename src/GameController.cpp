#include "GameController.h"


void GameController::reset() {
	mGameState = "GAME";
	current_round_ = 1;
	mBoard->init();
	generateCode();
}

GameController::GameController() {
	mGameState = "MAIN_MENU";
	current_round_ = 1;
	mSettings = new GameSettings();
	mBoard = new Board(mSettings->getCodeLength(), mSettings->getNumRounds());
	mInput = new InputController();
	mStateManager = new StateManager();

	generateCode();
}

GameController::~GameController() {
	delete mSettings;
	delete mBoard;
	delete mInput;
	delete mStateManager;
}


void GameController::generateCode() {
	std::vector<int> code;
	std::random_device rd;
	for (int i = 0; i < mSettings->getCodeLength(); i++) {
		code.push_back(rd() % mSettings->getNumColors() + 1);
	}
	mCode = code;
}


int GameController::roundsLeft() {
	return mSettings->getNumRounds() - current_round_ + 1;
}

void GameController::increaseRound() {
	current_round_++;
}

void GameController::updateState() {
	mGameState = mStateManager->getNextState(mGameState, mInput);
}

void GameController::executeState() {
	if (mInput->getCurrentInput() == "CHANGE_ROUNDS") {
		setNumRounds(stoi(mInput->getSecondInput()));
	}

	if (mInput->getCurrentInput() == "CHANGE_PEGS") {
		setNumPegs(stoi(mInput->getSecondInput()));
	}

	if (mInput->getCurrentInput() == "CODE_LENGTH") {
		setCodeLength(stoi(mInput->getSecondInput()));
	}
}


void GameController::mainLoop()
{
	while (1) {
		if (mGameState == "RESET") {
			reset();
		}

		if (mGameState == "BREAK") {
			break;
		}

		if (mGameState == "GAME") {
			mGraphics->displayGraphics(*mBoard, mGameState, mCode, *mSettings, getCurrentRound());

			std::cout << "Please enter a guess." << std::endl;

			std::string current_guess = mInput->getGuess(mSettings->getCodeLength(), mSettings->getNumColors());

			Code guess(current_guess);

			std::vector<int> comparison = guess.compare(getCode());

			getBoard()->setBoardRow(getCurrentRound() - 1, utility::to_vector(current_guess));
			getBoard()->setCompRow(getCurrentRound() - 1, comparison);

			if (utility::sum(comparison) == 8) {
				mGameState = "WIN";
			}
			else if (roundsLeft() == 1) {
				mGameState = "LOSE";
			}
			else {
				std::cout << std::endl;
				increaseRound();
			}
		}

		else {
			mGraphics->displayGraphics(*mBoard, mGameState, mCode, *mSettings, getCurrentRound());
			mInput->handleInput(mGameState);
			executeState();
			updateState();
		}
	}
}


void GameController::setNumRounds(int rounds) 
{
	mSettings->setRounds(rounds);
	mBoard->setHeight(rounds);
	mBoard->init();
}


void GameController::setCodeLength(int len)
{
	mSettings->setCodeLength(len);
	generateCode();
	mBoard->setWidth(len);
	mBoard->init();
}

void GameController::setNumPegs(int colors)
{
	mSettings->setColors(colors);
}

int GameController::getCodeLength() 
{ 
	return mSettings->getCodeLength(); 
}

Board* GameController::getBoard() 
{ 
	return mBoard; 
}

int GameController::getNumColors() 
{ 
	return mSettings->getNumColors(); 
}

std::vector<int> GameController::getCode() 
{ 
	return mCode; 
}

int GameController::getCurrentRound() 
{ 
	return current_round_; 
}

int GameController::getNumRounds() 
{ 
	return mSettings->getNumRounds(); 
}

InputController* GameController::getInputController()
{
	return mInput;
}

std::string GameController::getGameState()
{
	return mGameState;
}
