#ifndef CHESSBOARD_H
#define CHESSBOARD_H

class ChessBoard {
public:
    ChessBoard();
    void renderBoard();
    void movePiece(int fromRank, int fromFile, int toRank, int toFile);
    void capturePiece(int fromRank, int fromFile, int toRank, int toFile);
    void promotePawn(int rank, int file, char promoteToPiece);
    unsigned long long combineBitBoards();

private:
    unsigned long long whitePawns;
    unsigned long long whiteKnights;
    unsigned long long whiteBishops;
    unsigned long long whiteRooks;
    unsigned long long whiteQueen;
    unsigned long long whiteKing;

    unsigned long long blackPawns;
    unsigned long long blackKnights;
    unsigned long long blackBishops;
    unsigned long long blackRooks;
    unsigned long long blackQueen;
    unsigned long long blackKing;

};

#endif // CHESS
