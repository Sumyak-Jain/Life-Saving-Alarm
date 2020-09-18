#ifndef WINDOW1_H
#define WINDOW1_H

#include <QMainWindow>

namespace Ui {
class window1;
}

class window1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit window1(QWidget *parent = nullptr);
    ~window1();

private:
    Ui::window1 *ui;
};

#endif // WINDOW1_H
