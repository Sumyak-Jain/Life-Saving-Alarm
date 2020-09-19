#include "window1.h"
#include "ui_window1.h"
#include "window2.h"
window1::window1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::window1)
{
    ui->setupUi(this);
}

window1::~window1()
{
    delete ui;
}






void window1::on_pushButton_clicked()
{
    this->hide();
    window2 obj;
    obj.setModal(true);
    obj.exec();
}
