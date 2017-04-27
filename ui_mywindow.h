/********************************************************************************
** Form generated from reading UI file 'mywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWINDOW_H
#define UI_MYWINDOW_H

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
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QSplitter *splitter;
    QLabel *label;
    QLineEdit *usernameLE;
    QSplitter *splitter_2;
    QLabel *label_2;
    QLineEdit *passwordLE;
    QLabel *label_7;
    QWidget *page_2;
    QPushButton *class_button;
    QPushButton *teachers_button;
    QPushButton *studen_button;
    QPushButton *logout_button;
    QListWidget *listWidget;
    QPushButton *grades_button;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QLabel *label_3;
    QWidget *page_3;
    QPushButton *grades_button_2;
    QPushButton *studen_button_2;
    QPushButton *logout_button_2;
    QListWidget *listWidget_2;
    QPushButton *Bclasses;
    QPushButton *Del;
    QLabel *label_4;
    QPushButton *Update;
    QPushButton *Add_button;
    QWidget *page_4;
    QLabel *label_5;
    QPushButton *logout_button_3;
    QLabel *label_6;
    QMenuBar *menuBar;
    QMenu *menuTest_UI_Page;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyWindow)
    {
        if (MyWindow->objectName().isEmpty())
            MyWindow->setObjectName(QStringLiteral("MyWindow"));
        MyWindow->resize(1307, 677);
        centralWidget = new QWidget(MyWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(-80, -30, 1301, 631));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        groupBox = new QGroupBox(page);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(190, 90, 551, 361));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 160, 381, 51));
        splitter = new QSplitter(groupBox);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(40, 60, 234, 25));
        splitter->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        splitter->addWidget(label);
        usernameLE = new QLineEdit(splitter);
        usernameLE->setObjectName(QStringLiteral("usernameLE"));
        splitter->addWidget(usernameLE);
        splitter_2 = new QSplitter(groupBox);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(40, 119, 235, 25));
        splitter_2->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        splitter_2->addWidget(label_2);
        passwordLE = new QLineEdit(splitter_2);
        passwordLE->setObjectName(QStringLiteral("passwordLE"));
        passwordLE->setEchoMode(QLineEdit::Password);
        splitter_2->addWidget(passwordLE);
        label_7 = new QLabel(page);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(780, 160, 251, 131));
        QFont font1;
        font1.setPointSize(12);
        label_7->setFont(font1);
        label_7->setWordWrap(true);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        class_button = new QPushButton(page_2);
        class_button->setObjectName(QStringLiteral("class_button"));
        class_button->setGeometry(QRect(100, 170, 181, 81));
        teachers_button = new QPushButton(page_2);
        teachers_button->setObjectName(QStringLiteral("teachers_button"));
        teachers_button->setGeometry(QRect(100, 280, 181, 81));
        studen_button = new QPushButton(page_2);
        studen_button->setObjectName(QStringLiteral("studen_button"));
        studen_button->setGeometry(QRect(100, 400, 181, 81));
        logout_button = new QPushButton(page_2);
        logout_button->setObjectName(QStringLiteral("logout_button"));
        logout_button->setGeometry(QRect(1120, 30, 131, 41));
        listWidget = new QListWidget(page_2);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(310, 130, 731, 431));
        grades_button = new QPushButton(page_2);
        grades_button->setObjectName(QStringLiteral("grades_button"));
        grades_button->setGeometry(QRect(340, 560, 131, 41));
        pushButton_10 = new QPushButton(page_2);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(840, 560, 131, 41));
        pushButton_11 = new QPushButton(page_2);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(660, 560, 131, 41));
        pushButton_12 = new QPushButton(page_2);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(490, 560, 131, 41));
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(590, 40, 191, 81));
        label_3->setFont(font);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        grades_button_2 = new QPushButton(page_3);
        grades_button_2->setObjectName(QStringLiteral("grades_button_2"));
        grades_button_2->setEnabled(false);
        grades_button_2->setGeometry(QRect(350, 550, 141, 41));
        grades_button_2->setCheckable(true);
        studen_button_2 = new QPushButton(page_3);
        studen_button_2->setObjectName(QStringLiteral("studen_button_2"));
        studen_button_2->setGeometry(QRect(110, 320, 181, 81));
        studen_button_2->setAutoFillBackground(true);
        studen_button_2->setCheckable(true);
        studen_button_2->setChecked(false);
        logout_button_2 = new QPushButton(page_3);
        logout_button_2->setObjectName(QStringLiteral("logout_button_2"));
        logout_button_2->setGeometry(QRect(1130, 20, 131, 41));
        listWidget_2 = new QListWidget(page_3);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(300, 110, 731, 431));
        Bclasses = new QPushButton(page_3);
        Bclasses->setObjectName(QStringLiteral("Bclasses"));
        Bclasses->setGeometry(QRect(120, 210, 181, 81));
        Bclasses->setCheckable(true);
        Bclasses->setChecked(false);
        Del = new QPushButton(page_3);
        Del->setObjectName(QStringLiteral("Del"));
        Del->setEnabled(false);
        Del->setGeometry(QRect(740, 550, 131, 41));
        label_4 = new QLabel(page_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(600, 30, 191, 81));
        label_4->setFont(font);
        Update = new QPushButton(page_3);
        Update->setObjectName(QStringLiteral("Update"));
        Update->setEnabled(false);
        Update->setGeometry(QRect(910, 550, 131, 41));
        Add_button = new QPushButton(page_3);
        Add_button->setObjectName(QStringLiteral("Add_button"));
        Add_button->setEnabled(false);
        Add_button->setGeometry(QRect(560, 550, 131, 41));
        stackedWidget->addWidget(page_3);
        grades_button_2->raise();
        studen_button_2->raise();
        logout_button_2->raise();
        listWidget_2->raise();
        Del->raise();
        label_4->raise();
        Update->raise();
        Add_button->raise();
        Bclasses->raise();
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        label_5 = new QLabel(page_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(270, 110, 781, 331));
        QFont font2;
        font2.setPointSize(48);
        label_5->setFont(font2);
        logout_button_3 = new QPushButton(page_4);
        logout_button_3->setObjectName(QStringLiteral("logout_button_3"));
        logout_button_3->setGeometry(QRect(1140, 30, 131, 41));
        label_6 = new QLabel(page_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(590, 150, 181, 91));
        stackedWidget->addWidget(page_4);
        MyWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1307, 26));
        menuTest_UI_Page = new QMenu(menuBar);
        menuTest_UI_Page->setObjectName(QStringLiteral("menuTest_UI_Page"));
        MyWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MyWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MyWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyWindow->setStatusBar(statusBar);

        menuBar->addAction(menuTest_UI_Page->menuAction());

        retranslateUi(MyWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MyWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MyWindow)
    {
        MyWindow->setWindowTitle(QApplication::translate("MyWindow", "MyWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MyWindow", "Login", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MyWindow", "Login", Q_NULLPTR));
        label->setText(QApplication::translate("MyWindow", "Username :", Q_NULLPTR));
        label_2->setText(QApplication::translate("MyWindow", "Password :", Q_NULLPTR));
        label_7->setText(QApplication::translate("MyWindow", "Currently only LOGOUT button works on every other page. Use it to return to this page.                              Username and Password Combinations: admin/admin student/student  teacher/teacher", Q_NULLPTR));
        class_button->setText(QApplication::translate("MyWindow", "Classes", Q_NULLPTR));
        teachers_button->setText(QApplication::translate("MyWindow", "Teachers", Q_NULLPTR));
        studen_button->setText(QApplication::translate("MyWindow", "Students", Q_NULLPTR));
        logout_button->setText(QApplication::translate("MyWindow", "logout", Q_NULLPTR));
        grades_button->setText(QApplication::translate("MyWindow", "Grades", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("MyWindow", "PushButton", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("MyWindow", "PushButton", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("MyWindow", "PushButton", Q_NULLPTR));
        label_3->setText(QApplication::translate("MyWindow", "Student Page", Q_NULLPTR));
        grades_button_2->setText(QApplication::translate("MyWindow", "Grades", Q_NULLPTR));
        studen_button_2->setText(QApplication::translate("MyWindow", "Students", Q_NULLPTR));
        logout_button_2->setText(QApplication::translate("MyWindow", "Logout", Q_NULLPTR));
        Bclasses->setText(QApplication::translate("MyWindow", "Classes", Q_NULLPTR));
        Del->setText(QApplication::translate("MyWindow", "Del", Q_NULLPTR));
        label_4->setText(QApplication::translate("MyWindow", "TEACHER PAGE", Q_NULLPTR));
        Update->setText(QApplication::translate("MyWindow", "Update", Q_NULLPTR));
        Add_button->setText(QApplication::translate("MyWindow", "Add", Q_NULLPTR));
        label_5->setText(QApplication::translate("MyWindow", "POWER OVVERWHELMING", Q_NULLPTR));
        logout_button_3->setText(QApplication::translate("MyWindow", "Logout", Q_NULLPTR));
        label_6->setText(QApplication::translate("MyWindow", "Admin Page", Q_NULLPTR));
        menuTest_UI_Page->setTitle(QApplication::translate("MyWindow", "Test UI Page", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyWindow: public Ui_MyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWINDOW_H
