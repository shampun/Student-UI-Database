#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
   QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    db.setDatabaseName( "Driver={MySQL ODBC 5.3 Unicode Driver};" );
                        db.setUserName("root");
                        db.setPassword("comodo25PAnda");
    if (db.open()) {
        qDebug()<<"Opened";
        db.close();

    } else {
        qDebug() << "error" << db.lastError().text();

    }
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   QSqlQuery query;

   query.exec("INSERT INTO mydb.students "
              "VALUES (16, 'Alex', 'Beaty', 'abeaty28', 'Lkdkei&98', NULL);");
}
