#ifndef TEACHER_H
#define TEACHER_H

#include "user.h"
#include<QString>

class Teacher : public User
{
public:
    Teacher():User()
    {
        User();
       ID="";
       FirstName="";
       LastName="";

    }
    ~Teacher();

    Teacher(QString mID, QString FName, QString LName);

    void ADDStudent();
    void DELStudent();
    void ADDGrade();
    void DELGrade();
    void ViewClasses();

};

#endif // TEACHER_H
