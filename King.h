#pragma once
#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece {
public:
    King(Color c);

    std::string getName() const override;
    bool isValidMove(int sx, int sy, int dx, int dy) const override;
};

#endif

