#include "admin.h"
#include "ui_admin.h"
#include <QListWidgetItem>
#include <QListWidget>
#include <QMessageBox>
#include <QtSql/QtSql>
#include <Qtsql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QSqlDriver>
#include <QAbstractItemModel>
#include <QSortFilterProxyModel>
#include <QRegExp>
#include <iostream>
#include <loginwindow.h>

using namespace std;



Admin::Admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin)
{

    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxy_Model->setFilterCaseSensitivity(Qt::CaseInsensitive);
    Cteacher->setFilterCaseSensitivity(Qt::CaseInsensitive);
    Cstudent->setFilterCaseSensitivity(Qt::CaseInsensitive);
    CourseProxy->setFilterCaseSensitivity(Qt::CaseInsensitive);


}

Admin::~Admin()
{
    delete ui;
}

void Admin::DeleteCourse()
{
    QString cid,cname,sname,slast,sid,tname,tlast,tid;

    cid=ui->cid->text();
    cname=ui->cname->text();
    sname=ui->sname->text();
    slast=ui->slast->text();
    sid=ui->sid->text();
    tname=ui->tname->text();
    tlast=ui->tlast->text();
    tid=ui->tid->text();


    QSqlQuery delstud,delstud2,delstud3;

 delstud3.exec("DELETE FROM `mydb`.`courses_has_students` WHERE `Courses_idCourses`='"+cid+"' and`Students_idStudents`='"+sid+"'");
   delstud2.exec("DELETE FROM `mydb`.`grades` WHERE `Courses_has_Students_Courses_idCourses`='"+cid+"' and`Courses_has_Students_Students_idStudents`='"+sid+"', ");
 delstud.exec("DELETE FROM `mydb`.`courses` WHERE `idCourses`='"+cid+"' and`idStudents`='"+sid+"' and `Instructors_idInstructors`='"+tid+"'");


  if (delstud.exec())
  {
      QMessageBox::critical(this,tr("Delete"), tr("Deleted"));
  }
  else
  {
     QMessageBox::critical(this,tr("Error"), tr("Error"));
  }
}

void Admin::DeleteStudents()
{
  QString stid=ui->stid->text();
  QSqlQuery delstud;
delstud.prepare("Delete from students where idStudents='"+stid+"'");\

if (delstud.exec())
{
    QMessageBox::critical(this,tr("Delete"), tr("Deleted"));
}
else
{
   QMessageBox::critical(this,tr("Error"), tr("Error"));
}
}

void Admin::DeleteInstructor()
{
    QString stid=ui->stid->text();
    QSqlQuery delteach;
  delteach.prepare("Delete from instructors where idInstructors='"+stid+"'");\

  if (delteach.exec())
  {
      QMessageBox::critical(this,tr("Delete"), tr("Deleted"));
  }
  else
  {
     QMessageBox::critical(this,tr("Error"), tr("Error"));
  }
}

void Admin::BuildTeacherView()
{
    //BUILD TABLE METHOD #1 CALLING OUT THE SPECIFIC COLUMNS
      QSqlQueryModel *teachermodel=new QSqlQueryModel;


      QSqlQuery * viewteachers =new QSqlQuery;

      viewteachers->exec("SELECT idInstructors,InstrFName,InstrLName,InstrUserN,InstrPassW from mydb.instructors");


      teachermodel->setQuery(*viewteachers);
      teachermodel->setHeaderData(0, Qt::Horizontal, tr("Instructor ID"));
      teachermodel->setHeaderData(1, Qt::Horizontal, tr("Name"));
      teachermodel->setHeaderData(2, Qt::Horizontal, tr("Last Name"));
      teachermodel->setHeaderData(3, Qt::Horizontal, tr("UserName"));
      teachermodel->setHeaderData(4, Qt::Horizontal, tr("Password"));



      proxy_Model->setSourceModel(teachermodel);

      ui->courseView->setModel(proxy_Model);
      Tcheck = 0;
}
void Admin::BuildCourseTeacher()
{
    QSqlQueryModel *teachermodel=new QSqlQueryModel;


    QSqlQuery * viewteachers =new QSqlQuery;

    viewteachers->exec("SELECT idInstructors,InstrFName,InstrLName from mydb.instructors");


    teachermodel->setQuery(*viewteachers);
    teachermodel->setHeaderData(0, Qt::Horizontal, tr("ID"));
    teachermodel->setHeaderData(1, Qt::Horizontal, tr("Name"));
    teachermodel->setHeaderData(2, Qt::Horizontal, tr("Last Name"));




    Cteacher->setSourceModel(teachermodel);
}

void Admin::BuildCourseStudent()
{
    QSqlQueryModel *studentmodel=new QSqlQueryModel;


    QSqlQuery * viewstudents =new QSqlQuery;

    viewstudents->exec("SELECT idStudents,StuFName,StuLName from mydb.students");


    studentmodel->setQuery(*viewstudents);
    studentmodel->setHeaderData(0, Qt::Horizontal, tr("ID"));
    studentmodel->setHeaderData(1, Qt::Horizontal, tr("Name"));
    studentmodel->setHeaderData(2, Qt::Horizontal, tr("Last Name"));




    Cstudent->setSourceModel(studentmodel);


}

void Admin::BuildStudentView()
{
    QSqlQueryModel *studentmodel=new QSqlQueryModel;


    QSqlQuery * viewstudents =new QSqlQuery;

    viewstudents->exec("SELECT idStudents,StuFName,StuLName,StuUserN,StuPassW from mydb.students");


    studentmodel->setQuery(*viewstudents);
    studentmodel->setHeaderData(0, Qt::Horizontal, tr("Student ID"));
    studentmodel->setHeaderData(1, Qt::Horizontal, tr("Name"));
    studentmodel->setHeaderData(2, Qt::Horizontal, tr("Last Name"));
    studentmodel->setHeaderData(3, Qt::Horizontal, tr("UserName"));
    studentmodel->setHeaderData(4, Qt::Horizontal, tr("Password"));



    proxyModel->setSourceModel(studentmodel);

    ui->tableView->setModel(proxyModel);
    Tcheck = 2;
}

void Admin::BuildCourseView()
{
    QSqlQueryModel *Course_Model=new QSqlQueryModel;


    QSqlQuery * viewteachers =new QSqlQuery;

    viewteachers->exec("SELECT idCourses,CourseName,StuFName,StuLName,idStudents,InstrFName,InstrLName,Instructors_idInstructors from mydb.courses");


    Course_Model->setQuery(*viewteachers);
    Course_Model->setHeaderData(0, Qt::Horizontal, tr("Course ID"));
    Course_Model->setHeaderData(1, Qt::Horizontal, tr("Course"));
    Course_Model->setHeaderData(2, Qt::Horizontal, tr("Student"));
    Course_Model->setHeaderData(3, Qt::Horizontal, tr("Last Name"));
    Course_Model->setHeaderData(4, Qt::Horizontal, tr("Student ID"));
    Course_Model->setHeaderData(5, Qt::Horizontal, tr("Instructor"));
    Course_Model->setHeaderData(6, Qt::Horizontal, tr("Last Name"));
    Course_Model->setHeaderData(7, Qt::Horizontal, tr("Instructor ID"));




     CourseProxy->setSourceModel(Course_Model);


}
void Admin::Add_Students()
{
    QString stid,stname,stlast,stuser,stpw;

    stid=ui->stid->text();
    stname=ui->stname->text();
    stlast=ui->stlast->text();
    stuser=ui->stuser->text();
    stpw=ui->stpw->text();

    QSqlQuery addstudent;
       addstudent.prepare ("insert into mydb.students (idStudents,StuFName,StuLName,StuUserN,StuPassW ) values (?, ?,?,?,?)");
       addstudent.bindValue(0, stid);
       addstudent.bindValue(1, stname);
       addstudent.bindValue(2, stlast);
       addstudent.bindValue(3, stuser);
       addstudent.bindValue(4, stpw);
       addstudent.exec();
}
void Admin::Add_Instructor()
{
    QString stid,stname,stlast,stuser,stpw;

    stid=ui->stid->text();
    stname=ui->stname->text();
    stlast=ui->stlast->text();
    stuser=ui->stuser->text();
    stpw=ui->stpw->text();

    QSqlQuery addstudent;
       addstudent.prepare ("insert into mydb.instructors (idInstructors,InstrFName,InstrLName,InstrUserN,InstrPassW ) values (?, ?,?,?,?)");
       addstudent.bindValue(0, stid);
       addstudent.bindValue(1, stname);
       addstudent.bindValue(2, stlast);
       addstudent.bindValue(3, stuser);
       addstudent.bindValue(4, stpw);
       addstudent.exec();
}
void Admin::RegisterNewClass()
{
    QString stid,stname,stlast,tname,tlast,tid,cid,cname;

    cid=ui->cid->text();
    cname=ui->cname->text();
    stid=ui->sid->text();
    stname=ui->sname->text();
    stlast=ui->slast->text();
    tname=ui->tname->text();
    tlast=ui->tlast->text();
    tid=ui->tid->text();

    QSqlQuery addstudent;
       addstudent.prepare ("insert into mydb.courses (idCourses, CourseName, StuFName, StuLName, idStudents, InstrFName, InstrLName, Instructors_idInstructors) values (?,?,?,?,?,?,?,?)");
       addstudent.bindValue(0, cid);
       addstudent.bindValue(1, cname);
       addstudent.bindValue(2, stname);
       addstudent.bindValue(3, stlast);
       addstudent.bindValue(4, stid);
       addstudent.bindValue(5, tname);
       addstudent.bindValue(6, tlast);
       addstudent.bindValue(7, tid);
       addstudent.exec();

       if (addstudent.exec())
       {
           QMessageBox::critical(this,tr("Register"), tr("Registered"));
       }


}

void Admin::RegisterNewClass2()
{
    QString stid,stname,stlast,tname,tlast,tid,cid,cname;

    cid=ui->cid->text();
    cname=ui->cname->text();
    stid=ui->sid->text();
    stname=ui->sname->text();
    stlast=ui->slast->text();
    tname=ui->tname->text();
    tlast=ui->tlast->text();
    tid=ui->tid->text();

    QSqlQuery addstudent_2;
    addstudent_2.exec("INSERT INTO `mydb`.`courses_has_students` (`Courses_idCourses`, `Students_idStudents`) VALUES ('"+cid+"', '"+stid+"');");




}

void Admin::RegisterNewClass3()
{
    QString stid,stname,stlast,tname,tlast,tid,cid,cname;

    cid=ui->cid->text();
    cname=ui->cname->text();
    stid=ui->sid->text();
    stname=ui->sname->text();
    stlast=ui->slast->text();
    tname=ui->tname->text();
    tlast=ui->tlast->text();
    tid=ui->tid->text();

    QSqlQuery addstudent_3;
    addstudent_3.exec("INSERT INTO `mydb`.`grades` (`Courses_has_Students_Courses_idCourses`, `Courses_has_Students_Students_idStudents`) VALUES ('"+cid+"', '"+stid+"')");
}

void Admin::UpdateTeacher()
{
    QString stid,stname,stlast,stuser,stpw;

    stid=ui->stid->text();
    stname=ui->stname->text();
    stlast=ui->stlast->text();
    stuser=ui->stuser->text();
    stpw=ui->stpw->text();
    QSqlQuery updatest;
    updatest.exec("UPDATE instructors set InstrFName='"+stname+"',InstrLName='"+stlast+"',InstrUserN='"+stuser+"',InstrPassW='"+stpw+"' where idInstructors='"+stid+"'");

}
void Admin::UpdateStudent()
{
    QString stid,stname,stlast,stuser,stpw;

    stid=ui->stid->text();
    stname=ui->stname->text();
    stlast=ui->stlast->text();
    stuser=ui->stuser->text();
    stpw=ui->stpw->text();
    QSqlQuery updatest;
    updatest.exec("UPDATE students Set StuFName='"+stname+"',StuLName='"+stlast+"',StuUserN='"+stuser+"',StuPassW='"+stpw+"'  where idStudents='"+stid+"'");
}

void Admin::on_ViewTeachers_clicked()
{
 BuildTeacherView();
}

void Admin::on_ViewStudents_clicked()
{
    BuildStudentView();
}

void Admin::on_searchedit_textChanged(const QString &arg1)
{
    proxyModel->setFilterFixedString(arg1);
}

void Admin::on_comboBox_currentIndexChanged(int index)
{
     proxyModel->setFilterKeyColumn(index);
}

void Admin::on_pushButton_9_clicked()
{
ui->stackedWidget->setCurrentIndex(1);
}



void Admin::on_pushButton_2_clicked()
{
    Add_Students();
    BuildStudentView();
}

void Admin::on_pushButton_3_clicked()
{
    Add_Instructor();
    BuildTeacherView();
}

void Admin::on_tableView_activated(const QModelIndex &index)
{
    QString ccc = ui->tableView->model()->data(index).toString();



    QSqlQuery mod2;
    mod2.prepare("select * from students where idStudents='"+ccc+"' or StuFName='"+ccc+"' or StuLName='"+ccc+"' or StuUserN='"+ccc+"'" );

    if (mod2.exec())
    {
        while (mod2.next())
    {
    ui->stid->setText(mod2.value(0).toString());
    ui->stname->setText(mod2.value(1).toString());
    ui->stlast->setText(mod2.value(2).toString());
    ui->stuser->setText(mod2.value(3).toString());
    ui->stpw->setText(mod2.value(4).toString());
        }
    }

}

void Admin::on_pushButton_5_clicked()
{
    UpdateStudent();
    BuildStudentView();
}

void Admin::on_pushButton_6_clicked()
{
    BuildCourseView();
    ui->CourseView_2->setModel(CourseProxy);
    BuildCourseStudent();
    ui->stview->setModel(Cstudent);
    BuildCourseTeacher();
     ui->tview->setModel(Cteacher);
}



void Admin::on_stview_activated(const QModelIndex &index)
{
    QString cccc = ui->stview->model()->data(index).toString();
    QSqlQuery mod;
    mod.prepare("select * from students where idStudents='"+cccc+"' or StuFName='"+cccc+"' or StuLName='"+cccc+"'" );

    if (mod.exec())
    {
        while (mod.next())
    {
    ui->sid->setText(mod.value(0).toString());
    ui->sname->setText(mod.value(1).toString());
    ui->slast->setText(mod.value(2).toString());

        }
    }
}

void Admin::on_tview_activated(const QModelIndex &index)
{
    QString ccccc = ui->tview->model()->data(index).toString();
    QSqlQuery mod;
    mod.prepare("select * from instructors where idInstructors='"+ccccc+"' or InstrFName='"+ccccc+"' or InstrLName='"+ccccc+"'" );

    if (mod.exec())
    {
        while (mod.next())
    {
    ui->tid->setText(mod.value(0).toString());
    ui->tname->setText(mod.value(1).toString());
    ui->tlast->setText(mod.value(2).toString());

        }
    }
}

void Admin::on_pushButton_7_clicked()
{
RegisterNewClass();

RegisterNewClass2();
RegisterNewClass3();
BuildCourseView();
ui->CourseView_2->setModel(CourseProxy);
BuildCourseStudent();
ui->stview->setModel(Cstudent);
BuildCourseTeacher();
 ui->tview->setModel(Cteacher);

}

void Admin::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Admin::on_pushButton_4_clicked()
{
    UpdateTeacher();
    BuildTeacherView();
}

void Admin::on_courseView_activated(const QModelIndex &index)
{
    QString ccccc = ui->courseView->model()->data(index).toString();
    QSqlQuery mod;
    mod.prepare("select * from instructors where idInstructors='"+ccccc+"' or InstrFName='"+ccccc+"' or InstrLName='"+ccccc+"' or InstrUserN='"+ccccc+"'" );

    if (mod.exec())
    {
        while (mod.next())
    {
    ui->stid->setText(mod.value(0).toString());
    ui->stname->setText(mod.value(1).toString());
    ui->stlast->setText(mod.value(2).toString());
    ui->stuser->setText(mod.value(3).toString());
    ui->stpw->setText(mod.value(4).toString());
        }
    }
}

void Admin::on_searchedit_2_textChanged(const QString &arg1)
{
    proxy_Model->setFilterFixedString(arg1);
}

void Admin::on_comboBox_2_currentIndexChanged(int index)
{
    proxy_Model->setFilterKeyColumn(index);
}


void Admin::on_pushButton_22_clicked()
{
    DeleteStudents();
    BuildStudentView();
}

void Admin::on_remInstructor_clicked()
{
    DeleteInstructor();
    BuildTeacherView();
}

void Admin::on_CourseView_2_activated(const QModelIndex &index)
{
    QString c = ui->CourseView_2->model()->data(index).toString();
    QSqlQuery mod;
    mod.prepare("select *from courses where idCourses='"+c+"'or CourseName='"+c+"'or StuFName='"+c+"'or idStudents='"+c+"'");

    if (mod.exec())
    {
        while (mod.next())
    {
    ui->cid->setText(mod.value(0).toString());
    ui->cname->setText(mod.value(1).toString());
    ui->sname->setText(mod.value(2).toString());
    ui->slast->setText(mod.value(3).toString());
    ui->sid->setText(mod.value(4).toString());
    ui->tname->setText(mod.value(5).toString());
    ui->tlast->setText(mod.value(6).toString());
    ui->tid->setText(mod.value(7).toString());

        }
    }
}

void Admin::on_pushButton_clicked()
{
DeleteCourse();
BuildCourseView();
ui->CourseView_2->setModel(CourseProxy);
BuildCourseStudent();
ui->stview->setModel(Cstudent);
BuildCourseTeacher();
 ui->tview->setModel(Cteacher);

}

void Admin::on_searchedit_4_textChanged(const QString &arg1)
{
    Cteacher->setFilterFixedString(arg1);
}


void Admin::on_comboBox_4_currentIndexChanged(int index)
{
    Cteacher->setFilterKeyColumn(index);
}

void Admin::on_searchedit_3_textChanged(const QString &arg1)
{
    Cstudent->setFilterFixedString(arg1);
}

void Admin::on_comboBox_3_currentIndexChanged(int index)
{
    Cstudent->setFilterKeyColumn(index);
}

void Admin::on_searchedit_5_textChanged(const QString &arg1)
{
    CourseProxy->setFilterFixedString(arg1);
    CourseProxy->setFilterKeyColumn(0);
}

//LIST WIDGET STUDENT VIEW
void Admin::on_pushButton_10_clicked()
{
    ui->listWidget->clear();
    ssid=ui->stid->text();
    ssname=ui->stname->text();
    sslast=ui->stlast->text();
    ssusr = ui->stuser->text();
    sspwd = ui->stpw->text();
    ui->TheStudentName->setText(ssname + " " + sslast);
    ui->TheStudentID->setText(ssid);
    QString myclass = "";
    QString sameclass = NULL;

    QSqlQuery query;
    query.exec("SELECT * FROM mydb.courses");
    while (query.next())
    {

        if (query.value(2).toString() == ssname && query.value(3).toString()
                == sslast && query.value(4).toString() == ssid)
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
    ui->stackedWidget->setCurrentIndex(2);
    ui->swidge->setCurrentIndex(0);
}

void Admin::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString thecourseid = "";
    QString ProfFname = "";
    QString ProfLname = "";
    bool check = false;
    QSqlQuery query;
    query.exec("SELECT * FROM mydb.courses");
    while (query.next())
    {
        if (query.value(1).toString() == item->text() && query.value(2).toString() == ssname &&
        query.value(3).toString() == sslast && query.value(4).toString() == ssid )
        {
            thecourseid = query.value(0).toString();
            ProfFname = query.value(5).toString();
            ProfLname = query.value(6).toString();
            QSqlQuery q;
            q.exec("SELECT * FROM mydb.grades");
            while(q.next())
            {
                if (q.value(4).toString() == thecourseid
                        && q.value(5).toString() == ssid)
                {
                    ui->ProfessorName->setText(ProfFname +" "+ ProfLname);

                    ui->Test1Grade->setText(q.value(0).toString());
                    ui->Test2Grade->setText(q.value(1).toString());
                    ui->Test3Grade->setText(q.value(2).toString());
                    ui->AverageGrade->setText(q.value(3).toString());
                    ui->StudGPAvalue->setText(ssgpa+" out of 4.00");
                    check = true;
                }


            }
            if (check == false)
                cout << "No grade available for this course!" << endl;

        }
    }
}

void Admin::on_StudInfoButn_clicked()
{
    ui->StudFNameLabel->setText(ssname);
    ui->StudLNameLabel->setText(sslast);
    ui->StudIDlabel->setText(ssid);
    ui->StudInfoUsernameLabel->setText(ssusr);
    ui->StudInfoPasswordLabel->setText(sspwd);
    ui->swidge->setCurrentIndex(1);

}

void Admin::on_pushButton_12_clicked()
{
    ui->ProfessorName->setText("Select a course.");
    ui->AverageGrade->setText("N/A");
    ui->StudGPAvalue->setText("N/A");
    ui->Test1Grade->setText("N/A");
    ui->Test2Grade->setText("N/A");
    ui->Test3Grade->setText("N/A");
    ui->stackedWidget->setCurrentIndex(0);
}

void Admin::on_InfoBackButn_clicked()
{
    ui->swidge->setCurrentIndex(0);
}


void Admin::on_logout_button_6_clicked()
{
   L->show();
    close();
}
