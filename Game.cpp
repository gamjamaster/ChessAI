#include "Game.h"

void Game::run() {
    std::string input;

    while (true) {
        printBoard();
        std::cout << (currentTurn == Color::White ? "White" : "Black") << "'s move (e.g., e2e4), or 'q' to quit: ";
        std::getline(std::cin, input);

        if (input == "q") break;

        if (processMove(input)) {
            switchTurn();
        }
        else {
            std::cout << "Invalid move, try again." << std::endl;
        }
    }
}

bool Game::processMove(const std::string& move) {
    return false;
}
