#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    int width=this->width();
    int height=this->height();
    QPainter painter(this);
    QColor mas[7]={Qt::darkRed,Qt::red,Qt::yellow,Qt::green,Qt::blue,Qt::darkBlue,Qt::darkMagenta};
    painter.setBrush(QBrush(mas[0]));
    painter.drawEllipse(0,0,width,height*2);
    for (int i=1;i<7;i++)
    {
        painter.setBrush(QBrush(mas[i]));
        painter.drawEllipse(width/14*i,height/7*i,(width-(width/14)*2*i),height*2-height/7*i);
    }


}

void Widget::makeRepaint()
{
    this->repaint();
}
