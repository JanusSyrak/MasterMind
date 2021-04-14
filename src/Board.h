#pragma once

#include <iostream>
#include <vector>

class Board {
public:
	Board();
	Board(int w, int h);
	~Board();
	void init();
	void setBoardRow(int, std::vector<int>);

	void setWidth(int);
	int getWidth();
	void setHeight(int);
	int getHeight();
	void setCompRow(int, std::vector<int>);
	std::vector<std::vector<int>> getComparison();
	std::vector<std::vector<int>> getBoard();

private:
	int mWidth;
	int mHeight;
	std::vector<std::vector<int>> mBoard;
	std::vector<std::vector<int>> mComparison;
};