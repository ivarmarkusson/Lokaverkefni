#include "engine.h"
#include <iostream>
#include <QtSql>
#include <string>
#include <vector>
#include "string"
#include "computer.h"
#include "data.h"
#include "scientist.h"
#include "globalstrings.h"

using namespace std;

Engine::Engine()
{

}

//CONNECTS_TO_DATA_CLASS_TO_FETCH_DATA
//AND_RETURNS_IT_IN_A_VECTOR
vector<Scientist> Engine::sortSientists()
{
    vector<Scientist> temp;
    temp.clear();

    temp = SortSci(SCI_ORDER_BY_NAME_ASC);

    clearSciVector();
    return temp;
}

vector<Computer> Engine::sortComputers()
{
    vector<Computer> temp;
    temp.clear();

    temp = SortCom(COM_ORDER_BY_NAME_ASC);

    clearComVector();
    return temp;
}

vector<Connection> Engine::sortConnections()
{
    vector<Connection> temp;
    temp.clear();
    temp = SortConn(SORT_CONNECTIONS);
    connectionVector.clear();
    return temp;
}

vector<Scientist> Engine::searchScientists(const string input)
{
    vector<Scientist> temp;
    temp.clear();
    temp = searchSci(SEARCH_SCIENTIST, input);

    scientistVector.clear();
    return temp;
}

vector<Computer> Engine::searchComputers(const string input)
{
    vector<Computer> temp;
    temp.clear();
    temp = searchCom(SEARCH_COMPUTER, input);

    computerVector.clear();
    return temp;
}

//CONNECTS_TO_DATA_CLASS_TO_FETCH_DATA
void Engine::addScientists(Scientist& newScientist)
{
    AddSci(INSERT_PERSON,newScientist);
}

void Engine::addComputers(Computer& newComputer)
{
    AddCom(INSERT_COMPUTER, newComputer);
}

void Engine::removeScientist(QString ID)
{
    AddRemoveEdit("UPDATE persons SET Hide = 'true' WHERE id = '"+ID+"'");
}

void Engine::removeComputer(QString ID)
{
    AddRemoveEdit("UPDATE computers SET Hide = 'true' WHERE id = '"+ID+"'");
}

void Engine::removeConnection(QString ID)
{
    AddRemoveEdit("UPDATE tengitafla SET Hide = 'true' WHERE id = '"+ID+"'");
}

void Engine::editScientist(QString name, QString birth, QString death, QString gender, QString id)
{
    AddRemoveEdit("UPDATE persons SET Name = '"+name+"', Birth = '"+birth+"', Death = '"+death+"', Gender = '"+gender+"' WHERE id = '"+id+"'");
}

void Engine::editComputer(QString name, QString year, QString type, QString built, QString id)
{
    AddRemoveEdit("UPDATE computers SET Name = '"+name+"', Year = '"+year+"', Type = '"+type+"', Built = '"+built+"' WHERE id = '"+id+"'");
}

void Engine::addConnection(QString c_ID, QString s_ID)
{
    AddRemoveEdit("INSERT INTO tengitafla (computers_id, persons_id) VALUES ('"+c_ID+"', '"+s_ID+"')");
}


