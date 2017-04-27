#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>
#include "mywindow.h"
#include <QApplication>
#include <QtSql/QtSql>
#include <Qtsql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QSqlDriver>
#include <QRegExp>
#include <QDialog>
#include <QVariant>


namespace Ui {
class MyWindow;
}

class MyWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase db;
    QSortFilterProxyModel *proxyModel= new QSortFilterProxyModel(this);
    void connClose()
    {


    }

    bool connOpen()
    {
        db= QSqlDatabase::addDatabase("QODBC");
            db.setDatabaseName("DRIVER={MySQL ODBC 5.3 Unicode Driver};SERVER=LOCALHOST;Database=mydb;Uid=root;Password=root;");

            if(db.open())
            {

              qDebug()<<"connected"<<db.lastError().text();
              return true;

            }
            else
            {

                qDebug() <<"error connect" << db.lastError().text();
                return false;
            }
    }
    QSqlTableModel *model;

public:
    explicit MyWindow(QWidget *parent = 0);
    void buildList();
    QString finduser(QString Password);

    ~MyWindow();

private slots:
    void on_pushButton_clicked();

    void on_logout_button_clicked();

    void on_logout_button_2_clicked();

    void on_logout_button_3_clicked();

    void on_class_button_clicked();

    void on_class_button_2_clicked();

    void on_studen_button_2_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();




    void on_searchedit_textChanged(const QString &arg1);

private:
    Ui::MyWindow *ui;
};

#endif // MYWINDOW_H






