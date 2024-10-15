#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QVector>

class ChessBoard : public QWidget
{
    Q_OBJECT

public: 
    explicit ChessBoard(QWidget *parent = nullptr);
    ~ChessBoard();

private:
    void createBoard();
    void setupLabels();
    QVector<QLabel *> labels;

    const int boardSize = 8;
};  // Added semicolon here

#endif
