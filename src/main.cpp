#include <iostream>
#include "ChessBoard.h"

int main() {
    std::cout << "Engine started successfully..." << std::endl;

    ChessBoard chessBoard;
    chessBoard.renderBoard();

    return 0;
}
