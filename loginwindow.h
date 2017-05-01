#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <teacher.h>
namespace Ui {
class Loginwindow;
}

class Loginwindow : public QMainWindow
{
    Q_OBJECT

public:
    QString static mID,mFirstName,mLastName;

    explicit Loginwindow(QWidget *parent = 0);
    ~Loginwindow();

private slots:

    void on_LoginButton_clicked();

private:
    Ui::Loginwindow *ui;
};

#endif // LOGINWINDOW_H
