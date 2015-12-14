#include "scientist.h"
#include <iostream>
using namespace std;

Scientist::Scientist(){}

//Constructor with parameters
Scientist::Scientist(int i, string n, string b, string d, string g)
{
    s_ID = i;
    s_name = n;
    s_gender = g;
    s_birth = b;
    s_death = d;
}

//Get functions go get private variables
int Scientist::getID_Scientist()
{
    return s_ID;
}
string Scientist::getName_Scientist()
{
    return s_name;
}
string Scientist::getGender_Scientist()
{
    return s_gender;
}
string Scientist::getBirth_Scientist()
{
    return s_birth;
}
string Scientist::getDeath_Scientist()
{
    return s_death;
}

//Set functions to set private variables
void Scientist::setID_Scientist(int i)
{
    s_ID = i;
}
void Scientist::setName_Scientist(string n)
{
    s_name = n;
}
void Scientist::setGender_Scientist(string g)
{
    s_gender = g;
}
void Scientist::setBirth_Scientist(string i)
{
    s_birth = i;
}
void Scientist::setDeath_Scientist(string d)
{
    s_death = d;
}
