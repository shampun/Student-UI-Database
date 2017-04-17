#include "mywindow.h"
#include "ui_mywindow.h"
#include "teacher.h"
#include "user.h"
#include <QApplication>
#include <QMessageBox>
#include <QtSql/QtSql>
#include <Qtsql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QSqlDriver>
#include <QPushButton>
#include <QInputDialog>

Teacher *mUser;

QString user="";
 int StudentID;
QString courseID="";
QString CourseName="";
bool bclasses=true;



//QList AdminStorage= new QList<QString,QString>();

MyWindow::MyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyWindow)
{
    ui->setupUi(this);
     QObject::connect(ui->listWidget_2,SIGNAL(doubleClicked(QListWidgetItem*)),this,SLOT(ListChoice()));
    ADDbutton=ui->Add_button;
    Delbutton=ui->Del;
    Updatebutton=ui->Update;
    Studentbutton=ui->studen_button_2;
    Classesbutton=ui->Bclasses;
    Gradebutton=ui->grades_button_2;

    // Sets which "stackwidget" page to start on when program starts
    ui->stackedWidget->setCurrentIndex(0);
}

MyWindow::~MyWindow()
{
    delete ui;
}


// LOGIN PAGE
void MyWindow::on_pushButton_clicked()
{
    bool accepted=false;
    int pageIndex=0;
    // Define strings to rep user/pw
//    QString  username = ui->usernameLE->text();
//    QString  password = ui->passwordLE->text();

    QString  username = "cmartinez0";
    QString  password = "z8r2Py";

    if(username!=NULL || password!=NULL)
    {
    //Checking Passwords
    QSqlQuery query;
    query.exec("SELECT * FROM mydb.instructors");
    while(query.next())
    {
         qDebug ()<<query.value(0).toString()+" "+query.value(1).toString()+" "+query.value(2).toString();
        if(query.value(3).toString()==username && query.value(4).toString()==password)
        {
            QString line = query.value(0).toString();
            user=line;

       mUser= new Teacher(query.value(0).toString(),query.value(1).toString(),query.value(2).toString());
          accepted=true;
        pageIndex=2;
            break;
        }

    }
    qDebug()<<mUser->FirstName;
      qDebug()<<mUser->ID;
      qDebug()<<mUser->LastName;
    query.exec("SELECT * FROM mydb.students");
    while(query.next())
    {

        if(query.value(3).toString()==username && query.value(4).toString()==password)
        {
            QString line = query.value(0).toString();
            user=line;
              accepted=true;
               pageIndex=2;
            break;
        }
    }
    query.exec("SELECT * FROM mydb.admins");
    while(query.next())
    {
        if(query.value(3).toString()==username && query.value(4).toString()==password)
        {
            QString line = query.value(0).toString();
            user=line;
              accepted=true;
               pageIndex=4;
            break;
        }


    }

    if(!accepted)
    {
        qDebug("Username and Password not found");

    }
     else
        {
                 ui->stackedWidget->setCurrentIndex(pageIndex);
        }
    }
    else
    {

         qDebug("Username and Password not found");
    }

}



// STUDENT PAGE
void MyWindow::on_logout_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//Teacher Page
void MyWindow::on_logout_button_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//Admin Page
void MyWindow::on_logout_button_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MyWindow::on_class_button_clicked()
{


    QSqlQuery query;
    query.exec("SELECT CourseName,StuFName,StuLName,InstrFName FROM mydb.courses");
    while(query.next())
    {

       QString line = query.value(0).toString() + query.value(1).toString()
                     + query.value(2).toString() + query.value(3).toString();
      //  ui ->listWidget_2->addItem(line);
    }

   // ui ->listWidget->addItem(QString::number(1));
}



QString MyWindow::finduser(QString Password)
{
    QSqlQuery query;
    query.exec("SELECT InstrLName,InstrPassW FROM mydb.instructors");
    while(query.next())
    {
        if(query.value(1).toString()==Password)
        {
            return query.value(0).toString();
        }

    }
    query.exec("SELECT StuLName,StuPassW From mydb.students");
    while(query.next())
    {
        if(query.value(1).toString()==Password)
        {
           return query.value(0).toString();
        }

    }
    return NULL;


}


void MyWindow::on_studen_button_2_clicked()
{
        QPalette* palette1 = new QPalette();
        palette1->setColor(QPalette::Button,Qt::green);

        QPalette* palette3 = new QPalette();
        palette3->setColor(QPalette::Button,Qt::gray);

if(Classesbutton->isChecked()&& Studentbutton->isChecked())
        {
            QListWidgetItem *itm = ui->listWidget_2->currentItem();
            QString Selected = itm->text();
            ui->listWidget_2->clear();
            QSqlQuery query;
            query.exec("SELECT idCourses,CourseName,StuFName,StuLName FROM mydb.courses");
            while(query.next())
            {
                if(query.value(1).toString()==Selected)
                {
                    QString line = query.value(2).toString()+" "+query.value(3).toString();
                     ui ->listWidget_2->addItem(line);
                     if (ui->listWidget_2->count() > 0) {
                       ui->listWidget_2->item(0)->setSelected(true);
                       ui->listWidget_2->setFocus();
                     }
                }
                else
                    continue;

            }
            ADDbutton->setEnabled(false);
            Delbutton->setEnabled(false);
            Gradebutton->setEnabled(true);
            Updatebutton->setEnabled(false);



}
 if( !Classesbutton->isChecked() && Studentbutton->isChecked())
    {
    ui->listWidget_2->clear();
        ADDbutton->setEnabled(true);
        Delbutton->setEnabled(true);
        Updatebutton->setEnabled(true);
        Studentbutton->setChecked(true);
        QSqlQuery query;
        query.exec("SELECT StuFName,StuLName,InstrLName FROM mydb.courses");
        while(query.next())
        {

        if(mUser->LastName==query.value(2).toString())//Identify Teacher
            {
           QString line = query.value(0).toString()+query.value(1).toString();
            ui ->listWidget_2->addItem(line);
            }
        }
        if (ui->listWidget_2->count() > 0) {
          ui->listWidget_2->item(0)->setSelected(true);
        }

        Studentbutton->setPalette(*palette3);
        ADDbutton->setEnabled(false);
        Delbutton->setEnabled(false);
        Gradebutton->setEnabled(true);
        Updatebutton->setEnabled(false);


    }

 if(!Studentbutton->isChecked()&& !Classesbutton->isChecked())
 {
    ui->listWidget_2->clear();
    ADDbutton->setEnabled(false);
    Delbutton->setEnabled(false);
    Gradebutton->setEnabled(false);
    Updatebutton->setEnabled(false);

 }


   if(!Studentbutton->isChecked()&& Classesbutton->isChecked())
    {
        ui ->listWidget_2->clear();
        QString line2=NULL;
        QSqlQuery query;
        query.exec("SELECT CourseName,InstrLName FROM mydb.courses;");
        while(query.next())
        {
           if(mUser->LastName==query.value(1).toString())//Identify Teacher
            {
            QString line = query.value(0).toString();
              if(line2==line)
             {
                 continue;
             }
             else
            {
                ui ->listWidget_2->addItem(line);
                line2=line;
            }

            }
        }

        if (ui->listWidget_2->count() > 0)
                {
             ui->listWidget_2->item(0)->setSelected(true);
             ui->listWidget_2->setFocus();
      }
        ADDbutton->setEnabled(true);
        Delbutton->setEnabled(true);
        Updatebutton->setEnabled(false);
        Studentbutton->setChecked(false);
        Studentbutton->setPalette(*palette1);



    }


}

void MyWindow::on_grades_button_2_clicked()
{

 QList<Student *> students;


    if(!Studentbutton->isChecked() && Classesbutton->isChecked())
    {
        ADDbutton->setText("AddGrades");
        Delbutton->setText("RemoveGrade");
             QListWidgetItem *itm = ui->listWidget_2->currentItem();
            if(itm==NULL)
             {
                    qDebug("Please choose a class");
                }
             else
             {
        //View Grades of everyone in the highlighted course
                QString Selected = itm->text();
                ui->listWidget_2->clear();
                QSqlQuery query;

                query.exec("SELECT CourseName,idCourses,idStudents,StuFName,StuLName FROM mydb.courses");
                while(query.next())
                {
                    //Find course ID and students in that class
                    if(query.value(0).toString()==Selected)
                    {
                        courseID=query.value(1).toString();
                        students.append(new Student(query.value(2).toString(),query.value(3).toString(),query.value(4).toString()));
                    }


                 }
                //grab grades for each student
                query.exec("SELECT * FROM mydb.grades");
                while(query.next())
                {
                    for(int i=0;i<students.size();i++)
                    {
                        if(query.value(3).toString()==students[i]->ID)
                        {
                            QString line=students[i]->FirstName+" "+students[i]->LastName+" "+query.value(0).toString()+" "+query.value(1).toString();
                            ui->listWidget_2->addItem(line);
                        }
                    }
                 }


                }
    }
    //View Grades of a Specific Student highlighted in the list
    if(Studentbutton->isChecked() && Classesbutton->isChecked())
    {
        ADDbutton->setText("AddStudent");
        Delbutton->setText("RemoveStudent");
        QListWidgetItem *itm = ui->listWidget_2->currentItem();
        if(itm==NULL)
        {
            qDebug("Please choose student");
        }
        else
        {
            QString Selected = itm->text();
           QStringList list= Selected.split(QRegExp("\\s+"), QString::SkipEmptyParts);
            QSqlQuery query;

            query.exec("SELECT idStudents,StuFName,StuLName,CourseName,InstrLName FROM mydb.courses");
            while(query.next())
            {
                if(query.value(1).toString()==list[0])
                {
                    StudentID=query.value(0).toInt();
                    qDebug()<<"This works";
                    break;
                }
              }
            ui->listWidget_2->clear();
         query.exec("SELECT TestNum,Score,Courses_has_Students_Students_idStudents FROM mydb.grades");
         {
            while(query.next())
            {
                QString str;
                if(query.value(2).toString()==str.setNum(StudentID))
                {
                    QString line ="Test"+ query.value(0).toString()+"  "+query.value(1).toString();
                     ui ->listWidget_2->addItem(line);
                }
            }

         }
        }
    }
    if(!Gradebutton->isChecked())
    {
        ADDbutton->setText("AddStudent");
        Delbutton->setText("RemoveStudent");
        qDebug()<<courseID;
        ui->listWidget_2->clear();
        ui->listWidget_2->addItem(CourseName);
        Studentbutton->setChecked(false);

    }
    if (ui->listWidget_2->count() > 0)
            {
         ui->listWidget_2->item(0)->setSelected(true);
         ui->listWidget_2->setFocus();
  }
    if(Classesbutton->isChecked()&&Studentbutton->isChecked() && Gradebutton->isChecked())
    {
       ADDbutton->setEnabled(true);
       Delbutton->setEnabled(true);
       ADDbutton->setText("AddGrades");
       Delbutton->setText("RemoveGrade");
    }

}

void MyWindow::on_Add_button_clicked()
{

    QSqlQuery query;
    int newID=0;
    //Add Student to database
if(Classesbutton->isChecked()&&!Studentbutton->isChecked())
{
  QString Fname=  QInputDialog::getText(this,"Create Student","FirstName");
  QString Lname=  QInputDialog::getText(this,"Create Student","LastName");
    query.exec("Select idStudents From mydb.students");
    for(int i=1;i<50;i++)
    {
         while(query.next())
        {

            QString str= QString::number(i);
            qDebug()<<query.value(0).toString();
            if(query.value(0).toString()!=str)
            {
                newID=i;
                break;
            }
            break;
        }

    }


    query.prepare("INSERT INTO mydb.students(idStudents,StuFName,StuLName)"
              "VALUES(?,?,?)");
    query.bindValue(0,newID);
    query.bindValue(1,Fname);
    query.bindValue(2,Lname);
    query.exec();
}
    //Add grade to student
     if(Classesbutton->isChecked()&&Studentbutton->isChecked() && Gradebutton->isChecked())
     {
         QString testScore=  QInputDialog::getText(this,"Tests","Enter test Score");
         QString TestNum=  QInputDialog::getText(this,"Tests","Test Number");

         query.prepare("INSERT INTO mydb.grades(TestNum,Score,Courses_has_Students_Courses_idCourses,Courses_has_Students_Students_idStudents)VALUES(?,?,?,?)");
                 qDebug()<<TestNum.toInt();
         qDebug()<<testScore.toInt();
        qDebug()<<courseID.toInt();
          qDebug()<<StudentID;
         query.addBindValue(TestNum.toInt());
         query.addBindValue(testScore.toInt());
         query.addBindValue(courseID.toInt());
         query.addBindValue(StudentID);
         query.exec();


     }
}

void MyWindow::on_Del_clicked()
{

}

void MyWindow::on_Update_clicked()
{

}
void MyWindow::Listchoice()
{

}

void MyWindow::on_Bclasses_clicked()
{

     if(Classesbutton->isChecked())
    {
    Studentbutton->setChecked(false);
    ui ->listWidget_2->clear();
    QString line2=NULL;
    QSqlQuery query;
    query.exec("SELECT idCourses, CourseName,InstrLName FROM mydb.courses;");
    while(query.next())
    {

        if(mUser->LastName==query.value(2).toString())//Identify Teacher
        {
            QString line = query.value(1).toString();
            courseID=query.value(0).toString();
            CourseName=line;
              if(line2==line)
             {
                 continue;
             }
             else
            {
                ui ->listWidget_2->addItem(line);
                line2=line;
            }

        }
    }

        if (ui->listWidget_2->count() > 0)
                {
             ui->listWidget_2->item(0)->setSelected(true);
             ui->listWidget_2->setFocus();

        }

    ADDbutton->setEnabled(true);
    Delbutton->setEnabled(true);
    ADDbutton->setText(QString("ADDSTUDENT"));
    Delbutton->setText("DeleteSTUDENT");
    Gradebutton->setEnabled(true);

    }
    else
    {
         ui ->listWidget_2->clear();
        Studentbutton->setChecked(false);
        ADDbutton->setEnabled(false);
        Delbutton->setEnabled(false);
        Gradebutton->setEnabled(false);

    }
}
