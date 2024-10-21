#include "chess_board.h"
#include <QPixmap>

ChessBoard::ChessBoard(QWidget *parent)
    : QWidget(parent)
{
    createBoard();
    setMaximumSize(740, 740);
}

ChessBoard::~ChessBoard()
{
}

void ChessBoard::createBoard() {
    QFrame *frame = new QFrame(this);
    QGridLayout *layout = new QGridLayout(frame);

    const int boardSize = 8;
    const QString piecePath = "../../assets/chess_pieces/";

    // Create corner labels
    QLabel *topLeft = new QLabel();
    QLabel *topRight = new QLabel();
    QLabel *bottomLeft = new QLabel();
    QLabel *bottomRight = new QLabel();

    topLeft->setFixedSize(30, 30);
    topRight->setFixedSize(30, 30);
    bottomLeft->setFixedSize(30, 30);
    bottomRight->setFixedSize(30, 30);

    layout->addWidget(topLeft, 0, 0);
    layout->addWidget(topRight, 0, boardSize + 1);
    layout->addWidget(bottomLeft, boardSize + 1, 0);
    layout->addWidget(bottomRight, boardSize + 1, boardSize + 1);

    for (int col = 0; col < boardSize; ++col) {
        QLabel *fileLabel = new QLabel(QChar('a' + col));
        fileLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(fileLabel, 0, col + 1);

        QLabel *bottomFileLabel = new QLabel(QChar('a' + col));
        bottomFileLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(bottomFileLabel, boardSize + 1, col + 1);
    }

    for (int row = 0; row < boardSize; ++row) {
        QLabel *rankLabel = new QLabel(QString::number(boardSize - row));
        rankLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(rankLabel, row + 1, 0);

        QLabel *rightRankLabel = new QLabel(QString::number(boardSize - row));
        rightRankLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(rightRankLabel, row + 1, boardSize + 1);
    }

    // Create squares and set piece images
    for (int row = 0; row < boardSize; ++row) {
        for (int col = 0; col < boardSize; ++col) {
            QLabel *square = new QLabel();
            square->setFixedSize(90, 90);

            // Set background color
            if ((row + col) % 2 == 0) {
                square->setStyleSheet("background-color: #F0D9B5");
            } else {
                square->setStyleSheet("background-color: #B58863");
            }

            // Load images for pieces
            if (row == 0) {
                // Black pieces
                if (col == 0 || col == 7) square->setPixmap(QPixmap(piecePath + "black_pieces/Rook.png"));
                else if (col == 1 || col == 6) square->setPixmap(QPixmap(piecePath + "black_pieces/Knight.png"));
                else if (col == 2 || col == 5) square->setPixmap(QPixmap(piecePath + "black_pieces/Bishop.png"));
                else if (col == 3) square->setPixmap(QPixmap(piecePath + "black_pieces/Queen.png"));
                else if (col == 4) square->setPixmap(QPixmap(piecePath + "black_pieces/King.png"));
            } else if (row == 1) {
                // Black pawns
                square->setPixmap(QPixmap(piecePath + "black_pieces/Pawn.png"));
            } else if (row == 6) {
                // White pawns
                square->setPixmap(QPixmap(piecePath + "white_pieces/Pawn.png"));
            } else if (row == 7) {
                // White pieces
                if (col == 0 || col == 7) square->setPixmap(QPixmap(piecePath + "white_pieces/Rook.png"));
                else if (col == 1 || col == 6) square->setPixmap(QPixmap(piecePath + "white_pieces/Knight.png"));
                else if (col == 2 || col == 5) square->setPixmap(QPixmap(piecePath + "white_pieces/Bishop.png"));
                else if (col == 3) square->setPixmap(QPixmap(piecePath + "white_pieces/Queen.png"));
                else if (col == 4) square->setPixmap(QPixmap(piecePath + "white_pieces/King.png"));
            }

            square->setScaledContents(true); // Ensure the pixmap scales to fit
            layout->addWidget(square, row + 1, col + 1);
        }
    }

    layout->setHorizontalSpacing(0);
    layout->setVerticalSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(frame);
}

void ChessBoard::setupLabels()
{
    // The setupLabels function appears unused now, you may choose to implement further features or remove it.
}

