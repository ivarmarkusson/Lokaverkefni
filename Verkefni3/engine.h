#ifndef ENGINE_H
#define ENGINE_H

#include <QCoreApplication>
#include <string>
#include "data.h"
#include "computer.h"
#include <vector>
#include <QtSql>
#include <algorithm>
#include <iomanip>

using namespace std;

class Scientist;
class Computer;
class Connection;


class Engine:Data
{
public:
    Engine();

    vector<Scientist> sortSientists(int i);
    vector<Computer> sortComputers(int i);
    vector<Connection> sortConnections();
    //Sort Functions, for sort choices.

    vector<Scientist> searchScientists(const string input);
    vector<Computer> searchComputers(const string input);
    //search for scientists or computers from the list.

    void addScientists(Scientist& newScientist);
    void addComputers(Computer& newComputer);
    void addConnection(QString c_ID, QString s_ID);
    //add functions

    void removeScientist(QString ID);
    void removeComputer(QString ID);
    void removeConnection(QString ID);
    //removes scientists, computers and connection

    void editScientist(QString name, QString birth, QString death, QString gender, QString id);
    void editComputer(QString name, QString year, QString type, QString built, QString id);


};

#endif // ENGINE_H
