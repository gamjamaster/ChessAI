#pragma once
#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
public:
    Queen(Color c);

    std::string getName() const override;
    bool isValidMove(int sx, int sy, int dx, int dy, const Board& board) const override;
};

#endif

