#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(Color c) : Piece(c, (c == Color::White ? 'P' : 'p')) {}

string Pawn::getName() const {
    return "Pawn";
}

bool Pawn::isValidMove(int sx, int sy, int dx, int dy, const Board& board) const {
    int direction = (color == Color::White) ? -1 : 1;
    int startRow = (color == Color::White) ? 6 : 1;

    int dxDiff = dx - sx;
    int dyDiff = dy - sy;

    Piece* target = board.getPiece(dx, dy);

    if (dxDiff == direction && dyDiff == 0 && target == nullptr) {
        return true;
    }
    if (sx == startRow && dxDiff == 2 * direction && dyDiff == 0 &&
        target == nullptr && board.getPiece(sx + direction, sy) == nullptr) {
        return true;
    }
    if (dxDiff == direction && abs(dyDiff) == 1 && target != nullptr && target->getColor() != color) {
        return true;
    }
    return false;
}
