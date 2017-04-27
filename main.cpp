#include "sims.h"
#include "teacher.h"
#include "ui_sims.h"
#include "ui_teacher.h"
#include "loginwindow.h"
#include "admin.h"
#include <QApplication>





int main(int argc, char *argv[])
{
    QSqlDatabase db;

    QApplication a(argc, argv);
    SIMS w;
    Teacher T;
    Loginwindow L;
    Admin R;

    db= QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={MySQL ODBC 5.3 Unicode Driver};SERVER=LOCALHOST;Database=mydb;Uid=root;Password=root;");

    if(db.open())
    {
        cout << "Database connected!!!! " << endl;
    }
    else
    {
        cout << "Database connect failed"<<endl;
        qDebug() <<"error connect" << db.lastError().text();
    }
    R.show();
    return a.exec();
}
