#pragma once

const int MIN_PEGS = 3;
const int MAX_PEGS = 100;
const int MIN_ROUNDS = 5;
const int MAX_ROUNDS = 100;
const int MIN_CL = 3;
const int MAX_CL = 9;

class GameSettings {
public:
	GameSettings();
	GameSettings(int, int, int);
	~GameSettings();

	void setRounds(int);
	void setColors(int);
	void setCodeLength(int);

	int mNumRounds;
	int mNumColors;
	int mCodeLength;
};