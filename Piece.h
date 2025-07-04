#pragma once
#ifndef Piece_h
#define Piece_h

#include <string>
using namespace std;

enum class Color { White, Black };

class Board;

class Piece {
protected:
    Color color;
    char symbol;

public:
    Piece(Color c, char s) : color(c), symbol(s) {}
    virtual ~Piece() {}

    virtual string getName() const = 0;
    virtual bool isValidMove(int sx, int sy, int dx, int dy, const Board& board) const = 0;

    Color getColor() const { return color; }
    char getSymbol() const { return symbol; }
};

#endif
