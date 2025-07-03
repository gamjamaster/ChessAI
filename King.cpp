#include "King.h"

King::King(Color c) : Piece(c, (c == Color::White ? 'K' : 'k')) {}

std::string King::getName() const {
    return "King";
}

bool King::isValidMove(int sx, int sy, int dx, int dy) const {
    int dxDiff = abs(dx - sx);
    int dyDiff = abs(dy - sy);
    return (dxDiff <= 1 && dyDiff <= 1 && (dxDiff + dyDiff != 0));
}
