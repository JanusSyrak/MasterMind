#ifndef GRAPHICSCONTROLLER_H_
#define GRAPHICSCONTROLLER_H_

#include <string>

#include "Board.h"
#include "GameSettings.h"

class GraphicsController
{
public: 
	void printCode(std::vector<int> code);

	void displayGraphics(Board&, std::string, std::vector<int>, GameSettings&, int);
	void displaySettingsText(GameSettings&);

	void printHidden(int code_length);
	void render(Board& board, std::string, std::vector<int>);

private:
	void displayMainScreenText();
	void displayHelpText();
	void displayNewGameText();
	void displayWinText();
	void displayLoseText();
	void displayRoundsText();
	void displayPegsText();
	void displayCodeLengthText();
};

#endif // GRAPHICSCONTROLLER_H_