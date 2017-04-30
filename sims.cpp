#include "sims.h"
#include "ui_sims.h"
#include "teacher.h"
#include "ui_teacher.h"
#include "loginwindow.h"
#include <QtSql/QtSql>
#include <Qtsql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QInputDialog>
#include <QMessageBox>
#include<qstring.h>
#include <QListWidgetItem>
#include <QListWidget>

using namespace std;
SIMS::SIMS(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SIMS)
{
    ui->setupUi(this);

}
SIMS::SIMS(QString mID, QString mFirstName, QString mLastName, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::SIMS)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
    ui->TheStudentName->setText(mFirstName+" "+mLastName);
    ui->StudIDlabel->setText(mID);
    ui->TheStudentID->setText(mID);
    QSqlQuery query;
    query.exec("SELECT * FROM mydb.courses");
    while (query.next())
    {
     if(query.value(4).toString() == mID)
        {
        ui->listWidget->addItem(query.value(1).toString());
          }
    }
    id=mID;
    fname=mFirstName;
    lname=mLastName;

    //Add startup code



}
SIMS::~SIMS()
{
delete ui;
}
void SIMS::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->listWidget->clear();
    ui->ProfessorName->setText("Select a course.");
    ui->AverageGrade->setText("N/A");
    ui->StudGPAvalue->setText("N/A");
    ui->Test1Grade->setText("N/A");
    ui->Test2Grade->setText("N/A");
    ui->Test3Grade->setText("N/A");
    GPA = "Not Available";
}

void SIMS::on_InfoBackButn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void SIMS::on_StudInfoButn_clicked()
{
    ui->StudFNameLabel->setText(fname);
    ui->StudLNameLabel->setText(lname);
    ui->StudIDlabel->setText(id);
    ui->StudInfoUsernameLabel->setText(usr);
    ui->StudInfoPasswordLabel->setText(pwd);
    ui->stackedWidget->setCurrentIndex(2);
}

void SIMS::getClass()
{
    QString myclass = "";
    QString sameclass = NULL;

    QSqlQuery query;
    query.exec("SELECT * FROM mydb.courses");
    while (query.next())
    {

        if (query.value(2).toString() == fname && query.value(3).toString()
                == lname && query.value(4).toString() == id)
        {
            myclass = query.value(1).toString();

            if (sameclass == myclass)
                continue;
            else
            {
                ui->listWidget->addItem(myclass);
                sameclass = myclass;
            }
        }

    }
    if (myclass == "")
        ui->listWidget->addItem("Student not enroll in a course.");
}


void SIMS::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString thecourseid = "";
    QString ProfFname = "";
    QString ProfLname = "";
    bool check = false;
    QSqlQuery query;
    query.exec("SELECT * FROM mydb.courses");
    while (query.next())
    {
        if (query.value(1).toString() == item->text() && query.value(2).toString() == fname &&
        query.value(3).toString() == lname && query.value(4).toString() == id )
        {
            thecourseid = query.value(0).toString();
            ProfFname = query.value(5).toString();
            ProfLname = query.value(6).toString();
            QSqlQuery q;
            q.exec("SELECT * FROM mydb.grades");
            while(q.next())
            {
                if (q.value(4).toString() == thecourseid
                        && q.value(5).toString() == id)
                {
                    ui->ProfessorName->setText(ProfFname +" "+ ProfLname);
                    ui->Test1Grade->setText(q.value(0).toString());
                    ui->Test2Grade->setText(q.value(1).toString());
                    ui->Test3Grade->setText(q.value(2).toString());
                    ui->AverageGrade->setText(q.value(3).toString());
                    ui->StudGPAvalue->setText(GPA+" out of 4.00");
                    check = true;
                }


            }
            if (check == false)
                cout << "No grade available for this course!" << endl;

        }
    }
}
