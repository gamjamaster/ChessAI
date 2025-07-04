#include "Bishop.h"
#include <cmath>

Bishop::Bishop(Color c) : Piece(c, (c == Color::White ? 'B' : 'b')) {}

string Bishop::getName() const {
    return "Bishop";
}

bool Bishop::isValidMove(int sx, int sy, int dx, int dy, const Board& board) const {
    if (abs(dx - sx) == abs(dy - sy)) {
        return board.isPathClear(sx, sy, dx, dy);
    }
    return false;
}