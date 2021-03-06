#ifndef TEACHER_H
#define TEACHER_H
#include <qlist.h>
#include <QMainWindow>
#include <QList>
#include <QString>
#include <QListWidgetItem>
#include <QListWidget>
#include <qpushbutton.h>
#include <loginwindow.h>

using namespace std;


namespace Ui {
class Teacher;
}

class Teacher : public QMainWindow
{
    Q_OBJECT

public:
    QString ID;
    QString FirstName;
    QString LastName;
    Loginwindow *Login=new Loginwindow;



   explicit Teacher(QString mID,QString mFirstName,QString mLastName,QWidget *parent = 0);
//    {

//        ID=mID;
//        FirstName=mFirstName;
//        LastName=mLastName;


//    }
    explicit Teacher(QWidget *parent = 0);
    ~Teacher();

    void AddStudent(QString CourseID, QString CourseName);
    void RemoveStudent(QString CourseID, QString StudFname);
    void GetAllStudents();
    void DelGrade(QString CourseID, QString StudentID, QString TestNum);
    void AddGrade(QString StudentID,int CourseID);
    void ShowStudents(Teacher *Teach);
    void ShowStudentsGrades(QString StudentID, QString CourseID);
    void showAstudentgrade(QString StudentID,QString CourseID);
    QString GetCourseID();
    QStringList ShowGrades(QString CourseID);
    void GetClasses(Teacher *Teach);
    QString FindStudent(int ID);
    QString GetStudentID(QString name);
    QPushButton *ADDStudentbutton;
    QPushButton *AddGradebutton;
    QPushButton *Viewgradesbutton;
   QPushButton *Removestudentbutton;
   QPushButton *RemoveGradebutton;




private slots:
    void on_pushButton_clicked();



    void on_TeacherWidget_itemClicked(QListWidgetItem *item);

    void on_AddButton_clicked();

    void on_RemoveStudent_clicked();

    void on_AddGrade_clicked();

    void on_RemoveGrade_clicked();

    void on_viewGrades_clicked();

    void on_listWidget_2_itemClicked(QListWidgetItem *item);

    void on_listWidget_2_itemDoubleClicked(QListWidgetItem *item);

    void on_Logoutbutton_clicked();

private:
 Ui::Teacher *ui;


};
class Student
{
    public:
    QString ID;
    QString FirstName;
    QString LastName;
        Student()
        {

            ID="";
            FirstName="";
            LastName="";

        }
        Student(QString mID, QString FName, QString LName)
        {
            ID=mID;
            FirstName=FName;
            LastName=LName;
        }
        QString show();
    ~Student();

};



#endif // TEACHER_H
