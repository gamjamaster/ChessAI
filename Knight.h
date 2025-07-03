#pragma once
#ifndef Knight_h
#define Knight_h
#include "Piece.h"

class Knight : public Piece {
public:
	Knight(Color c);

	string getName() const override;
	bool isValidMove(int sx, int sy, int dx, int dy) const override;
};

#endif

