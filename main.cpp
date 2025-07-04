#pragma once
#include <iostream>
#include <string>
#include "Board.h"

class Game {
private:
	Board board;
	Color currentTurn;

	void printBoard() const {
		board.print();
	}

	void switchTurn() {
		currentTurn = (currentTurn == Color::White) ? Color::Black : Color
	}

	bool processMove(const string& move);

public:
	Game() : currentTurn(Color::White){}

	void run();
};