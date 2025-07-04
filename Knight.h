#pragma once
#include "Piece.h"
#include "Board.h"

class Knight : public Piece {
public:
    Knight(Color c);
    string getName() const override;
    bool isValidMove(int sx, int sy, int dx, int dy, const Board& board) const override;
};
