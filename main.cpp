#include "mywindow.h"
#include <QApplication>
#include <QtSql/QtSql>
#include <Qtsql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QSqlDriver>

#include <iostream>
using namespace std;




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWindow w;
    w.show();
    QString dbname= "mydb";
    QSqlDatabase db= QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={MySQL ODBC 5.3 Unicode Driver};SERVER=LOCALHOST;Database=mydb;Uid=root;Password=sandman03;");

    if(!db.open())
    {

        cout << "Database connect failed"<<endl;
        qDebug() <<"error connect" << db.lastError().text();

    }
    else
    {
        cout<< "Database connected"<<endl;


    }

    return a.exec();
}

