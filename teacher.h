#ifndef TEACHER_H
#define TEACHER_H

#include "user.h"
#include<QString>

using namespace std;

class Teacher : public User
{
public:
    Teacher():User()
    {

       ID="";
       FirstName="";
       LastName="";

    }
    ~Teacher();

    Teacher(QString mID, QString FName, QString LName) : User()
    {
        ID=mID;
        FirstName=FName;
        LastName=LName;
    }


    void ADDStudent();
    void DELStudent();
    void ADDGrade();
    void DELGrade();
    void ViewClasses();

};
class Student : public User
{
public:
    Student(): User()
    {

        ID="";
        FirstName="";
        LastName="";

    }
    Student(QString mID, QString FName, QString LName) : User()
    {
        ID=mID;
        FirstName=FName;
        LastName=LName;
    }
~Student();











};

#endif // TEACHER_H
