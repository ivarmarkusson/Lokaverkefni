#include "connection.h"
#include <string>
using namespace std;

Connection::Connection(){}

//Constructor with parameters
Connection::Connection(string s, string c)
{
    sci_name = s;
    com_name =c;
}

//Get functions go get private variables
string Connection::getName_Sci()
{
    return sci_name;
}
string Connection::getName_Com()
{
    return com_name;
}

//Set functions to set private variables
void Connection::setName_Sci(string s)
{
    sci_name = s;
}
void Connection::SetName_Com(string c)
{
    com_name = c;
}
