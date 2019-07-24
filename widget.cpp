#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pb_Coffe->setEnabled(false);
    ui->pb_Coke->setEnabled(false);
    ui->pb_Tea->setEnabled(false);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::ChangeMoney(int n){

    money += n;
    Enable();
    ui->lcdNumber->display(money);
}

void Widget::ReturnMoney(){

    int res[4];
    int initmoney[4]={500,100,50,10};
    for(int i=0;i<5;i++){
        res[i]=money/initmoney[i];
        money = money-(initmoney[i]*res[i]);
    }
    ShowReturn(res);
    Enable();

}
void Widget ::ShowReturn(int res[]){
    QString str;
    str = QString("500: %1 \n 100: %2 \n 50: %3 \n 10: %4").arg(res[0]).arg(res[1]).arg(res[2]).arg(res[3]);
    QMessageBox msg;
    msg.information(nullptr,"title",str);
    money=0;
    ui->lcdNumber->display(money);
}


void Widget::Enable(){

    if(money <0){
        money=0;
    }

    if(money<100){
        ui->pb_Coffe->setEnabled(false);
        ui->pb_Coke->setEnabled(false);
        ui->pb_Tea->setEnabled(false);
    }
    else if(100<=money && 150>money) {
        ui->pb_Coffe->setEnabled(true);
        ui->pb_Coke->setEnabled(false);
        ui->pb_Tea->setEnabled(false);

    }
    else if(150<=money && 200>money) {
        ui->pb_Coffe->setEnabled(true);
        ui->pb_Coke->setEnabled(false);
        ui->pb_Tea->setEnabled(true);

    }
    else {
            ui->pb_Coffe->setEnabled(true);
            ui->pb_Coke->setEnabled(true);
            ui->pb_Tea->setEnabled(true);
    }

}
void Widget::on_pb_10_clicked()
{
   ChangeMoney(10);


}

void Widget::on_pb_50_clicked()
{

   ChangeMoney(50);
}

void Widget::on_pb_100_clicked()
{
   ChangeMoney(100);
}

void Widget::on_pb_500_clicked()
{
    ChangeMoney(500);
}



void Widget::on_pb_Coffe_clicked()
{
    ChangeMoney(-100);
}

void Widget::on_pb_Tea_clicked()
{
    ChangeMoney(-150);
}

void Widget::on_pb_Coke_clicked()
{
    ChangeMoney(-200);
}

void Widget::on_pb_Return_clicked()
{
    ReturnMoney();

}
