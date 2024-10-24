#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <string>

struct ChessPiece {
    unsigned long long* bitboard;
};

class ChessBoard {
public:
    ChessBoard();
    void renderBoard();
    bool movePiece(const std::string& fromSquare, const std::string& toSquare);
    void capturePiece(int fromRank, int fromFile, int toRank, int toFile);
    void promotePawn(int rank, int file, char promoteToPiece);
    unsigned long long combineBitBoards();

private:
    unsigned long long whitePawns, whiteKnights, whiteBishops, whiteRooks, whiteQueen, whiteKing;
    unsigned long long blackPawns, blackKnights, blackBishops, blackRooks, blackQueen, blackKing;

    // Arrays for holding the pieces in a collective manner
    unsigned long long* whitePieces[6];
    unsigned long long* blackPieces[6];

};

#endif // CHESS
