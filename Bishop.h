#pragma once
#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include "Board.h"

class Bishop : public Piece {
public:
    Bishop(Color c);
    string getName() const override;
    bool isValidMove(int sx, int sy, int dx, int dy, const Board& board) const override;
};

#endif
