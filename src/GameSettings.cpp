#include "GameSettings.h"

GameSettings::GameSettings()
{
	mNumRounds = 12;
	mNumColors = 6;
	mCodeLength = 4;
}

GameSettings::GameSettings(int num_rounds, int num_colors, int code_length) {
	mNumRounds = num_rounds;
	mNumColors = num_colors;
	mCodeLength = code_length;
}

GameSettings::~GameSettings()
{
}

void GameSettings::setRounds(int rounds) {
	mNumRounds = rounds;
}

void GameSettings::setColors(int colors) {
	mNumColors = colors;
}

void GameSettings::setCodeLength(int code_length) {
	mCodeLength = code_length;
}

int GameSettings::getNumRounds()
{
	return mNumRounds;
}

int GameSettings::getNumColors()
{
	return mNumColors;
}

int GameSettings::getCodeLength()
{
	return mCodeLength;
}