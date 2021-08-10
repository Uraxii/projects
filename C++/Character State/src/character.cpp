#include "character.h"

Character::Character(string _name, string _sirName)
{
    this->name = _name;
    this->sirName = _sirName;
    this->hp = 100;
    this->mana = 100;
    this->exp = 0;
    this->lvl = 1;
    this->bag[10];
    this-> test_attack = 10;
}

//Getters
string Character::Get_Name() { return name; }
string Character::Get_sirName() { return sirName; }
int Character::Get_HP() { return hp; }

void Character::Modify_HP(int amnt){hp + amnt;} //Pass a negative num to subtract.
