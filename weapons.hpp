#ifndef weapon_hpp
#define weapon_hpp
#include "templates.hpp"
#include <list>

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