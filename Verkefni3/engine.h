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
    void editComputers(int i);
    //edit (add or remove) scientists or computers.

    void connectScientistAndComputer(int i);
    //For connecting scientists and computers

};

#endif // ENGINE_H
