#ifndef func_hpp
#define func_hpp
#include <map>
#include "templates.hpp"
#include "monsters.hpp"
#include "hero.hpp"

using namespace std;

template <class T>
class Battle
{
public:
    T Hdex, Hend, Hstr, Hint, Hcrit, Mdex, Mend, Mstr, Mint, Mcrit;
    Battle(T hs, T hd, T hi, T he, T hc, T ms, T md, T mi, T me, T mc);
    int D100roll();
    int D10roll();
    T physical_hit(T adex, T ddex, T dend, T astr, T acrit);
    T magical_hit(T aint, T dint, T dend);
    T quick_physical_hit(T adex, T ddex, T dend, T astr, T acrit);
};

void savecharacter(Hero hero);
void saveinitinventory(Hero hero);
void saveeq(Equipment eq, Template hero);
void loadcharacter(Hero &hero, string savefile, int &ind);
void loadeq(Equipment &eq, Template hero);
void deletecharacter(string savefile);
void dispcharacter(Template hero);
void disphistory(Template hero);
void dispinventory1(Template &hero);
void dispinventory2(Template hero);
void clearscreen();
void spanko(int t);
void classchoosing(Hero &hero);
void Arena(Hero &character);
void Drop(Hero &character, string drop);
int battle(Hero &character, Monster monster);
Item itemchooser(string name);
int itemverifier(string &itemname, list<string> equipment);
string itemdropper();
void itemfinder(Hero character, string Entry);
string finder(int i, string array[20], string entry);

#endif