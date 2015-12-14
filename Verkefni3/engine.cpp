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

vector<Scientist> Engine::sortSientists(int i)
{
    vector<Scientist> temp;
    temp.clear();

    switch (i) {
        case 1:
            temp = SortSci(SCI_ORDER_BY_NAME_ASC);
            break;
        case 2:
            temp = SortSci(SCI_ORDER_BY_NAME_DESC);
            break;
        case 3:
            temp = SortSci(SCI_ORDER_BY_GENDER_ASC);
            break;
        case 4:
            temp = SortSci(SCI_ORDER_BY_GENDER_DESC);
            break;
        case 5:
            temp = SortSci(SCI_ORDER_BY_BIRTH_ASC);
            break;
        case 6:
            temp = SortSci(SCI_ORDER_BY_BIRTH_DESC);
            break;
        case 7:
            temp = SortSci(SCI_ORDER_BY_DEATH_ASC);
            break;
        case 8:
            temp = SortSci(SCI_ORDER_BY_DEATH_DESC);
            break;
        default:
            cout << "Invalid Input! Try Again!" << endl;
            break;
        }
    return temp;
}

vector<Computer> Engine::sortComputers(int i)
{
    vector<Computer> temp;
    temp.clear();

    switch (i) {
        case 1:
            temp = SortCom(COM_ORDER_BY_NAME_ASC);
            break;
        case 2:
            temp = SortCom(COM_ORDER_BY_NAME_DESC);
            break;
        case 3:
            temp = SortCom(COM_ORDER_BY_TYPE_ASC);
            break;
        case 4:
            temp = SortCom(COM_ORDER_BY_TYPE_DESC);
            break;
        case 5:
            temp = SortCom(COM_ORDER_BY_YEAR_ASC);
            break;
        case 6:
            temp = SortCom(COM_ORDER_BY_YEAR_DESC);
            break;
        case 7:
            temp = SortCom(COM_ORDER_BY_BUILT_ASC);
            break;
        case 8:
            temp = SortCom(COM_ORDER_BY_BUILT_DESC);
            break;
        default:
            cout << "Invalid Input! Try Again!" << endl;
            break;
        }
    clearComVector();
    return temp;
}

vector<Connection> Engine::sortConnections()
{
    vector<Connection> temp;
    temp.clear();
    temp = viewConnected(SORT_CONNECTIONS);
    clearConnectVector();
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


void Engine::addScientists(Scientist& newScientist)
{
    AddSci(INSERT_PERSON,newScientist);
}

void Engine::addComputers(Computer& newComputer)
{
    AddCom(INSERT_COMPUTER, newComputer);
}

void Engine::editComputers(int i)
{
    switch(i)
    {
        case 1:
            //AddCom(INSERT_COMPUTER);
            break;
        case 2:
            //RemoveCom();
            break;
        default:
            cout << "Invalid Input, Try again!" << endl;
            return;
    }

    //Needs to return vector to mainWindowClass
}

void Engine::connectScientistAndComputer(int i)
{
    vector<Connection> temp;

    switch(i)
        {
            case 1:
                temp = viewConnected(PRINT_CONNECTION);
                break;
            case 2:
                //AddConnected(ADD_CONNECTION);
                break;
            default:
                cout << "Invalid Input, Try Again!" << endl;
                break;
        }

    //Needs to return vector to mainWindowClass
    clearConnectVector();
    temp.clear();
}

