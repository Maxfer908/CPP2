#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    timer.start(1000);
    ui->lcdNumber->display(count);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::tick()
{
    count--;
    if (count<=0)
    {
        this->close();
    }
    ui->lcdNumber->display(count);
}

void Widget::on_pushButton_clicked()
{
    count++;
    ui->lcdNumber->display(count);
}
