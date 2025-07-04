# ChessAI

A simple object-oriented Chess AI written in C++.

This project implements the basic rules of chess, a board representation, and a random-move AI.  
It is designed for learning, experimenting, and extending with more advanced AI algorithms.

---

## Features

- Full chess board and piece implementation:
  - King, Queen, Rook, Bishop, Knight, Pawn
- Object-oriented design for easy extension
- Random-move AI (can be replaced with stronger algorithms)
- Console-based interface
- Visual Studio and VSCode support

---

## Getting Started

### Prerequisites

- Windows OS
- Visual Studio 2019 or later (or VSCode with C++ extension)
- C++17 or later

---

## Build & Run

### Using Visual Studio

1. Open `ChessAI.sln` in Visual Studio.
2. Select the desired build configuration (Debug/Release, x64/Win32).
3. Build the solution (`Ctrl + Shift + B`).
4. Run the project (`F5`).

### Using Command Line

1. Open a terminal in the project root.
2. Compile with your preferred compiler, e.g.:

   ```bash
   g++ -std=c++17 -o ChessAI main.cpp Game.cpp Board.cpp RandomAI.cpp Pieces/*.cpp
   ```

3. Run the executable:

   ```bash
   ./ChessAI
   ```

---

## Project Structure

```
ChessAI/
├── main.cpp                  # Entry point
├── Game.*                    # Game flow and logic
├── Board.*                   # Board representation and move validation
├── Piece.*                   # Base class for all chess pieces
├── King/Queen/.../*.cpp      # Piece-specific logic
├── RandomAI.*                # Simple random-move AI
```

---

## How to Play

- The game runs in the console.
- Moves are made automatically by the AI.
- You can extend the AI or add a user interface as needed.

---

## Extending

- Implement stronger AI (e.g., Minimax, Alpha-Beta Pruning)
- Add a graphical user interface
- Add support for special chess rules:
  - Castling
  - En passant
  - Promotion

---

## Contributing

Pull requests are welcome!  
For major changes, please open an issue first to discuss what you would like to change.

---

## License

This project is open source and available under the [MIT License](LICENSE).
