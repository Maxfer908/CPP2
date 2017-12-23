#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    r=rand()%255;
    g=rand()%255;
    b=rand()%255;
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    timer.start(10);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
   int w=this->width();
   int h=this->height();
   QPainter painter(this);
   painter.setBrush(QBrush(QColor::fromRgb(r,g,b)));
   painter.drawRect(0,0,w,h);
}

void Widget::tick()
{
if ((r+vr>=255)||(r+vr<=0))
    vr*=-1;
if ((g+vg>=255)||(g+vg<=0))
    vg*=-1;
if ((b+vb>=255)||(b+vb<=0))
    vb*=-1;
r+=vr;
g+=vg;
b+=vb;
this->repaint();
}

