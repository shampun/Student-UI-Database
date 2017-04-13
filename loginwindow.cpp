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

    db.setDatabaseName ("DRIVER={MySQL ODBC 5.3 Unicode Driver};SERVER=mysql;DATABASE=mydb;Uid=root;Password=root;");

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
    ui->stackedWidget->setCurrentIndex(2);
    ui->usernameline->setText("");
    ui->pwdline->setText("");
}

void loginWindow::on_logoutbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void loginWindow::on_Gradesbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void loginWindow::on_GPAbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void loginWindow::on_infobutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void loginWindow::on_backbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void loginWindow::on_backbutton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void loginWindow::on_backbutton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void loginWindow::on_StudentButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void loginWindow::on_InstructorButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void loginWindow::on_InstrLoginButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
    ui->InstrUNLine->clear();
    ui->InstrPWline->clear();
}

void loginWindow::on_logoutbutton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void loginWindow::on_StudEditInfoButn_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void loginWindow::on_StudSaveButn_clicked()
{
    QString usr, pwd;
    usr = ui->StudNewUsrnTextLine->text();
    pwd = ui->StudNewPwdTextLine->text();
    ui->StudActualUsername->setText(usr);
    ui->StudActualPassword->setText(pwd);
    ui->StudNewUsrnTextLine->clear();
    ui->StudNewPwdTextLine->clear();
}

void loginWindow::on_backbutton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void loginWindow::on_StudCourse1TestGradesButn_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void loginWindow::on_StudCourse2TestGradeButn_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void loginWindow::on_StudCourse3TestGradeButn_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void loginWindow::on_course1button_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void loginWindow::on_course2button_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void loginWindow::on_course3button_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void loginWindow::on_backbutton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void loginWindow::on_backbutton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void loginWindow::on_backbutton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void loginWindow::on_course1button_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void loginWindow::on_course2button_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void loginWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void loginWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void loginWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}


void loginWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void loginWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}

void loginWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}
