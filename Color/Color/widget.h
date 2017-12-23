#ifndef WIDGET_H
#define WIDGET_H
#include <QKeyEvent>
#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QPaintEvent>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    QTimer timer;
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void dim(QKeyEvent *e);
    void paintEvent(QPaintEvent *e);
    int vr=1;
    int vg=2;
    int vb=3;
    int r;
    int g;
    int b;
public slots:
   void tick();
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
