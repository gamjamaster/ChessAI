#pragma once
#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(Color c);

    std::string getName() const override;
    bool isValidMove(int sx, int sy, int dx, int dy) const override;
};

#endif
