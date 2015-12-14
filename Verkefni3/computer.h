#ifndef COMPUTER_H
#define COMPUTER_H

#include <QCoreApplication>
#include <string>
using namespace std;

class Computer
{
public:
    Computer();
    Computer(int i, string n, string y, string t, string b);
    //Constructor with parameters.
    //Initializes c_ID to i, c_name to n,c_yearBuilt to y, c_type to t and c_built to b.

    int getID_Computer();
    string getName_Computer();
    string getType_Computer();
    string getYearBuilt_Computer();
    string getBuilt_Computer();
    //Get Functions to get private variables

    void setID_Computer(int i);
    void setName_Computer(string n);
    void setType_Computer(string t);
    void setYearBuilt_Computer(string y);
    void setBuilt_Computer(string b);
    //Set Functions to set private variables

private:
    int c_ID;
    string c_name;
    string c_type;
    string c_yearBuilt;
    string c_built;
};

#endif // COMPUTER_H
