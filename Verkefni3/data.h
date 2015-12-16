#ifndef DATA_H
#define DATA_H

#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFileInfo>
#include <QString>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include "scientist.h"
#include "computer.h"
#include "connection.h"
#include <stdlib.h>
#include <string>
#include <cstring>

using namespace std;

class Scientist;
class Computer;
class Connection;

class Data
{
    public:
        Data();

        void openDatabase();
        //Opens database from SQL.
        void closeDatabase();
        //Closes database

        vector<Scientist> SortSci(QString str);
        vector<Computer> SortCom(QString str);
        vector<Connection> SortConn(QString str);
        //Runs SQL database and returns a vector to be printed out

        void AddSci(QString str, Scientist sci);
        void AddCom(QString str,  Computer com);
        void AddRemoveEdit(QString str);
        //Adds new scientist, computer and connection to the list.

        void clearSciVector();
        void clearComVector();
        void clearConnectVector();
        //Clears vector in Data Class

        vector<Scientist> searchSci(QString str, const string searchText);
        vector<Computer> searchCom(QString str, string searchText);
        //Opens SQLite Database, pushes to vectors below and
        //returns them in Engine(DOMAIN) Class

        vector<Scientist> scientistVector;
        vector<Computer> computerVector;
        vector<Connection> connectionVector;
        //Vectors that data is pushed into for printing

    private:
        QSqlDatabase db;
};

#endif // DATA_H
