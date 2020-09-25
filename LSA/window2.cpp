#include "window2.h"
#include "ui_window2.h"
#include "window1.h"
#include <QMessageBox>

window2::window2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::window2)
{
    ui->setupUi(this);
   mydb1=QSqlDatabase::addDatabase("QSQLITE");
   mydb1.setDatabaseName("D:/LSA_db/registerLSA.db");
   if(!mydb1.open()){
      qDebug()<<"not connected";
   }
   else
        qDebug()<<"connected";
}

window2::~window2()
{
    delete ui;
}



void window2::on_register2_clicked()
{
    QString user_name,guardian_name,hospital_name,login_name,login_password;
    int userAge,guardian_phone,hospital_phone;
     user_name=ui->lineEdit->text();
      userAge=ui->lineEdit_2->text().toInt();
       guardian_name=ui->lineEdit_3->text();
        guardian_phone=ui->lineEdit_4->text().toInt();
         hospital_name=ui->lineEdit_5->text();
          hospital_phone=ui->lineEdit_6->text().toInt();
           login_name=ui->lineEdit_7->text();
            login_password=ui->lineEdit_8->text();

            QSqlQuery qry;
            qry.prepare("insert into register_data values(?,?,?,?,?,?,?,?)");
            qry.addBindValue(userAge);
            qry.addBindValue(user_name);
            qry.addBindValue(guardian_name);
            qry.addBindValue(guardian_phone);
            qry.addBindValue(hospital_name);
            qry.addBindValue(hospital_phone);
            qry.addBindValue(login_name);
            qry.addBindValue(login_password);

           if(qry.exec())
            {


                     QMessageBox::information(this,tr("Confirmed"),tr("Registered Successfully!"));

                }
                       else{
                    QMessageBox::information(this,tr("Invalid"),tr("Sorry,Something went wrong!"));

                }
           window1*obj=new window1(this);
           obj->show();

            }



void window2::on_Goback_clicked()
{

    window1*obj=new window1(this);
    obj->show();

}
