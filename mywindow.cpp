#include "mywindow.h"
#include "ui_mywindow.h"
#include <QMessageBox>
#include <QtSql/QtSql>
#include <Qtsql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QSqlDriver>
#include <QAbstractItemModel>
#include <QSortFilterProxyModel>
#include<QRegExp>

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
         ui->stackedWidget->setCurrentIndex(3);
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

//ADMIN PAGE

//VIEW TEACHERS
void MyWindow::on_pushButton_2_clicked()
{

  //BUILD TABLE METHOD #1 CALLING OUT THE SPECIFIC COLUMNS
    QSqlQueryModel *teachermodel=new QSqlQueryModel;


    QSqlQuery * viewteachers =new QSqlQuery;

    viewteachers->exec("SELECT idInstructors,InstrFName,InstrLName,InstrUserN from mydb.instructors");


    teachermodel->setQuery(*viewteachers);
    teachermodel->setHeaderData(0, Qt::Horizontal, tr("ID"));
    teachermodel->setHeaderData(1, Qt::Horizontal, tr("Name"));
    teachermodel->setHeaderData(2, Qt::Horizontal, tr("Last Name"));
    teachermodel->setHeaderData(3, Qt::Horizontal, tr("UserName"));



    proxyModel->setSourceModel(teachermodel);

    ui->tableView->setModel(proxyModel);





}
//VIEW STUDENTS
void MyWindow::on_pushButton_3_clicked()
{

 //METHOD #2 TO BUILD TABLE, CALL ALL AND HIDE THE COLUMNS YOU DONT WANT
    model = new QSqlTableModel();


    model->setTable("students");
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Last Name"));
    model->setHeaderData(3, Qt::Horizontal, tr("UserName"));

    ui->tableView->setModel(model);
    ui->tableView->hideColumn(4);
    ui->tableView->hideColumn(5);

    proxyModel->setSourceModel(model);

    ui->tableView->setModel(proxyModel);
}

void MyWindow::on_pushButton_4_clicked()
{
    model = new QSqlTableModel();


    model->setTable("instructors");
    model->select();

    ui->tableView->setModel(model);

}

void MyWindow::on_searchedit_textChanged(const QString &arg1)
{
    QString arg2 = ui->searchedit->text();
     proxyModel->setFilterRegExp(QRegExp(arg2,Qt::CaseInsensitive, QRegExp::Wildcard));
     proxyModel->setFilterKeyColumn(1);

}

