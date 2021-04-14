#pragma once

#include <random>
#include <string>

#include "Board.h"
#include "Code.h"
#include "GameSettings.h"
#include "GraphicsController.h"
#include "InputController.h"
#include "StateManager.h"
#include "utility.h"

class GameController {
public:
	GameController();
	~GameController();

	int roundsLeft();
	void reset();
	void increaseRound();

	void updateState();

	void generateCode();
	void mainLoop();

	void setNumPegs(int);
	void setNumRounds(int);
	void setCodeLength(int);

	int getCurrentRound();
	Board* getBoard();
	std::vector<int> getCode();

	int getCodeLength();
	int getNumColors();
	int getNumRounds();

	InputController* getInputController();
	std::string getGameState();

	void executeState();

private:
	int current_round_;
	int num_rounds_;
	int num_colors_;
	int code_length_;

	std::vector<int> mCode;
	std::string mGameState;

	Board* mBoard;
	GraphicsController* mGraphics;
	InputController* mInput;
	StateManager* mStateManager;
	GameSettings* mSettings;


};