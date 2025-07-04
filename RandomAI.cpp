#include "RandomAI.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <tuple>

bool RandomAI::makeRandomMove(Board& board, Color color) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::vector<std::tuple<int, int, int, int>> legalMoves;

    for (int sx = 0; sx < 8; ++sx) {
        for (int sy = 0; sy < 8; ++sy) {
            Piece* piece = board.getPiece(sx, sy);
            if (!piece || piece->getColor() != color) continue;

            for (int dx = 0; dx < 8; ++dx) {
                for (int dy = 0; dy < 8; ++dy) {
                    if (sx == dx && sy == dy) continue;
                    if (piece->isValidMove(sx, sy, dx, dy, board)) {
                        legalMoves.emplace_back(sx, sy, dx, dy);
                    }
                }
            }
        }
    }

    if (legalMoves.empty()) return false;

    auto move = legalMoves[std::rand() % legalMoves.size()];
    int sx = std::get<0>(move);
    int sy = std::get<1>(move);
    int dx = std::get<2>(move);
    int dy = std::get<3>(move);
    board.movePiece(sx, sy, dx, dy);
    return true;
}
