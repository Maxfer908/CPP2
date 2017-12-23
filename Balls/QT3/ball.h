#ifndef BALL_H
#define BALL_H

#include <QtGui>
#include <QPainter>

class Ball
{
protected:
    int r;
    int x,y;
    QColor color;
    QPoint point;
public:
    Ball(int w, int h);
    void move(int w, int h);
    void draw(QPainter& painter);
    void bounce();
    bool check(Ball * b);
    int vx, vy;
};

#endif // BALL_H
