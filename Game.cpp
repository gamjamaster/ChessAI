#include "Game.h"
#include "RandomAI.h"
#include <tuple>

void Game::run() {
    while (true) {
        printBoard();

        if (currentTurn == Color::White) {
            cout << "White's move: ";
            string move;
            cin >> move;

            if (!processMove(move)) {
                cout << "Invalid move. Try again." << endl;
                continue;
            }
        }

        else {
            cout << "AI is thinking..." << endl;
            std::tuple<int, int, int, int> move = getBestMove(Color::Black);
            int sx = std::get<0>(move);
            int sy = std::get<1>(move);
            int dx = std::get<2>(move);
            int dy = std::get<3>(move);
            if (sx == -1) {
                cout << "No valid move for AI. Stalemate?" << endl;
                return;
            }
            board.movePiece(sx, sy, dx, dy);
            cout << "AI moved from " << char('a' + sy) << 8 - sx
                << " to " << char('a' + dy) << 8 - dx << endl;
        }

        if (board.isCheckmate(currentTurn == Color::White ? Color::Black : Color::White)) {
            printBoard();
            cout << "Checkmate! ";
            cout << (currentTurn == Color::White ? "White" : "Black") << " wins!" << endl;

            cout << "Play again? (y/n): ";
            string again;
            cin >> again;
            if (again == "y" || again == "Y") {
                board.initialize();
                currentTurn = Color::White;
                run();
            }
            else {
                cout << "Goodbye!" << endl;
                return;
            }
        }

        switchTurn();
    }
}



bool Game::processMove(const std::string& move) {
    if (move.length() != 4) return false;

    int sy = move[0] - 'a';
    int sx = 8 - (move[1] - '0');
    int dy = move[2] - 'a';
    int dx = 8 - (move[3] - '0');

    Piece* piece = board.getPiece(sx, sy);
    if (!piece) {
        std::cout << "No piece at source.\n";
        return false;
    }

    if (piece->getColor() != currentTurn) {
        std::cout << "It's not your turn.\n";
        return false;
    }

    if (!piece->isValidMove(sx, sy, dx, dy, board)) {
        std::cout << "Invalid move.\n";
        return false;
    }

    board.movePiece(sx, sy, dx, dy);
    switchTurn();
    return true;
}

tuple<int, int, int, int> Game::getBestMove(Color aiColor) {
    int bestScore = -1000000;
    tuple<int, int, int, int> bestMove = { -1, -1, -1, -1 };

    // Use the public accessor for squares
    auto& squares = board.getSquares();

    for (int sx = 0; sx < 8; ++sx) {
        for (int sy = 0; sy < 8; ++sy) {
            Piece* piece = board.getPiece(sx, sy);
            if (!piece || piece->getColor() != aiColor) continue;

            for (int dx = 0; dx < 8; ++dx) {
                for (int dy = 0; dy < 8; ++dy) {
                    if (sx == dx && sy == dy) continue;

                    Piece* target = board.getPiece(dx, dy);
                    if (target && target->getColor() == aiColor) continue;

                    if (piece->isValidMove(sx, sy, dx, dy, board)) {
                        auto backupFrom = std::move(squares[sx][sy]);
                        auto backupTo = std::move(squares[dx][dy]);

                        squares[dx][dy] = std::move(backupFrom);
                        squares[sx][sy] = nullptr;

                        int score = board.evaluate(aiColor);

                        squares[sx][sy] = std::move(squares[dx][dy]);
                        squares[dx][dy] = std::move(backupTo);

                        if (score > bestScore) {
                            bestScore = score;
                            bestMove = { sx, sy, dx, dy };
                        }
                    }
                }
            }
        }
    }

    return bestMove;
}