#include "Rook.h"

Rook::Rook(Color c) : Piece(c, (c == Color::White ? 'R' : 'r')) {}

string Rook::getName() const {
	return "Rook";
}

bool Rook::isValidMove(int sx, int sy, int dx, int dy) const {
	return (sx == dx || sy == dy);
}