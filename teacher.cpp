#include "teacher.h"
#include "ui_teacher.h"
#include <QtSql/QtSql>
#include <Qtsql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QInputDialog>
#include <QMessageBox>
#include<qstring.h>
#include <QListWidgetItem>
#include <QListWidget>

QStringList Classes;
QList<Student*> students;
QList<Student*> Allstudents;
QString Selected="";

Teacher::Teacher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Teacher)
{
    ui->setupUi(this);

}
Teacher::Teacher(QString mID, QString mFirstName, QString mLastName, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::Teacher)
{
    ui->setupUi(this);
    ID=mID;
    FirstName=mFirstName;
    LastName=mLastName;
    GetClasses(this);

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
void Teacher::DelGrade(QString CourseID, QString StudentID,QString TestNum,QString testScore)
{
    QSqlQuery query;
    if(TestNum=="1")
    {
      query.prepare("update mydb.grades set Test1=? Where Courses_has_Students_Students_idStudents=?");
           query.bindValue(0,testScore.toInt());
           query.bindValue(1,StudentID);
        }
           else
           {
           QMessageBox::information(this,"No entries added","No entries added");
            }


    if(TestNum=="2")
    {
            query.prepare("update mydb.grades set Test2=? Where Courses_has_Students_Students_idStudents=?");
            query.bindValue(0,testScore.toInt());
            query.bindValue(1,StudentID);
        }
        else
        {
            QMessageBox::information(this,"No entries added","No entries added");
        }

    if(TestNum=="3")
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
void Teacher::GetAllStudents()
{
    QSqlQuery query;
    QStringList Students;
     ui->listWidget_2->clear();
    query.exec("SELECT * FROM mydb.students;");
    while(query.next())
    {
        Allstudents.append(new Student(query.value(0).toString(),query.value(1).toString(),query.value(2).toString()));

    }
    QString line2="";
    for(int i=0;i<Allstudents.length()-1;i++)
    {
        for(int j=0;j<students.length()-1;j++)
        {

            qDebug()<<Allstudents.size();
            if(Allstudents[i]->FirstName!=students[j]->FirstName)
            {
                QString line=Allstudents[i]->FirstName+" "+Allstudents[i]->LastName;
                if(line==line2)
                {
                continue;
                }
                else
                {
                    ui->listWidget_2->addItem(line);
                    line2=line;
                }

            }
            else
                continue;
        }
    }

}
QString Student::show()
{
    QString line;
    line=this->ID+" "+this->FirstName+" "+this->LastName;
    return line;

}
void Teacher::AddStudent(QString CourseID,QString CourseName,Teacher *teach)
{

    QMessageBox::information(this,"ADDing a Student","Choose the student you wish to add");



}
void Teacher::RemoveStudent(QString CourseID, QString StudFname)
{
    QSqlQuery query;
QString line=GetStudentID(StudFname);
   query.prepare("delete from mydb.courses Where idStudents= ? and idCourses= ? ");

   query.bindValue(0,line);
   query.bindValue(1,CourseID);
   query.exec();
}
QString Teacher::FindStudent(int ID)
{
    QSqlQuery query;
    query.exec("SELECT * FROM mydb.students");
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
QStringList Teacher::ShowGrades(QString CourseID)
{
    QStringList mGrades;
    QSqlQuery query;
    QString line;
    query.exec("SELECT * FROM mydb.grades;");
    while(query.next())
    {

        if(CourseID==query.value(4).toString())
        {
QString mStudent= FindStudent(query.value(5).toInt())+" Test 1 "+query.value(0).toString()+" Test2 "+query.value(1).toString()+" Test3 "+query.value(2).toString()
        +" Avg "+query.value(3).toString();



          mGrades.append(mStudent);


        }
        else
            continue;
    }
    return mGrades;

}
QString Teacher::GetCourseID()
{

    QListWidgetItem *itm = ui->TeacherWidget->currentItem();
    QString Selected = itm->text();
    QSqlQuery query;
    QString courseID="";

    query.exec("SELECT CourseName,idCourses,idStudents,StuFName,StuLName FROM mydb.courses");
    while(query.next())
    {
        //Find course ID and students in that class
        if(query.value(0).toString()==Selected)
        {
            courseID=query.value(1).toString();
            break;
        }
    }
    return courseID;

}
void Teacher::ShowStudents(Teacher *Teach)
{
    QStringList Students;
    QSqlQuery query;
    query.exec("SELECT * FROM mydb.courses;");
    while(query.next())
    {
        if(query.value(7)==Teach->ID)
        {
            QString line=query.value(2).toString()+" "+query.value(3).toString();
            Students.append(line);
            students.append(new Student(query.value(4).toString(),query.value(2).toString(),query.value(3).toString()));
        }
    }
    ui->listWidget_2->addItems(Students);


}
void Teacher::GetClasses(Teacher *Teach)
{
    QString line,line2;

    QSqlQuery query;
    if (query.exec("SELECT * FROM mydb.courses"))
    {
      while(query.next())
      {
        if(query.value(7)==Teach->ID)
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
     ui->TeacherWidget->addItems(Classes);
     if (ui->listWidget_2->count() > 0)
             {
          ui->listWidget_2->item(0)->setSelected(true);
          ui->listWidget_2->setFocus();

     }

}
void Teacher::ShowStudentsGrades(QString StudentID, QString CourseID)
{

      ui->listWidget_2->clear();
    QSqlQuery query;
    QStringList line;
    QString grades;
    query.exec("SELECT * FROM mydb.grades;");
    while(query.next())
    {
            if(CourseID==query.value(4)&&StudentID==query.value(5))
            {
                grades=FindStudent(StudentID.toInt())+" Test1 "+query.value(0).toString()+" Test2 "+query.value(1).toString()+" Test3 "+query.value(2).toString();

                    break;
            }

    }
    line.append(grades);
        ui->listWidget_2->addItems(line);
}
void Teacher::on_pushButton_clicked()
{

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
QString Teacher::GetStudentID(QString name)
{
    QSqlQuery query;
    QString id;
    query.exec("SELECT * FROM mydb.students;");
    while(query.next())
    {
       if(query.value(1)==name)
       {
           id=query.value(0).toString();
       }
    }
    return id;

}

void Teacher::on_TeacherWidget_itemClicked(QListWidgetItem *item)
{   ui->listWidget_2->clear();
    Selected=item->text();
    if(ui->listWidget_2->count()==0)
    {
           ShowStudents(this);
    }


}

void Teacher::on_AddButton_clicked()
{
     ui->listWidget_2->clear();
    GetAllStudents();
     QListWidgetItem *itm = ui->TeacherWidget->currentItem();

     AddStudent(GetCourseID(),itm->text(),this);
     QMessageBox::information(this,"How to choose","Double check on the student you wish to add");

}

void Teacher::on_RemoveStudent_clicked()
{
    QListWidgetItem *itm = ui->listWidget_2->currentItem();
    QString selected= itm->text();
     QStringList list= selected.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    RemoveStudent(GetCourseID(),list[0]);
}

void Teacher::on_AddGrade_clicked()
{
    QListWidgetItem *itm = ui->listWidget_2->currentItem();
    if(itm==NULL)
    {
        QMessageBox::information(this,"Warning","Please Choose student");
        return;
    }
    else
    {
    QString selected= itm->text();
     QStringList list= selected.split(QRegExp("\\s+"), QString::SkipEmptyParts);
     QString id=GetCourseID();
    AddGrade(GetStudentID(list[0]),id.toInt());
    }
}

void Teacher::on_RemoveGrade_clicked()
{
   QListWidgetItem *itm = ui->listWidget_2->currentItem();
   if(itm==NULL)
   {
       QMessageBox::information(this,"Warning","Please Choose student");
       return;
   }
   else
   {
   QString mStudent=itm->text();
   QStringList list= mStudent.split(QRegExp("\\s+"), QString::SkipEmptyParts);
   QString testScore=  QInputDialog::getText(this,"Tests","Enter test Score");
  QString TestNum=  QInputDialog::getText(this,"Tests","Test Number");
  DelGrade(GetCourseID(),list[0],TestNum,testScore);
   }
}

void Teacher::on_viewGrades_clicked()
{
    QStringList Grades;
    QListWidgetItem *itm = ui->listWidget_2->currentItem();
    QListWidgetItem *Titm = ui->TeacherWidget->currentItem();
     QString selected,selected1;
    if(itm==NULL)
      {
           //QMessageBox::information(this,"Nothing has been chosen","Please make a selection");
      }
      else
        {
          selected= itm->text();
        }
    if(Titm==NULL)
    {

    }
    else
    {
        selected1= Titm->text();
    }

    ui->listWidget_2->clear();
    QStringList list= Selected.split(QRegExp("\\s+"), QString::SkipEmptyParts);
         if(Selected == "")
         {
            //No one Selected
         }
         //Everyone in the class grades will be shown
         else if(Selected==selected1)
         {
        Grades=ShowGrades(GetCourseID());
        ui->listWidget_2->addItems(Grades);
         }
         //Individual student will show grades
         else if(Selected==selected)
         {
             ShowStudentsGrades(GetStudentID(list[0]),GetCourseID());
         }

}

void Teacher::on_listWidget_2_itemClicked(QListWidgetItem *item)
{
    Selected=item->text();
}

void Teacher::on_listWidget_2_itemDoubleClicked(QListWidgetItem *item)
{

           QListWidgetItem *itm=ui->TeacherWidget->currentItem();
            QString McourseName=itm->text();
     QSqlQuery query;
  QListWidgetItem *itm2=ui->listWidget_2->currentItem();
   QString mstudent=itm2->text();
      QStringList list= mstudent.split(QRegExp("\\s+"), QString::SkipEmptyParts);
   if( QMessageBox::question(this,"Adding student","is this the student",QMessageBox::Yes,QMessageBox::No))
   {
       // Insert new student into class
           query.prepare("INSERT INTO mydb.courses(idCourses,CourseName,StuFName,StuLName,idStudents,InstrFName,InstrLName,Instructors_idInstructors)"
                     "VALUES(?,?,?,?,?,?,?,?)");


           query.bindValue(0,GetCourseID());
           query.bindValue(1,McourseName);
           query.bindValue(2,list[1]);
           query.bindValue(3,list[2]);
           query.bindValue(4,list[0]);
           query.bindValue(5,this->FirstName);
           query.bindValue(6,this->LastName);
           query.bindValue(7,this->ID);
           query.exec();
           query.prepare("Insert into mydb.courses_has_students(Courses_idCourses,Students_idStudents)"
                "VALUES(?,?)");

           query.bindValue(0,this->ID);
           query.bindValue(1,list[0]);
            query.exec();
           query.prepare("Insert into mydb.grades(Courses_has_Students_Courses_idCourses,Courses_has_Students_Students_idStudents)"
                "VALUES(?,?)");
           query.bindValue(0,this->ID);
           query.bindValue(1,list[0]);
           query.exec();
           ui->listWidget_2->clear();
   }
   else
   {
    QMessageBox::information(this,"Error","Unable to add Student");
   }

}
