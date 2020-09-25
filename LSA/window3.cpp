#include "window3.h"
#include "ui_window3.h"

window3::window3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::window3)
{
    ui->setupUi(this);
}

window3::~window3()
{
    delete ui;
}
