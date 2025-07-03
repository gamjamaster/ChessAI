#include "Knight.h"
#include <cmath>

Knight::Knight(Color c) : Piece(c, (c == Color::White ? 'K' : 'k')) {}

string Knight::getName() const {
	return "Knight";
}

bool Knight::isValidMove(int sx, int sy, int dx, int dy) const {
	int dxAbs = abs(dx - sx);
	int dyAbs = abs(dy - sy);
	return (dxAbs == 2 && dyAbs == 1) || (dxAbs == 1 && dyAbs == 2);
}