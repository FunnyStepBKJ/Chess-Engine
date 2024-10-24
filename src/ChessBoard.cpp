#include <iostream>
#include "ChessBoard.h"

ChessBoard::ChessBoard() {
    // Initialize the starting positions for white pieces
    whitePawns = 0x000000000000FF00; // 0b00000000000000000000000000000000000000000000000000000000000011111111
    whiteKnights = 0x0000000000000042; // 0b00000000000000000000000000000000000000000000000000000000001010010
    whiteBishops = 0x0000000000000024; // 0b00000000000000000000000000000000000000000000000000000000000100100
    whiteRooks = 0x0000000000000081; // 0b00000000000000000000000000000000000000000000000000000000010000001
    whiteQueen = 0x0000000000000008; // 0b0000000000000000000000000000000000000000000000000000000000001000
    whiteKing = 0x0000000000000010; // 0b0000000000000000000000000000000000000000000000000000000000010000

    // Initialize the starting positions for black pieces
    blackPawns = 0x00FF000000000000; // 0b1111111100000000000000000000000000000000000000000000000000000000
    blackKnights = 0x4200000000000000; // 0b0100001000000000000000000000000000000000000000000000000000000000
    blackBishops = 0x2400000000000000; // 0b0010010000000000000000000000000000000000000000000000000000000000
    blackRooks = 0x8100000000000000; // 0b1000000100000000000000000000000000000000000000000000000000000000
    blackQueen = 0x0800000000000000; // 0b0000100000000000000000000000000000000000000000000000000000000000
    blackKing = 0x1000000000000000; // 0b0001000000000000000000000000000000000000000000000000000000000000

    // Initialize the arrays with pointers to bitboards
    whitePieces[0] = &whitePawns;
    whitePieces[1] = &whiteKnights;
    whitePieces[2] = &whiteBishops;
    whitePieces[3] = &whiteRooks;
    whitePieces[4] = &whiteQueen;
    whitePieces[5] = &whiteKing;

    blackPieces[0] = &blackPawns;
    blackPieces[1] = &blackKnights;
    blackPieces[2] = &blackBishops;
    blackPieces[3] = &blackRooks;
    blackPieces[4] = &blackQueen;
    blackPieces[5] = &blackKing;
}

// Combines all the bitboard into one main board that will be displayed.
unsigned long long ChessBoard::combineBitBoards() {
    unsigned long long board = 0Ull;

    board |= whiteKnights;
    board |= whitePawns;
    board |= whiteBishops;
    board |= whiteRooks;
    board |= whiteQueen;
    board |= whiteKing;
    
    board |= blackPawns;
    board |= blackKnights;
    board |= blackBishops;
    board |= blackRooks;
    board |= blackQueen;
    board |= blackKing;

    return board;
}

// Prints the whole board to the terminal
void ChessBoard::renderBoard() {
    unsigned long long chessBoard = combineBitBoards();

    for (int rank = 7; rank >=0; --rank) {
        std::cout << "                                      ";
        for (int file = 0; file < 8; file++) {
            int index = rank * 8 + file;
            unsigned long long bit = 1ULL << index;
            
            // Check for white pieces
            if ((whitePawns & bit) != 0) std::cout << "WP "; 
            else if ((whiteKnights & bit) != 0) std::cout << "WN "; 
            else if ((whiteBishops & bit) != 0) std::cout << "WB "; 
            else if ((whiteRooks & bit) != 0) std::cout << "WR "; 
            else if ((whiteQueen & bit) != 0) std::cout << "WQ "; 
            else if ((whiteKing & bit) != 0) std::cout << "WK "; 

            // Check for black pieces 
            else if ((blackPawns & bit) != 0) std::cout << "BP ";
            else if ((blackKnights & bit) != 0) std::cout << "BN "; 
            else if ((blackBishops & bit) != 0) std::cout << "BB "; 
            else if ((blackRooks & bit) != 0) std::cout << "BR "; 
            else if ((blackQueen & bit) != 0) std::cout << "BQ "; 
            else if ((blackKing & bit) != 0) std::cout << "BK "; 
            else std::cout << "00 "; // Empty square
        }
        std::cout << std::endl;
    }
}

// Moves the piece from the provided parameters "fromFile & fromRank" to "toFile & and toRank" 
bool ChessBoard::movePiece(const std::string& fromSquare, const std::string& toSquare) {
    int fF = fromSquare[0] - 'a';
    int fR = fromSquare[1] - '1';
    int tF = toSquare[0] - 'a';
    int tR = toSquare[1] - '1';

    int initialPosition = fR * 8 + fF;
    int newPosition = tR * 8 + tF;

    unsigned long long iPiecePosition = 1ULL << initialPosition;
    unsigned long long nPiecePosition = 1ULL << newPosition;
    
    // Check for white pieces
    for (int i = 0; i < 6; i++) {
        if ((*whitePieces[i] & iPiecePosition) != 0) {
            *whitePieces[i] = (*whitePieces[i] ^ iPiecePosition) | nPiecePosition;
            return true;
        }
    }

    // Check for black pieces 
    for (int i = 0; i < 6; i++) {
        if ((*blackPieces[i] & iPiecePosition) != 0) {
            *blackPieces[i] = (*blackPieces[i] ^ iPiecePosition) | nPiecePosition;
            return true; 
        }
    }

    return false;
}
