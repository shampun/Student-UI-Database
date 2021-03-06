#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "sims.h"
#include "teacher.h"
#include "admin.h"
#include <QtSql/QtSql>
#include <Qtsql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>
using namespace std;

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
void Loginwindow::on_LoginButton_clicked()
{
    QString username = ui->LoginUserName->text();
    QString   pwd = ui->LoginPassword->text();

//    QString  username = "lame";
//    QString  pwd = "city";
    QSqlQuery query;

        if (query.exec("SELECT * FROM mydb.students"))
        {
            while (query.next())
            {
                if(query.value(3).toString() == username && query.value(4).toString() == pwd)
                {

                    this->hide();
                   SIMS *s=new SIMS(query.value(0).toString(),query.value(1).toString(),query.value(2).toString());
                      s->show();

                        break;

                }

            }
          }

        if(query.exec("Select * From mydb.instructors"))
        {
            while (query.next())
            {
                if(query.value(3).toString() == username && query.value(4).toString() == pwd)
                {
                    this->hide();
                    Teacher *Teach=new Teacher(query.value(0).toString(),query.value(1).toString(),query.value(2).toString());
                    Teach->show();
                    break;
                }
            }

        }
        if(query.exec("Select * From mydb.admins"))
        {

            while (query.next())
            {
                if(query.value(1).toString() == username && query.value(2).toString() == pwd)
                {
                    this->hide();
                    Admin *admin=new Admin();
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


