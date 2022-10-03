#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

#define FIELD_WIDTH 7
#define FIELD_HEIGHT 6
const int DIR_NUMBER = 4;
const int di[] = { 1, 0, 1, 1 };
const int dj[] = { 0, 1, -1, 1 };
const int WIN_LENGTH = 4;

enum Cell{
    EMPTY,
    RED,
    YELLOW
};


class Field{
 Cell cells[FIELD_WIDTH][FIELD_HEIGHT];
 bool isRedTurn;
 Cell winner;
 public:
    Field(bool isRedFirst);
    void clear(bool isRedFirst);
    void checkWinner();
    bool makeTurn(int column);
    bool isWon(bool red) const;
    bool isOver() const;
    Cell getCell(int i, int j) const;
    bool isRedTurnNow() const;
    void print() const;
    void printResult() const;
};




#endif
