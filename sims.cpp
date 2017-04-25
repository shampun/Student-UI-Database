#include "sims.h"
#include "ui_sims.h"
#include "teacher.h"
#include "ui_teacher.h"
#include "loginwindow.h"

using namespace std;
SIMS::SIMS(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SIMS)
{
    ui->setupUi(this);


    ui->stackedWidget->setCurrentIndex(1);
    ui->StudLoginStatusLabel->clear();
    //usr = ui->StudUsrnLE->text();
   // pwd = ui->StudPwdLE->text();

    QSqlQuery query;
    if (query.exec("SELECT * FROM mydb.students"))
    {
        while (query.next())
        {
            if(query.value(3).toString() == usr && query.value(4).toString() == pwd)
            {
                id = query.value(0).toString();
                fname = query.value(1).toString();
                lname = query.value(2).toString();
                GPA = query.value(5).toString();
                qDebug () << usr << pwd << id << fname << lname << GPA;
                ui->stackedWidget->setCurrentIndex(1);
                ui->TheStudentName->setText(fname+" "+lname);
                ui->TheStudentID->setText(id);
                getClass ();

            }

        }
        if (GPA == "Not Available")
               ui->StudLoginStatusLabel->setText("Wrong cridentials! Try again!");
     }
    if(query.exec("Select * From mydb.instructors"))
    {
        while (query.next())
        {
            if(query.value(3).toString() == usr && query.value(4).toString() == pwd)
            {


            }
        }

    }
    else
    {
        cout << "Can't find table!!" << endl;
        //ui->StudUsrnLE->clear();
        //ui->StudPwdLE->clear();
    }


}

SIMS::~SIMS()
{
    delete ui;

}

void SIMS::on_StudLoginBtn_clicked()
{
    ui->StudLoginStatusLabel->clear();
    usr = ui->StudUsrnLE->text();
    pwd = ui->StudPwdLE->text();

    QSqlQuery query;
    if (query.exec("SELECT * FROM mydb.students"))
    {
        while (query.next())
        {
            if(query.value(3).toString() == usr && query.value(4).toString() == pwd)
            {
                id = query.value(0).toString();
                fname = query.value(1).toString();
                lname = query.value(2).toString();
                GPA = query.value(5).toString();
                qDebug () << usr << pwd << id << fname << lname << GPA;
                ui->stackedWidget->setCurrentIndex(1);
                ui->TheStudentName->setText(fname+" "+lname);
                ui->TheStudentID->setText(id);
                getClass ();

            }

        }
        if (GPA == "Not Available")
               ui->StudLoginStatusLabel->setText("Wrong cridentials! Try again!");
     }
    if(query.exec("Select * From mydb.instructors"))
    {
        while (query.next())
        {
            if(query.value(3).toString() == usr && query.value(4).toString() == pwd)
            {


            }
        }

    }
    else
    {
        cout << "Can't find table!!" << endl;
        ui->StudUsrnLE->clear();
        ui->StudPwdLE->clear();
    }


//      this->hide();
//     Teacher *m=new Teacher(this);
//        m->show();



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
