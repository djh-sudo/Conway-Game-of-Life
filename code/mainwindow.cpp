#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cell = Cell();
    ui->label->setMouseTracking(true);
    this->lastX = -1;
    this->lastY = -1;
    this->index = 20;
    this->speed = 100;
    cell.setSize(index,index);
    timer = new QTimer();
    connect(timer,&QTimer::timeout,this,&MainWindow::updateGrid);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}


void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPen pen(Qt::gray);
    painter.setPen(pen);

    painter.translate(ui->label->x(),ui->label->y());
    QBrush brush(Qt::white,Qt::SolidPattern);
    painter.setBrush(brush);

    painter.drawRect(0,0,ui->label->width(),ui->label->height());

    for(int i=0;i<cell.getWidthNumber();i++){
        painter.drawLine(i*cell.getWidth(),0,i*cell.getWidth(),cell.getHeightNumber()*cell.getHeight());
    }

    for(int j=0;j<cell.getWidthNumber();j++){
        painter.drawLine(0,j*cell.getHeight(),cell.getWidthNumber()*cell.getWidth(),j*cell.getHeight());
    }
    brush.setColor(Qt::black);
    painter.setBrush(brush);

    for(int i=0;i<cell.getWidthNumber();i++){
        for(int j=0;j<cell.getHeightNumber();j++){
            if(cell.getCell(i,j) == true){
                painter.drawRect(i*cell.getWidth(),j*cell.getHeight(),cell.getWidth(),cell.getHeight());
            }
        }
    }
}


void MainWindow::mouseMoveEvent(QMouseEvent *e){

    if((e->buttons() & Qt::LeftButton)){
        QPoint point = e->pos()-ui->label->pos();
        if(point.x()>=0 and point.x()<=cell.getWidth()*cell.getWidthNumber() and point.y()>=0 and point.y()<=cell.getHeight()*cell.getHeightNumber()){
            if(point.x()/cell.getWidth() != lastX || point.y()/cell.getHeight()!=lastY){
                cell.setCell(point.x()/cell.getWidth(),point.y()/cell.getHeight());
                update();
                lastX = point.x()/cell.getWidth();
                lastY = point.y()/cell.getHeight();
            }
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *e){
    if(e->button() == Qt::LeftButton){
        QPoint point = e->pos()-ui->label->pos();
        if(point.x()>=0 and point.x()<=cell.getWidth()*cell.getWidthNumber() and point.y()>=0 and point.y()<=cell.getHeight()*cell.getHeightNumber()){
            cell.setCell(point.x()/cell.getWidth(),point.y()/cell.getHeight());
            update();
            lastX = point.x()/cell.getWidth();
            lastY = point.y()/cell.getHeight();
        }
    }

}


int MainWindow::getNeighborCount(int x, int y){
    int count = 0;
    bool d1 = (x>0 &&y>0)?cell.getCell(x-1,y-1):0;
    bool d2 = (y>0)?cell.getCell(x,y-1):0;
    bool d3 = (y>0 && x<cell.getArrayNumber()-1)?cell.getCell(x+1,y-1):0;
    bool d4 = (x>0)?cell.getCell(x-1,y):0;
    bool d5 = (x<cell.getArrayNumber()-1)?cell.getCell(x+1,y):0;
    bool d6 = (x>0 && y<cell.getArrayNumber()-1)?cell.getCell(x-1,y+1):0;
    bool d7 = (y<cell.getArrayNumber()-1)?cell.getCell(x,y+1):0;
    bool d8 = (y<cell.getArrayNumber()-1 && x<cell.getArrayNumber()-1)?cell.getCell(x+1,y+1):0;
    count = (int)d1 + (int)d2 +(int)d3 +(int)d4 +(int)d5 +(int)d6 +(int)d7 +(int)d8;
    return count;
}

void MainWindow::updateGrid(){
    for(int i=0;i<cell.getArrayNumber();i++){
        for(int j=0;j<cell.getArrayNumber();j++){
            int count = getNeighborCount(i,j);
            if(count == 3)
                cell.setTure(i,j);
            else if(count!=2)
                cell.setFalse(i,j);
            else continue;
        }
    }
    cell.updateCell();
    update();

}

void MainWindow::on_pushButton_clicked()
{
    updateGrid();
}

void MainWindow::on_pushButton_2_clicked()
{
    timer->start(speed);
    ui->label_2->setText("starting ...");
}

void MainWindow::on_pushButton_3_clicked()
{
    if(timer->isActive())
        timer->stop();
    ui->label_2->setText("stop!");
}

void MainWindow::on_pushButton_4_clicked()
{

    if(cell.getWidthNumber()>=40){
        int delta = (cell.getWidthNumber()-36)/2-2;
        cell.setCell(1+delta,3);
        cell.setCell(1+delta,4);
        cell.setCell(2+delta,3);
        cell.setCell(2+delta,4);

        cell.setCell(7+delta,3);
        cell.setCell(8+delta,3);

        cell.setCell(9+delta,2);
        cell.setCell(9+delta,4);
        cell.setCell(10+delta,1);
        cell.setCell(10+delta,2);
        cell.setCell(10+delta,4);
        cell.setCell(10+delta,5);

        cell.setCell(11+delta,0);
        cell.setCell(11+delta,6);

        cell.setCell(12+delta,3);

        cell.setCell(13+delta,0);
        cell.setCell(13+delta,1);
        cell.setCell(13+delta,5);
        cell.setCell(13+delta,6);

        cell.setCell(16+delta,5);
        cell.setCell(16+delta,6);
        cell.setCell(16+delta,7);

        cell.setCell(17+delta,5);
        cell.setCell(17+delta,7);
        cell.setCell(17+delta,8);

        cell.setCell(18+delta,7);
        cell.setCell(18+delta,8);

        cell.setCell(19+delta,6);
        cell.setCell(19+delta,7);

        cell.setCell(20+delta,4);
        cell.setCell(20+delta,6);

        cell.setCell(21+delta,2);
        cell.setCell(21+delta,3);
        cell.setCell(21+delta,6);

        cell.setCell(27+delta,3);
        cell.setCell(27+delta,4);
        cell.setCell(27+delta,5);
        cell.setCell(27+delta,6);
        cell.setCell(27+delta,7);

        cell.setCell(28+delta,2);
        cell.setCell(28+delta,4);
        cell.setCell(28+delta,5);
        cell.setCell(28+delta,6);
        cell.setCell(28+delta,8);

        cell.setCell(29+delta,3);
        cell.setCell(29+delta,7);

        cell.setCell(30+delta,4);
        cell.setCell(30+delta,5);
        cell.setCell(30+delta,6);

        cell.setCell(31+delta,5);

        cell.setCell(35+delta,5);
        cell.setCell(35+delta,6);

        cell.setCell(36+delta,5);
        cell.setCell(36+delta,6);

    }
    update();
}

void MainWindow::on_pushButton_5_clicked()
{
    cell.clear();
    update();
}

void MainWindow::on_pushButton_6_clicked()
{
    int delta = (cell.getWidthNumber()-3)/2;
    cell.setCell(delta,3);
    cell.setCell(1+delta,4);
    cell.setCell(2+delta,2);
    cell.setCell(2+delta,3);
    cell.setCell(2+delta,4);
    update();
}

void MainWindow::on_pushButton_7_clicked()
{
    int delta = (cell.getWidthNumber()-3)/2;
    cell.setCell(delta,2);
    cell.setCell(delta,3);

    cell.setCell(1+delta,1);
    cell.setCell(1+delta,2);
    cell.setCell(1+delta,3);

    cell.setCell(2+delta,1);
    cell.setCell(2+delta,2);
    cell.setCell(2+delta,4);

    cell.setCell(3+delta,2);
    cell.setCell(3+delta,3);
    cell.setCell(3+delta,4);

    cell.setCell(4+delta,3);
    update();
}

void MainWindow::on_pushButton_12_clicked()
{
    switch (index) {
    case 100:{
        index = 50;
        break;
    }
    case 50:{
        index = 25;
        break;
    }
    case 25:{
        index = 20;
        break;
    }
    case 20:{
        index = 10;
        break;
    }
    case 10:{
        index = 5;
        break;
    }
    case 5:{
        index = 5;
        break;
    }
    default:index = 20;
        break;
    }
    cell.setSize(index,index);
    update();
}

void MainWindow::on_pushButton_11_clicked()
{
    switch (index) {
    case 100:{
        index = 100;
        break;
    }
    case 50:{
        index = 100;
        break;
    }
    case 25:{
        index = 50;
        break;
    }
    case 20:{
        index = 25;
        break;
    }
    case 10:{
        index = 20;
        break;
    }
    case 5:{
        index = 10;
        break;
    }
    default:index = 20;
        break;
    }
    cell.setSize(index,index);
    update();
}

void MainWindow::on_pushButton_8_clicked()
{
    if(speed>=10)
        speed -=5;
    if(timer->isActive())
        timer->stop();
    timer->start(speed);
    ui->label_2->setText("starting ...");
}

void MainWindow::on_pushButton_9_clicked()
{
    if(speed<=1000)
        speed +=5;
    if(timer->isActive())
        timer->stop();
    timer->start(speed);
    ui->label_2->setText("starting ...");
}

void MainWindow::on_pushButton_10_clicked()
{
    int delta = (cell.getWidthNumber()-9)/2;
    cell.setCell(delta,delta+5);
    cell.setCell(delta+1,delta+5);
    cell.setCell(delta+2,delta+5);

    cell.setCell(delta+4,delta+1);
    cell.setCell(delta+4,delta+2);
    cell.setCell(delta+4,delta+3);
    cell.setCell(delta+4,delta+7);
    cell.setCell(delta+4,delta+8);
    cell.setCell(delta+4,delta+9);

    cell.setCell(delta+6,delta+5);
    cell.setCell(delta+7,delta+5);
    cell.setCell(delta+8,delta+5);

    update();
}

void MainWindow::on_pushButton_13_clicked()
{
    if(cell.getWidthNumber()>=20){
        int delta = (cell.getWidthNumber()-13)/2;

        cell.setCell(delta+2,delta+4);
        cell.setCell(delta+2,delta+5);
        cell.setCell(delta+2,delta+6);
        cell.setCell(delta+2,delta+10);
        cell.setCell(delta+2,delta+11);
        cell.setCell(delta+2,delta+12);

        cell.setCell(delta+4,delta+2);
        cell.setCell(delta+4,delta+7);
        cell.setCell(delta+4,delta+9);
        cell.setCell(delta+4,delta+14);

        cell.setCell(delta+5,delta+2);
        cell.setCell(delta+5,delta+7);
        cell.setCell(delta+5,delta+9);
        cell.setCell(delta+5,delta+14);

        cell.setCell(delta+6,delta+2);
        cell.setCell(delta+6,delta+7);
        cell.setCell(delta+6,delta+9);
        cell.setCell(delta+6,delta+14);

        cell.setCell(delta+7,delta+4);
        cell.setCell(delta+7,delta+5);
        cell.setCell(delta+7,delta+6);
        cell.setCell(delta+7,delta+10);
        cell.setCell(delta+7,delta+11);
        cell.setCell(delta+7,delta+12);

        cell.setCell(delta+9,delta+4);
        cell.setCell(delta+9,delta+5);
        cell.setCell(delta+9,delta+6);
        cell.setCell(delta+9,delta+10);
        cell.setCell(delta+9,delta+11);
        cell.setCell(delta+9,delta+12);

        cell.setCell(delta+10,delta+2);
        cell.setCell(delta+10,delta+7);
        cell.setCell(delta+10,delta+9);
        cell.setCell(delta+10,delta+14);

        cell.setCell(delta+11,delta+2);
        cell.setCell(delta+11,delta+7);
        cell.setCell(delta+11,delta+9);
        cell.setCell(delta+11,delta+14);

        cell.setCell(delta+12,delta+2);
        cell.setCell(delta+12,delta+7);
        cell.setCell(delta+12,delta+9);
        cell.setCell(delta+12,delta+14);

        cell.setCell(delta+14,delta+4);
        cell.setCell(delta+14,delta+5);
        cell.setCell(delta+14,delta+6);
        cell.setCell(delta+14,delta+10);
        cell.setCell(delta+14,delta+11);
        cell.setCell(delta+14,delta+12);

        update();
    }
}
