#include "Queen.h"

Queen::Queen(Color c) : Piece(c, (c == Color::White ? 'Q' : 'q')) {}

std::string Queen::getName() const {
    return "Queen";
}

bool Queen::isValidMove(int sx, int sy, int dx, int dy) const {
    return (sx == dx || sy == dy || abs(sx - dx) == abs(sy - dy));
}
