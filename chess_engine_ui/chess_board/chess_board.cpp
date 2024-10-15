#include "chess_board.h"

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
    QGridLayout *layout = new QGridLayout(this);
    setLayout(layout);

    const int boardSize = 8;  // 8x8 chessboard

    QLabel *topLeft = new QLabel();
    QLabel *topRight = new QLabel();
    QLabel *bottomLeft = new QLabel();
    QLabel *bottomRight = new QLabel();

    topLeft->setFixedSize(30, 30);
    topRight->setFixedSize(30, 30);
    bottomLeft->setFixedSize(30, 30);
    bottomRight->setFixedSize(30, 30);

    layout->addWidget(topLeft, 0, 0);
    layout->addWidget(topRight, 0, boardSize+1);
    layout->addWidget(bottomLeft, boardSize+1, 0);
    layout->addWidget(bottomRight, boardSize+1, boardSize+1);

    for (int col = 0; col < boardSize; ++col) {
        QLabel *fileLabel = new QLabel(QChar('a' + col));
        fileLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(fileLabel, 0, col + 1);

        QLabel *bottomFileLabel = new QLabel(QChar('a' + col));
        bottomFileLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(bottomFileLabel, boardSize + 1, col + 1);

        fileLabel->setStyleSheet("background-color: #");
    }

    for (int row = 0; row < boardSize; ++row) {
        QLabel *rankLabel = new QLabel(QString::number(boardSize - row));
        rankLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(rankLabel, row + 1, 0);

        QLabel *rightRankLabel = new QLabel(QString::number(boardSize - row));
        rightRankLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(rightRankLabel, row + 1, boardSize + 1);
    }

    for (int row = 0; row < boardSize; ++row) {
        for (int col = 0; col < boardSize; ++col) {
            QLabel *square = new QLabel();
            square->setFixedSize(90, 90);
            if ((row + col) % 2 == 0) {
                square->setStyleSheet("background-color: #F0D9B5");
            } else {
                square->setStyleSheet("background-color: #B58863");
            }
            layout->addWidget(square, row + 1, col + 1);
        }
    }

    layout->setHorizontalSpacing(0);
    layout->setVerticalSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);

    setLayout(layout);
}


void ChessBoard::setupLabels()
{
    for (int i = 0; i < boardSize * boardSize; ++i) {
        QLabel *label = new QLabel(this);
        label->setFixedSize(90, 90);
        
        if ((i / boardSize) % 2 == 0) {
            label->setStyleSheet((i % 2 == 0) ? "background-color: #FEFCE8;" : "background-color: #57534E;");
        } else {
            label->setStyleSheet((i % 2 == 0) ? "background-color: #57534E;" : "background-color: #FEFCE8;");
        }

        labels.append(label);
    }
}

