#ifndef TEACHER_H
#define TEACHER_H

#include <QMainWindow>

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

    void AddStudent();
    void RemoveStudent();
    void DelGrade();
    void AddGrade();
    void ShowStudents();
    void ShowGrades();
    void GetClasses(QString);
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
