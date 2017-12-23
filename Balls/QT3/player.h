#ifndef PLAYER_H
#define PLAYER_H
#include <QKeyEvent>
#include "ball.h"
#include <QPoint>
#include <QPainter>
class Player : public Ball
{
public:
    Player(int h,int w);
    void move(QKeyEvent& a);
    void draw(QPainter& painter);
    int hp=10;
};

#endif // PLAYER_H
