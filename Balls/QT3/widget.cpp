#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QDebug>
#include <QMessageBox>
#include "ball.h"
#include "player.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lcdNumber->hide();
}

Widget::~Widget()
{
 delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    if(started)
    {
        QPainter painter(this);
        for (int i=0; i<NUM; i++)
            balls[i]->draw(painter);
        players[0]->draw(painter);
        this->s_hp(players[0]->hp);
    }

}

void Widget::keyPressEvent(QKeyEvent * a)
{
    players[0]->move(*a);
}

void Widget::stop()
{
    for (int i=0; i<NUM; i++)
        delete balls[i];
    delete players[0];
    disconnect(&timer, SIGNAL(timeout()), this, SLOT(moveAll()));
    timer.stop();
    started=false;
    int res=time(NULL)-start_time;
    QMessageBox::warning(this,"Game Over","Your result: "+QString::number(res)+" sec");
    ui->lcdNumber->hide();
    ui->pushButton->show();
    ui->pushButton_2->show();
}

int Widget::moveAll()
{
    for (int i=0; i<NUM; i++)
    {

        for (int j=i+1;j<NUM;j++)
            if (balls[i]->check(balls[j]))
            {
                balls[i]->vx*=-1;
                balls[i]->vy*=-1;
                balls[j]->vx*=-1;
                balls[j]->vy*=-1;
            }
        if (players[0]->check(balls[i]))
        {
            balls[i]->vx*=-1;
            balls[i]->vy*=-1;
            players[0]->hp--;
            if (players[0]->hp<=0)
            {
                stop();
                return 0;
            }
        }
            balls[i]->move(width(), height());
    }
    this->s_hp(players[0]->hp);
    this->repaint();
}

void Widget::s_hp(int a)
{
    ui->lcdNumber->display(a);
}

void Widget::on_pushButton_clicked()
{
    ui->lcdNumber->show();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    started=true;
    start_time=time(NULL);
    for (int i=0; i<NUM; i++)
        balls[i] = new Ball(width(), height());
    for (int i=0; i<NUM; i++)
    {

        for (int j=i+1;j<NUM;j++)
            if (balls[i]->check(balls[j]))
            {
                *balls[i]=Ball(width(),height());
            }
    }
    players[0] = new Player(width(),height());
    players[0]->hp=10;
    connect(&timer, SIGNAL(timeout()), this, SLOT(moveAll()));
    timer.start(40);
}

void Widget::on_pushButton_2_clicked()
{
    delete ui;
    this->close();
}
