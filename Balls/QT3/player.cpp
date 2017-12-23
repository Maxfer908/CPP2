#include "player.h"
#include <QDebug>
Player::Player(int w,int h):Ball(w,h)
{
    point.setX( w/2 );
    point.setY( h/2 );
    color = Qt::red;
    vx=15;
    vy=15;
    x=point.x();
    y=point.y();
    r=15;
}

void Player::move(QKeyEvent& a)
{
    if (a.key()==Qt::Key_W)
        point+=QPoint(0,-vx);
    if (a.key()==Qt::Key_S)
        point+=QPoint(0,vx);
    if (a.key()==Qt::Key_A)
        point+=QPoint(-vy,0);
    if (a.key()==Qt::Key_D)
        point+=QPoint(vy,0);
}

void Player::draw(QPainter& painter)
{
    painter.setBrush(QBrush(color));
    painter.drawImage(point.x()-r,point.y()-r,QImage(":/new/img/player.jpg").scaled(2*r,2*r));
}


