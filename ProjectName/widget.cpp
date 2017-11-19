#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QTimer>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer=new QTimer;
    timer->start(50);
    connect(timer,SIGNAL(timeout()),this,SLOT(c_c()));
}

Widget::~Widget()
{
    delete timer;
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    int width=this->width();
    int height=this->height();
    QPainter painter(this);
    painter.setBrush(QBrush(QColor::fromRgb(r,g,b)));
    painter.drawRect(0,0,width,height*2);
}

void Widget::c_c()
{
    r+=r_s;
    g+=g_s;
    b+=b_s;
    if (r>=255||r<0)
    {
        r_s*=-1;
        while(r>=255||r<0)
            r+=r_s;
    }
    if (g>=255||g<0)
    {
        g_s*=-1;
        while(g>=255||g<0)
            g+=g_s;
    }
    if (b>=255||b<0)
    {
        b_s*=-1;
        while(b>=255||b<0)
            b+=b_s;
    }


    this->repaint();
}

void Widget::makeRepaint()
{
    this->repaint();
}
