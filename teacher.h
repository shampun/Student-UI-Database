#ifndef TEACHER_H
#define TEACHER_H
#include <qlist.h>
#include <QMainWindow>
#include <QList>
#include <QListWidgetItem>
#include <QListWidget>
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


    Teacher(QString mID,QString mFirstName,QString mLastName)
    {
        ID=mID;
        FirstName=mFirstName;
        LastName=mLastName;

    }
    explicit Teacher(QWidget *parent = 0);
    ~Teacher();

    void AddStudent(QString CourseID,QString CourseName,Teacher teach);
    void RemoveStudent(QString CourseID, QString StudFname);
    void DelGrade(QString CourseID, QString StudentID, QString Testnum);
    void AddGrade(QString StudentID,int CourseID);
    QStringList ShowStudents(QString CourseName);
    QStringList ShowGrades(QString CourseID, Teacher teach);
    QStringList GetClasses(QString ID);
    QString FindStudent(int ID);
private slots:
    void on_pushButton_clicked();

    void on_classes_clicked();

    void on_Mclasses_clicked();

    void on_TeachWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_2_clicked();

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
    ~Student();

};



#endif // TEACHER_H
