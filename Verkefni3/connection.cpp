#include "connection.h"
#include <string>
using namespace std;

Connection::Connection(){}

//Constructor with parameters
Connection::Connection(int i, string s, string c)
{
    ID_connection = i;
    sci_name = s;
    com_name =c;
}

//Get functions go get private variables
int Connection::getID_connection()
{
    return ID_connection;
}
string Connection::getName_Sci()
{
    return sci_name;
}
string Connection::getName_Com()
{
    return com_name;
}

//Set functions to set private variables
void Connection::setID_connection(int i)
{
    ID_connection = i;
}
void Connection::setName_Sci(string s)
{
    sci_name = s;
}
void Connection::SetName_Com(string c)
{
    com_name = c;
}
