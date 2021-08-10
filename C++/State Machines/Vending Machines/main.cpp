#include <iostream>
#include <string>

using namespace std;

enum MachineState
{
    SELECT = 0, QUANTITY = 1, CALCULATE = 2, UPDATE = 3
};

enum Brand
{
    COKE = 100, PEPSI = 200, SEVEN_UP = 300
};

struct User
{
    string name;
    int points;
};

struct Soda
{
    Brand brandName;
    int inventory;
    int price;
};

int main()
{

    MachineState currentState = SELECT;

    Soda vendingMachine[3];

    vendingMachine[0].brandName = COKE;
    vendingMachine[0].inventory = 10;
    vendingMachine[0].price = 1000;

    vendingMachine[1].brandName = PEPSI;
    vendingMachine[1].inventory = 10;
    vendingMachine[1].price = 2000;

    vendingMachine[2].brandName = SEVEN_UP;
    vendingMachine[2].inventory = 10;
    vendingMachine[2].price = 3000;

    Soda selectedSoda;
    User eric;
    eric.name = "ERIC";
    eric.points = 100000;

    int length = *(&vendingMachine+1) - vendingMachine; //Length of array vending machine   --->>   https://www.geeksforgeeks.org/how-to-find-size-of-array-in-cc-without-using-sizeof-operator/

    cout << "<<---CURRENT STATUS--->>" << endl;
    cout << "[[Vending Machine]]" << endl;
    for(int i = 0; i < length; i++)
    {
        cout << vendingMachine[i].brandName << " : " << vendingMachine[i].inventory << " : " << vendingMachine[i].price << endl;
    }

    cout << "[[USER]]" << endl;
    cout << eric.name << ": " << eric.points << " points" << endl;
    cout << "<<---END STATUS--->>" << endl << endl;

    cout << "Please make a drink selection: ";
    int selectedDrink;
    cin >> selectedDrink;

    cout << selectedDrink<< endl;
    switch(currentState)
    {

        switch(selectedDrink)
        {
        case COKE:
            selectedSoda.brandName = COKE;
            currentState = QUANTITY;
        case PEPSI:
            selectedSoda.brandName = PEPSI;
            currentState = QUANTITY;
        case SEVEN_UP:
            selectedSoda.brandName = SEVEN_UP;
            currentState = QUANTITY;
        default:
            cout << "!!!INVALID DRINK SELECTION!!!" << endl;
            break;

        }

    case SELECT:
        break;

    case QUANTITY:
        break;

    case CALCULATE:
        break;

    case UPDATE:
        break;

    default:
        cout << "!!!ERROR!!! INVALID STATE DETECTED" << endl;
    }

    return 0;
}
