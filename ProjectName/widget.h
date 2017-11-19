#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void c_c();
protected:
    void paintEvent(QPaintEvent*);
    void makeRepaint();
private:
    QTimer *timer;
    Ui::Widget *ui;
    int r=0;
    int g=0;
    int b=0;
    int r_s=3;
    int g_s=2;
    int b_s=1;
};

#endif // WIDGET_H
