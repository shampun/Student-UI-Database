#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include "mywindow.h"
#include <QApplication>
#include <QtSql/QtSql>
#include <Qtsql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QSqlDriver>
#include <QRegExp>
#include <QDialog>
#include <QVariant>




namespace Ui {
class Admin;
}

class Admin : public QMainWindow
{
    Q_OBJECT

public:

    //Define Filter
    QSortFilterProxyModel *proxyModel= new QSortFilterProxyModel(this);
    QSortFilterProxyModel *CourseProxy= new QSortFilterProxyModel(this);
    QSortFilterProxyModel *Cstudent= new QSortFilterProxyModel(this);
    QSortFilterProxyModel *Cteacher= new QSortFilterProxyModel(this);
    QSqlTableModel *model;
    QSqlTableModel *CourseModel;
    int Tcheck = 0;

    explicit Admin(QWidget *parent = 0);
    ~Admin();

private slots:


    void on_ViewTeachers_clicked();

    void on_ViewStudents_clicked();

    void on_searchedit_textChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_9_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();



    void on_stview_activated(const QModelIndex &index);

    void on_tview_activated(const QModelIndex &index);

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Admin *ui;
    void UpdateStudent();
    void UpdateTeacher();
    void Add_Instructor();
    void Add_Students();
    void RegisterNewClass();
    void BuildCourseStudent();
    void BuildCourseTeacher();
    void BuildCourseView();
    void BuildTeacherView();
    void BuildStudentView();

};

#endif // ADMIN_H
