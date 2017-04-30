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
#include <QListWidgetItem>
#include <QListWidget>




namespace Ui {
class Admin;
}

class Admin : public QMainWindow
{
    Q_OBJECT

public:

    //Define Filter
    QSortFilterProxyModel *proxyModel= new QSortFilterProxyModel(this);
    QSortFilterProxyModel *proxy_Model= new QSortFilterProxyModel(this);
    QSortFilterProxyModel *CourseProxy= new QSortFilterProxyModel(this);
    QSortFilterProxyModel *Cstudent= new QSortFilterProxyModel(this);
    QSortFilterProxyModel *Cteacher= new QSortFilterProxyModel(this);
    QSqlTableModel *model;
    QSqlTableModel *CourseModel;
    QString ssname, sslast, ssid,ssusr, sspwd, ssgpa;
    int Tcheck = 0;

    explicit Admin(QWidget *parent = 0);
    ~Admin();

private slots:


    void on_ViewTeachers_clicked();

    void on_ViewStudents_clicked();

    void on_searchedit_textChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_9_clicked();

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

    void on_courseView_activated(const QModelIndex &index);

    void on_searchedit_2_textChanged(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_pushButton_22_clicked();

    void on_remInstructor_clicked();

    void on_CourseView_2_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_searchedit_4_textChanged(const QString &arg1);

    void on_comboBox_4_currentIndexChanged(int index);

    void on_searchedit_3_textChanged(const QString &arg1);

    void on_comboBox_3_currentIndexChanged(int index);

    void on_searchedit_5_textChanged(const QString &arg1);

    void on_pushButton_10_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_StudInfoButn_clicked();

    void on_pushButton_12_clicked();

    void on_InfoBackButn_clicked();

    void on_logout_button_6_clicked();

private:
    Ui::Admin *ui;
    void DeleteCourse();
    void LoadCourseInfo();
    void DeleteStudents();
    void DeleteInstructor();
    void UpdateStudent();
    void UpdateTeacher();
    void Add_Instructor();
    void Add_Students();
    void RegisterNewClass();
    void RegisterNewClass2();
    void RegisterNewClass3();
    void BuildCourseStudent();
    void BuildCourseTeacher();
    void BuildCourseView();
    void BuildTeacherView();
    void BuildStudentView();

};

#endif // ADMIN_H
