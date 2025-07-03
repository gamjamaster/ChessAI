#pragma once
#ifndef board_h
#define board
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
};

#endif
