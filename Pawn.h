#pragma once
#ifndef Pawn_h
#define Pawn_h
#include "Piece.h"

class Pawn : public Piece {
	public: 
		Pawn(Color c);

		string getName() const override;
		bool isValidMove(int sx, int sy, int dx, int dy) const override;
};

#endif