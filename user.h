#ifndef USER_H
#define USER_H


#include<QString>

class User
{
public:
    QString LastName;
    QString FirstnName;
    QString ID;
    User()
    {
        LastName="";
        FirstnName="";
        ID="";

    }
~User();

    QString getID();
};

#endif // USER_H
