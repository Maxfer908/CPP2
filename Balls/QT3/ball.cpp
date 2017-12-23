#include "ball.h"

Ball::Ball(int w, int h)
{
    // устанавливаем радиус
    r = 15 + rand()%15;
    // устанавливанием координаты
    point.setX( r + rand()%(w - 2*r) );
    point.setY( r + rand()%(h - 2*r) );
    // придумываем цвет
    color = QColor::fromRgb(rand()%255, rand()%255, rand()%255);
    // устанавливаем скорости
    vx = 5 + rand()%5;
    vy = 5 + rand()%5;
    if (rand()%2==0) vx *= -1;
    if (rand()%2==0) vy *= -1;
    x=point.x();
    y=point.y();
}

void Ball::move(int w, int h)
{
    point += QPoint(vx,vy);
    if ((point.x()+r>=w)||(point.x()+r<=0)||((point.x()-r>=w)||(point.x()-r<=0)))
    {
        vx*=-1;
        point += QPoint(vx,0);
    }
    if ((point.y()+r>=h)||(point.y()+r<=0)||((point.y()-r>=h)||(point.y()-r<=0)))
    {
        vy*=-1;
        point += QPoint(0,vy);
    }
}

void Ball::draw(QPainter &painter)
{
    painter.setBrush(QBrush(color));
    painter.drawImage(point.x()-r,point.y()-r,QImage(":/new/img/ball.jpg").scaled(2*r,2*r));
}

int distance(QPoint a, QPoint b)
{
    return (a.x()-b.x())*(a.x()-b.x())+(a.y()-b.y())*(a.y()-b.y());
}

bool Ball::check(Ball *b)
{
    if (distance(this->point,b->point)<=(this->r+b->r)*(this->r+b->r))
        return true;
    return false;
}
