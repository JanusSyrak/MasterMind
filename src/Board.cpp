#include "Board.h"

Board::Board()
{
	width_ = 4;
	height_ = 12;
	init();
}

Board::Board(int w, int h) {
	width_ = w;
	height_ = h;
	init();
}

Board::~Board()
{
}

void Board::init() {
	std::vector<std::vector<int>> board;
	for (int i = 0; i < height_; i++) {
		std::vector<int> row;
		for (int j = 0; j < width_; j++) {
			row.push_back(0);
		}
		board.push_back(row);
	}
	board_ = board;
	comparison_ = board;
}

void Board::setBoardRow(int index, std::vector<int> code) {
	board_[index] = code;
}

void Board::setCompRow(int index, std::vector<int> code) {
	comparison_[index] = code;
}

int Board::getWidth() {
	return width_;
}

void Board::setWidth(int width) {
	width_ = width;
}

void Board::setHeight(int height)
{
	height_ = height;
}

int Board::getHeight() {
	return height_;
}


std::vector<std::vector<int>> Board::getComparison() {
	return comparison_;
}


std::vector<std::vector<int>> Board::getBoard() {
	return board_;
}
