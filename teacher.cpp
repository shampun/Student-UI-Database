#include "teacher.h"
#include "ui_teacher.h"
#include "loginwindow.h"
#include <QtSql/QtSql>
#include <Qtsql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>

Teacher::Teacher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Teacher)
{
    ui->setupUi(this);
}

Teacher::~Teacher()
{
    delete ui;
}
void Teacher::AddGrade()
{

}
void Teacher::DelGrade()
{

}
void Teacher::AddStudent()
{

}
void Teacher::RemoveStudent()
{

}
void Teacher::ShowGrades()
{

}
void Teacher::ShowStudents()
{


}
void Teacher::GetClasses(QString s)
{
    QSqlQuery query;
    if (query.exec("SELECT * FROM mydb.courses"))
    {
        while (query.next())
        {
            if(query.value(7).toString()==s)
            {
                QString line=query.value(1).toString();
                QString line2;
                if(line2==line)
                {
                    continue;
                }
                ui->listWidget->addItem(line);

            }
        }

}
}
