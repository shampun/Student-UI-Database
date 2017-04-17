#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
namespace Ui {
class MyWindow;
}

class MyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyWindow(QWidget *parent = 0);
    void buildList();
    QString finduser(QString Password);
    void Listchoice();
  QPushButton *ADDbutton;
  QPushButton *Delbutton;
    QPushButton *Updatebutton;
 QPushButton *Studentbutton;
 QPushButton *Gradebutton;
 QPushButton *Classesbutton;

    ~MyWindow();

private slots:
    void on_pushButton_clicked();

    void on_logout_button_clicked();

    void on_logout_button_2_clicked();

    void on_logout_button_3_clicked();

    void on_class_button_clicked();

    void on_studen_button_2_clicked();

    void on_grades_button_2_clicked();



    void on_Add_button_clicked();

    void on_Del_clicked();

    void on_Update_clicked();

    void on_Bclasses_clicked();

private:
    Ui::MyWindow *ui;
};

#endif // MYWINDOW_H
