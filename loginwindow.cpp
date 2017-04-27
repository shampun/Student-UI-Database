#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "sims.h"
#include "admin.h"
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
QString username = ui->LoginUserName->text();
 QString   pwd = ui->LoginPassword->text();

    QSqlQuery query;
    SIMS *student=new SIMS();
    if (query.exec("SELECT * FROM mydb.students"))
    {
        while (query.next())
        {
            if(query.value(3).toString() == username && query.value(4).toString() == pwd)
            {

                this->hide();

                  student->show();
                  student->id = query.value(0).toString();
                   student->fname = query.value(1).toString();
                   student->lname = query.value(2).toString();
                  student->GPA = query.value(5).toString();
                  student->usr=username;
                  student->pwd=pwd;
                  student->getClass();
                    break;

            }

        }
      }
    Teacher *Teach=new Teacher();
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



                //T.show();
                Teach->show();

                Teach->ID=query.value(0).toString();
                Teach->FirstName=query.value(1).toString();
                Teach->LastName=query.value(2).toString();
                Teach->GetClasses(Teach->ID);
                break;
            }
        }

    }
     Admin *admin=new Admin();
    if(query.exec("Select * From mydb.admins"))
    {
        while (query.next())
        {
            qDebug()<<query.value(1);
            qDebug()<<query.value(2);
            if(query.value(1).toString() == username && query.value(2).toString() == pwd)
            {

                this->hide();
               // Teacher *T=new
              //  Teacher(query.value(0).toString(),query.value(1).toString(),query.value(2).toString());
               //Teacher *T=new Teacher(query.value(0).toString(),query.value(1).toString(),query.value(2).toString());
//                Teacher *T=new Teacher(this);



                //T.show();
                admin->show();


                break;
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
