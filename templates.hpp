#ifndef temp_hpp
#define temp_hpp
#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

class Template
{
public:
    string name, textfile, ext, clas;
    int strength, dexterity, endurance, intelligence, maxhealth, health, crit, exp, level;
    list<string> eq;
    vector<string> inv;
};

class Classtemp
{
    public:
    virtual void att(Template &hero)=0;
};

class Item
{
public:
    string name, effect;
    int id, place, dmgw, dmgi, dmgr, strw, dexw, intw, endw;
    Item(string namen, int idn, int placen, int statn1, int statn2, int statn3, int statn4, int statn5, int statn6,int statn7,string effectn);
    Item(string namen);
    Item();
};

Item itemchooser(string name);
string itemdropper();

#endif