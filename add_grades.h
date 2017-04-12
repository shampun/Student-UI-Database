#ifndef ADD_GRADES_H
#define ADD_GRADES_H

#include <QDialog>

namespace Ui {
class Add_Grades;
}

class Add_Grades : public QDialog
{
    Q_OBJECT

public:
    explicit Add_Grades(QWidget *parent = 0);
    ~Add_Grades();

private slots:
    void on_addgrades_button_clicked();

private:
    Ui::Add_Grades *ui;
};

#endif // ADD_GRADES_H
