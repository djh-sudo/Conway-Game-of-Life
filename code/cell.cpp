#include "cell.h"
#include<cstdio>
#include<cstdlib>
Cell::Cell()
{
    this->width = 10;
    this->height = 10;
    this->widthNumber = 100;
    this->heightNumber = 100;
}

int Cell::getWidth(){
    return this->width;
}

int Cell::getHeight(){
    return this->height;
}

int Cell::getWidthNumber(){
    return this->widthNumber;
}

int Cell::getHeightNumber(){
    return this->heightNumber;
}


bool Cell::getCell(int x, int y){
    return Board[x][y];
}

void Cell::setCell(int x, int y){
    Board[x][y] = !Board[x][y];
    copy[x][y] = !copy[x][y];
}

void Cell::setSize(int width, int height){
    this->width = width;
    this->height = height;
    this->widthNumber = 1000/width;
    this->heightNumber = 1000/height;
}

void Cell::setTure(int x, int y){
    copy[x][y] = true;
}

void Cell::setFalse(int x, int y){
    copy[x][y] = false;
}

void Cell::updateCell(){
    for(int i=0;i<getArrayNumber();i++){
        for(int j=0;j<getArrayNumber();j++){
            Board[i][j] = copy[i][j];
        }
    }
}

int Cell::getArrayNumber(){
    return 200;
}

void Cell::clear(){
    for(int i=0;i<getArrayNumber();i++){
        for(int j=0;j<getArrayNumber();j++){
            copy[i][j] = false;
            Board[i][j] = copy[i][j];
        }
    }
}
