#include "mywindow.h"
#include "ui_mywindow.h"
#include <QMessageBox>
#include <QtSql/QtSql>
#include <Qtsql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QSqlDriver>

QList<QString>AdminP;
QList<QString>AdminU;
QList<QString>StudentP;
QList<QString>StudentU;
QList<QString>TeacherP;
QList<QString>TeacherU;
QString user="";


//QList AdminStorage= new QList<QString,QString>();

MyWindow::MyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyWindow)
{
    ui->setupUi(this);

    // Sets which "stackwidget" page to start on when program starts
    ui->stackedWidget->setCurrentIndex(0);
}

MyWindow::~MyWindow()
{
    delete ui;
}


// LOGIN PAGE
void MyWindow::on_pushButton_clicked()
{
    bool accepted=false;
    // Define strings to rep user/pw
    QString  username = ui->usernameLE->text();
    QString  password = ui->passwordLE->text();

//Checking Passwords
for(int i=0;i<AdminU.size();i++)
{
     if(username==AdminU[i] && password==AdminP[i])
     {
         //Clear username and password
       ui->usernameLE->clear();
       ui->passwordLE->clear();
        accepted=true;

       // Go to page meant for actor
       ui->stackedWidget->setCurrentIndex(3);
       break;
     }
}
if(!accepted)
{
    for(int i=0;i<TeacherU.size();i++)
    {
        if(username==TeacherU[i] && password==TeacherP[i])
        {
        ui->usernameLE->clear();
        ui->passwordLE->clear();
        accepted=true;
        user=finduser(TeacherP[i]);
        ui->stackedWidget->setCurrentIndex(2);
        break;
        }
    }
}
if(!accepted)
{
    for(int i=0;i<StudentU.size();i++)
        {
        if(username==StudentU[i] && password==StudentP[i])
        {
        ui->usernameLE->clear();
        ui->passwordLE->clear();
        accepted=true;
        user=finduser(StudentP[i]);
        ui->stackedWidget->setCurrentIndex(1);
        break;
        }
    }
}
   if(!accepted)
    {
        //Clear username and password
      ui->usernameLE->clear();
      ui->passwordLE->clear();

      //Display Wrong U/PW Box
       QMessageBox::warning(this,"Login", "Incorrect Username or Password");
         ui->stackedWidget->setCurrentIndex(2);
    }
}



// STUDENT PAGE
void MyWindow::on_logout_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//Teacher Page
void MyWindow::on_logout_button_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//Admin Page
void MyWindow::on_logout_button_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MyWindow::on_class_button_clicked()
{


    QSqlQuery query;
    query.exec("SELECT CourseName,StuFName,StuLName,InstrFName FROM mydb.courses");
    while(query.next())
    {

       QString line = query.value(0).toString() + query.value(1).toString()
                     + query.value(2).toString() + query.value(3).toString();
      //  ui ->listWidget_2->addItem(line);
    }

   // ui ->listWidget->addItem(QString::number(1));
}


void MyWindow::on_class_button_2_clicked()
{
   ui ->listWidget_2->clear();
    QSqlQuery query;
    query.exec("SELECT CourseName,InstrLName FROM mydb.courses;");
    while(query.next())
    {

    if(user==query.value(1).toString())//Identify Teacher
        {
       QString line = query.value(0).toString();
        ui ->listWidget_2->addItem(line);
        }
    }

   // ui ->listWidget->addItem(QString::number(1));
}
QString MyWindow::finduser(QString Password)
{
    QSqlQuery query;
    query.exec("SELECT InstrLName,InstrPassW FROM mydb.instructors");
    while(query.next())
    {
        if(query.value(1).toString()==Password)
        {
            return query.value(0).toString();
        }

    }
    query.exec("SELECT StuLName,StuPassW From mydb.students");
    while(query.next())
    {
        if(query.value(1).toString()==Password)
        {
           return query.value(0).toString();
        }

    }
    return NULL;


}
void MyWindow::buildList()
{
    QSqlQuery query;
    query.exec("SELECT AdmUserN FROM mydb.admins");
    while(query.next())
    {

       QString line = query.value(0).toString();
       AdminU.append(line);
    }

    query.exec("SELECT AdmPassW FROM mydb.admins");
    while(query.next())
    {

       QString line = query.value(0).toString();
       AdminP.append(line);
    }

    query.exec("SELECT InstrUserN FROM mydb.instructors;");
    while(query.next())
    {

       QString line = query.value(0).toString();
       TeacherU.append(line);
    }

    query.exec("SELECT InstrPassW FROM mydb.instructors");
    while(query.next())
    {

       QString line = query.value(0).toString();
       TeacherP.append(line);
    }

    query.exec("SELECT StuUserN FROM mydb.students");
    while(query.next())
    {

     QString line = query.value(0).toString();
      StudentU.append(line);
    }

    query.exec("SELECT StuPassW FROM mydb.instructors");
    while(query.next())
    {

      QString line = query.value(0).toString();
       StudentP.append(line);
    }

}

void MyWindow::on_studen_button_2_clicked()
{
    ui ->listWidget_2->clear();
     QSqlQuery query;
     query.exec("SELECT StuFName,StuLName,InstrLName FROM mydb.courses");
     while(query.next())
     {

     if(user==query.value(2).toString())//Identify Teacher
         {
        QString line = query.value(0).toString()+query.value(1).toString();
         ui ->listWidget_2->addItem(line);
         }
     }
}
