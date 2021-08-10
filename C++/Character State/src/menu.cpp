#include "menu.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void Menu()
{
    cout << "--->>MENU<<---" << endl;
    cout << "    RESUME" <<  endl;
    cout << "     QUIT" << endl;

    string selection;
    cin >> selection;

    if(selection == "quit")
    {
        cout << "Exit? (y/n): ";
        cin >> selection;

        if(selection == "y") { cout << "Exiting program..." << endl; exit(0); } //Exits program w/ error code 0.
    }

}

