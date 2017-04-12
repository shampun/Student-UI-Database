#include "add_grades.h"
#include "ui_add_grades.h"
#include <QtSql/QtSql>
#include <Qtsql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QSqlDriver>
#include <QmessageBox>
#include <QString>



#include <iostream>
using namespace std;


Add_Grades::Add_Grades(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_Grades)
{
    ui->setupUi(this);
}

Add_Grades::~Add_Grades()
{
    delete ui;
}

void Add_Grades::on_addgrades_button_clicked()
{
    QString testnum, score, courseid, studid;
    testnum=ui->Testnum_edit->text();
    score=ui->score_edit->text();
    courseid=ui->courseid_edit->text();
    studid=ui->studentid_edit->text();
QSqlQuery updategrades;
    updategrades.prepare("update grades set TestNum='"+testnum+"',score='"+score+"',Courses_has_Students_Courses_idCourses='"+courseid+"',Courses_has_Students_Students_idStudents='"+studid+"' where TestNum='"+testnum+"',Courses_has_Students_Courses_idCourses='"+courseid+"', where Courses_has_Students_Students_idStudents='"+studid+"'"
                         ); updategrades.exec();

//    QSqlQuery addgrades;
//    addgrades.prepare ("insert into mydb.grades (TestNum,Score,Courses_has_Students_Courses_idCourses,Courses_has_Students_Students_idStudents ) values (?, ?,?,?)");
//    addgrades.bindValue(0, testnum);
//    addgrades.bindValue(1, score);
//    addgrades.bindValue(2, courseid);
//    addgrades.bindValue(3, studid);
//    addgrades.exec();
//    close();

}


