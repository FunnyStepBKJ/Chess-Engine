#include "mainwindow.h"
#include "chess_board/chess_board.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ChessBoard *board = new ChessBoard(this);
    setCentralWidget(board);
}

MainWindow::~MainWindow()
{
}

