#include "Code.h"

Code::Code()
{
}

Code::Code(std::string s)
{
	mCode = utility::to_vector(s);
}

Code::Code(std::vector<int> v)
{
	mCode = v;
}

Code::~Code()
{
}

// 2 is for correct position and color, 1 is for correct color
std::vector<int> Code::compare(Code other) {
	std::vector<int> comparison(mCode.size(), 0);
	std::vector<int> guess = mCode;
	std::vector<int> answer = other.mCode;

	// Check for correct position and color
	for (int i = 0; i < mCode.size(); i++) {
		if (guess[i] == answer[i]) {
			comparison[i] = 2;
			guess[i] = -1;
			answer[i] = -1;
		}
	}

	// Check for correct color only
	for (int i = 0; i < guess.size(); i++) {
		for (int j = 0; j < guess.size(); j++) {
			if (guess[i] == answer[j] && guess[i] >= 0 && answer[j] >= 0) {
				comparison[i] = 1;
				guess[i] = -1;
				answer[j] = -1;
			}
		}
	}

	// Shuffle vector so the player cannot directly infer the correct pegs
	utility::shuffle_vector(comparison);
	return comparison;
}
