#ifndef WIDGET_H
#define WIDGET_H
#include <QPaintEvent>
#include <QTimer>
#include <QPainter>
#include <QMouseEvent>
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QTimer timer;
    int x,y;
    int r=15;
    int m_x,m_y;
    int score=0;
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *a);
public slots:
    void tick();
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
