#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>

namespace Ui {
class Loginwindow;
}

class Loginwindow : public QMainWindow
{
    Q_OBJECT

public:
    QString ID,FirstName,LastName;

    explicit Loginwindow(QWidget *parent = 0);
    ~Loginwindow();

private slots:
    void on_pushButton_clicked();



private:
    Ui::Loginwindow *ui;
};

#endif // LOGINWINDOW_H
