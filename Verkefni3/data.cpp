#include "data.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <functional>
#include "scientist.h"
#include "engine.h"
#include "connection.h"
#include <string>
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
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <cctype>

using namespace std;
class Scientist;

Data::Data()
{

}

void Data::openDatabase()
{
    db = QSqlDatabase::addDatabase ("QSQLITE");
    QString dbName = QString ("Database (4).sqlite");
    db.setDatabaseName(dbName);
    if(!db.open()) {
        qDebug() << "Could not open db";
    }
}

void Data::closeDatabase()
{
    QString connection;
    connection = db.connectionName();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(connection);
}

//Clears vectors in Data Class
void Data::clearSciVector()
{
    scientistVector.clear();
}
void Data::clearComVector()
{
    computerVector.clear();
}
void Data::clearConnectVector()
{
    connectionVector.clear();
}

vector<Scientist> Data::SortSci(QString str)
{
    openDatabase();
    QSqlQuery query(db);
    query.prepare(str);
    query.bindValue ("Name", QString::fromStdString("dbName"));
    query.exec(str);
    while(query.next())
    {
        if(query.value ("Hide") == "false")
        {
            int id = query.value ("id").toUInt();
            string name = query.value ("Name").toString().toStdString();
            string birth = query.value ("Birth").toString().toStdString();
            string death = query.value ("Death").toString().toStdString();
            string gender = query.value ("Gender").toString().toStdString();

            Scientist sci(id, name, birth, death, gender);
            scientistVector.push_back(sci);
        }
    }
    closeDatabase();
    return scientistVector;
}

vector<Computer> Data::SortCom(QString str)
{
    openDatabase();
    QSqlQuery query(db);
    query.prepare(str);
    query.bindValue ("Name", QString::fromStdString("dbName"));
    query.exec(str);
    while(query.next())
    {
        if(query.value ("Hide") == "false")
        {
            int id = query.value ("id").toUInt();
            string name = query.value ("Name").toString().toStdString();
            string year = query.value ("Year").toString().toStdString();
            string type = query.value ("Type").toString().toStdString();
            string built = query.value ("Built").toString().toStdString();

            Computer com(id, name, year, type, built);
            computerVector.push_back(com);
        }
    }
    closeDatabase();
    return computerVector;
}

void Data::AddSci(QString str, Scientist sci)
{
    openDatabase();
    QSqlQuery query(db);
    string Name, Birth, Death, Gender;
    string Hide = "false";

    Name = sci.getName_Scientist();
    Gender = sci.getGender_Scientist();
    Birth = sci.getBirth_Scientist();
    Death = sci.getDeath_Scientist();

    query.prepare(str);
    query.bindValue(":Name", QString::fromStdString(Name));
    query.bindValue(":Birth", QString::fromStdString(Birth));
    query.bindValue(":Death", QString::fromStdString(Death));
    query.bindValue(":Gender", QString::fromStdString(Gender));
    query.bindValue(":Hide", QString::fromStdString(Hide));
    query.exec();

    closeDatabase();
}

void Data::AddCom(QString str, Computer com)
{
    openDatabase();
    QSqlQuery query(db);
    string Name, Year, Type, Built;
    string Hide = "false";

    Name = com.getName_Computer();
    Year = com.getYearBuilt_Computer();
    Type = com.getType_Computer();
    Built = com.getBuilt_Computer();

    query.prepare(str);
    query.bindValue(":Name", QString::fromStdString(Name));
    query.bindValue(":Year", QString::fromStdString(Year));
    query.bindValue(":Type", QString::fromStdString(Type));
    query.bindValue(":Built", QString::fromStdString(Built));
    query.bindValue(":Hide", QString::fromStdString(Hide));
    query.exec();

    closeDatabase();
}
/*
void Data::AddConnected(QString str)
{

    int input;
    int c_tempId;
    int s_tempId;

    vector<Scientist> s_temp = searchSci("SELECT * FROM Persons WHERE "
                                         "(Name LIKE '%'||:Name||'%') "
                                         "AND (Birth LIKE '%'||:Birth||'%') "
                                         "AND (Death LIKE '%'||:Death||'%') "
                                         "AND (Gender LIKE '%'||:Gender||'%')");

    vector<Computer> c_temp = searchCom("SELECT * FROM Computers WHERE "
                                        "(Name LIKE '%'||:Name||'%') "
                                        "AND (Year LIKE '%'||:Year||'%') "
                                        "AND (Type LIKE '%'||:Type||'%') "
                                        "AND (Built LIKE '%'||:Built||'%')");


    if(s_temp.size() < 1)
    {
        cout << "Scientist Not In Database!" << endl;
        return;
    }
    else
    {
        for(unsigned int i = 0; i < s_temp.size(); i++)
        {
            cout << setw(10) << left << i << ": "
                 << setw(30) << left << s_temp.at(i).getName_Scientist()
                 << setw(15) << left << s_temp.at(i).getBirth_Scientist()
                 << setw(10) << right << s_temp.at(i).getDeath_Scientist()
                 << setw(15) << right << s_temp.at(i).getGender_Scientist()
                 << endl;
        }
        cout << "Select The Number Of Scientist You Want To Connect: ";
        cin >> input;

        s_tempId = s_temp.at(input).getID_Scientist();

        cout << endl << s_temp.at(input).getName_Scientist() << " Has Been Selected!" << endl;
    }

    if(c_temp.size() < 1)
    {
        cout << "Computer Not In Database!" << endl;
        return;
    }
    else
    {
        for(unsigned int i = 0; i < c_temp.size(); i++)
        {
            cout << setw(10) << left << i << ": "
                 << setw(30) << left << c_temp.at(i).getName_Computer()
                 << setw(15) << left << c_temp.at(i).getType_Computer()
                 << setw(10) << right << c_temp.at(i).getYearBuilt_Computer()
                 << setw(15) << right << c_temp.at(i).getBuilt_Computer()
                 << endl;
        }
        cout << "Select The Number Of Computer You Want To Connect: ";
        cin >> input;

        c_tempId = c_temp.at(input).getID_Computer();
        cout << endl << c_temp.at(input).getName_Computer() << "Has Been Selected!" << endl;
    }

    openDatabase();
    QSqlQuery query(db);

    query.prepare(str);

    query.bindValue (":computers_id", QString::number(c_tempId));
    query.bindValue (":persons_id", QString::number(s_tempId));
    query.exec();
    cout << "Connection Added!" << endl;
    closeDatabase();
}
*/
/*
void Data::RemoveSci(QString str)
{
    //Might be used
}
*/
vector <Connection> Data::viewConnected (QString str)
{
    openDatabase();
    QSqlQuery query(db);
    query.prepare(str);
    query.exec();

    while(query.next())
    {
        string s_name = query.value("pName").toString().toStdString();
        string c_name = query.value("Name").toString().toStdString();

        Connection con(s_name, c_name);
        connectionVector.push_back(con);
    }
    closeDatabase();
    return connectionVector;
}

vector <Scientist> Data::searchSci (QString str, const string searchText)
{
    openDatabase();
    QSqlQuery query(db);

    string n,b,d,g;

    n = searchText;
    b = searchText;
    d = searchText;
    g = searchText;

    query.prepare(str);

    query.bindValue (":Name",QString::fromStdString(n));
    query.bindValue (":Birth",QString::fromStdString(b));
    query.bindValue (":Death",QString::fromStdString(d));
    query.bindValue (":Gender",QString::fromStdString(g));

    query.exec();

    while(query.next())
    {
        if (query.value("Hide") == "false")
        {
            int id = query.value ("id").toUInt();
            string name = query.value ("Name").toString().toStdString();
            string birth = query.value ("Birth").toString().toStdString();
            string death = query.value ("Death").toString().toStdString();
            string gender = query.value ("Gender").toString().toStdString();

            Scientist sci(id, name, birth, death, gender);
            scientistVector.push_back(sci);
        }
    }
    query.clear();
    closeDatabase();
    return scientistVector;
}

vector<Computer> Data::searchCom(QString str, string searchText)
{
    openDatabase();
    QSqlQuery query(db);

    string n,y,t,b;

    n = searchText;
    y = searchText;
    t = searchText;
    b = searchText;

    query.prepare(str);

    query.bindValue(":Name",QString::fromStdString(n));
    query.bindValue(":Year",QString::fromStdString(y));
    query.bindValue(":Type",QString::fromStdString(t));
    query.bindValue(":Built",QString::fromStdString(b));

    query.exec();

    while(query.next())
    {
        if(query.value("Hide") == "false")
        {
            int id = query.value("id").toUInt();
            string name = query.value("Name").toString().toStdString();
            string year = query.value("Year").toString().toStdString();
            string type = query.value("Type").toString().toStdString();
            string built = query.value("built").toString().toStdString();

            Computer com(id, name, year, type, built);

            computerVector.push_back(com);
        }
    }
    query.clear();
    closeDatabase();
    return computerVector;
}
