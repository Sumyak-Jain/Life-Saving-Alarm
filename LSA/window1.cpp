#include "window1.h"
#include "ui_window1.h"
#include "window2.h"
#include "window3.h"
#include <QMessageBox>
window1::window1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::window1)
{
    ui->setupUi(this);
     mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/LSA_db/registerLSA.db");
    if(!mydb.open()){
       qDebug()<<"not connected";
    }
    else
         qDebug()<<"connected";

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

void window1::on_Login_clicked()
{
    QString username,password;
    username=ui->lineEdit->text();
    password=ui->lineEdit_2->text();

    QSqlQuery qry;
    if(qry.exec("select login_name, logiin_password from register_data where login_name=\'" +username + "\' and logiin_password=\'" +password+ "\'"))
    {

        if(qry.next()){
            window3*obj=new window3(this);
            obj->show();

        }
               else{
            QMessageBox::information(this,tr("Invalid"),tr("wrong username and password"));

        }

    }


}
