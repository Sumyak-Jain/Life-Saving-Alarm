#ifndef WINDOW1_H
#define WINDOW1_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
QT_BEGIN_NAMESPACE
namespace Ui { class window1; }

QT_END_NAMESPACE

class window1 : public QMainWindow
{
    Q_OBJECT

public:
    window1(QWidget *parent = nullptr);
    ~window1();

private slots:
    void on_pushButton_2_clicked();

    void on_reg_clicked();

    void on_pushButton_clicked();

    void on_Login_clicked();

private:
    Ui::window1 *ui;
    QSqlDatabase mydb;

};
#endif // WINDOW1_H
