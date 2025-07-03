#pragma once
#ifndef Rook_h
#define Rook_h
#include "Piece.h"

class Rook : public Piece {
public:
	Rook(Color c);

	string getName() const override;
	bool isValidMove(int sx, int sy, int dx, int dy) const override;
};

#endif#pragma once
