#include <iostream>
#include "character.h"
#include "moving.h"
#include "combat.h"
#include "talking.h"
#include "inventory.h"
#include "menu.h"

using namespace std;

enum State
{
    idle,
    moving,
    fight,
    talking,
    inventory,
    menu,
};


State playerState; //Initializes state variable characterState

int main()
{
    Character player("Test", "Player");
    cout << "player name: " << player.Get_Name() << " " << player.Get_sirName() << endl;

    Character monster("Test", "Monster");
    cout << "Monster name: " << monster.Get_Name() << " " << monster.Get_sirName() << endl << endl;

    string command;
    bool run = true;

    while(run)
    {
        playerState = idle;
        cout << "What will you do?: ";
        cin >> command;

        if(command == "move") playerState = moving;
        else if(command == "fight") playerState = fight;
        else if(command == "talk") playerState = talking;
        else if(command == "bag") playerState = inventory;
        else if(command == "menu") playerState = menu;
        else cout << "!!!INVALID COMMAND!!!\tcommand:" << command <<endl;

        switch(playerState)
        {
        case(idle): break;
        case(moving): Moving(); break;
        case(fight): Combat(); break;
        case(talking): Talking(); break;
        case(inventory): Inventory(); break;
        case(menu): Menu(); break;
        default: cout << "!!!INVALID STATE!!!\tcharacterState:" << playerState << endl;
        }
    }

    return 0;
}
