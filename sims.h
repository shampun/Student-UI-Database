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
    ~SIMS();
    QString id, usr, pwd, fname, lname, courseID, test1G, test2G, test3G, avg;
    QString GPA = "Not Available";


private slots:
    void on_StudLoginBtn_clicked();

    void on_pushButton_clicked();

    void on_InfoBackButn_clicked();

    void on_StudInfoButn_clicked();

    void getClass();

    void on_listWidget_itemClicked( QListWidgetItem *item);

private:
    Ui::SIMS *ui;




};

#endif // SIMS_H
