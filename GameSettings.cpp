#include "GameSettings.h"

GameSettings::GameSettings()
{
	num_rounds_ = 12;
	num_colors_ = 6;
	code_length_ = 4;
}

GameSettings::GameSettings(int num_rounds, int num_colors, int code_length) {
	num_rounds_ = num_rounds;
	num_colors_ = num_colors;
	code_length_ = code_length;
}

GameSettings::~GameSettings()
{
}

void GameSettings::setRounds(int rounds) {
	num_rounds_ = rounds;
}

void GameSettings::setColors(int colors) {
	num_colors_ = colors;
}

void GameSettings::setCodeLength(int code_length) {
	code_length_ = code_length;
}