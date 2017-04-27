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
    explicit Teacher(QWidget *parent = 0);
    ~Teacher();

private:
    Ui::Teacher *ui;

    void AddStudent();
    void RemoveStudent();
    void DelGrade();
    void AddGrade();
    void ShowStudents();
    void ShowGrades();

};

#endif // TEACHER_H
