#ifndef USER_H
#define USER_H

#include "mywindow.h"
#include "ui_mywindow.h"
#include<QString>

using namespace std;


class User
{
public:
    QString LastName;
    QString FirstName;
    QString ID;
    User()
    {
        LastName="";
        FirstName="";
        ID="";

    }

    ~User();



    QString getID();
};

#endif // USER_H
