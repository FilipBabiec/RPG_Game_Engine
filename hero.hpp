#ifndef hero_hpp
#define hero_hpp
#include "templates.hpp"
#include "monsters.hpp"
#include <list>

using namespace std;

class Hero : public Template 
{
    friend class Classtemp;
    friend class Mage;
    friend class Thief;
    friend class Berserker;
    friend class Warrior;
public:
    int k;

    Hero();

    void Death();

    Hero(string Name);

    void level_up(int new_exp, int outcome);

    void death();

    void finder(int &i, string &entry);
};

class Mage : public Classtemp
{
public:
  void att(Template &hero);
};

class Warrior : public Classtemp
{
public:
  void att(Template &hero);
};

class Berserker : public Classtemp
{
public:
  void att(Template &hero);
};

class Thief : public Classtemp
{
public:
  void att(Template &hero);
};

class Equipment
{
public:
    string mname, meffect, oname, oeffect, rname, reffect, aname, aeffect;
    int id, place, mdmgw, mdmgi, mdmgr, mstrw, mdexw, mintw, mendw, odmgw, odmgi, odmgr, ostrw, odexw, ointw, oendw, rdmgw, rdmgi, rdmgr, rstrw, rdexw, rintw, rendw, admgw, admgi, admgr, astrw, adexw, aintw, aendw, bonusdmgw, bonusdmgi, bonusdmgr, bonusstr, bonusdex, bonusint, bonusend;
    Equipment();
    Equipment(Equipment &eq, Item item);
};

#endif
