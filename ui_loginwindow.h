/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Loginwindow
{
public:
    QWidget *centralwidget;
    QLabel *welcomeLabel;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *LoginUserName;
    QLineEdit *LoginPassword;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Loginwindow)
    {
        if (Loginwindow->objectName().isEmpty())
            Loginwindow->setObjectName(QStringLiteral("Loginwindow"));
        Loginwindow->resize(800, 600);
        centralwidget = new QWidget(Loginwindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        welcomeLabel = new QLabel(centralwidget);
        welcomeLabel->setObjectName(QStringLiteral("welcomeLabel"));
        welcomeLabel->setGeometry(QRect(200, 120, 651, 31));
        QFont font;
        font.setPointSize(16);
        welcomeLabel->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(620, 180, 91, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(610, 250, 55, 16));
        LoginUserName = new QLineEdit(centralwidget);
        LoginUserName->setObjectName(QStringLiteral("LoginUserName"));
        LoginUserName->setGeometry(QRect(290, 180, 261, 22));
        LoginPassword = new QLineEdit(centralwidget);
        LoginPassword->setObjectName(QStringLiteral("LoginPassword"));
        LoginPassword->setGeometry(QRect(300, 240, 241, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(350, 340, 93, 28));
        Loginwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Loginwindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Loginwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(Loginwindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Loginwindow->setStatusBar(statusbar);

        retranslateUi(Loginwindow);

        QMetaObject::connectSlotsByName(Loginwindow);
    } // setupUi

    void retranslateUi(QMainWindow *Loginwindow)
    {
        Loginwindow->setWindowTitle(QApplication::translate("Loginwindow", "MainWindow", Q_NULLPTR));
        welcomeLabel->setText(QApplication::translate("Loginwindow", "Welcome to the Login page", Q_NULLPTR));
        label->setText(QApplication::translate("Loginwindow", "UserName", Q_NULLPTR));
        label_2->setText(QApplication::translate("Loginwindow", "Password", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Loginwindow", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Loginwindow: public Ui_Loginwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
