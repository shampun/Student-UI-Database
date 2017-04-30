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

  ADDStudentbutton=ui->AddButton;
   AddGradebutton=ui->AddGrade;
   Viewgradesbutton=ui->viewGrades;
 Removestudentbutton=ui->RemoveStudent;
 RemoveGradebutton=ui->RemoveGrade;

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
   if(TestNum.toInt()>0 && TestNum.toInt()<4)
   {
       //modify each grades for a specific test
       if(TestNum=="1")
       {
       query.prepare("INSERT INTO mydb.grades(Test1,Courses_has_Students_Courses_idCourses,Courses_has_Students_Students_idStudents)VALUES(?,?,?)");
           if(query.isValid())
              {
                query.addBindValue(testScore.toInt());
                query.addBindValue(CourseID);
                query.addBindValue(StudentID);
                 query.exec();
              }
          else
            {
               if(QMessageBox::question(this,"Grade exist","Entry exist would you like to change it",QMessageBox::Yes |QMessageBox::No))
                {
                 query.prepare("update mydb.grades set Test1=? Where Courses_has_Students_Students_idStudents=?");
                query.bindValue(0,testScore.toInt());
                query.bindValue(1,StudentID);
                 query.exec();
                }
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
                query.exec();
         }
           else
            {
            if(QMessageBox::question(this,"Grade exist","Entry exist would you like to change it",QMessageBox::Yes |QMessageBox::No))
           {
               query.prepare("update mydb.grades set Test2=? Where Courses_has_Students_Students_idStudents=?");
               query.bindValue(0,testScore.toInt());
               query.bindValue(1,StudentID);
                query.exec();
           }
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
               query.exec();
          }
          else
         {
             if(QMessageBox::question(this,"Grade exist","Entry exist would you like to change it",QMessageBox::Yes |QMessageBox::No))
            {
              query.prepare("update mydb.grades set Test3=? Where Courses_has_Students_Students_idStudents=?");
              query.bindValue(0,testScore.toInt());
              query.bindValue(1,StudentID);
               query.exec();
             }

       }

        }
    query.exec();
    ui->listWidget_2->setEnabled(false);
    ui->listWidget_2->clear();
     ShowStudents(this);
     AddGradebutton->setChecked(false);
   }
   else
   {
       QMessageBox::information(this,"TestNUM","Need to enter a test number within range 1-3");

       ui->listWidget_2->setEnabled(false);
       ui->listWidget_2->clear();
        ShowStudents(this);
        AddGradebutton->setChecked(false);


   }
}
void Teacher::DelGrade(QString CourseID, QString StudentID,QString TestNum)
{
    QSqlQuery query;
    int zero=0;
    qDebug()<<StudentID;
    qDebug()<<CourseID;
    if(TestNum=="1")
    {
        query.exec("UPDATE `mydb`.`grades` SET `Test1`='0' WHERE `Courses_has_Students_Courses_idCourses`='"+CourseID+"' and`Courses_has_Students_Students_idStudents`='"+StudentID+"'");

    }


    if(TestNum=="2")
    {
      query.prepare("update grades set Test2=?, Where Courses_has_Students_Courses_idCourses=? and Courses_has_Students_Students_idStudents=?");
      if(query.isValid())
      {
            query.bindValue(0,NULL);
            query.bindValue(1,CourseID);
            query.bindValue(2,StudentID);
             query.exec();
                }
     }

    if(TestNum=="3")
    {
     query.prepare("update mydb.grades set Test3=? Where Courses_has_Students_Courses_idCourses=? and Courses_has_Students_Students_idStudents=?");
     if(query.isValid())
     {
     query.bindValue(0,NULL);
           query.bindValue(1,CourseID.toInt());
           query.bindValue(2,StudentID.toInt());
            query.exec();
      }
    }



ui->listWidget_2->setEnabled(false);
ui->listWidget_2->clear();
 ShowStudents(this);
 RemoveGradebutton->setChecked(false);

}
void Teacher::GetAllStudents()
{
    QSqlQuery query;

     ui->listWidget_2->clear();
    query.exec("SELECT * FROM mydb.students;");
    while(query.next())
    {
        Allstudents.append(new Student(query.value(0).toString(),query.value(1).toString(),query.value(2).toString()));

    }
    qDebug()<<Allstudents.size();
        for(int i=0;i<Allstudents.size()-1;i++)
        {

            qDebug()<<students.size();
            for(int j=0;j<students.size();j++)
            {
                qDebug()<<Allstudents[i]->FirstName;
                qDebug()<<students[j]->FirstName;
                if(Allstudents[i]->ID==students[j]->ID)
                {
                 Allstudents.removeOne(Allstudents[i]);
                }
            }
         }
           qDebug()<<Allstudents.size();
           QStringList allstudents;
           for(int i=0;i<Allstudents.size();i++)
           {
               allstudents.append(Allstudents[i]->FirstName+" "+Allstudents[i]->LastName);
           }
           ui->listWidget_2->clear();
        ui->listWidget_2->addItems(allstudents);

}
QString Student::show()
{
    QString line;
    line=this->ID+" "+this->FirstName+" "+this->LastName;
    return line;

}
void Teacher::AddStudent(QString CourseID, QString CourseName)
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


    query.bindValue(0,CourseID);
    query.bindValue(1,CourseName);
    query.bindValue(2,list[0]);
    query.bindValue(3,list[1]);
    query.bindValue(4,GetStudentID(list[0]));
    query.bindValue(5,this->FirstName);
    query.bindValue(6,this->LastName);
    query.bindValue(7,this->ID);
    query.exec();
    query.prepare("Insert into mydb.courses_has_students(Courses_idCourses,Students_idStudents)"
         "VALUES(?,?)");
    qDebug()<<GetStudentID(list[0]);
    query.bindValue(0,this->ID);
    query.bindValue(1,GetStudentID(list[0]));
     query.exec();
    query.prepare("Insert into mydb.grades(Courses_has_Students_Courses_idCourses,Courses_has_Students_Students_idStudents,Test1,Test2,Test3)"
         "VALUES(?,?,?,?,?)");
    query.bindValue(0,this->ID);
    query.bindValue(1,GetStudentID(list[0]));
    query.bindValue(2,"0");
    query.bindValue(3,"0");
    query.bindValue(4,"0");
    query.exec();
    ui->listWidget_2->clear();
     ui->listWidget_2->setEnabled(false);
     ShowStudents(this);
     ADDStudentbutton->setChecked(false);
}
else
{
QMessageBox::information(this,"Error","Unable to add Student");
}


}
void Teacher::RemoveStudent(QString CourseID, QString StudFname)
{
    QSqlQuery query;
QString line=GetStudentID(StudFname);
   query.prepare("delete from mydb.courses Where idStudents= ? and idCourses= ? ");

   query.bindValue(0,line);
   query.bindValue(1,CourseID);
   query.exec();
   ui->listWidget_2->setEnabled(false);
   ui->listWidget_2->clear();
   ShowStudents(this);
   Removestudentbutton->setChecked(false);
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
    query.exec("SELECT * FROM mydb.grades;");
    while(query.next())
    {
        if(query.value(4).toString()==GetCourseID())
        {
           QString line=FindStudent(query.value(5).toInt());

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
void Teacher::showAstudentgrade(QString StudentID, QString CourseID)
{

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
    RemoveGradebutton->setEnabled(true);
    AddGradebutton->setEnabled(true);
    Removestudentbutton->setEnabled(true);
    Viewgradesbutton->setEnabled(true);
    ADDStudentbutton->setEnabled(true);
    Selected=item->text();
    if(ui->listWidget_2->count()==0)
    {
           ShowStudents(this);
    }


}

void Teacher::on_AddButton_clicked()
{
    if(!ADDStudentbutton->isChecked())
    {
            RemoveGradebutton->setEnabled(true);
            AddGradebutton->setEnabled(true);
            Removestudentbutton->setEnabled(true);
            ui->listWidget_2->clear();
            Viewgradesbutton->setEnabled(true);
            ShowStudents(this);
            ui->listWidget_2->setEnabled(false);
    }
      else
    {
            RemoveGradebutton->setEnabled(false);
            Viewgradesbutton->setEnabled(false);
            AddGradebutton->setEnabled(false);
            Removestudentbutton->setEnabled(false);
            ui->listWidget_2->setEnabled(true);

     ui->listWidget_2->clear();
     GetAllStudents();
     QMessageBox::information(this,"How to choose","Double check on the student you wish to add");
    }
}

void Teacher::on_RemoveStudent_clicked()
{
    if(!Removestudentbutton->isChecked())
    {
            RemoveGradebutton->setEnabled(true);
            AddGradebutton->setEnabled(true);

            ADDStudentbutton->setEnabled(true);
            Viewgradesbutton->setEnabled(true);
            ui->listWidget_2->clear();
            ShowStudents(this);
            ui->listWidget_2->setEnabled(false);
    }
      else
    {
            RemoveGradebutton->setEnabled(false);
            Viewgradesbutton->setEnabled(false);
            AddGradebutton->setEnabled(false);

             ADDStudentbutton->setEnabled(false);
                 ui->listWidget_2->setEnabled(true);
    }
}

void Teacher::on_AddGrade_clicked()
{
    if(!AddGradebutton->isChecked())
    {
            RemoveGradebutton->setEnabled(true);
            Removestudentbutton->setEnabled(true);
            ADDStudentbutton->setEnabled(true);
            Viewgradesbutton->setEnabled(true);
            ui->listWidget_2->clear();
            ShowStudents(this);
            ui->listWidget_2->setEnabled(false);
    }
      else
    {
            RemoveGradebutton->setEnabled(false);
            Viewgradesbutton->setEnabled(false);
            Removestudentbutton->setEnabled(false);
             ADDStudentbutton->setEnabled(false);
        ui->listWidget_2->setEnabled(true);
    }
}

void Teacher::on_RemoveGrade_clicked()
{
    if(!RemoveGradebutton->isChecked())
    {

            AddGradebutton->setEnabled(true);
            Removestudentbutton->setEnabled(true);
            ADDStudentbutton->setEnabled(true);
            Viewgradesbutton->setEnabled(true);
            ui->listWidget_2->clear();
            ShowStudents(this);
            ui->listWidget_2->setEnabled(false);
    }
      else
    {
            Viewgradesbutton->setEnabled(false);
            AddGradebutton->setEnabled(false);
            Removestudentbutton->setEnabled(false);
             ADDStudentbutton->setEnabled(false);
            ui->listWidget_2->setEnabled(true);
    }

}

void Teacher::on_viewGrades_clicked()
{
    if(!Viewgradesbutton->isChecked())
    {
        AddGradebutton->setEnabled(true);
        Removestudentbutton->setEnabled(true);
        RemoveGradebutton->setEnabled(true);
        ADDStudentbutton->setEnabled(true);
        ui->listWidget_2->setEnabled(false);
        ui->listWidget_2->clear();
        ShowStudents(this);
    }
    else
    {
    AddGradebutton->setEnabled(false);
    ADDStudentbutton->setEnabled(false);
    Removestudentbutton->setEnabled(false);
    RemoveGradebutton->setEnabled(false);
    ui->listWidget_2->setEnabled(true);
    QStringList Grades;
    QListWidgetItem *itm = ui->listWidget_2->currentItem();
    QListWidgetItem *Titm = ui->TeacherWidget->currentItem();
     QString selected,selected1;

    ui->listWidget_2->clear();
        selected=Titm->text();
 Grades=  ShowGrades(GetCourseID());
  ui->listWidget_2->addItems(Grades);
    }


}

void Teacher::on_listWidget_2_itemClicked(QListWidgetItem *item)
{
    Selected=item->text();

}

void Teacher::on_listWidget_2_itemDoubleClicked(QListWidgetItem *item)
{
         if(ADDStudentbutton->isChecked())
         {
             QListWidgetItem *itm = ui->TeacherWidget->currentItem();
             QString Selected = itm->text();
             ui->listWidget_2->setEnabled(true);

             AddStudent(GetCourseID(),Selected);
             RemoveGradebutton->setEnabled(true);
             AddGradebutton->setEnabled(true);
             Removestudentbutton->setEnabled(true);
             Viewgradesbutton->setEnabled(true);

         }
         if(AddGradebutton->isChecked())
         {
              QListWidgetItem *itm = ui->listWidget_2->currentItem();
             QString selected= itm->text();
              QStringList list= selected.split(QRegExp("\\s+"), QString::SkipEmptyParts);
              QString id=GetCourseID();
             AddGrade(GetStudentID(list[0]),id.toInt());
             RemoveGradebutton->setEnabled(true);
             Removestudentbutton->setEnabled(true);
              ADDStudentbutton->setEnabled(true);
             Viewgradesbutton->setEnabled(true);
         }
         if(RemoveGradebutton->isChecked())
         {
            QListWidgetItem *itm = ui->listWidget_2->currentItem();
            QString selected= itm->text();
            QStringList list=selected.split(QRegExp("\\s+"), QString::SkipEmptyParts);

           QString TestNum=  QInputDialog::getText(this,"Tests","Test Number");
           if(TestNum.toInt()>0 && TestNum.toInt()<4)
              {
           DelGrade(GetCourseID(),GetStudentID(list[0]),TestNum);
           Removestudentbutton->setEnabled(true);
           AddGradebutton->setEnabled(true);

            ADDStudentbutton->setEnabled(true);
           Viewgradesbutton->setEnabled(true);
           }
           else
           {
               QMessageBox::information(this,"Testnumber","Enter a test number between 1-3");
           }
         }
         if(Viewgradesbutton->isChecked())
         {
             QListWidgetItem *itm = ui->listWidget_2->currentItem();
             QString selected= itm->text();
             QStringList list= selected.split(QRegExp("\\s+"), QString::SkipEmptyParts);

             ShowStudentsGrades(GetStudentID(list[0]),GetCourseID());
             RemoveGradebutton->setEnabled(true);
             AddGradebutton->setEnabled(true);
             Removestudentbutton->setEnabled(true);
             ADDStudentbutton->setEnabled(true);

         }
         if(Removestudentbutton->isChecked())
         {
             QListWidgetItem *itm = ui->listWidget_2->currentItem();
             QString selected= itm->text();
              QStringList list= selected.split(QRegExp("\\s+"), QString::SkipEmptyParts);
             RemoveStudent(GetCourseID(),list[0]);
             RemoveGradebutton->setEnabled(true);
             AddGradebutton->setEnabled(true);
             ADDStudentbutton->setEnabled(true);
             Viewgradesbutton->setEnabled(true);

         }




}
