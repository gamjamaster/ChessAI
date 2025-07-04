#pragma once
#ifndef board_h
#define board_h
#include "Piece.h"
#include <memory>
#include <vector>

class Board {
private:
	vector<vector<unique_ptr<Piece>> > squares;

public:
    Board();
    void initialize();
    void print() const;
    Piece* getPiece(int x, int y) const;
    void movePiece(int sx, int sy, int dx, int dy);
    bool isInsideBoard(int x, int y) const;

    // 복사 금지 (명시적으로)
    Board(const Board&) = delete;
    Board& operator=(const Board&) = delete;
};

#endif
