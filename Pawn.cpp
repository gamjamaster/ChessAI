#include "Pawn.h"

Pawn :: Pawn(Color c) : Piece(c, (c == Color::White ? 'P' : 'p')){}

string Pawn::getName() const {
	return "Pawn";
}

bool Pawn::isValidMove(int sx, int sy, int dx, int dy) const {
	int direction = (color == Color::White) ? -1 : 1;
	return (sx + direction == dx && sy == dy);
}