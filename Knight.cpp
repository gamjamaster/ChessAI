#include "Knight.h"
#include <cmath>

Knight::Knight(Color c) : Piece(c, (c == Color::White ? 'N' : 'n')) {}

string Knight::getName() const {
    return "Knight";
}

bool Knight::isValidMove(int sx, int sy, int dx, int dy, const Board& board) const {
    int dxAbs = abs(dx - sx);
    int dyAbs = abs(dy - sy);

    if ((dxAbs == 2 && dyAbs == 1) || (dxAbs == 1 && dyAbs == 2)) {
        Piece* target = board.getPiece(dx, dy);
        return target == nullptr || target->getColor() != color;
    }
    return false;
}
