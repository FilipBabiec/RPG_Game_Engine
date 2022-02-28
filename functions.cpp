#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <forward_list>
#include <sys/types.h>
#include <sys/stat.h>
#include <list>
#include <functional>
#include "templates.hpp"
#include "hero.hpp"
#include "monsters.hpp"
#include "functions.hpp"
//#ifdef __unix__
//#include <unistd.h>
//#elif _WIN32 || _WIN64
#include <windows.h>
#include <direct.h>
//#endif

template<class T>
Battle<T>::Battle(T hs, T hd, T hi, T he, T hc, T ms, T md, T mi, T me, T mc) {
    Hstr = hs;
    Hdex = hd;
    Hint = hi;
    Hend = he;
    Hcrit = hc;
    Mstr = ms;
    Mdex = md;
    Mint = mi;
    Mend = me;
    Mcrit = mc;
}

template<class T>
int Battle<T>::D100roll()
{
    int Rolled;
    Rolled = rand() % 100 + 1;
    return Rolled;
}

template<class T>
int Battle<T>::D10roll()
{
    int Rolled;
    Rolled = rand() % 10 + 1;
    return Rolled;
}

template<class T>
T Battle<T>::physical_hit(T adex, T ddex, T dend, T astr, T acrit)
{
    T dmg;
    if (adex + D100roll() > ddex + D100roll() / 2) {
    dmg = ((astr + D10roll() + D10roll()) - (dend + D10roll() + D10roll()));
    if (dmg < 0) dmg = 0;
    if (dmg > 1) dmg = dmg + 25;
    if (D100roll() < acrit) {
    dmg = 2 * dmg;
    cout << "CRITICAL STRIKE!" << endl;
    }
    if (dmg == 0)
    cout << "Attack was blocked!" << endl;
    else
    cout << "The hit connects and deals " << dmg << "damage!" << endl;
    } else {
    dmg = 0;
    cout << "Attack was dodged!" << endl;
    }
    return dmg;
}

template<class T>
T Battle<T>::magical_hit(T aint, T dint, T dend)
{
    T dmg;
    if (aint + D100roll() > dint + D100roll()) {
    dmg = (aint + D10roll()) / 2;
    cout << "Spell deals " << dmg << "damage!" << endl;
    } else {
    dmg = 0;
    cout << "Casting interrupted!" << endl;
    }
    return dmg;
}

template<class T>
T Battle<T>::quick_physical_hit(T adex, T ddex, T dend, T astr, T acrit)
{
    T dmg;
    if (adex + D100roll() > (ddex + D100roll()) / 2) {
    dmg = ((adex + D10roll() + astr / 2 + D10roll()) - (dend / 2 + D10roll() + ddex + D10roll()));
    if (dmg < 0) dmg = 0;
    if (D100roll() < acrit) {
    dmg = 5 * dmg;
    cout << "CRITICAL STRIKE!" << endl;
    }
    if (dmg == 0)
    cout << "Attack was blocked!" << endl;
    else
    cout << "The hit connects and deals " << dmg << "damage!" << endl;
    } else {
    dmg = 0;
    cout << "Attack was dodged!" << endl;
    }
    return dmg;
}

void savecharacter(Hero hero)
{
    string path;
    if (hero.clas=="Monster")
        path = "monsters/" + hero.name + ".txt";
    else
        path = "profiles/"+hero.name;
//#ifdef __unix__
//        mkdir(path.c_str(),0777);
//#elif _WIN32 || _WIN64
        _mkdir(path.c_str());
//#endif
        path = "profiles/" + hero.name + "/" + hero.name + ".txt";
    ofstream savefile(path.c_str(), ios::out);
    savefile << hero.name << endl;
    savefile << hero.clas << endl;
    savefile << hero.level << endl;
    savefile << hero.strength << endl;
    savefile << hero.dexterity << endl;
    savefile << hero.endurance << endl;
    savefile << hero.intelligence << endl;
    savefile << hero.crit << endl;
    savefile << hero.health << endl;
    savefile << hero.maxhealth << endl;
    savefile.close();
}

void saveinitinventory(Hero hero)
{
    string path;
    path = "profiles/" + hero.name + "/" + "Inventory.txt";

    ofstream file(path.c_str());
    for (auto& i : hero.eq)
    {
        file << i << endl;
    }
    file.close();
}
void saveeq(Equipment eq, Template hero)
{
    string path;
    path = "profiles/" + hero.name + "/" + "Equipment.txt";
    ofstream savefile(path.c_str(), ios::out);
    savefile << eq.mname << endl;
    savefile << eq.mdmgw << endl;
    savefile << eq.mdmgi << endl;
    savefile << eq.mdmgr << endl;
    savefile << eq.mstrw << endl;
    savefile << eq.mdexw << endl;
    savefile << eq.mintw << endl;
    savefile << eq.mendw << endl;
    savefile << eq.oname << endl;
    savefile << eq.odmgw << endl;
    savefile << eq.odmgi << endl;
    savefile << eq.odmgr << endl;
    savefile << eq.ostrw << endl;
    savefile << eq.odexw << endl;
    savefile << eq.ointw << endl;
    savefile << eq.oendw << endl;
    savefile << eq.rname << endl;
    savefile << eq.rdmgw << endl;
    savefile << eq.rdmgi << endl;
    savefile << eq.rdmgr << endl;
    savefile << eq.rstrw << endl;
    savefile << eq.rdexw << endl;
    savefile << eq.rintw << endl;
    savefile << eq.rendw << endl;
    savefile << eq.aname << endl;
    savefile << eq.admgw << endl;
    savefile << eq.admgi << endl;
    savefile << eq.admgr << endl;
    savefile << eq.astrw << endl;
    savefile << eq.adexw << endl;
    savefile << eq.aintw << endl;
    savefile << eq.aendw << endl;
    savefile.close();
}

void loadcharacter(Hero &hero, string savefile, int &ind)
{
    savefile = "profiles/" + savefile + "/" + savefile + ".txt";
    ifstream save(savefile.c_str());
    if (save.good()==true)
    {
        ind = 1;
        save >> hero.name;
        save >> hero.clas;
        save >> hero.level;
        save >> hero.strength;
        save >> hero.dexterity;
        save >> hero.endurance;
        save >> hero.intelligence;
        save >> hero.crit;
        save >> hero.health;
        save >> hero.maxhealth;
        save.close();
    }
    else
    {
        cout << "Save file does not exist!" << endl;
        ind = 2;
    }
}

void loadeq(Equipment &eq, Template hero)
{
    string path;
    path = "profiles/" + hero.name + "/" + "Equipment.txt";
    ifstream savefile(path.c_str());
    savefile >> eq.mname;
    savefile >> eq.mdmgw;
    savefile >> eq.mdmgi;
    savefile >> eq.mdmgr;
    savefile >> eq.mstrw;
    savefile >> eq.mdexw;
    savefile >> eq.mintw;
    savefile >> eq.mendw;
    savefile >> eq.oname;
    savefile >> eq.odmgw;
    savefile >> eq.odmgi;
    savefile >> eq.odmgr;
    savefile >> eq.ostrw;
    savefile >> eq.odexw;
    savefile >> eq.ointw;
    savefile >> eq.oendw;
    savefile >> eq.rname;
    savefile >> eq.rdmgw;
    savefile >> eq.rdmgi;
    savefile >> eq.rdmgr;
    savefile >> eq.rstrw;
    savefile >> eq.rdexw;
    savefile >> eq.rintw;
    savefile >> eq.rendw;
    savefile >> eq.aname;
    savefile >> eq.admgw;
    savefile >> eq.admgi;
    savefile >> eq.admgr;
    savefile >> eq.astrw;
    savefile >> eq.adexw;
    savefile >> eq.aintw;
    savefile >> eq.aendw;
    savefile.close();
}

void loadmonster(Monster &hero, string savefile, int &ind)
{
    savefile = "monsters/" + savefile + ".txt";
    ifstream save(savefile.c_str());
    if (save.good()==true)
    {
        ind = 1;
        save >> hero.name;
        save >> hero.clas;
        save >> hero.strength;
        save >> hero.dexterity;
        save >> hero.endurance;
        save >> hero.intelligence;
        save >> hero.crit;
        save >> hero.health;
        save >> hero.maxhealth;
        save.close();
    }
    else
    {
        cout << "Save file does not exist!" << endl;
        ind = 2;
    }
}

void deletecharacter(string savefile)
{
    string save;
    save = "profiles/" + savefile + "/" + savefile + ".txt";
    remove(save.c_str());
    save = "profiles/" + savefile + "/history.txt";
    remove(save.c_str());
    save = "profiles/" + savefile + "/Inventory.txt";
    remove(save.c_str());
    save = "profiles/" + savefile + "/Equipment.txt";
    remove(save.c_str());

    save = "profiles/" + savefile;
    if (_rmdir(save.c_str()) != 0)
        cout << ("No such save file!") << endl;
    else {
        cout << "Save file deleted successfully" << endl;
    }
}

void dispcharacter(Template hero)
{
    if (hero.clas=="Monster")
    cout << "\nYour enemy:\n" << endl;
    else
    cout << "\nYour character:\n" << endl;
    cout << "Name: " << hero.name << endl;
    cout << "Class: " << hero.clas << endl;
    if (hero.clas!="Monster")
    cout << "Level: " << hero.level << endl;
    cout << "Strength: " << hero.strength << endl;
    cout << "Dexterity: " << hero.dexterity << endl;
    cout << "Endurance: " << hero.endurance << endl;
    cout << "Intelligence: " << hero.intelligence << endl;
    cout << "Crit chance: " << hero.crit << "%"<< endl;
    cout << "Health: " << hero.health << "/" << hero.maxhealth << endl;
}

void disphistory(Template hero)
{
    if (hero.clas!="Monster")
    {
        string path, read;
        forward_list<string> History;
        path = "profiles/" + hero.name + "/" + "history.txt";
        ifstream file (path.c_str());
        if (!file.is_open()) {
            cout << "\n\nHistory does not exist yet." << endl;
        }
        else
        {
            for (int i = 0; i < 10; i++){
                file >> read;
                if (file.eof())
                {
                    break;
                }
                else
                {
                    History.push_front(read);
                }
            }
            file.close();
            History.reverse();
            cout << "\n\nHistory of battles:" << endl;
            for (auto &i : History)
            {
                cout << i << endl;
            }
        }
    }
}

void dispinventory1(Template &hero)
{
    if (hero.clas!="Monster")
    {
        string path, read;
        Item item;
        Equipment eq;
        loadeq(eq, hero);
        cout << "\n\nYour equipment:\n" << endl;
        cout << "\nMain hand: " << endl;
        cout << "Item: " << eq.mname << endl;
        cout << "Description: "; if(eq.mname!="Empty"){item = itemchooser(eq.mname);} cout << endl;
        cout << "\nOff hand: " << endl;
        cout << "Item: " << eq.oname << endl;
        cout << "Description: "; if(eq.oname!="Empty"){item = itemchooser(eq.oname);} cout << endl;
        cout << "\nRing: " << endl;
        cout << "Item: " << eq.rname << endl;
        cout << "Description: "; if(eq.rname!="Empty"){item = itemchooser(eq.rname);} cout << endl;
        cout << "\nArmour: " << endl;
        cout << "Item: " << eq.aname << endl;
        cout << "Description: "; if(eq.aname!="Empty"){item = itemchooser(eq.aname);} cout << endl;

        path = "profiles/" + hero.name + "/" + "Inventory.txt";
        ifstream file (path.c_str());
        if (!file.is_open()) {
            cout << "\n\nInventory empty" << endl;
        }
        else
        {
            for (int i = 0; i < 20; i++){
                file >> read;
                if (file.eof())
                {
                    break;
                }
                else
                {
                    hero.eq.push_back(read);
                    hero.inv.push_back(read);
                }
            }
            file.close();


            cout << "\n\nInventory: " << endl;
            for (auto &i : hero.eq)
            {
                cout << i << endl;
            }
        }
    }
}

void dispinventory2(Template hero)
{
    if (hero.clas!="Monster")
    {
        string path, read;
        Item item;
            Equipment eq;
            loadeq(eq, hero);
            cout << "\n\nYour equipment:\n" << endl;
            cout << "\nMain hand: " << endl;
            cout << "Item: " << eq.mname << endl;
            cout << "Description: "; if(eq.mname!="Empty"){item = itemchooser(eq.mname);} cout << endl;
            cout << "\nOff hand: " << endl;
            cout << "Item: " << eq.oname << endl;
            cout << "Description: "; if(eq.oname!="Empty"){item = itemchooser(eq.oname);} cout << endl;
            cout << "\nRing: " << endl;
            cout << "Item: " << eq.rname << endl;
            cout << "Description: "; if(eq.rname!="Empty"){item = itemchooser(eq.rname);} cout << endl;
            cout << "\nArmour: " << endl;
            cout << "Item: " << eq.aname << endl;
            cout << "Description: "; if(eq.aname!="Empty"){item = itemchooser(eq.aname);} cout << endl;

            cout << "\n\nInventory: " << endl;
            for (auto &i : hero.eq)
            {
                cout << i << endl;
            }
    }
}

void clearscreen()
{
    #ifdef __unix__
        system("clear");
    #elif _WIN32 || _WIN64
        system("cls");
    #endif
}

void spanko(int t)
{
    #ifdef __unix__
        sleep(t);
    #elif _WIN32 || _WIN64
        Sleep(t*1000);
    #endif
}

void classchoosing(Hero &hero)
{
    string c;
    int ind;
    do
     {
      clearscreen();
      cout << "Which class do you choose?: " << endl;
      cout << " -mage\n -berserker\n -warrior\n -thief\n" << endl;
      cin >> c;
      if (c=="mage")
        {
          Mage mageinit;
          Classtemp *mage;
          mage = &mageinit;
          mage->att(hero);
          ind = 1;
        }
        else if (c=="berserker")
        {
          Berserker berserkerinit;
          Classtemp *berserker;
          berserker = &berserkerinit;
          berserker->att(hero);
          ind = 1;
        }
        else if (c=="warrior")
        {
          Warrior warriorinit;
          Classtemp *warrior;
          warrior = &warriorinit;
          warrior->att(hero);
          ind = 1;
        }
        else if (c=="thief")
        {
          Thief thiefinit;
          Classtemp *thief;
          thief = &thiefinit;
          thief->att(hero);
          ind = 1;
        }
        else
        {
          clearscreen();
          cout << "No such class!" << endl;
          spanko(3);
          ind = 2;
        }
    } while (ind==2);
}

int battle(Hero &character, Monster monster)
{
    int outcome, attack_type, ma;
    Battle <int> battle1(character.strength, character.dexterity, character.intelligence, character.endurance, character.crit,
                         monster.strength, monster.dexterity, monster.intelligence, monster.endurance, monster.crit);
    do {
        clearscreen();
        dispcharacter(character);
        cout << "\n" << endl;
        dispcharacter(monster);
        cout << "\n\nWhat do you want to do?\n1. Strong physical attack\n2. Quick physical attack\n3. Magical attack\n" << endl;
        cin >> attack_type;
        if (attack_type==1) {
            clearscreen();
            dispcharacter(character);
            cout << "\n" << endl;
            dispcharacter(monster);
            cout << "\n\nYou use the strong attack!" << endl;
            spanko(1);
            monster.health = monster.health - battle1.physical_hit(battle1.Hdex, battle1.Mdex, battle1.Mend, battle1.Hstr, battle1.Hcrit);
            spanko(3);
        }
        else if(attack_type==3)
        {
            clearscreen();
            dispcharacter(character);
            cout << "\n" << endl;
            dispcharacter(monster);
            cout << "\n\nYou use magical attack!" << endl;
            spanko(1);
            monster.health = monster.health - battle1.magical_hit(battle1.Hint, battle1.Mint, battle1.Mend);
            spanko(3);
        }
        else if(attack_type==2)
        {
            clearscreen();
            dispcharacter(character);
            cout << "\n" << endl;
            dispcharacter(monster);
            cout << "\n\nYou use quick attack!" << endl;
            spanko(1);
            monster.health = monster.health - battle1.quick_physical_hit(battle1.Hdex, battle1.Mdex, battle1.Mend, battle1.Hstr, battle1.Hcrit);
            spanko(3);
        }
        else
        {
            clearscreen();
            dispcharacter(character);
            cout << "\n" << endl;
            dispcharacter(monster);
            cout << "\n\nYou missed your chance to attack!" << endl;
        }
        if (monster.health<=0)
            cout << "Monster dies!" << endl;
        else {
            ma = rand() % 3 + 1;
            if (ma==1) {
                clearscreen();
                dispcharacter(character);
                cout << "\n" << endl;
                dispcharacter(monster);
                cout << "\n\nMonster uses strong physical attack!" << endl;
                spanko(1);
                character.health = character.health - battle1.physical_hit(battle1.Mdex, battle1.Hdex, battle1.Hend, battle1.Mstr, battle1.Mcrit);
                spanko(3);
            }
            else if (ma==2)
            {
                clearscreen();
                dispcharacter(character);
                cout << "\n" << endl;
                dispcharacter(monster);
                cout << "\n\nMonster uses magical attack!" << endl;
                spanko(1);
                character.health = character.health - battle1.magical_hit(battle1.Mint, battle1.Hint, battle1.Mend);
                spanko(3);
            }
            else
            {
                clearscreen();
                dispcharacter(character);
                cout << "\n" << endl;
                dispcharacter(monster);
                cout << "\n\nMonster uses quick physical attack!" << endl;
                spanko(1);
                character.health = character.health - battle1.quick_physical_hit(battle1.Mdex, battle1.Hdex, battle1.Hend, battle1.Mstr, battle1.Mcrit);
                spanko(3);
            }
        }
    } while(character.health > 0 && monster.health > 0);
    if (character.health<=0)
    {
        outcome = 0;
        character.health = 0;
    }
    else
        outcome = 1;
    if (outcome==1)
    {
        clearscreen();
        dispcharacter(character);
        cout << "\n" << endl;
        dispcharacter(monster);
        cout << "\n\n" << endl;
        cout << "You have won and gained " << monster.exp << " experience!" << endl;
        spanko(3);
        character.level_up(monster.exp, outcome);
        remove(character.textfile.c_str());
        savecharacter(character);
    }
    else
    {
        clearscreen();
        dispcharacter(character);
        cout << "\n" << endl;
        dispcharacter(monster);
        cout << "\n\n" << endl;
        cout << "YOU DIED!" << endl;
        character.Death();
        savecharacter(character);
        spanko(3);

    }
    return outcome;
}

int listsize(forward_list<string> list)
{
    int j = 1;
    for (auto &i : list)
    {
        j++;
    }
    return j;
}
void Arena(Hero &character)
{
    int outcome;
    string path, read, drop;
    character.exp = 0;
    forward_list<string> history;
    path = "profiles/" + character.name + "/" + "history.txt";
    ifstream file (path.c_str());
    if (!file.is_open())
    {}
    else {
        for (int i = 0; i < 10; i++) {
            file >> read;
            if (file.eof()) {
                break;
            } else {
                history.push_front(read);
            }
        }
        file.close();
        history.reverse();
    }

    path = "profiles/" + character.name + "/" + "Inventory.txt";
    ifstream file1 (path.c_str());
    if (!file1.is_open())
    {}
    else {
        for (int i = 0; i < 20; i++) {
            file1 >> read;
            if (file1.eof()) {
                break;
            } else {
                character.eq.push_back(read);
            }
        }
        file1.close();
    }

    Monster monster("Spider");
    outcome = battle(character, monster);
    if (outcome==1)
    {
        drop = itemdropper();
        Drop(character, drop);
        history.push_front(monster.name+"_victory");
        if (listsize(history)>10)
        {
            history.reverse();
            history.pop_front();
            history.reverse();
        }
        Monster monster("Goblin");
        outcome = battle(character, monster);
        if (outcome==1)
        {
            drop = itemdropper();
            Drop(character, drop);
            history.push_front(monster.name+"_victory");
            if (listsize(history)>10)
            {
                history.reverse();
                history.pop_front();
                history.reverse();
            }
            Monster monster("Orc");
            outcome = battle(character, monster);
            if (outcome==1)
            {
                drop = itemdropper();
                Drop(character, drop);
                history.push_front(monster.name+"_victory");
                if (listsize(history)>10)
                {
                    history.reverse();
                    history.pop_front();
                    history.reverse();
                }
                Monster monster("Troll");
                outcome = battle(character, monster);
                if (outcome==1)
                {
                    drop = itemdropper();
                    Drop(character, drop);
                    history.push_front(monster.name+"_victory");
                    if (listsize(history)>10)
                    {
                        history.reverse();
                        history.pop_front();
                        history.reverse();
                    }
                    Monster monster("Dragon", "boss");
                    outcome = battle(character, monster);
                    if (outcome==1)
                    {
                        drop = itemdropper();
                        Drop(character, drop);
                        history.push_front(monster.name+"_victory");
                        if (listsize(history)>10)
                        {
                            history.reverse();
                            history.pop_front();
                            history.reverse();
                        }
                        ofstream file (path.c_str());
                        for (auto &i : history)
                        {
                            file << i << endl;
                        }
                        file.close();
                        cout << "Congratulations you have defeated all enemies in the arena!" << endl;
                        spanko(4);
                        character.level_up(200, outcome);
                    }
                    else
                    {
                        history.push_front(monster.name+"_defeat");
                        if (listsize(history)>10)
                        {
                            history.reverse();
                            history.pop_front();
                            history.reverse();
                        }
                        ofstream file (path.c_str());
                        for (auto &i : history)
                        {
                            file << i << endl;
                        }
                        file.close();
                    }
                }
                else
                {
                    history.push_front(monster.name+"_defeat");
                    if (listsize(history)>10)
                    {
                        history.reverse();
                        history.pop_front();
                        history.reverse();
                    }
                    ofstream file (path.c_str());
                    for (auto &i : history)
                    {
                        file << i << endl;
                    }
                    file.close();
                }
            }
            else
            {
                history.push_front(monster.name+"_defeat");
                if (listsize(history)>10)
                {
                    history.reverse();
                    history.pop_front();
                    history.reverse();
                }
                ofstream file (path.c_str());
                for (auto &i : history)
                {
                    file << i << endl;
                }
                file.close();
            }
        }
        else
        {
            history.push_front(monster.name+"_defeat");
            if (listsize(history)>10)
            {
                history.reverse();
                history.pop_front();
                history.reverse();
            }
            ofstream file (path.c_str());
            for (auto &i : history)
            {
                file << i << endl;
            }
            file.close();
        }
    }
    else
    {
        history.push_front(monster.name+"_defeat");
        if (listsize(history)>10)
        {
            history.reverse();
            history.pop_front();
            history.reverse();
        }
        ofstream file (path.c_str());
        for (auto &i : history)
        {
            file << i << endl;
        }
        file.close();
    }
}

void Drop(Hero &character, string drop)
{
    string path;
    character.eq.push_back(drop);
    path = "profiles/" + character.name + "/" + "Inventory.txt";
    ofstream file (path.c_str());
    for (auto &i : character.eq)
    {
        file << i << endl;
    }
    file.close();
    cout << "You dropped: " << drop << endl;
    spanko(3);
}

int itemverifier(string &itemname, list<string> equipment)
{
    int k = 0;
    list<string>::iterator it;
    for (it = equipment.begin(); it != equipment.end(); ++it) {
        if (itemname.compare(*it) == 0)
        {
            k = 1;
        }
    }
    return k;
}

Item itemchooser(string name)
{
    Item Item1("Sword_of_ice", 1, 1, 10, 0, 0, 2, 0, 0, 0, "Deals 10 additional physical damage and grants +2 strength");
    Item Item2("Sword_of_fire", 2, 1, 5, 0, 0, 4, 0, 0, 0, "Deals 5 additional physical damage and grants +4 strength");
    Item Item3("Giant_sword", 3, 1, 15, 0, 0, 10, -20, 0, 0, "Deals 15 additional physical damage and grants +10 strength, but lowers dexterity by 20");
    Item Item4("Sword_of_magic", 4, 1, 10, 0, 0, 10, 10, 10, 0, "Deals 10 additional physical damage and grants 10 to strength, dexterity and intelligence");
    Item Item5("Swift_sword", 5, 1, 5, 0, 0, 10, 15, 0, 0, "Deals 5 additional physical damage and grants +10 strength and +15 dexterity");
    Item Item6("Defensive_sword", 6, 1, 0, 0, 5, 5, 0, 0, 10, "Reduces damage by 5 and grants +5 to strength and +10 to endurance");

    Item Item7("Magic_shield", 7, 2, 0, 0, 10, 0, 0, 10, 5, "Reduces damage by 10 and grants +10 to intelligence and +5 to endurance");
    Item Item8("Shield_of_power", 8, 2, 0, 0, 10, 10, 10, 10, 10, "Reduces damage by 10 and grants +10 to all attributes");
    Item Item9("Offensive_shield", 9, 2, 0, 0, 5, 10, 10, 0, 0, "Reduces damage by 5 and grants +10 to dexterity and intelligence");
    Item Item10("Regular_shield", 10, 2, 0, 0, 10, 0, 0, 0, 10, "Reduces damage by 10 and grants +10 to endurance");

    Item Item11("Magical_book", 11, 2, 0, 5, 5, 0, 0, 10, 0, "Increases magic damage by 5, reduces damage by 5 and grants +10 to intelligence");
    Item Item12("Offensive_book", 12, 2, 0, 15, 0, 0, 0, 10, 0, "Increases magic damage by 5, reduces damage by 5 and grants +10 to intelligence");
    Item Item13("Defensive_book", 13, 2, 0, 0, 10, 0, 0, 5, 10, "Reduces damage by 10 grants +5 to intelligence and +10 to endurance");

    Item Item14("Ring_of_strength", 14, 3, 0, 0, 0, 5, 0, 0, 0, "Adds 5 to strength");
    Item Item15("Ring_of_intelligence", 15, 3, 0, 0, 0, 0, 0, 5, 0, "Adds 5 to intelligence");
    Item Item16("Ring_of_endurance", 16, 3, 0, 0, 0, 0, 5, 0, 0, "Adds 5 to dexterity");
    Item Item17("Damage_ring", 17, 3, 5, 0, 0, 0, 5, 0, 0, "Adds 5 to damage");
    Item Item18("Defensive_ring", 18, 3, 0, 0, 5, 0, 5, 0, 0, "Adds 5 to damage reduction");
    Item Item19("Mage's_ring", 19, 3, 0, 5, 0, 0, 5, 0, 0, "Adds 5 to magic damage");
    Item Item20("Ring_of_dexterity", 20, 3, 0, 0, 0, 0, 5, 0, 0, "Adds 5 to dexterity");

    Item Item21("Divine_armour", 21, 4, 0, 0, 10, 10, 10, 10, 10, "Adds 10 to all attributes and provides 10 damage reduction");
    Item Item22("Mage's_robes", 22, 4, 0, 0, 5, 0, 0, 10, 0, "Adds 5 to intelligence and provides 5 damage reduction");
    Item Item23("Light_armour", 23, 4, 0, 0, 5, 0, 10, 0, 5, "Adds 20 to dexterity and 5 to endurance, and provides 5 damage reduction");
    Item Item24("Heavy_armour", 24, 4, 0, 0, 10, 0, -10, 0, 10, "Adds 10 to endurance but reducec dexterity by 10, and provides 10 damage reduction");
    Item chooseditem;

    if(name=="Sword_of_ice")
    {
        chooseditem = Item1;
        cout << chooseditem.name << ": " << chooseditem.effect;
    }
    else if(name=="Sword_of_fire")
    {
        chooseditem = Item2;
        cout << chooseditem.name << ": " << chooseditem.effect;
    }
    else if(name=="Giant_sword")
    {
        chooseditem = Item3;
        cout << chooseditem.name << ": " << chooseditem.effect;
    }
    else if(name=="Sword_of_magic")
    {
        chooseditem = Item4;
        cout << chooseditem.name << ": " << chooseditem.effect;
    }
    else if(name=="Swift_sword")
    {
        chooseditem = Item5;
        cout << chooseditem.name << ": " << chooseditem.effect;
    }
    else if(name=="Defensive_sword")
    {
        chooseditem = Item6;
        cout << chooseditem.name << ": " << chooseditem.effect;
    }
    else if(name=="Magic_shield")
    {
        chooseditem = Item7;
        cout << chooseditem.name << ": " << chooseditem.effect;
    }
    else if(name=="Shield_of_power")
    {
        chooseditem = Item8;
        cout << chooseditem.name << ": " << chooseditem.effect;
    }
    else if(name=="Offensive_shield")
    {
        chooseditem = Item9;
        cout << chooseditem.name << ": " << chooseditem.effect;
    }
    else if(name== "Regular_shield")
    {
        chooseditem = Item10;
        cout << chooseditem.name << ": " << chooseditem.effect;
    }
    else if(name== "Magical_book")
    {
        chooseditem = Item11;
        cout << chooseditem.effect;
    }
    else if(name== "Offensive_book")
    {
        chooseditem = Item12;
        cout << chooseditem.name << ": " << chooseditem.effect;
    }
    else if(name== "Defensive_book")
    {
        chooseditem = Item13;
        cout << chooseditem.name << ": " << chooseditem.effect;
    }
    else if(name== "Ring_of_strength")
    {
        chooseditem = Item14;
        cout << chooseditem.name << ": " << chooseditem.effect;
    }
    else if(name== "Ring_of_intelligence")
    {
        chooseditem = Item15;
        cout << chooseditem.name << ": " << chooseditem.effect;
    }
    else if(name== "Ring_of_endurance")
    {
        chooseditem = Item16;
        cout << chooseditem.name << ": " << chooseditem.effect;
    }
    else if(name== "Damage_ring")
    {
        chooseditem = Item17;
        cout << chooseditem.name << ": " << chooseditem.effect;
    }
    else if(name== "Defensive_ring")
    {
        chooseditem = Item18;
        cout << chooseditem.name << ": " << chooseditem.effect;
    }
    else if(name== "Mage's_ring")
    {
        chooseditem = Item19;
        cout << chooseditem.name << ": " << chooseditem.effect;
    }
    else if(name== "Ring_of_dexterity")
    {
        chooseditem = Item20;
        cout << chooseditem.name << ": " << chooseditem.effect;
    }
    else if(name== "Divine_armour")
    {
        chooseditem = Item21;
        cout << chooseditem.name << ": " << chooseditem.effect;
    }
    else if(name== "Mage's_robes")
    {
        chooseditem = Item22;
        cout << chooseditem.name << ": " << chooseditem.effect;
    }
    else if(name== "Light_armour")
    {
        chooseditem = Item23;
        cout << chooseditem.name << ": " << chooseditem.effect;
    }
    else if(name== "Heavy_armour")
    {
        chooseditem = Item24;
        cout << chooseditem.name << ": " << chooseditem.effect;

    }
    else
    {
        cout << "No such item!" << endl;
        Item item("Empty");
        chooseditem = item;
    }
    return chooseditem;
}

string itemdropper()
{
    Item Item1("Sword_of_ice", 1, 1, 10, 0, 0, 2, 0, 0, 0, "Deals 10 additional physical damage and grants +2 strength");
    Item Item2("Sword_of_fire", 2, 1, 5, 0, 0, 4, 0, 0, 0, "Deals 5 additional physical damage and grants +4 strength");
    Item Item3("Giant_sword", 3, 1, 15, 0, 0, 10, -20, 0, 0, "Deals 15 additional physical damage and grants +10 strength, but lowers dexterity by 20");
    Item Item4("Sword_of_magic", 4, 1, 10, 0, 0, 10, 10, 10, 0, "Deals 10 additional physical damage and grants 10 to strength, dexterity and intelligence");
    Item Item5("Swift_sword", 5, 1, 5, 0, 0, 10, 15, 0, 0, "Deals 5 additional physical damage and grants +10 strength and +15 dexterity");
    Item Item6("Defensive_sword", 6, 1, 0, 0, 5, 5, 0, 0, 10, "Reduces damage by 5 and grants +5 to strength and +10 to endurance");

    Item Item7("Magic_shield", 7, 2, 0, 0, 10, 0, 0, 10, 5, "Reduces damage by 10 and grants +10 to intelligence");
    Item Item8("Shield_of_power", 8, 2, 0, 0, 10, 10, 10, 10, 10, "Reduces damage by 10 and grants +10 to all attributes");
    Item Item9("Offensive_shield", 9, 2, 0, 0, 5, 10, 10, 0, 0, "Reduces damage by 5 and grants +10 to strength and dexterity");
    Item Item10("Regular_shield", 10, 2, 0, 0, 10, 0, 0, 0, 10, "Reduces damage by 10 and grants +10 to endurance");

    Item Item11("Magical_book", 11, 2, 0, 5, 5, 0, 0, 10, 0, "Increases magic damage by 5, reduces damage by 5 and grants +10 to intelligence");
    Item Item12("Offensive_book", 12, 2, 0, 15, 0, 0, 0, 10, 0, "Increases magic damage by 5, reduces damage by 5 and grants +10 to intelligence");
    Item Item13("Defensive_book", 13, 2, 0, 0, 10, 0, 0, 5, 10, "Reduces damage by 10 grants +5 to intelligence and +10 to endurance");

    Item Item14("Ring_of_strength", 14, 3, 0, 0, 0, 5, 0, 0, 0, "Adds 5 to strength");
    Item Item15("Ring_of_intelligence", 15, 3, 0, 0, 0, 0, 0, 5, 0, "Adds 5 to intelligence");
    Item Item16("Ring_of_endurance", 16, 3, 0, 0, 0, 0, 5, 0, 0, "Adds 5 to endurance");
    Item Item17("Damage_ring", 17, 3, 5, 0, 0, 0, 5, 0, 0, "Adds 5 to damage");
    Item Item18("Defensive_ring", 18, 3, 0, 0, 5, 0, 5, 0, 0, "Adds 5 to damage reduction");
    Item Item19("Mage's_ring", 19, 3, 0, 5, 0, 0, 5, 0, 0, "Adds 5 to magic damage");
    Item Item20("Ring_of_dexterity", 20, 3, 0, 0, 0, 0, 5, 0, 0, "Adds 5 to dexterity");

    Item Item21("Divine_armour", 21, 4, 0, 0, 10, 10, 10, 10, 10, "Adds 10 to all attributes and provides 10 damage reduction");
    Item Item22("Mage's_robes", 22, 4, 0, 0, 5, 0, 0, 10, 0, "Adds 5 to intelligence and provides 5 damage reduction");
    Item Item23("Light_armour", 23, 4, 0, 0, 5, 0, 10, 0, 5, "Adds 20 to dexterity and 5 to endurance, and provides 5 damage reduction");
    Item Item24("Heavy_armour", 24, 4, 0, 0, 10, 0, -10, 0, 10, "Adds 10 to endurance but reducec dexterity by 10, and provides 10 damage reduction");
    string chooseditem;
    int random = rand() % 23+1;
    switch(random)
    {
        case 1:
        {
            chooseditem = Item1.name;
            break;
        }
        case 2:
        {
            chooseditem = Item2.name;
            break;
        }
        case 3:
        {
            chooseditem = Item3.name;
            break;
        }
        case 4:
        {
            chooseditem = Item4.name;
            break;
        }
        case 5:
        {
            chooseditem = Item5.name;
            break;
        }
        case 6:
        {
            chooseditem = Item6.name;
            break;
        }
        case 7:
        {
            chooseditem = Item7.name;
            break;
        }
        case 8:
        {
            chooseditem = Item8.name;
            break;
        }
        case 9:
        {
            chooseditem = Item9.name;
            break;
        }
        case 10:
        {
            chooseditem = Item10.name;
            break;
        }
        case 11:
        {
            chooseditem = Item11.name;
            break;
        }
        case 12:
        {
            chooseditem = Item12.name;
            break;
        }
        case 13:
        {
            chooseditem = Item13.name;
            break;
        }
        case 14:
        {
            chooseditem = Item14.name;
            break;
        }
        case 15:
        {
            chooseditem = Item15.name;
            break;
        }
        case 16:
        {
            chooseditem = Item16.name;
            break;
        }
        case 17:
        {
            chooseditem = Item17.name;
            break;
        }
        case 18:
        {
            chooseditem = Item18.name;
            break;
        }
        case 19:
        {
            chooseditem = Item19.name;
            break;
        }
        case 20:
        {
            chooseditem = Item20.name;
            break;
        }
        case 21:
        {
            chooseditem = Item21.name;
            break;
        }
        case 22:
        {
            chooseditem = Item22.name;
            break;
        }
        case 23:
        {
            chooseditem = Item23.name;
            break;
        }
        case 24:
        {
            chooseditem = Item24.name;
            break;
        }
        default:
        {
            cout << "No such item!" << endl;
            chooseditem = "Empty";
            break;
        }
    }
    return chooseditem;
}

