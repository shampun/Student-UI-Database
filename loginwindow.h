#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <Qtsql/QSqlDatabase>
#include <Qtsql/QSqlQuery>
#include <QtSql/QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlDriver>

namespace Ui {
class loginWindow;
}

class loginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = 0);
    ~loginWindow();

private slots:
    void on_loginbutton_clicked();

    void on_logoutbutton_clicked();

    void on_Gradesbutton_clicked();

    void on_GPAbutton_clicked();

    void on_infobutton_clicked();

    void on_backbutton_clicked();

    void on_backbutton_2_clicked();

    void on_backbutton_3_clicked();

private:
    Ui::loginWindow *ui;
    QSqlDatabase db;
};

#endif // LOGINWINDOW_H
