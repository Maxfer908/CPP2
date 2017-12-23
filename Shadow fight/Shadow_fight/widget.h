#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    QTimer timer;
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    int count=10;
private:
    Ui::Widget *ui;
public slots:
    void tick();
private slots:
    void on_pushButton_clicked();
};

#endif // WIDGET_H
