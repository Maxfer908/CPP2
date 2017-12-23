#include "widget.h"
#include "ui_widget.h"
#include <QPoint>
#include <QColor>
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lcdNumber->display(score);
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    timer.start(3000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    x=rand()%this->width();
    y=rand()%this->height();
    QPoint point;
    point.setX(x);
    point.setY(y);
    QPainter painter(this);
    painter.setBrush(QBrush(QColor(Qt::red)));
    painter.drawEllipse(point, r, r);
}

void Widget::mousePressEvent(QMouseEvent *a)
{
    m_x=a->x();
    m_y=a->y();
    if (((m_x>=x-15)&&(m_x<=x+15))&&((m_y>=y-15)&&(m_y<=y+15)))
        score++;
    qDebug()<<5;
    ui->lcdNumber->display(score);
    this->repaint();
}

void Widget::tick()
{
 this->repaint();
}
