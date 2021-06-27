#ifndef CELL_H
#define CELL_H


class Cell
{
private:
    bool Board[250][250];
    bool copy[250][250];
    int width;
    int height;
    int widthNumber;
    int heightNumber;

public:
    Cell();
    int getWidth();
    int getHeight();
    int getWidthNumber();
    int getHeightNumber();
    bool getCell(int x,int y);
    void setCell(int x,int y);
    void setSize(int width,int height);
    void setTure(int x,int y);
    void setFalse(int x,int y);
    void updateCell();
    int getArrayNumber();
    void clear();
};

#endif // CELL_H
