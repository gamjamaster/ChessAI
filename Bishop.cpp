#include "Bishop.h"
#include <cmath>

Bishop::Bishop(Color c) : Piece(c, (c == Color::White ? 'B' : 'b')) {}

string Bishop::getName() const {
	return "Bishop";
}

bool Bishop::isValidMove(int sx, int sy, int dx, int dy) const {
	return abs(dx - sx) == abs(dy - sy);
}