#include "window3.h"
#include "ui_window3.h"
#include <QDesktopServices>
#include <QUrl>
#include "window2.h"


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


void window3::on_pushButton_3_clicked()
{
    QString link="https://thingspeak.com/channels/1245745";
        QDesktopServices ::openUrl(QUrl(link));

}

void window3::on_pushButton_clicked()
{
    window2*obj1=new window2(this);
      obj1->show();

}
