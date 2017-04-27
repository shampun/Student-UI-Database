#include "teacher.h"
#include "ui_teacher.h"

Teacher::Teacher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Teacher)
{
    ui->setupUi(this);
}

Teacher::~Teacher()
{
    delete ui;
}
void Teacher::AddGrade()
{

}
void Teacher::DelGrade()
{

}
void Teacher::AddStudent()
{

}
void Teacher::RemoveStudent()
{

}
void Teacher::ShowGrades()
{

}
void Teacher::ShowStudents()
{


}
