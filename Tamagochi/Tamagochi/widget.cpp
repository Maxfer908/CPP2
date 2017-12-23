#include "widget.h"
#include "ui_widget.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    animal=new Animal;
    ui->progressBar->setValue(animal->happiness);
    ui->progressBar_2->setValue(animal->food);
    ui->progressBar_3->setValue(animal->health);
    ui->label->setPixmap(QPixmap(":/files/Images/happy.jpg"));
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    timer.start(1000);
}

Widget::~Widget()
{

}

void Widget::tick()
{
    animal->tick();
    ui->progressBar->setValue(animal->happiness);
    ui->progressBar_2->setValue(animal->food);
    ui->progressBar_3->setValue(animal->health);
    if ((ui->progressBar->value()<5000)||(ui->progressBar_2->value()<5000)||(ui->progressBar_3->value()<5000))
        ui->label->setPixmap(QPixmap(":/files/Images/boring.jpg"));
    else
        ui->label->setPixmap(QPixmap(":/files/Images/happy.jpg"));
    if (!animal->isAlive())
        this->close();
}

void Widget::on_pushButton_clicked()
{
    animal->play();
    ui->progressBar->setValue(animal->happiness);
}

void Widget::on_pushButton_2_clicked()
{
    animal->feed();
    ui->progressBar_2->setValue(animal->food);
}

void Widget::on_pushButton_3_clicked()
{
    animal->wash();
    ui->progressBar_3->setValue(animal->health);
}
