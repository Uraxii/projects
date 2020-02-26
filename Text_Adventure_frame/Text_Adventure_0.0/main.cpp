#include <iostream>

using namespace std;

//-----     FUNCTIONS       -----

void Position(int x, int y)
{
    cout << "You are at (" << x << ", " << y << ")." << endl;
}

int main()
{
    //-----     INIT VARIABLES       -----

    //Map variables
    int maxX = 4, maxY = 3, maxZ = 3;
    int maxRooms = maxX*maxY*4;
    int maxRoomQualities = 20;
    int dungeon[maxZ][maxRooms][maxRoomQualities];
    int roomNumber = 0;

    //Player variables
    int pX = 0;
    int pY = 0;
    int pHealth = 100;
    int pMana = 100;
    int pGold = 0;

    //Game loop variables
    bool playing = true;
    string cmd;

    //-----         GENERATES DUNGEON ARRAY     -----

    //Generates floors
    for(int z_coordinate = 0; z_coordinate < maxZ; z_coordinate++)
    {
        roomNumber = 0;
        //Generates rows on x-coordinate
        for(int x_coordinate = maxX*-1; x_coordinate < maxX; x_coordinate++)
        {
            //Generates columns on y-coordinate
            for(int y_coordinate = maxY*-1; y_coordinate < maxY; y_coordinate++)
            {
                //Assigns qualities to the room
                dungeon[z_coordinate][roomNumber][0] = roomNumber;
                dungeon[z_coordinate][roomNumber][1] = x_coordinate;
                dungeon[z_coordinate][roomNumber][2] = y_coordinate;
                dungeon[z_coordinate][roomNumber][3] = 99;
                dungeon[z_coordinate][roomNumber][4] = 99;
                dungeon[z_coordinate][roomNumber][5] = 99;
                dungeon[z_coordinate][roomNumber][6] = 99;
                dungeon[z_coordinate][roomNumber][7] = 99;
                dungeon[z_coordinate][roomNumber][8] = 99;
                dungeon[z_coordinate][roomNumber][9] = 99;
                dungeon[z_coordinate][roomNumber][10] = 99;
                dungeon[z_coordinate][roomNumber][11] = 99;
                dungeon[z_coordinate][roomNumber][12] = 99;
                dungeon[z_coordinate][roomNumber][13] = 99;
                dungeon[z_coordinate][roomNumber][14] = 99;
                dungeon[z_coordinate][roomNumber][15] = 99;
                dungeon[z_coordinate][roomNumber][16] = 99;
                dungeon[z_coordinate][roomNumber][17] = 99;
                dungeon[z_coordinate][roomNumber][18] = 99;
                dungeon[z_coordinate][roomNumber][19] = 99;
                //cout << "Created room " << roomNumber << " on floor " << z_coordinate << " @ (" << x_coordinate << ", " << y_coordinate << ")" << endl;
                roomNumber++;
            }
        }
    }

    /*
    //Qualities of the generated rooms
    for(int row = 0; row < maxZ; row++)
    {
        cout << "-----  FLOOR " << row << " -----" << endl;

        for(int column = 0; column < maxRooms; column++)
        {
            cout << "Room " << dungeon[row][column][0] << " properties:\n";

            for (int index = 0; index < maxRoomQualities; index++)
            {
                    cout << dungeon[row][column][index] << ", ";
            }

            cout << "\n-----      -----" << endl;
        }
        cout << endl;
    }
    */

    //-----     GAME LOOOP       -----
    while (playing)
    {
        cout << "What will you do?: ";
        cin >> cmd;
        //Converts input to lower case
        for(int i = 0; i < cmd.length(); i++)
        {
            cmd[i] = tolower(cmd[i]);
        }
        cout << "command: " << cmd << endl;

        //
        if(cmd[0] == 'p') Position(pX, pY);
        else if(cmd == "help")
            {
                cout << "-----  COMMANDS MENU   -----" << endl;
                cout << "Position: Gives the players position." << endl;
                cout << "Quit: Exits the game." << endl;
            }
        else if (cmd == "quit")
            {
                cout << "Quiting game..." << endl;
                break;
            }
        else if(cmd == "hello") cout << "Hello!" << endl;
        else cout << "INVALID COMMAND. TYPE HELP FOR A LIST OF COMMANDS" << endl;
        cout << "-----      -----" << endl;
    }

}
