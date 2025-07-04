#include "Queen.h"
#include "Board.h"
#include <cmath>

Queen::Queen(Color c) : Piece(c, (c == Color::White ? 'Q' : 'q')) {}

string Queen::getName() const {
    return "Queen";
}

bool Queen::isValidMove(int sx, int sy, int dx, int dy, const Board& board) const {
    if (sx == dx || sy == dy) {
        return board.isPathClear(sx, sy, dx, dy);
    }
    else if (abs(dx - sx) == abs(dy - sy)) {
        return board.isPathClear(sx, sy, dx, dy);
    }
    return false;
}
