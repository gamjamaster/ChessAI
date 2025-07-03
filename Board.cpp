#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include <iostream>

Board::Board() {
	squares.resize(8, vector<unique_ptr<Piece>>(8, nullptr));
	initialize();
}

void Board::initialize() {
	for (int i = 0; i < 8; i++) {
		squares[1][i] = make_unique<Pawn>(Color::Black);
		squares[6][i] = make_unique<Pawn>(Color::White);
	}

	vector<unique_ptr<Piece>> blackPieces = {
		make_unique<Rook>(Color::Black),
		make_unique<Knight>(Color::Black),
		make_unique<Bishop>(Color::Black),
		make_unique<Queen>(Color::Black),
		make_unique<King>(Color::Black),
		make_unique<Bishop>(Color::Black),
		make_unique<Knight>(Color::Black),
		make_unique<Rook>(Color::Black),
	};

	vector<unique_ptr<Piece>> whitePieces = {
		make_unique<Rook>(Color::White),
		make_unique<Knight>(Color::White),
		make_unique<Bishop>(Color::White),
		make_unique<Queen>(Color::White),
		make_unique<King>(Color::White),
		make_unique<Bishop>(Color::White),
		make_unique<Knight>(Color::White),
		make_unique<Rook>(Color::White),
	};

	for (int i = 0; i < 8; i++) {
		squares[0][i] = move(blackPieces[i]);
		squares[7][i] = move(whitePieces[i]);
	}
}

void Board::print() const {
	cout << " a b c d e f g h" << endl;
	for (int row = 0; row < 8; row++) {
		cout << 8 - row << " ";
		for (int col = 0; col < 8; col++) {
			if (squares[row][col]) {
				cout << squares[row][col]->getSymbol() << " ";
			}
			else {
				cout << ". ";
			}
		}
		cout << 8 - row << endl;
	}
	cout << " a b c d e f g h" << endl;
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