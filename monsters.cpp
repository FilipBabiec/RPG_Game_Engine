#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include "monsters.hpp"

using namespace std;


Monster::Monster(string save)
  {
    name = save;
    clas = "Monster";
    textfile = save + ".txt";
    exp = rand() % 200+1;
    strength = rand() % 40+20;
    dexterity = rand() % 40+20;
    intelligence = rand() % 30+20;
    endurance = rand() % 40+20;
    crit = rand() % 10+1;
    maxhealth = rand() % 100+50;
    health = maxhealth;
    drop = rand() % 4+1;
  }

Monster::Monster(string save, string boss)
{
    int i;
    name = save+"(boss)";
    i = rand() % 10+1;
    if (i>0 && i<4)
    {
        clas = "Glass_Cannon";
        textfile = save+"_boss.txt";
        exp = 200;
        strength = rand() % 130+80;
        dexterity = rand() % 20+40;
        intelligence = rand() % 130+80;
        endurance = rand() % 10+10;
        crit = rand() % 30+15;
        maxhealth = rand() % 50+50;
        health = maxhealth;
        drop = rand() % 4+1;
    }
    if (i>=4 && i<7)
    {
        clas = "Tank";
        textfile = save+"_boss.txt";
        exp = 200;
        strength = rand() % 20+20;
        dexterity = rand() % 20+10;
        intelligence = rand() % 20+40;
        endurance = rand() % 40+60;
        crit = rand() % 10+1;
        maxhealth = rand() % 500+300;
        health = maxhealth;
        drop = rand() % 4+1;
    }
    if (i>=7 && i<10)
    {
        clas = "High";
        textfile = save+"_boss.txt";
        exp = 200;
        strength = rand() % 60+40;
        dexterity = rand() % 60+40;
        intelligence = rand() % 60+40;
        endurance = rand() % 60+40;
        crit = rand() % 20+1;
        maxhealth = rand() % 200+200;
        health = maxhealth;
        drop = rand() % 4+1;
    }
    if (i==10)
    {
        clas = "Elder";
        textfile = save+"_boss.txt";
        exp = 400;
        strength = rand() % 100+150;
        dexterity = rand() % 100+150;
        intelligence = rand() % 100+150;
        endurance = rand() % 100+150;
        crit = rand() % 20+1;
        maxhealth = rand() % 450+250;
        health = maxhealth;
        drop = rand() % 4+1;
    }

}

Monster::~Monster()
    {}