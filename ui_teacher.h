/********************************************************************************
** Form generated from reading UI file 'teacher.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHER_H
#define UI_TEACHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Teacher
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QListWidget *listWidget_2;
    QPushButton *AddButton;
    QPushButton *RemoveStudent;
    QPushButton *AddGrade;
    QPushButton *RemoveGrade;
    QLabel *label_3;
    QPushButton *viewGrades;
    QWidget *page_2;
    QLabel *label_2;
    QLabel *Classeslbl;
    QListWidget *TeacherWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Teacher)
    {
        if (Teacher->objectName().isEmpty())
            Teacher->setObjectName(QStringLiteral("Teacher"));
        Teacher->resize(800, 600);
        centralwidget = new QWidget(Teacher);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(40, 120, 711, 471));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        listWidget_2 = new QListWidget(page);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(5, 100, 651, 192));
        AddButton = new QPushButton(page);
        AddButton->setObjectName(QStringLiteral("AddButton"));
        AddButton->setGeometry(QRect(80, 370, 93, 28));
        RemoveStudent = new QPushButton(page);
        RemoveStudent->setObjectName(QStringLiteral("RemoveStudent"));
        RemoveStudent->setGeometry(QRect(200, 370, 93, 28));
        AddGrade = new QPushButton(page);
        AddGrade->setObjectName(QStringLiteral("AddGrade"));
        AddGrade->setGeometry(QRect(340, 370, 93, 28));
        RemoveGrade = new QPushButton(page);
        RemoveGrade->setObjectName(QStringLiteral("RemoveGrade"));
        RemoveGrade->setGeometry(QRect(500, 370, 93, 28));
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(270, 80, 55, 16));
        viewGrades = new QPushButton(page);
        viewGrades->setObjectName(QStringLiteral("viewGrades"));
        viewGrades->setGeometry(QRect(500, 300, 93, 28));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(320, 20, 121, 16));
        Classeslbl = new QLabel(centralwidget);
        Classeslbl->setObjectName(QStringLiteral("Classeslbl"));
        Classeslbl->setGeometry(QRect(70, 20, 55, 16));
        TeacherWidget = new QListWidget(centralwidget);
        TeacherWidget->setObjectName(QStringLiteral("TeacherWidget"));
        TeacherWidget->setGeometry(QRect(50, 70, 301, 121));
        Teacher->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Teacher);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Teacher->setMenuBar(menubar);
        statusbar = new QStatusBar(Teacher);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Teacher->setStatusBar(statusbar);

        retranslateUi(Teacher);

        QMetaObject::connectSlotsByName(Teacher);
    } // setupUi

    void retranslateUi(QMainWindow *Teacher)
    {
        Teacher->setWindowTitle(QApplication::translate("Teacher", "MainWindow", Q_NULLPTR));
        AddButton->setText(QApplication::translate("Teacher", "AddStudent", Q_NULLPTR));
        RemoveStudent->setText(QApplication::translate("Teacher", "RemoveStudent", Q_NULLPTR));
        AddGrade->setText(QApplication::translate("Teacher", "AddGrade", Q_NULLPTR));
        RemoveGrade->setText(QApplication::translate("Teacher", "RemoveGrade", Q_NULLPTR));
        label_3->setText(QApplication::translate("Teacher", "Students", Q_NULLPTR));
        viewGrades->setText(QApplication::translate("Teacher", "View Grades", Q_NULLPTR));
        label_2->setText(QApplication::translate("Teacher", "Teacher Page", Q_NULLPTR));
        Classeslbl->setText(QApplication::translate("Teacher", "Classes", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Teacher: public Ui_Teacher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHER_H
