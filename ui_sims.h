/********************************************************************************
** Form generated from reading UI file 'sims.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMS_H
#define UI_SIMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SIMS
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *StudUsrnLabel;
    QLabel *StudPwdLabel;
    QLineEdit *StudUsrnLE;
    QLineEdit *StudPwdLE;
    QPushButton *StudLoginBtn;
    QLabel *welcomeLabel;
    QLabel *StudLoginStatusLabel;
    QWidget *page_3;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QPushButton *StudInfoButn;
    QGroupBox *groupBox_2;
    QLabel *Test1Label;
    QLabel *Test1Grade;
    QLabel *Test2Label;
    QLabel *Test2Grade;
    QLabel *Test3Label;
    QLabel *Test3Grade;
    QLabel *AverageLabel;
    QLabel *AverageGrade;
    QLabel *StudGPAlabel;
    QLabel *StudGPAvalue;
    QLabel *TheStudentName;
    QLabel *TheStudentID;
    QLabel *ProfessorName;
    QWidget *page_2;
    QPushButton *InfoBackButn;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *StudFNameLabel;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *StudLNameLabel;
    QLabel *StudIDlabel;
    QLabel *StudInfoUsernameLabel;
    QLabel *StudInfoPasswordLabel;
    QWidget *TeacherMain;
    QListWidget *ClassList;
    QListWidget *StudentList;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SIMS)
    {
        if (SIMS->objectName().isEmpty())
            SIMS->setObjectName(QStringLiteral("SIMS"));
        SIMS->resize(735, 420);
        centralWidget = new QWidget(SIMS);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(20, -10, 701, 341));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        StudUsrnLabel = new QLabel(page);
        StudUsrnLabel->setObjectName(QStringLiteral("StudUsrnLabel"));
        StudUsrnLabel->setGeometry(QRect(220, 90, 81, 16));
        QFont font;
        font.setPointSize(12);
        StudUsrnLabel->setFont(font);
        StudPwdLabel = new QLabel(page);
        StudPwdLabel->setObjectName(QStringLiteral("StudPwdLabel"));
        StudPwdLabel->setGeometry(QRect(220, 150, 81, 16));
        StudPwdLabel->setFont(font);
        StudUsrnLE = new QLineEdit(page);
        StudUsrnLE->setObjectName(QStringLiteral("StudUsrnLE"));
        StudUsrnLE->setGeometry(QRect(330, 90, 131, 20));
        StudUsrnLE->setFont(font);
        StudPwdLE = new QLineEdit(page);
        StudPwdLE->setObjectName(QStringLiteral("StudPwdLE"));
        StudPwdLE->setGeometry(QRect(330, 150, 131, 20));
        StudPwdLE->setFont(font);
        StudPwdLE->setEchoMode(QLineEdit::Password);
        StudLoginBtn = new QPushButton(page);
        StudLoginBtn->setObjectName(QStringLiteral("StudLoginBtn"));
        StudLoginBtn->setGeometry(QRect(300, 220, 75, 31));
        StudLoginBtn->setFont(font);
        welcomeLabel = new QLabel(page);
        welcomeLabel->setObjectName(QStringLiteral("welcomeLabel"));
        welcomeLabel->setGeometry(QRect(240, 9, 281, 31));
        QFont font1;
        font1.setPointSize(16);
        welcomeLabel->setFont(font1);
        StudLoginStatusLabel = new QLabel(page);
        StudLoginStatusLabel->setObjectName(QStringLiteral("StudLoginStatusLabel"));
        StudLoginStatusLabel->setGeometry(QRect(490, 120, 171, 31));
        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        listWidget = new QListWidget(page_3);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 90, 256, 192));
        pushButton = new QPushButton(page_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(580, 10, 75, 23));
        StudInfoButn = new QPushButton(page_3);
        StudInfoButn->setObjectName(QStringLiteral("StudInfoButn"));
        StudInfoButn->setGeometry(QRect(150, 300, 371, 23));
        groupBox_2 = new QGroupBox(page_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(380, 110, 301, 161));
        Test1Label = new QLabel(groupBox_2);
        Test1Label->setObjectName(QStringLiteral("Test1Label"));
        Test1Label->setGeometry(QRect(10, 20, 47, 20));
        Test1Grade = new QLabel(groupBox_2);
        Test1Grade->setObjectName(QStringLiteral("Test1Grade"));
        Test1Grade->setGeometry(QRect(180, 20, 47, 13));
        Test2Label = new QLabel(groupBox_2);
        Test2Label->setObjectName(QStringLiteral("Test2Label"));
        Test2Label->setGeometry(QRect(10, 50, 47, 13));
        Test2Grade = new QLabel(groupBox_2);
        Test2Grade->setObjectName(QStringLiteral("Test2Grade"));
        Test2Grade->setGeometry(QRect(180, 50, 47, 13));
        Test3Label = new QLabel(groupBox_2);
        Test3Label->setObjectName(QStringLiteral("Test3Label"));
        Test3Label->setGeometry(QRect(10, 80, 47, 13));
        Test3Grade = new QLabel(groupBox_2);
        Test3Grade->setObjectName(QStringLiteral("Test3Grade"));
        Test3Grade->setGeometry(QRect(180, 80, 47, 13));
        AverageLabel = new QLabel(groupBox_2);
        AverageLabel->setObjectName(QStringLiteral("AverageLabel"));
        AverageLabel->setGeometry(QRect(10, 110, 47, 13));
        AverageGrade = new QLabel(groupBox_2);
        AverageGrade->setObjectName(QStringLiteral("AverageGrade"));
        AverageGrade->setGeometry(QRect(180, 110, 47, 13));
        StudGPAlabel = new QLabel(groupBox_2);
        StudGPAlabel->setObjectName(QStringLiteral("StudGPAlabel"));
        StudGPAlabel->setGeometry(QRect(10, 140, 47, 13));
        StudGPAvalue = new QLabel(groupBox_2);
        StudGPAvalue->setObjectName(QStringLiteral("StudGPAvalue"));
        StudGPAvalue->setGeometry(QRect(180, 140, 101, 16));
        TheStudentName = new QLabel(page_3);
        TheStudentName->setObjectName(QStringLiteral("TheStudentName"));
        TheStudentName->setGeometry(QRect(10, 0, 331, 16));
        TheStudentID = new QLabel(page_3);
        TheStudentID->setObjectName(QStringLiteral("TheStudentID"));
        TheStudentID->setGeometry(QRect(10, 20, 211, 16));
        ProfessorName = new QLabel(page_3);
        ProfessorName->setObjectName(QStringLiteral("ProfessorName"));
        ProfessorName->setGeometry(QRect(110, 60, 121, 16));
        stackedWidget->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        InfoBackButn = new QPushButton(page_2);
        InfoBackButn->setObjectName(QStringLiteral("InfoBackButn"));
        InfoBackButn->setGeometry(QRect(20, 310, 75, 23));
        groupBox = new QGroupBox(page_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(190, 80, 361, 221));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 50, 61, 16));
        StudFNameLabel = new QLabel(groupBox);
        StudFNameLabel->setObjectName(QStringLiteral("StudFNameLabel"));
        StudFNameLabel->setGeometry(QRect(210, 50, 101, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 80, 61, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(60, 110, 47, 13));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(60, 140, 61, 16));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(60, 170, 61, 16));
        StudLNameLabel = new QLabel(groupBox);
        StudLNameLabel->setObjectName(QStringLiteral("StudLNameLabel"));
        StudLNameLabel->setGeometry(QRect(210, 80, 101, 16));
        StudIDlabel = new QLabel(groupBox);
        StudIDlabel->setObjectName(QStringLiteral("StudIDlabel"));
        StudIDlabel->setGeometry(QRect(210, 110, 101, 16));
        StudInfoUsernameLabel = new QLabel(groupBox);
        StudInfoUsernameLabel->setObjectName(QStringLiteral("StudInfoUsernameLabel"));
        StudInfoUsernameLabel->setGeometry(QRect(210, 140, 101, 16));
        StudInfoPasswordLabel = new QLabel(groupBox);
        StudInfoPasswordLabel->setObjectName(QStringLiteral("StudInfoPasswordLabel"));
        StudInfoPasswordLabel->setGeometry(QRect(210, 170, 101, 16));
        stackedWidget->addWidget(page_2);
        TeacherMain = new QWidget();
        TeacherMain->setObjectName(QStringLiteral("TeacherMain"));
        ClassList = new QListWidget(TeacherMain);
        ClassList->setObjectName(QStringLiteral("ClassList"));
        ClassList->setGeometry(QRect(70, 50, 256, 192));
        StudentList = new QListWidget(TeacherMain);
        StudentList->setObjectName(QStringLiteral("StudentList"));
        StudentList->setGeometry(QRect(410, 60, 256, 192));
        stackedWidget->addWidget(TeacherMain);
        SIMS->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SIMS);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 735, 26));
        SIMS->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SIMS);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SIMS->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SIMS);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SIMS->setStatusBar(statusBar);

        retranslateUi(SIMS);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SIMS);
    } // setupUi

    void retranslateUi(QMainWindow *SIMS)
    {
        SIMS->setWindowTitle(QApplication::translate("SIMS", "SIMS", Q_NULLPTR));
        StudUsrnLabel->setText(QApplication::translate("SIMS", "Username:", Q_NULLPTR));
        StudPwdLabel->setText(QApplication::translate("SIMS", "Password:", Q_NULLPTR));
        StudLoginBtn->setText(QApplication::translate("SIMS", "login", Q_NULLPTR));
        welcomeLabel->setText(QApplication::translate("SIMS", "Welcome to the Login page", Q_NULLPTR));
        StudLoginStatusLabel->setText(QString());
        pushButton->setText(QApplication::translate("SIMS", "logout", Q_NULLPTR));
        StudInfoButn->setText(QApplication::translate("SIMS", "View info", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("SIMS", "My grades", Q_NULLPTR));
        Test1Label->setText(QApplication::translate("SIMS", "Test 1", Q_NULLPTR));
        Test1Grade->setText(QApplication::translate("SIMS", "N/A", Q_NULLPTR));
        Test2Label->setText(QApplication::translate("SIMS", "Test 2", Q_NULLPTR));
        Test2Grade->setText(QApplication::translate("SIMS", "N/A", Q_NULLPTR));
        Test3Label->setText(QApplication::translate("SIMS", "Test 3", Q_NULLPTR));
        Test3Grade->setText(QApplication::translate("SIMS", "N/A", Q_NULLPTR));
        AverageLabel->setText(QApplication::translate("SIMS", "Average", Q_NULLPTR));
        AverageGrade->setText(QApplication::translate("SIMS", "N/A", Q_NULLPTR));
        StudGPAlabel->setText(QApplication::translate("SIMS", "GPA", Q_NULLPTR));
        StudGPAvalue->setText(QApplication::translate("SIMS", "N/A", Q_NULLPTR));
        TheStudentName->setText(QApplication::translate("SIMS", "Student name", Q_NULLPTR));
        TheStudentID->setText(QApplication::translate("SIMS", "ID", Q_NULLPTR));
        ProfessorName->setText(QApplication::translate("SIMS", "Select a course.", Q_NULLPTR));
        InfoBackButn->setText(QApplication::translate("SIMS", "back", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("SIMS", "My Information", Q_NULLPTR));
        label_2->setText(QApplication::translate("SIMS", "First Name:", Q_NULLPTR));
        StudFNameLabel->setText(QApplication::translate("SIMS", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("SIMS", "Last Name:", Q_NULLPTR));
        label_5->setText(QApplication::translate("SIMS", "ID:", Q_NULLPTR));
        label_6->setText(QApplication::translate("SIMS", "Username:", Q_NULLPTR));
        label_7->setText(QApplication::translate("SIMS", "Password:", Q_NULLPTR));
        StudLNameLabel->setText(QApplication::translate("SIMS", "TextLabel", Q_NULLPTR));
        StudIDlabel->setText(QApplication::translate("SIMS", "TextLabel", Q_NULLPTR));
        StudInfoUsernameLabel->setText(QApplication::translate("SIMS", "TextLabel", Q_NULLPTR));
        StudInfoPasswordLabel->setText(QApplication::translate("SIMS", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SIMS: public Ui_SIMS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMS_H
