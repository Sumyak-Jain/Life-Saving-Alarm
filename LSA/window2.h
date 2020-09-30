#ifndef WINDOW2_H
#define WINDOW2_H
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QDialog>

namespace Ui {
class window2;
}

class window2 : public QDialog
{
    Q_OBJECT

public:
    explicit window2(QWidget *parent = nullptr);
    ~window2();

private slots:
    void on_pushButton_clicked();

    void on_register2_clicked();

    void on_Goback_clicked();

private:
    Ui::window2 *ui;
    QSqlDatabase mydb1;
};

#endif // WINDOW2_H
