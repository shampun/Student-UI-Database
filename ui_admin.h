/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
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
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_8;
    QPushButton *logout_button_6;
    QPushButton *ViewTeachers;
    QPushButton *ViewStudents;
    QPushButton *pushButton_9;
    QPushButton *pushButton_22;
    QTableView *tableView;
    QLineEdit *searchedit;
    QLabel *label_10;
    QComboBox *comboBox;
    QTableView *courseView;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *Aid;
    QLabel *Aname;
    QLineEdit *stname;
    QLabel *Alast;
    QLineEdit *stlast;
    QLabel *Auser;
    QLineEdit *stuser;
    QLabel *Apw;
    QLineEdit *stid;
    QLineEdit *stpw;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLineEdit *searchedit_2;
    QComboBox *comboBox_2;
    QLabel *label_15;
    QPushButton *remInstructor;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QWidget *page;
    QTableView *tview;
    QTableView *CourseView_2;
    QPushButton *pushButton_6;
    QTableView *stview;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton;
    QLabel *label_21;
    QComboBox *comboBox_3;
    QLineEdit *searchedit_3;
    QLabel *label_22;
    QComboBox *comboBox_4;
    QLineEdit *searchedit_4;
    QLineEdit *searchedit_5;
    QLabel *label_24;
    QWidget *layoutWidget1;
    QFormLayout *formLayout_2;
    QLabel *label_6;
    QLineEdit *cid;
    QLabel *label_7;
    QLineEdit *cname;
    QLabel *label_8;
    QLineEdit *sname;
    QLabel *label_9;
    QLineEdit *slast;
    QLabel *label_11;
    QLineEdit *sid;
    QLabel *label_12;
    QLineEdit *tname;
    QLabel *label_13;
    QLineEdit *tlast;
    QLabel *label_14;
    QLineEdit *tid;
    QWidget *page_2;
    QStackedWidget *swidge;
    QWidget *page_4;
    QListWidget *listWidget;
    QPushButton *pushButton_12;
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
    QWidget *page_5;
    QPushButton *InfoBackButn;
    QGroupBox *groupBox;
    QLabel *label_16;
    QLabel *StudFNameLabel;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *StudLNameLabel;
    QLabel *StudIDlabel;
    QLabel *StudInfoUsernameLabel;
    QLabel *StudInfoPasswordLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName(QStringLiteral("Admin"));
        Admin->resize(1153, 623);
        centralwidget = new QWidget(Admin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1151, 591));
        page_8 = new QWidget();
        page_8->setObjectName(QStringLiteral("page_8"));
        logout_button_6 = new QPushButton(page_8);
        logout_button_6->setObjectName(QStringLiteral("logout_button_6"));
        logout_button_6->setGeometry(QRect(960, 50, 131, 41));
        ViewTeachers = new QPushButton(page_8);
        ViewTeachers->setObjectName(QStringLiteral("ViewTeachers"));
        ViewTeachers->setGeometry(QRect(150, 60, 81, 23));
        ViewStudents = new QPushButton(page_8);
        ViewStudents->setObjectName(QStringLiteral("ViewStudents"));
        ViewStudents->setGeometry(QRect(60, 60, 81, 23));
        pushButton_9 = new QPushButton(page_8);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(870, 440, 91, 41));
        pushButton_22 = new QPushButton(page_8);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        pushButton_22->setGeometry(QRect(990, 290, 101, 23));
        tableView = new QTableView(page_8);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(60, 90, 601, 211));
        searchedit = new QLineEdit(page_8);
        searchedit->setObjectName(QStringLiteral("searchedit"));
        searchedit->setGeometry(QRect(310, 60, 113, 20));
        label_10 = new QLabel(page_8);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(260, 60, 47, 13));
        comboBox = new QComboBox(page_8);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(430, 60, 69, 22));
        courseView = new QTableView(page_8);
        courseView->setObjectName(QStringLiteral("courseView"));
        courseView->setGeometry(QRect(60, 350, 601, 211));
        layoutWidget = new QWidget(page_8);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(720, 220, 261, 126));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        Aid = new QLabel(layoutWidget);
        Aid->setObjectName(QStringLiteral("Aid"));

        formLayout->setWidget(0, QFormLayout::LabelRole, Aid);

        Aname = new QLabel(layoutWidget);
        Aname->setObjectName(QStringLiteral("Aname"));

        formLayout->setWidget(1, QFormLayout::LabelRole, Aname);

        stname = new QLineEdit(layoutWidget);
        stname->setObjectName(QStringLiteral("stname"));

        formLayout->setWidget(1, QFormLayout::FieldRole, stname);

        Alast = new QLabel(layoutWidget);
        Alast->setObjectName(QStringLiteral("Alast"));

        formLayout->setWidget(2, QFormLayout::LabelRole, Alast);

        stlast = new QLineEdit(layoutWidget);
        stlast->setObjectName(QStringLiteral("stlast"));

        formLayout->setWidget(2, QFormLayout::FieldRole, stlast);

        Auser = new QLabel(layoutWidget);
        Auser->setObjectName(QStringLiteral("Auser"));

        formLayout->setWidget(3, QFormLayout::LabelRole, Auser);

        stuser = new QLineEdit(layoutWidget);
        stuser->setObjectName(QStringLiteral("stuser"));

        formLayout->setWidget(3, QFormLayout::FieldRole, stuser);

        Apw = new QLabel(layoutWidget);
        Apw->setObjectName(QStringLiteral("Apw"));

        formLayout->setWidget(4, QFormLayout::LabelRole, Apw);

        stid = new QLineEdit(layoutWidget);
        stid->setObjectName(QStringLiteral("stid"));

        formLayout->setWidget(0, QFormLayout::FieldRole, stid);

        stpw = new QLineEdit(layoutWidget);
        stpw->setObjectName(QStringLiteral("stpw"));

        formLayout->setWidget(4, QFormLayout::FieldRole, stpw);

        pushButton_2 = new QPushButton(page_8);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(720, 360, 75, 23));
        pushButton_3 = new QPushButton(page_8);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(810, 360, 81, 23));
        pushButton_4 = new QPushButton(page_8);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(990, 250, 91, 23));
        pushButton_5 = new QPushButton(page_8);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(990, 220, 91, 23));
        searchedit_2 = new QLineEdit(page_8);
        searchedit_2->setObjectName(QStringLiteral("searchedit_2"));
        searchedit_2->setGeometry(QRect(320, 310, 113, 20));
        comboBox_2 = new QComboBox(page_8);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(440, 310, 69, 22));
        label_15 = new QLabel(page_8);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(270, 310, 47, 13));
        remInstructor = new QPushButton(page_8);
        remInstructor->setObjectName(QStringLiteral("remInstructor"));
        remInstructor->setGeometry(QRect(990, 320, 101, 23));
        pushButton_10 = new QPushButton(page_8);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(910, 360, 75, 23));
        pushButton_11 = new QPushButton(page_8);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(1000, 360, 91, 23));
        stackedWidget->addWidget(page_8);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        tview = new QTableView(page);
        tview->setObjectName(QStringLiteral("tview"));
        tview->setGeometry(QRect(400, 60, 321, 271));
        CourseView_2 = new QTableView(page);
        CourseView_2->setObjectName(QStringLiteral("CourseView_2"));
        CourseView_2->setGeometry(QRect(60, 370, 861, 211));
        pushButton_6 = new QPushButton(page);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(750, 280, 75, 23));
        stview = new QTableView(page);
        stview->setObjectName(QStringLiteral("stview"));
        stview->setGeometry(QRect(70, 60, 331, 271));
        pushButton_7 = new QPushButton(page);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(860, 280, 75, 23));
        pushButton_8 = new QPushButton(page);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(1000, 20, 75, 23));
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(950, 280, 75, 23));
        label_21 = new QLabel(page);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(130, 30, 47, 13));
        comboBox_3 = new QComboBox(page);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(300, 30, 69, 22));
        searchedit_3 = new QLineEdit(page);
        searchedit_3->setObjectName(QStringLiteral("searchedit_3"));
        searchedit_3->setGeometry(QRect(180, 30, 113, 20));
        label_22 = new QLabel(page);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(420, 30, 47, 13));
        comboBox_4 = new QComboBox(page);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setGeometry(QRect(590, 30, 69, 22));
        searchedit_4 = new QLineEdit(page);
        searchedit_4->setObjectName(QStringLiteral("searchedit_4"));
        searchedit_4->setGeometry(QRect(470, 30, 113, 20));
        searchedit_5 = new QLineEdit(page);
        searchedit_5->setObjectName(QStringLiteral("searchedit_5"));
        searchedit_5->setGeometry(QRect(260, 340, 113, 20));
        label_24 = new QLabel(page);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(190, 340, 51, 20));
        layoutWidget1 = new QWidget(page);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(750, 60, 261, 204));
        formLayout_2 = new QFormLayout(layoutWidget1);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_6);

        cid = new QLineEdit(layoutWidget1);
        cid->setObjectName(QStringLiteral("cid"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, cid);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_7);

        cname = new QLineEdit(layoutWidget1);
        cname->setObjectName(QStringLiteral("cname"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, cname);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_8);

        sname = new QLineEdit(layoutWidget1);
        sname->setObjectName(QStringLiteral("sname"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, sname);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_9);

        slast = new QLineEdit(layoutWidget1);
        slast->setObjectName(QStringLiteral("slast"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, slast);

        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_11);

        sid = new QLineEdit(layoutWidget1);
        sid->setObjectName(QStringLiteral("sid"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, sid);

        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_12);

        tname = new QLineEdit(layoutWidget1);
        tname->setObjectName(QStringLiteral("tname"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, tname);

        label_13 = new QLabel(layoutWidget1);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_13);

        tlast = new QLineEdit(layoutWidget1);
        tlast->setObjectName(QStringLiteral("tlast"));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, tlast);

        label_14 = new QLabel(layoutWidget1);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout_2->setWidget(7, QFormLayout::LabelRole, label_14);

        tid = new QLineEdit(layoutWidget1);
        tid->setObjectName(QStringLiteral("tid"));

        formLayout_2->setWidget(7, QFormLayout::FieldRole, tid);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        swidge = new QStackedWidget(page_2);
        swidge->setObjectName(QStringLiteral("swidge"));
        swidge->setGeometry(QRect(140, 80, 821, 401));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        listWidget = new QListWidget(page_4);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 90, 256, 192));
        pushButton_12 = new QPushButton(page_4);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(10, 360, 75, 23));
        StudInfoButn = new QPushButton(page_4);
        StudInfoButn->setObjectName(QStringLiteral("StudInfoButn"));
        StudInfoButn->setGeometry(QRect(150, 300, 371, 23));
        groupBox_2 = new QGroupBox(page_4);
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
        TheStudentName = new QLabel(page_4);
        TheStudentName->setObjectName(QStringLiteral("TheStudentName"));
        TheStudentName->setGeometry(QRect(10, 0, 331, 16));
        TheStudentID = new QLabel(page_4);
        TheStudentID->setObjectName(QStringLiteral("TheStudentID"));
        TheStudentID->setGeometry(QRect(10, 20, 211, 16));
        ProfessorName = new QLabel(page_4);
        ProfessorName->setObjectName(QStringLiteral("ProfessorName"));
        ProfessorName->setGeometry(QRect(110, 60, 121, 16));
        swidge->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        InfoBackButn = new QPushButton(page_5);
        InfoBackButn->setObjectName(QStringLiteral("InfoBackButn"));
        InfoBackButn->setGeometry(QRect(20, 310, 75, 23));
        groupBox = new QGroupBox(page_5);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(190, 80, 361, 221));
        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(60, 50, 61, 16));
        StudFNameLabel = new QLabel(groupBox);
        StudFNameLabel->setObjectName(QStringLiteral("StudFNameLabel"));
        StudFNameLabel->setGeometry(QRect(210, 50, 101, 16));
        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(60, 80, 61, 16));
        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(60, 110, 47, 13));
        label_19 = new QLabel(groupBox);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(60, 140, 61, 16));
        label_20 = new QLabel(groupBox);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(60, 170, 61, 16));
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
        swidge->addWidget(page_5);
        stackedWidget->addWidget(page_2);
        Admin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Admin);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1153, 21));
        Admin->setMenuBar(menubar);
        statusbar = new QStatusBar(Admin);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Admin->setStatusBar(statusbar);

        retranslateUi(Admin);

        stackedWidget->setCurrentIndex(0);
        swidge->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QMainWindow *Admin)
    {
        Admin->setWindowTitle(QApplication::translate("Admin", "MainWindow", Q_NULLPTR));
        logout_button_6->setText(QApplication::translate("Admin", "Logout", Q_NULLPTR));
        ViewTeachers->setText(QApplication::translate("Admin", "View Teachers", Q_NULLPTR));
        ViewStudents->setText(QApplication::translate("Admin", "View Students", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("Admin", "View Courses", Q_NULLPTR));
        pushButton_22->setText(QApplication::translate("Admin", "Remove Student", Q_NULLPTR));
        label_10->setText(QApplication::translate("Admin", "Search", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Admin", "ID", Q_NULLPTR)
         << QApplication::translate("Admin", "Name", Q_NULLPTR)
         << QApplication::translate("Admin", "Last Name", Q_NULLPTR)
         << QApplication::translate("Admin", "UserName", Q_NULLPTR)
        );
        Aid->setText(QApplication::translate("Admin", " ID", Q_NULLPTR));
        Aname->setText(QApplication::translate("Admin", " First Name", Q_NULLPTR));
        Alast->setText(QApplication::translate("Admin", " Last Name", Q_NULLPTR));
        Auser->setText(QApplication::translate("Admin", " User Name", Q_NULLPTR));
        Apw->setText(QApplication::translate("Admin", " Password", Q_NULLPTR));
        stid->setText(QString());
        pushButton_2->setText(QApplication::translate("Admin", "Add Student", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Admin", "Add Instructor", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Admin", "Update Teacher", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Admin", "Update Student", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Admin", "ID", Q_NULLPTR)
         << QApplication::translate("Admin", "Name", Q_NULLPTR)
         << QApplication::translate("Admin", "Last Name", Q_NULLPTR)
         << QApplication::translate("Admin", "UserName", Q_NULLPTR)
        );
        label_15->setText(QApplication::translate("Admin", "Search", Q_NULLPTR));
        remInstructor->setText(QApplication::translate("Admin", "Remove Instructor", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("Admin", "View Student", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("Admin", "View Instructor", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("Admin", "View", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("Admin", "Register", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("Admin", "Back", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Admin", "Delete", Q_NULLPTR));
        label_21->setText(QApplication::translate("Admin", "Search", Q_NULLPTR));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("Admin", "ID", Q_NULLPTR)
         << QApplication::translate("Admin", "Name", Q_NULLPTR)
         << QApplication::translate("Admin", "Last Name", Q_NULLPTR)
        );
        label_22->setText(QApplication::translate("Admin", "Search", Q_NULLPTR));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("Admin", "ID", Q_NULLPTR)
         << QApplication::translate("Admin", "Name", Q_NULLPTR)
         << QApplication::translate("Admin", "Last Name", Q_NULLPTR)
        );
        label_24->setText(QApplication::translate("Admin", "Search ID", Q_NULLPTR));
        label_6->setText(QApplication::translate("Admin", " Course Id", Q_NULLPTR));
        label_7->setText(QApplication::translate("Admin", " Course Name", Q_NULLPTR));
        label_8->setText(QApplication::translate("Admin", " Student Name", Q_NULLPTR));
        label_9->setText(QApplication::translate("Admin", " Student Last Name", Q_NULLPTR));
        label_11->setText(QApplication::translate("Admin", " Student Id", Q_NULLPTR));
        label_12->setText(QApplication::translate("Admin", " Instructor First Name", Q_NULLPTR));
        label_13->setText(QApplication::translate("Admin", " Instructor Last Name", Q_NULLPTR));
        label_14->setText(QApplication::translate("Admin", " Instructor Id", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("Admin", "back", Q_NULLPTR));
        StudInfoButn->setText(QApplication::translate("Admin", "View info", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Admin", "My grades", Q_NULLPTR));
        Test1Label->setText(QApplication::translate("Admin", "Test 1", Q_NULLPTR));
        Test1Grade->setText(QApplication::translate("Admin", "N/A", Q_NULLPTR));
        Test2Label->setText(QApplication::translate("Admin", "Test 2", Q_NULLPTR));
        Test2Grade->setText(QApplication::translate("Admin", "N/A", Q_NULLPTR));
        Test3Label->setText(QApplication::translate("Admin", "Test 3", Q_NULLPTR));
        Test3Grade->setText(QApplication::translate("Admin", "N/A", Q_NULLPTR));
        AverageLabel->setText(QApplication::translate("Admin", "Average", Q_NULLPTR));
        AverageGrade->setText(QApplication::translate("Admin", "N/A", Q_NULLPTR));
        StudGPAlabel->setText(QApplication::translate("Admin", "GPA", Q_NULLPTR));
        StudGPAvalue->setText(QApplication::translate("Admin", "N/A", Q_NULLPTR));
        TheStudentName->setText(QApplication::translate("Admin", "Student name", Q_NULLPTR));
        TheStudentID->setText(QApplication::translate("Admin", "ID", Q_NULLPTR));
        ProfessorName->setText(QApplication::translate("Admin", "Select a course.", Q_NULLPTR));
        InfoBackButn->setText(QApplication::translate("Admin", "back", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Admin", "My Information", Q_NULLPTR));
        label_16->setText(QApplication::translate("Admin", "First Name:", Q_NULLPTR));
        StudFNameLabel->setText(QApplication::translate("Admin", "TextLabel", Q_NULLPTR));
        label_17->setText(QApplication::translate("Admin", "Last Name:", Q_NULLPTR));
        label_18->setText(QApplication::translate("Admin", "ID:", Q_NULLPTR));
        label_19->setText(QApplication::translate("Admin", "Username:", Q_NULLPTR));
        label_20->setText(QApplication::translate("Admin", "Password:", Q_NULLPTR));
        StudLNameLabel->setText(QApplication::translate("Admin", "TextLabel", Q_NULLPTR));
        StudIDlabel->setText(QApplication::translate("Admin", "TextLabel", Q_NULLPTR));
        StudInfoUsernameLabel->setText(QApplication::translate("Admin", "TextLabel", Q_NULLPTR));
        StudInfoPasswordLabel->setText(QApplication::translate("Admin", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
