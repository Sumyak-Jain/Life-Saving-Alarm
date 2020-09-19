#include "window2.h"
#include "ui_window2.h"
#include "window1.h"
#include <QMessageBox>

window2::window2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::window2)
{
    ui->setupUi(this);
}

window2::~window2()
{
    delete ui;
}



void window2::on_register2_clicked()
{
    QMessageBox::information(this,tr("Confirmed"),tr("Registered Successfully"));
}

void window2::on_Goback_clicked()
{

    window1*obj=new window1(this);
    obj->show();

}
