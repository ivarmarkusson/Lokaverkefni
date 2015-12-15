#ifndef CONNECTION_H
#define CONNECTION_H
#include <QCoreApplication>
#include <string>
using namespace std;

class Connection
{
public:
    Connection();
    Connection(int i,string s, string c);
    //Constructor with parameters.
    //Initializes sci_name to s and com_name to c

    int getID_connection();
    string getName_Sci();
    string getName_Com();
    //Get Functions to get private variables

    void setID_connection(int i);
    void setName_Sci(string s);
    void SetName_Com(string c);
    //Set Functions to set private variables

private:
    int ID_connection;
    string sci_name;
    string com_name;
};

#endif // CONNECTION_H
