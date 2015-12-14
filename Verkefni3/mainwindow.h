#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "displaywindow.h"
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void login_menu();
    void open_display_window();

private:
    Ui::MainWindow *ui;
    QSqlDatabase logindb;
    DisplayWindow *displaywindow_object;

private slots:

    void on_pushButton_login_clicked();
};

#endif // MAINWINDOW_H
