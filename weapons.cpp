#include "templates.hpp"
#include <map>
#include <string>

Item::Item(string namen)
{
    name = namen;
}

Item::Item()
{}

Item::Item(string namen, int idn, int placen, int statn1, int statn2, int statn3, int statn4, int statn5, int statn6,int statn7,string effectn)
    {
        place = placen;
        name = namen;
        id = idn;
        dmgw = statn1;
        dmgi = statn2;
        dmgr = statn3;
        strw = statn4;
        dexw = statn5;
        intw = statn6;
        endw = statn7;
        effect = effectn;
    }
	
	Item Item1("Sword_of_ice", 1, 1, 10, 0, 0, 2, 0, 0, 0, "Deals 10 additional physical damage and grants +2 strength");
    Item Item2("Sword_of_fire", 2, 1, 5, 0, 0, 4, 0, 0, 0, "Deals 5 additional physical damage and grants +4 strength");
    Item Item3("Giant_sword", 3, 1, 15, 0, 0, 10, -20, 0, 0, "Deals 15 additional physical damage and grants +10 strength, but lowers dexterity by 20");
    Item Item4("Sword_of_magic", 4, 1, 10, 0, 0, 10, 10, 10, 0, "Deals 10 additional physical damage and grants 10 to strength, dexterity and intelligence");
    Item Item5("Swift_sword", 5, 1, 5, 0, 0, 10, 15, 0, 0, "Deals 5 additional physical damage and grants +10 strength and +15 dexterity");
    Item Item6("Defensive_sword", 6, 1, 0, 0, 5, 5, 0, 0, 10, "Reduces damage by 5 and grants +5 to strength and +10 to endurance");

    Item Item7("Magic_shield", 7, 2, 0, 0, 10, 0, 0, 10, 5, "Reduces damage by 10 and grants +10 to intelligence");
    Item Item8("Shield_of_power", 8, 2, 0, 0, 10, 10, 10, 10, 10, "Reduces damage by 10 and grants +10 to all attributes");
    Item Item9("Offensive_shield", 9, 2, 0, 0, 5, 10, 10, 0, 0, "Reduces damage by 10 and grants +10 to intelligence");
    Item Item10("Regular_shield", 10, 2, 0, 0, 10, 0, 0, 0, 10, "Reduces damage by 10 and grants +10 to intelligence");

    Item Item11("Magical_book", 11, 2, 0, 5, 5, 0, 0, 10, 0, "Increases magic damage by 5, reduces damage by 5 and grants +10 to intelligence");
    Item Item12("Offensive_book", 12, 2, 0, 15, 0, 0, 0, 10, 0, "Increases magic damage by 5, reduces damage by 5 and grants +10 to intelligence");
    Item Item13("Defensive_book", 13, 2, 0, 0, 10, 0, 0, 5, 10, "Reduces damage by 10 grants +5 to intelligence and +10 to endurance");

    Item Item14("Ring_of_strength", 14, 3, 0, 0, 0, 5, 0, 0, 0, "Adds 5 to strength");
    Item Item15("Ring_of_intelligence", 15, 3, 0, 0, 0, 0, 0, 5, 0, "Adds 5 to intelligence");
    Item Item16("Ring_of_endurance", 16, 3, 0, 0, 0, 0, 5, 0, 0, "Adds 5 to dexterity");
    Item Item17("Damage_ring", 17, 3, 5, 0, 0, 0, 5, 0, 0, "Adds 5 to damage");
    Item Item18("Defensive_ring", 18, 3, 0, 0, 5, 0, 5, 0, 0, "Adds 5 to damage");
    Item Item19("Mage's_ring", 19, 3, 0, 5, 0, 0, 5, 0, 0, "Adds 5 to magic damage");
    Item Item20("Ring_of_dexterity", 20, 3, 0, 0, 0, 0, 5, 0, 0, "Adds 5 to dexterity");

    Item Item21("Divine_armour", 21, 4, 0, 0, 10, 10, 10, 10, 10, "Adds 10 to all attributes and provides 10 damage reduction");
    Item Item22("Mage's_robes", 22, 4, 0, 0, 5, 0, 0, 10, 0, "Adds 5 to intelligence and provides 5 damage reduction");
    Item Item23("Light_armour", 23, 4, 0, 0, 5, 0, 10, 0, 5, "Adds 20 to dexterity and 5 to endurance, and provides 5 damage reduction");
    Item Item24("Heavy_armour", 24, 4, 0, 0, 10, 0, -10, 0, 10, "Adds 10 to endurance but reducec dexterity by 10, and provides 10 damage reduction");

    map<string, Item> Item_list;
/*
Item_list["Sword_of_ice"] = Item1;
Item_list["Sword_of_fire"] = Item2;
Item_list["Giant_sword"] = Item3;
Item_list["Sword_of_magic"] = Item4;
Item_list["Swift_sword"] = Item5;
Item_list["Defensive_sword"] = Item6;
Item_list["Magic_shield"] = Item7;
Item_list["Shield_of_power"] = Item8;
Item_list["Offensive_shield"] = Item9;
Item_list["Regular_shield"] = Item10;
Item_list["Magical_book"] = Item11;
Item_list["Offensive_book"] = Item12;
Item_list["Defensive_book"] = Item13;
Item_list["Ring_of_strength"] = Item14;
Item_list["Ring_of_intelligence"] = Item15;
Item_list["Ring_of_endurance"] = Item16;
Item_list["Damage_ring"] = Item17;
Item_list["Defensive_ring"] = Item18;
Item_list["Mage's_ring"] = Item19;
Item_list["Ring_of_dexterity"] = Item20;
Item_list["Divine_armour"] = Item21;
Item_list["Mage's_robes"] = Item22;
Item_list["Light_armour"] = Item23;
Item_list["Heavy_armour"] = Item24;

*/