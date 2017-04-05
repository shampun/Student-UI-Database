#include "loginwindow.h"
#include "ui_loginwindow.h"

loginWindow::loginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    //QString servername = "LOCALHOST\\MYSQLWORKBENCH";
    //QString dbname = "mydb";


    db = QSqlDatabase::addDatabase("QODBC");

    //db.setConnectOptions();

    //QString dsn =  QString ("DRIVER = {MySql ODBC 5.3 Unicode Driver}; SERVER = LOCALHOST;DATABASE = mydb; Uid = root; Password = root"); //.arg(dbname);

    db.setDatabaseName ("DRIVER={MySQL ODBC 5.3 Unicode Driver};SERVER=LOCALHOST;DATABASE=mydb;Uid=root;Password=root;");

    if (!db.isOpen())
        ui->statusLabel->setText("Failed to connect Db");
    else
    {
        ui->statusLabel->setText("Database connected");

    }


}
loginWindow::~loginWindow()
{
    delete ui;
    db.close();
}

void loginWindow::on_loginbutton_clicked()
{
    /*QString usr, pwd;
    usr = ui->usernameline->text();
    pwd = ui->pwdline->text();

    QSqlQuery query;
    if (query.exec("Select * from Students where StuUserN = '"+usr+"' and StuPassW = '"+pwd+"'"))
    {
        int count = 0;
        while (query.next())
        {
            count++;
        }

        if (count < 0)
            ui->stackedWidget->setCurrentIndex(1);
        else
            ui->statusLabel->setText("Wront username or password!");
    }

    else
    {
        ui->statusLabel->setText("DB not connect!");
    }*/
    ui->stackedWidget->setCurrentIndex(1);
    ui->usernameline->setText("");
    ui->pwdline->setText("");
}

void loginWindow::on_logoutbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void loginWindow::on_Gradesbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void loginWindow::on_GPAbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void loginWindow::on_infobutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void loginWindow::on_backbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void loginWindow::on_backbutton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void loginWindow::on_backbutton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
