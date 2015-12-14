#include "mainwindow.h"
#include <QApplication>
#include "data.h"
#include "engine.h"
#include <QtSql>
#include <QDebug>

using namespace std;


int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    MainWindow window;
    window.show();

    return application.exec();
}


