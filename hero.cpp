#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <list>
#include "hero.hpp"
#include "functions.hpp"

#ifdef __unix__
#include <unistd.h>
#elif _WIN32 || _WIN64
#include <windows.h>
#endif

using namespace std;

Hero::Hero()
	{}

Hero::Hero(string Name)
	{
		name = Name;
		clas = "None";
		textfile = Name + ".txt";
		strength = 20;
		dexterity = 20;
		endurance = 20;
		intelligence = 20;
		crit = 5;
		k = 0;
        exp = 0;
        level = -2;
	}

void Hero::Death()
{
    strength = strength-10;
    dexterity = dexterity-10;
    endurance = endurance-10;
    intelligence = intelligence-10;
    maxhealth = maxhealth-20;
    health = maxhealth;
    exp = 0;
    level = level-1;
    eq.clear();
}

  void Mage::att(Template &hero)
  {
    hero.clas = "Mage";
    hero.intelligence = hero.intelligence*2;
    hero.maxhealth = 120;
    hero.dexterity = hero.dexterity+15;
    hero.health = hero.maxhealth;
    hero.eq.push_back("Mage's_ring");
  }

  void Warrior::att(Template &hero)
  {
    hero.clas = "Warrior";
    hero.endurance = hero.endurance*2;
    hero.strength = hero.strength+5;
    hero.maxhealth = 200;
    hero.health = hero.maxhealth;
    hero.eq.push_back("Warrior's_ring");
  }

  void Berserker::att(Template &hero)
  {
    hero.clas = "Berserker";
    hero.strength = hero.strength*2;
    hero.dexterity = hero.dexterity+10;
    hero.endurance = hero.endurance+10;
    hero.maxhealth = 150;
    hero.health = hero.maxhealth;
    hero.eq.push_back("Berserker's_ring");
  }

  void Thief::att(Template &hero)
  {
    hero.clas = "Thief";
    hero.dexterity = hero.dexterity*2;
    hero.strength = hero.strength+10;
    hero.endurance = hero.endurance+5;
    hero.maxhealth = 130;
    hero.health = hero.maxhealth;
    hero.crit = 20;
    hero.eq.push_back("Thief's_ring");
  }

  void Hero::level_up(int new_exp, int outcome)
  {
    if (outcome = 1)
    {
        k = 0;
        exp = exp+new_exp;
        while (exp>=100)
        {
            k = k + 2;
            exp = exp - 100;
            level++;
        }

        while(k>0)
        {
            int a;
            for (int i=0;i<k;i++)
            {
#ifdef __unix__
                system("clear");
#elif _WIN32 || _WIN64
                system("cls");
#endif

                cout << "Name: " << name << endl;
                cout << "\nPoints to spend: " << k << endl;
                cout << "Choose which attribute to increase: " << endl;
                cout << "1. Strength: " << strength << endl;
                cout << "2. Dexterity: " << dexterity << endl;
                cout << "3. Endurance: " << endurance << endl;
                cout << "4. Intelligence: " << intelligence << endl;
                cout << "5. Heal up, Health: " << health << "/" << maxhealth << "\n" << endl;
                cin >> a;
                switch (a)
                {
                    case 1:
                    {
                        strength=strength+5;
                        k--;
                        break;
                    }
                    case 2:
                    {
                        dexterity=dexterity+5;
                        k--;
                        break;
                    }
                    case 3:
                    {
                        endurance=endurance+5;
                        maxhealth=maxhealth+10;
                        health=health+10;
                        k--;
                        break;
                    }
                    case 4:
                    {
                        intelligence=intelligence+5;
                        k--;
                        break;
                    }
                    case 5:
                    {
                        health=maxhealth;
                        k--;
                        break;
                    }
                    default:
                    {
                        i--;
                        cout << "No such attribute" << endl;
#ifdef __unix__
                        sleep(1);
#elif _WIN32 || _WIN64
                        Sleep(1000);
#endif
                        break;
                    }
                }
            }
        }
    }
    else
    {
        exp = exp-new_exp;
        if (exp<0) exp = 0;
    }
  }

  Equipment::Equipment()
  {
      mname = "Empty";
      mdmgw = 0;
      mdmgi = 0;
      mdmgr = 0;
      mstrw = 0;
      mdexw = 0;
      mintw = 0;
      mendw = 0;
      meffect = "None";
      oname = "Empty";
      odmgw = 0;
      odmgi = 0;
      odmgr = 0;
      ostrw = 0;
      odexw = 0;
      ointw = 0;
      oendw = 0;
      oeffect = "None";
      rname = "Empty";
      rdmgw = 0;
      rdmgi = 0;
      rdmgr = 0;
      rstrw = 0;
      rdexw = 0;
      rintw = 0;
      rendw = 0;
      reffect = "None";
      aname = "Empty";
      admgw = 0;
      admgi = 0;
      admgr = 0;
      astrw = 0;
      adexw = 0;
      aintw = 0;
      aendw = 0;
      aeffect = "None";
  }
  Equipment::Equipment(Equipment &eq, Item item)
  {
    switch(item.place)
    {
        case 1:
        {
            mname = item.name;
            mdmgw = item.dmgw;
            mdmgi = item.dmgi;
            mdmgr = item.dmgr;
            mstrw = item.strw;
            mdexw = item.dexw;
            mintw = item.intw;
            mendw = item.endw;
            meffect = item.effect;

            oname = eq.oname;
            odmgw = eq.odmgw;
            odmgi = eq.odmgi;
            odmgr = eq.odmgr;
            ostrw = eq.ostrw;
            odexw = eq.odexw;
            ointw = eq.ointw;
            oendw = eq.oendw;
            oeffect = eq.oeffect;
            rname = eq.rname;
            rdmgw = eq.rdmgw;
            rdmgi = eq.rdmgi;
            rdmgr = eq.rdmgr;
            rstrw = eq.rstrw;
            rdexw = eq.rdexw;
            rintw = eq.rintw;
            rendw = eq.rendw;
            reffect = eq.reffect;
            aname = eq.aname;
            admgw = eq.admgw;
            admgi = eq.admgi;
            admgr = eq.admgr;
            astrw = eq.astrw;
            adexw = eq.adexw;
            aintw = eq.aintw;
            aendw = eq.aendw;
            aeffect = eq.aeffect;
            break;
        }
        case 2:
        {
            oname = item.name;
            odmgw = item.dmgw;
            odmgi = item.dmgi;
            odmgr = item.dmgr;
            ostrw = item.strw;
            odexw = item.dexw;
            ointw = item.intw;
            oendw = item.endw;
            oeffect = item.effect;

            mname = eq.mname;
            mdmgw = eq.mdmgw;
            mdmgi = eq.mdmgi;
            mdmgr = eq.mdmgr;
            mstrw = eq.mstrw;
            mdexw = eq.mdexw;
            mintw = eq.mintw;
            mendw = eq.mendw;
            meffect = eq.meffect;
            rname = eq.rname;
            rdmgw = eq.rdmgw;
            rdmgi = eq.rdmgi;
            rdmgr = eq.rdmgr;
            rstrw = eq.rstrw;
            rdexw = eq.rdexw;
            rintw = eq.rintw;
            rendw = eq.rendw;
            reffect = eq.reffect;
            aname = eq.aname;
            admgw = eq.admgw;
            admgi = eq.admgi;
            admgr = eq.admgr;
            astrw = eq.astrw;
            adexw = eq.adexw;
            aintw = eq.aintw;
            aendw = eq.aendw;
            aeffect = eq.aeffect;
            break;
        }
        case 3:
        {
            rname = item.name;
            rdmgw = item.dmgw;
            rdmgi = item.dmgi;
            rdmgr = item.dmgr;
            rstrw = item.strw;
            rdexw = item.dexw;
            rintw = item.intw;
            rendw = item.endw;
            reffect = item.effect;

            oname = eq.oname;
            odmgw = eq.odmgw;
            odmgi = eq.odmgi;
            odmgr = eq.odmgr;
            ostrw = eq.ostrw;
            odexw = eq.odexw;
            ointw = eq.ointw;
            oendw = eq.oendw;
            oeffect = eq.oeffect;
            mname = eq.mname;
            mdmgw = eq.mdmgw;
            mdmgi = eq.mdmgi;
            mdmgr = eq.mdmgr;
            mstrw = eq.mstrw;
            mdexw = eq.mdexw;
            mintw = eq.mintw;
            mendw = eq.mendw;
            meffect = eq.meffect;
            aname = eq.aname;
            admgw = eq.admgw;
            admgi = eq.admgi;
            admgr = eq.admgr;
            astrw = eq.astrw;
            adexw = eq.adexw;
            aintw = eq.aintw;
            aendw = eq.aendw;
            aeffect = eq.aeffect;
            break;
        }
        case 4:
        {
            aname = item.name;
            admgw = item.dmgw;
            admgi = item.dmgi;
            admgr = item.dmgr;
            astrw = item.strw;
            adexw = item.dexw;
            aintw = item.intw;
            aendw = item.endw;
            aeffect = item.effect;

            oname = eq.oname;
            odmgw = eq.odmgw;
            odmgi = eq.odmgi;
            odmgr = eq.odmgr;
            ostrw = eq.ostrw;
            odexw = eq.odexw;
            ointw = eq.ointw;
            oendw = eq.oendw;
            oeffect = eq.oeffect;
            rname = eq.rname;
            rdmgw = eq.rdmgw;
            rdmgi = eq.rdmgi;
            rdmgr = eq.rdmgr;
            rstrw = eq.rstrw;
            rdexw = eq.rdexw;
            rintw = eq.rintw;
            rendw = eq.rendw;
            reffect = eq.reffect;
            mname = eq.mname;
            mdmgw = eq.mdmgw;
            mdmgi = eq.mdmgi;
            mdmgr = eq.mdmgr;
            mstrw = eq.mstrw;
            mdexw = eq.mdexw;
            mintw = eq.mintw;
            mendw = eq.mendw;
            meffect = eq.meffect;
            break;
        }
    }
    bonusdmgw = mdmgw + odmgw + rdmgw + admgw;
    bonusdmgi = mdmgi + odmgi + rdmgi + admgi;
    bonusdmgr = mdmgr + odmgr + rdmgr + admgr;
    bonusstr = mstrw + ostrw + rstrw + astrw;
    bonusdex = mdexw + odexw + rdexw + adexw;
    bonusint = mintw + ointw + rintw + aintw;
    bonusend = mendw + oendw + rendw + aendw;
  }

void Hero::finder(int &i, string &entry)
{
    if (i==inv.size())
    {
        cout << entry << " was not found in the inventory" << endl;
        spanko(1);
    }
    else
    {
        if (entry==inv[i])
        {
            Item item;
            item = itemchooser(entry);
        }
        else
        {
            i++;
            finder(i, entry);
        }
    }
}