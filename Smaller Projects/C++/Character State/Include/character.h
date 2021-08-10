#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>

using namespace std;

class Character
{
private:
    string name, sirName;
    int hp, mana, exp, lvl, class_id;
    int spell_ids[4];
    int bag[10];
    int test_attack;

public:

    Character(string _name, string _sirName);
    string Get_Name();
    string Get_sirName();
    int Get_HP();

    void Modify_HP(int amnt);
};

#endif // CHARACTER_H
