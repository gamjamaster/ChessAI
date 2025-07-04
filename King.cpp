#include "King.h"
#include "Board.h"
#include <cmath>

King::King(Color c) : Piece(c, (c == Color::White ? 'K' : 'k')) {}

string King::getName() const {
    return "King";
}

bool King::isValidMove(int sx, int sy, int dx, int dy, const Board& board) const {
    int dxAbs = abs(dx - sx);
    int dyAbs = abs(dy - sy);

    if (dxAbs <= 1 && dyAbs <= 1) {
        Piece* target = board.getPiece(dx, dy);
        return target == nullptr || target->getColor() != color;
    }
    return false;
}
