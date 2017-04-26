#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "sims.h"
#include "teacher.h"
#include <QtSql/QtSql>
#include <Qtsql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>



Loginwindow::Loginwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Loginwindow)
{
    ui->setupUi(this);
}

Loginwindow::~Loginwindow()
{
    delete ui;
}

void Loginwindow::on_pushButton_clicked()
{
//QString username = ui->LoginUserName->text();
// QString   pwd = ui->LoginPassword->text();

    QString  username = "cmartinez0";
    QString  pwd = "z8r2Py";
    QSqlQuery query;
    SIMS student;
    if (query.exec("SELECT * FROM mydb.students"))
    {
        while (query.next())
        {
            if(query.value(3).toString() == username && query.value(4).toString() == pwd)
            {
               /*student.id = query.value(0).toString();
                student.fname = query.value(1).toString();
                student.lname = query.value(2).toString();
               student.GPA = query.value(5).toString();*/
               student.usr=username;
               student.pwd=pwd;

                this->hide();
               SIMS *s=new SIMS(this);
                  s->show();

            }

        }
      }
    Teacher T;
    if(query.exec("Select * From mydb.instructors"))
    {
        while (query.next())
        {
            if(query.value(3).toString() == username && query.value(4).toString() == pwd)
            {

              this->hide();
               // Teacher *T=new
              //  Teacher(query.value(0).toString(),query.value(1).toString(),query.value(2).toString());
               //Teacher *T=new Teacher(query.value(0).toString(),query.value(1).toString(),query.value(2).toString());
//                Teacher *T=new Teacher(this);

                T.ID=query.value(0).toString();
                T.FirstName=query.value(1).toString();
                T.LastName=query.value(2).toString();
                T.GetClasses(T.ID);
                T.show();
            }
        }

    }
    else
    {
        cout << "Can't find table!!" << endl;
        ui->LoginPassword->clear();
        ui->LoginUserName->clear();
    }
}
