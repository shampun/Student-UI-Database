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
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label;
    QLabel *label_3;
    QWidget *page_2;
    QLabel *label_2;
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
        stackedWidget->setGeometry(QRect(40, 80, 711, 471));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        listWidget = new QListWidget(page);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(50, 100, 256, 192));
        listWidget_2 = new QListWidget(page);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(400, 100, 256, 192));
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 370, 93, 28));
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 370, 93, 28));
        pushButton_3 = new QPushButton(page);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(340, 370, 93, 28));
        pushButton_4 = new QPushButton(page);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(500, 360, 93, 28));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 50, 55, 16));
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(510, 50, 55, 16));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(320, 20, 121, 16));
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
        pushButton->setText(QApplication::translate("Teacher", "AddStudent", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Teacher", "RemoveStudent", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Teacher", "AddGrade", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Teacher", "RemoveGrade", Q_NULLPTR));
        label->setText(QApplication::translate("Teacher", "Classes", Q_NULLPTR));
        label_3->setText(QApplication::translate("Teacher", "Students", Q_NULLPTR));
        label_2->setText(QApplication::translate("Teacher", "Teacher Page", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Teacher: public Ui_Teacher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHER_H
