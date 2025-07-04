#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include <iostream>
#include<map>

Board::Board() {
    squares.resize(8);
    for (auto& row : squares) {
        row.resize(8);
    }
    initialize();
}

void Board::initialize() {
    for (int i = 0; i < 8; i++) {
        squares[1][i] = make_unique<Pawn>(Color::Black);
        squares[6][i] = make_unique<Pawn>(Color::White);
    }

    vector<unique_ptr<Piece>> blackPieces;
    blackPieces.emplace_back(make_unique<Rook>(Color::Black));
    blackPieces.emplace_back(make_unique<Knight>(Color::Black));
    blackPieces.emplace_back(make_unique<Bishop>(Color::Black));
    blackPieces.emplace_back(make_unique<Queen>(Color::Black));
    blackPieces.emplace_back(make_unique<King>(Color::Black));
    blackPieces.emplace_back(make_unique<Bishop>(Color::Black));
    blackPieces.emplace_back(make_unique<Knight>(Color::Black));
    blackPieces.emplace_back(make_unique<Rook>(Color::Black));

    vector<unique_ptr<Piece>> whitePieces;
    whitePieces.emplace_back(make_unique<Rook>(Color::White));
    whitePieces.emplace_back(make_unique<Knight>(Color::White));
    whitePieces.emplace_back(make_unique<Bishop>(Color::White));
    whitePieces.emplace_back(make_unique<Queen>(Color::White));
    whitePieces.emplace_back(make_unique<King>(Color::White));
    whitePieces.emplace_back(make_unique<Bishop>(Color::White));
    whitePieces.emplace_back(make_unique<Knight>(Color::White));
    whitePieces.emplace_back(make_unique<Rook>(Color::White));

    for (int i = 0; i < 8; i++) {
        squares[0][i] = move(blackPieces[i]);
        squares[7][i] = move(whitePieces[i]);
    }
}

void Board::print() const {
    std::cout << " a b c d e f g h\n";
    for (int row = 0; row < 8; row++) {
        std::cout << 8 - row << " ";
        for (int col = 0; col < 8; col++) {
            if (squares[row][col]) {
                std::cout << squares[row][col]->getSymbol() << " ";
            }
            else {
                std::cout << ". ";
            }
        }
        std::cout << 8 - row << "\n";
    }
    std::cout << " a b c d e f g h\n";
}

Piece* Board::getPiece(int x, int y) const {
    if (!isInsideBoard(x, y)) { return nullptr; }
    return squares[x][y].get();
}

void Board::movePiece(int sx, int sy, int dx, int dy) {
    if (!isInsideBoard(sx, sy) || !isInsideBoard(dx, dy)) { return; }

    squares[dx][dy] = move(squares[sx][sy]);
    squares[sx][sy] = nullptr;
}

bool Board::isInsideBoard(int x, int y) const {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

bool Board::isPathClear(int sx, int sy, int dx, int dy) const {
    int dxDiff = dx - sx;
    int dyDiff = dy - sy;

    int stepX = (dxDiff == 0) ? 0 : (dxDiff > 0 ? 1 : -1);
    int stepY = (dyDiff == 0) ? 0 : (dyDiff > 0 ? 1 : -1);

    int x = sx + stepX;
    int y = sy + stepY;

    while (x != dx || y != dy) {
        if (squares[x][y] != nullptr) {
            return false;
        }
        x += stepX;
        y += stepY;
    }

    return true;
}

bool Board::isInCheck(Color color) const {
    int kingX = -1, kingY = -1;
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            Piece* p = squares[x][y].get();
            if (p && p->getColor() == color && p->getName() == "King") {
                kingX = x;
                kingY = y;
                break;
            }
        }
    }

    if (kingX == -1) return false;

    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            Piece* p = squares[x][y].get();
            if (p && p->getColor() != color) {
                if (p->isValidMove(x, y, kingX, kingY, *this)) {
                    return true;
                }
            }
        }
    }

    return false;
}


bool Board::isCheckmate(Color color) {
    if (!isInCheck(color)) return false;

    for (int sx = 0; sx < 8; ++sx) {
        for (int sy = 0; sy < 8; ++sy) {
            Piece* piece = getPiece(sx, sy);
            if (!piece || piece->getColor() != color) continue;

            for (int dx = 0; dx < 8; ++dx) {
                for (int dy = 0; dy < 8; ++dy) {
                    if (!isInsideBoard(dx, dy)) continue;
                    Piece* target = getPiece(dx, dy);
                    if (target && target->getColor() == color) continue;

                    if (piece->isValidMove(sx, sy, dx, dy, *this)) {
                        auto backupFrom = std::move(squares[sx][sy]);
                        auto backupTo = std::move(squares[dx][dy]);

                        squares[dx][dy] = std::move(backupFrom);
                        squares[sx][sy] = nullptr;

                        bool stillInCheck = isInCheck(color);

                        squares[sx][sy] = std::move(squares[dx][dy]);
                        squares[dx][dy] = std::move(backupTo);

                        if (!stillInCheck) return false;
                    }
                }
            }
        }
    }

    return true;
}

int Board::evaluate(Color forColor) const {
    map<char, int> values = {
        {'P', 100}, {'N', 300}, {'B', 300},
        {'R', 500}, {'Q', 900}, {'K', 10000},
        {'p', -100}, {'n', -300}, {'b', -300},
        {'r', -500}, {'q', -900}, {'k', -10000}
    };

    int score = 0;

    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            Piece* p = getPiece(x, y);
            if (p) {
                char sym = p->getSymbol();
                if (forColor == Color::White)
                    score += values[sym];
                else
                    score -= values[sym];
            }
        }
    }

    return score;
}

