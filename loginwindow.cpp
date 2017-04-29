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
void Loginwindow::on_LoginButton_clicked()
{
    //QString username = ui->LoginUserName->text();
    // QString   pwd = ui->LoginPassword->text();

        QString  username = "cmartinez0";
        QString  pwd = "z8r2Py";
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
        else
        {
            cout << "Can't find table!!" << endl;
            ui->LoginPassword->clear();
            ui->LoginUserName->clear();
        }
  }


