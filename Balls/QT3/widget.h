#ifndef WIDGET_H
#define WIDGET_H
#include "player.h"
#include <QWidget>
#include <QTimer>
#include <QPaintEvent>
#include "ball.h"

namespace Ui {
class Widget;
}

const int NUM = 10;

class Widget : public QWidget
{
    Q_OBJECT
    QTimer timer;
    Ball * balls[NUM];
    Player * players[1];
    bool started=false;
    int start_time;
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
protected:
    void paintEvent(QPaintEvent * e);
    void keyPressEvent(QKeyEvent * a);
    void stop();
protected slots:
    int moveAll();
private:
    Ui::Widget *ui;
public slots:
    void s_hp(int a);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // WIDGET_H
