#include "Board.h"

Board::Board()
{
	mWidth = 4;
	mHeight = 12;
	init();
}

Board::Board(int w, int h) {
	mWidth = w;
	mHeight = h;
	init();
}

Board::~Board()
{
}

void Board::init() {
	std::vector<std::vector<int>> board;
	for (int i = 0; i < mHeight; i++) {
		std::vector<int> row;
		for (int j = 0; j < mWidth; j++) {
			row.push_back(0);
		}
		board.push_back(row);
	}
	mBoard = board;
	mComparison = board;
}

void Board::setBoardRow(int index, std::vector<int> code) {
	mBoard[index] = code;
}

void Board::setCompRow(int index, std::vector<int> code) {
	mComparison[index] = code;
}

int Board::getWidth() {
	return mWidth;
}

void Board::setWidth(int width) {
	mWidth = width;
}

void Board::setHeight(int height)
{
	mHeight = height;
}

int Board::getHeight() {
	return mHeight;
}


std::vector<std::vector<int>> Board::getComparison() {
	return mComparison;
}


std::vector<std::vector<int>> Board::getBoard() {
	return mBoard;
}
