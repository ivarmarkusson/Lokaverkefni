#include "computer.h"
#include <string>
using namespace std;

Computer::Computer(){}

//Constructor with parameters
Computer::Computer(int i, string n, string y, string t, string b)
{
    c_ID = i;
    c_name = n;
    c_type = t;
    c_yearBuilt = y;
    c_built = b;
}

//Get functions go get private variables
int Computer::getID_Computer()
{
    return c_ID;
}
string Computer::getName_Computer()
{
    return c_name;
}
string Computer::getType_Computer()
{
    return c_type;
}
string Computer::getYearBuilt_Computer()
{
    return c_yearBuilt;
}
string Computer::getBuilt_Computer()
{
    return c_built;
}

//Set functions to set private variables
void Computer::setID_Computer(int i)
{
    c_ID = i;
}
void Computer::setName_Computer(string n)
{
    c_name = n;
}
void Computer::setType_Computer(string t)
{
    c_type = t;
}
void Computer::setYearBuilt_Computer(string y)
{
    c_yearBuilt = y;
}
void Computer::setBuilt_Computer(string b)
{
    c_built = b;
}
