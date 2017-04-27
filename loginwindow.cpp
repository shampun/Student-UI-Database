#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "sims.h"
#include "teacher.h"
#include <admin.h>


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
QString username = ui->LoginUserName->text();
 QString   pwd = ui->LoginPassword->text();

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
    if(query.exec("Select * From mydb.instructors"))
    {
        while (query.next())
        {
            if(query.value(3).toString() == username && query.value(4).toString() == pwd)
            {


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


