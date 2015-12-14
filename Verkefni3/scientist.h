#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <QCoreApplication>
#include <string>
using namespace std;

class Scientist
{
public:
    Scientist();
    Scientist(int i, string n, string b, string d, string g);
    //Constructor with parameters
    //Initializes s_ID to i, s_name to n, s_birth to b
    //s_death to d and s_gender to g

    int getID_Scientist();
    string getName_Scientist();
    string getGender_Scientist();
    string getBirth_Scientist();
    string getDeath_Scientist();
    //Get Functions to get private variables

    void setID_Scientist(int i);
    void setName_Scientist(string n);
    void setGender_Scientist(string g);
    void setBirth_Scientist(string b);
    void setDeath_Scientist(string d);
    //Set Functions to set private variables

private:
    int s_ID;
    string s_name;
    string s_gender;
    string s_birth;
    string s_death;
};

#endif // SCIENTIST_H
