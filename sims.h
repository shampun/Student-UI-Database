#ifndef SIMS_H
#define SIMS_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtSql/QtSql>
#include <Qtsql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QListWidgetItem>
#include <QListWidget>
#include <iostream>
using namespace std;

namespace Ui {
class SIMS;
}

class SIMS : public QMainWindow
{
    Q_OBJECT

public:
    explicit SIMS(QWidget *parent = 0);
      explicit SIMS(QString mID, QString mFirstName, QString mLastName, QString mGPA, QWidget *parent = 0);
    ~SIMS();
    QString GPA, usr, pwd, fname, lname, courseID, test1G, test2G, test3G, avg;
    QString id = "Not Available";
   Loginwindow *Log= new Loginwindow;

    void getClass();

private slots:


    void on_pushButton_clicked();

    void on_InfoBackButn_clicked();

    void on_StudInfoButn_clicked();


    void on_listWidget_itemClicked( QListWidgetItem *item);

    void on_StudLoginBtn_clicked();

private:
    Ui::SIMS *ui;




};

#endif // SIMS_H
