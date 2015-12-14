/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_login;
    QGridLayout *gridLayout_2;
    QLabel *label_username;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_login;
    QLabel *label_password;
    QLabel *label_status;
    QMenuBar *menuBar;
    QMenu *menuMain_Menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(324, 323);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_login = new QGroupBox(centralWidget);
        groupBox_login->setObjectName(QStringLiteral("groupBox_login"));
        gridLayout_2 = new QGridLayout(groupBox_login);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_username = new QLabel(groupBox_login);
        label_username->setObjectName(QStringLiteral("label_username"));

        gridLayout_2->addWidget(label_username, 0, 0, 1, 1);

        lineEdit_username = new QLineEdit(groupBox_login);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));

        gridLayout_2->addWidget(lineEdit_username, 0, 1, 1, 1);

        lineEdit_password = new QLineEdit(groupBox_login);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(lineEdit_password, 1, 1, 1, 1);

        pushButton_login = new QPushButton(groupBox_login);
        pushButton_login->setObjectName(QStringLiteral("pushButton_login"));

        gridLayout_2->addWidget(pushButton_login, 3, 1, 1, 1);

        label_password = new QLabel(groupBox_login);
        label_password->setObjectName(QStringLiteral("label_password"));

        gridLayout_2->addWidget(label_password, 1, 0, 1, 1);

        label_status = new QLabel(groupBox_login);
        label_status->setObjectName(QStringLiteral("label_status"));

        gridLayout_2->addWidget(label_status, 2, 0, 1, 2);

        label_username->raise();
        label_password->raise();
        lineEdit_username->raise();
        lineEdit_password->raise();
        pushButton_login->raise();
        label_status->raise();

        gridLayout->addWidget(groupBox_login, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 324, 26));
        menuMain_Menu = new QMenu(menuBar);
        menuMain_Menu->setObjectName(QStringLiteral("menuMain_Menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(lineEdit_username, lineEdit_password);
        QWidget::setTabOrder(lineEdit_password, pushButton_login);

        menuBar->addAction(menuMain_Menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox_login->setTitle(QApplication::translate("MainWindow", "Login", 0));
        label_username->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Username</span></p></body></html>", 0));
        lineEdit_username->setPlaceholderText(QApplication::translate("MainWindow", "Enter Username", 0));
        lineEdit_password->setPlaceholderText(QApplication::translate("MainWindow", "Enter Password", 0));
        pushButton_login->setText(QApplication::translate("MainWindow", "Login", 0));
        label_password->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Password</span></p></body></html>", 0));
        label_status->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">[+]Status</span></p><p align=\"center\"><br/></p></body></html>", 0));
        menuMain_Menu->setTitle(QApplication::translate("MainWindow", "Login", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
