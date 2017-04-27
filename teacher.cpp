#include "teacher.h"
#include "ui_teacher.h"
#include <QtSql/QtSql>
#include <Qtsql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QInputDialog>
#include <QMessageBox>
#include<qstring.h>

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
void Teacher::AddGrade(QString StudentID, int CourseID)
{

    QSqlQuery query;
    QString testScore=  QInputDialog::getText(this,"Tests","Enter test Score");
   QString TestNum=  QInputDialog::getText(this,"Tests","Test Number");
       //modify each grades for a specific test
       if(TestNum=="1")
       {
       query.prepare("INSERT INTO mydb.grades(Test1,Courses_has_Students_Courses_idCourses,Courses_has_Students_Students_idStudents)VALUES(?,?,?)");
           if(query.isValid())
              {
                query.addBindValue(testScore.toInt());
                query.addBindValue(CourseID);
                query.addBindValue(StudentID);
              }
          else if(QMessageBox::question(this,"Grade exist","Entry exist would you like to change it",QMessageBox::Yes |QMessageBox::No))
            {
              query.prepare("update mydb.grades set Test1=? Where Courses_has_Students_Students_idStudents=?");
              query.bindValue(0,testScore.toInt());
              query.bindValue(1,StudentID);
             }
              else
              {
              QMessageBox::information(this,"No entries added","No entries added");
               }

       }
       if(TestNum=="2")
       {
       query.prepare("INSERT INTO mydb.grades(Test2,Courses_has_Students_Courses_idCourses,Courses_has_Students_Students_idStudents)VALUES(?,?,?)");
       if(query.isValid())
       {
               query.addBindValue(testScore.toInt());
               query.addBindValue(CourseID);
               query.addBindValue(StudentID);
         }
           else if(QMessageBox::question(this,"Grade exist","Entry exist would you like to change it",QMessageBox::Yes |QMessageBox::No))
           {
               query.prepare("update mydb.grades set Test2=? Where Courses_has_Students_Students_idStudents=?");
               query.bindValue(0,testScore.toInt());
               query.bindValue(1,StudentID);
           }
           else
           {
               QMessageBox::information(this,"No entries added","No entries added");
           }
       }
       if(TestNum=="3")
       {
      query.prepare("INSERT INTO mydb.grades(Test3,Courses_has_Students_Courses_idCourses,Courses_has_Students_Students_idStudents)VALUES(?,?,?)");
         if(query.isValid())
         {
              query.addBindValue(testScore.toInt());
              query.addBindValue(CourseID);
              query.addBindValue(StudentID);
          }
          else if(QMessageBox::question(this,"Grade exist","Entry exist would you like to change it",QMessageBox::Yes |QMessageBox::No))
          {
              query.prepare("update mydb.grades set Test3=? Where Courses_has_Students_Students_idStudents=?");
              query.bindValue(0,testScore.toInt());
              query.bindValue(1,StudentID);
          }
          else
          {
              QMessageBox::information(this,"No entries added","no entries added");
          }

       }
       else
       {
           QMessageBox::information(this,"No entries added","no entries added");
       }

    query.exec();
}
void Teacher::DelGrade(QString CourseID, QString StudentID,QString Testnum)
{
    QSqlQuery query;
    if(Testnum=="Test1")
    {
        query.prepare("update mydb.grades set test1=?, Where Courses_has_Students_Students_idStudents=?,Courses_has_Students_Courses_idCourses=?");
        query.bindValue(0,NULL);
        query.bindValue(1,StudentID);
        query.bindValue(2,CourseID);
        query.exec();
    }
    if(Testnum=="Test2")
    {
        query.prepare("update mydb.grades set test2=?, Where Courses_has_Students_Students_idStudents=?,Courses_has_Students_Courses_idCourses=?");
        query.bindValue(0,NULL);
        query.bindValue(1,StudentID);
         query.bindValue(2,CourseID);
        query.exec();
    }
    if(Testnum=="Test3")
    {
        query.prepare("update mydb.grades set test3=?, Where Courses_has_Students_Students_idStudents=?,Courses_has_Students_Courses_idCourses=?");
        query.bindValue(0,NULL);
        query.bindValue(1,StudentID);
         query.bindValue(2,CourseID);
        query.exec();

    }
}
void Teacher::AddStudent(QString CourseID,QString CourseName,Teacher teach)
{
    QString Fname=  QInputDialog::getText(this,"Create Student","FirstName");
    QString Lname=  QInputDialog::getText(this,"Create Student","LastName");
    //created an iD for the student loop
    bool ID=false;
    int newID;
       QSqlQuery query;
      query.exec("Select idStudents From mydb.students");
      for(int i=1;i<50;i++)
      {
          if(!ID)
          {
               while(query.next())
              {

                  QString str= QString::number(i);
                  if(query.value(0).toInt()==i)
                  {
                     break;
                  }
                  else
                      {
                          newID=i;
                          ID=true;
                          break;
                      }
               }

          }
          else
              break;

      }

      //Insert new student into class
      query.prepare("INSERT INTO mydb.courses(idCourses,CourseName,StuFName,StuLName,idStudents,InstrFName,InstrLName,Instructors_idInstructors)"
                "VALUES(?,?,?,?,?,?,?,?)");


      query.bindValue(0,CourseID);
      query.bindValue(1,CourseName);
      query.bindValue(2,Fname);
      query.bindValue(3,Lname);
      query.bindValue(4,newID);
      query.bindValue(5,teach.FirstName);
      query.bindValue(6,teach.LastName);
      query.bindValue(7,teach.ID);
      query.exec();

}
void Teacher::RemoveStudent(QString CourseID, QString StudFname)
{
    QSqlQuery query;
    int StudentID;
    query.exec("SELECT idStudents,StuFName,StuLName,CourseName,InstrLName FROM mydb.courses");
    while(query.next())
    {
        if(query.value(1).toString()==StudFname)
        {
            StudentID=query.value(0).toInt();
            break;
        }
      }
   query.prepare("delete from mydb.courses Where idStudents=?,idCourses=?");
   query.bindValue(0,StudentID);
   query.bindValue(1,CourseID.toInt());
   query.exec();
}
QString Teacher::FindStudent(int ID)
{
    QSqlQuery query;
    query.exec("SELECT * FROM mydb.students;");
    while(query.next())
    {
        if(query.value(0).toInt()==ID)
        {
            return query.value(1).toString()+" "+query.value(2).toString();

        }
        else
            continue;
    }
    return "Student has no ID";

}
QStringList Teacher::ShowGrades(QString CourseID,Teacher teach)
{
    QStringList mGrades;
    QSqlQuery query;
    QString line;
    query.exec("SELECT * FROM mydb.grades;");
    while(query.next())
    {

        if(CourseID==query.value(4).toInt())
        {
     QString mStudent= FindStudent(query.value(4).toInt());
             mStudent="Test1"+query.value(0).toString();
             mStudent=+" Test2 "+query.value(1).toString();
            mStudent=+" Test3 "+query.value(2).toString();

          mGrades.append(mStudent);


        }
        else
            continue;
    }
    return mGrades;

}
QStringList Teacher::ShowStudents(Teacher Teach)
{
    QStringList Students;
    QSqlQuery query;
    query.exec("SELECT * FROM mydb.courses;");
    while(query.next())
    {
        if(query.value(7)==Teach.ID)
        {
            QString line=query.value(2).toString()+" "+query.value(3).toString();
            Students.append(line);

        }
    }
   return Students;

}
QStringList Teacher::GetClasses(Teacher Teach)
{
    QString line,line2;
    QStringList Classes;
    QSqlQuery query;
    if (query.exec("SELECT * FROM mydb.courses"))
    {
      while(query.next())
      {
        if(query.value(7)==Teach.ID)
        {
         line=query.value(1).toString();
         if(line==line2)
         {
            continue;
         }
         else
         {
             line2=line;
             Classes<<(line);
         }

       }
      }

    }
    return Classes;
}

void Teacher::on_pushButton_clicked()
{
      ui->Classeslbl->setText("AJ IS the man");
          QString line;
            QString line2;
    QSqlQuery query;
    if (query.exec("SELECT * FROM mydb.courses"))
    {
        while (query.next())
        {
            if(query.value(7).toString()==ID)
            {
               line=query.value(1).toString();

                if(line2==line)
                {
                    continue;
                }\
                else
                {
                    line2=line;
                    qDebug()<<line;


                    ui->TeacherWidget->addItem(line);
                    ui->listWidget_2->addItem(line);
                    //ui->TeacherWidget->addItems(line);
                }


            }
        }

    }
    ui->TeacherWidget->addItem(line);
}
