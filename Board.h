#pragma once
#include <vector>
#include <memory>
#include "Piece.h"
using namespace std;



class Board {
private:
    vector<vector<unique_ptr<Piece>>> squares;

public:
    Board();
    void initialize();
    void print() const;

    Piece* getPiece(int x, int y) const;
    void movePiece(int sx, int sy, int dx, int dy);
    bool isInsideBoard(int x, int y) const;
    bool isInCheck(Color color) const;
    bool isCheckmate(Color color);
    int evaluate(Color forColor) const;

    bool isPathClear(int sx, int sy, int dx, int dy) const;
    std::vector<std::vector<std::unique_ptr<Piece>>>& getSquares() { return squares; }
    bool isValidMove(int sx, int sy, int dx, int dy, const Board& board) const;
};