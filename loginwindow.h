#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <Qtsql/QSqlDatabase>
#include <Qtsql/QSqlQuery>
#include <QtSql/QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlDriver>

namespace Ui {
class loginWindow;
}

class loginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = 0);
    ~loginWindow();

private slots:
    void on_loginbutton_clicked();

    void on_logoutbutton_clicked();

    void on_Gradesbutton_clicked();

    void on_GPAbutton_clicked();

    void on_infobutton_clicked();

    void on_backbutton_clicked();

    void on_backbutton_2_clicked();

    void on_backbutton_3_clicked();

    void on_StudentButton_clicked();

    void on_InstructorButton_clicked();

    void on_InstrLoginButton_clicked();

    void on_logoutbutton_2_clicked();

    void on_StudEditInfoButn_clicked();

    void on_StudSaveButn_clicked();

    void on_backbutton_7_clicked();

    void on_StudCourse1TestGradesButn_clicked();

    void on_StudCourse2TestGradeButn_clicked();

    void on_StudCourse3TestGradeButn_clicked();

    void on_course1button_clicked();

    void on_course2button_clicked();

    void on_course3button_clicked();

    void on_backbutton_6_clicked();

    void on_backbutton_5_clicked();

    void on_backbutton_4_clicked();

    void on_course1button_2_clicked();

    void on_course2button_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::loginWindow *ui;
    QSqlDatabase db;
};

#endif // LOGINWINDOW_H
