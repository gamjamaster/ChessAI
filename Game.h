#pragma once
#include "Board.h"
#include <iostream>
#include <string>

class Game {
private:
    Board board;
    Color currentTurn;

    void printBoard() const {
        board.print();
    }

    void switchTurn() {
        currentTurn = (currentTurn == Color::White) ? Color::Black : Color::White;
    }

    bool processMove(const string& move);

public:
    Game() : currentTurn(Color::White) {}

    void run();
    tuple<int, int, int, int> getBestMove(Color aiColor);
};
#pragma once
