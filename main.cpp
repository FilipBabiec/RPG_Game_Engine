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
#include "templates.hpp"
#include "hero.hpp"
#include "monsters.hpp"
#include "functions.hpp"


#ifdef __unix__
#include <unistd.h>
#elif _WIN32 || _WIN64
#include <windows.h>
#endif

using namespace std;

int main() {
    string charact, ans, sfile, line;
    int p, ind, outcome, attack_type, ma;
    vector<string> list;

    ifstream listf("savelist.txt");
    if (listf.good()==true)
    {
        while(getline(listf,line))
        {
            list.push_back(line);
        }
        listf.close();
    }
    do {
        clearscreen();
        cout << "Welcome to the RPG character creator!\n" << endl;
        cout << "1. Create a new character\n" <<
                "2. Load and manage an existing character\n" <<
                "3. Delete an existing character\n" <<
                "4. Enter the arena\n" <<
                "5. Exit the program\n" << endl;
        cin >> p;
        switch (p) {
            case 1: {
                clearscreen();
                cout << "Create a new character:" << endl;
                cin >> charact;
                cout << endl;
                Hero character (charact);
                classchoosing(character);
                list.push_back(charact);
                clearscreen();
                character.level_up(300, 1);
                clearscreen();
                dispcharacter(character);
                cout << "Do you want to save your hero?(Y/N)" << endl;
                cin >> ans;
                if (ans=="y")
                {
                    savecharacter(character);
                    saveinitinventory(character);
                    Equipment eq;
                    saveeq(eq, character);
                }

                clearscreen();
                break;
            }
            case 2: {
                clearscreen();
                cout << "Load an existing character:" << endl;
                for (unsigned int l1 = 0; l1 < list.size(); l1++)
                {
                    cout << list[l1] << endl;
                }
                cout << "" <<endl;
                cin >> charact;
                Hero character;
                loadcharacter(character, charact, ind);
                if (ind == 1)
                {
                    clearscreen();
                    Equipment eq;
                    dispcharacter(character);
                    disphistory(character);
                    cout << "\nIf you want to see inventory type 'inv', if you want to go back, type 'quit': ";
                    cin >> ans;
                    loadeq(eq, character);
                    if (ans!="quit")
                    {
                        dispinventory1(character);
                    }
                    while (ans!="quit")
                    {
                        clearscreen();
                        dispinventory2(character);
                        cout << "\nIf you want to check any item, enter its name and if you want to change your equipment, type 'eq', if you want to go back type 'quit': " << endl;
                        cin >> ans;
                        Item item;
                        if (ans=="eq")
                        {
                            cout << "What item do you want to equip: " << endl;
                            cin >> ans;
                            item = itemchooser(ans);
                            int verified = itemverifier(item.name, character.eq);
                            if (verified == 1)
                            {
                                if (item.name != "Empty")
                                {
                                    Equipment eq1(eq, item);
                                    saveeq(eq1, character);
                                }
                            }
                            else if (verified == 0)
                            {
                                cout << "You do not have this item!" << endl;
                                spanko(3);
                            }
                        }
                        else if (ans=="quit")
                        {}
                        else
                        {

                            clearscreen();
                            int l = 0;
                            character.finder(l, ans);
                        }
                    }
                }
                else spanko(3);
                break;
            }
            case 3: {
                clearscreen();
                cout << "Delete an existing character:" << endl;
                for (unsigned int l1 = 0; l1 < list.size(); l1++)
                {
                    cout << list[l1] << endl;
                }
                cout << "" << endl;
                cin >> charact;
                cout << endl;
                deletecharacter(charact);
                list.erase(remove(list.begin(), list.end(), charact), list.end());
                spanko(3);
                break;
            }
            case 4: {
                clearscreen();
                cout << "Choose a character:" << endl;
                for (unsigned int l1 = 0; l1 < list.size(); l1++)
                {
                    cout << list[l1] << endl;
                }
                cout << "" <<endl;
                Hero character;
                do {
                    cin >> charact;
                    loadcharacter(character, charact, ind);
                    if (ind == 1) {}
                    else spanko(3);
                } while (ind==2);
                Arena(character);
                break;
            }
            case 5: {
                ofstream listfile("savelist.txt", ios::out);
                for (unsigned int l2 = 0; l2 < list.size(); l2++)
                {
                    listfile << list[l2] << endl;
                }
                listfile.close();
                return 0;
                break;
            }
            default: {
                cout << "That is not an option!" << endl;
                spanko(3);
            }
        }
    } while(true);

}