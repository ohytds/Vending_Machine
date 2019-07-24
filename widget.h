#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void ChangeMoney(int n);
    void ReturnMoney();
    void Enable();
    void ShowReturn(int res[]);
    int money {0};


private slots:
    void on_pb_10_clicked();

    void on_pb_50_clicked();

    void on_pb_100_clicked();

    void on_pb_500_clicked();

    void on_pb_Coffe_clicked();

    void on_pb_Tea_clicked();

    void on_pb_Coke_clicked();

    void on_pb_Return_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
