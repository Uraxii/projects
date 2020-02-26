#include <iostream>

using namespace std;

//-----     FUNCTIONS       -----

/**
* Parses command input and determines where to move player.
* Actual max values should be <max value> - 1. So the if maxZ = 3, the highest value Z the player should have is 2 because there is a floor 0.
*
* @param player coordinate int values, maximum coordinate values, room array qualities, and the command string.
* @return player coordinates as x,y,z.
*/
int Move(int x, int y, int z, int maxX, int maxY, int maxZ, int roomNum, int roomQualities[], string command)
{
    char action;
    for(int i = 0; i < command.length(); i++)
    {
        if(command[i-1] == ' ' && isalpha(command[i])) action = command[i];
        else action = command[1];
    }


    if(action == 'n' && roomQualities[3] == 1)
    {
        cout << "You walk North." << endl;
        //return x, y+1, z, roomNum+1;
        return 1;
    }

    else if(action == 's' && roomQualities[4] == 1)
        {
            cout << "You walk South." << endl;
            //return x, y-1, z, roomNum-1;
            return 2;
        }

    else if(action == 'e' && roomQualities[5] == 1)
    {
        cout << "You walk East." << endl;
        //return x-1, y, z, roomNum+maxY;
        return 3;
    }

    else if(action == 'w' && roomQualities[6] == 1)
    {
        cout << "You walk West." << endl;
        //return x+1, y, z, roomNum-maxY;
        return 4;
    }

    else if(action == 'u' && roomQualities[7] == 1)
    {
        cout << "You walk up to the floor above you." << endl;
        //return x, y, z+1, roomNum;
        return 5;
    }

    else if(action == 'd' && roomQualities[8] == 1)
    {
        cout << "You walk down to the floor below you." << endl;
        //return x, y, z-1, roomNum;
        return 6;
    }

    else
    {
        cout << "You ran around the room aimlessly. Never finding, and ultimately forgetting, exactly what you were searching for." << endl;
        return 0;
    }
}

/**
* Outputs formated statement of a coordinate.
*
* @param 4 ints that will be formated as room# (x,y,z) and output to the console.
* @return void
*/
void Position(int x, int y, int z, int room)
{
    cout << "You are in room " << room << " at (" << x << "," << y << "," << z << ")." << endl;
}

/**
*
* Returns int of current room player is in.
*
* @param player x, player y, player z, array of the floor they are in.
* @return returns int i of the current position the player is in.
*/
int Current_Room(int x, int y, int roomQualities[])
{
        //Found match
        if(roomQualities[1] == x && roomQualities[2] == y) return roomQualities[0];
        //Did not find a match
        return -1;
}

/**
*
*
*
*
*/
void Look(int roomQualities[])
{
    if(roomQualities[3] == 1) cout << "You see a door to the North." << endl;
    if(roomQualities[4] == 1) cout << "You see a door to the South." << endl;
    if(roomQualities[5] == 1) cout << "You see a door to the East." << endl;
    if(roomQualities[6] == 1) cout << "You see a door to the West." << endl;
    if(roomQualities[7] == 1) cout << "You see stairs leading up." << endl;
    if(roomQualities[8] == 1) cout << "You see stairs leading down." << endl;
}

/**
*
* Lists commands that can be done.
*
* @param null
* @return void
*/
void Help()
{
    cout << "-----  COMMANDS MENU   -----" << endl;
    cout << "Position: Gives the players position." << endl;
    cout << "Quit: Exits the game." << endl;
}

/**
*
* Returns a passed in string as lower case.
*
* @param string that will have all its characters set to lower case.
* @return Returns the lower case of a passed in string.
*/
string Lower_Case(string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}


//-----     MAIN FUNCTION   -----
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
    int pX = 0, pY = 0, pZ = 0, pRoom = 0;
    int pHealth = 10, pMana = 10;
    int pLvl = 0, pXP = 0;
    int pGold = 0;

    //Game loop variables
    bool playing = true;
    string cmd;
    int moveAction = 0;

    //-----         GENERATE DUNGEON ARRAY     -----

    //Generates floors
    for(int z_coordinate = 0; z_coordinate < maxZ; z_coordinate++)
    {
        roomNumber = 0;
        //Generates rows on x-coordinate
        for(int x_coordinate = maxX*(-1); x_coordinate < maxX; x_coordinate++)
        {
            //Generates columns on y-coordinate
            for(int y_coordinate = maxY*(-1); y_coordinate < maxY; y_coordinate++)
            {
                //Assigns qualities to the room
                dungeon[z_coordinate][roomNumber][0] = roomNumber; //Number of room in floor
                dungeon[z_coordinate][roomNumber][1] = x_coordinate; //X position in floor
                dungeon[z_coordinate][roomNumber][2] = y_coordinate; //Y position in floor
                dungeon[z_coordinate][roomNumber][3] = 1; //North Door, 1 = true, 0 = false
                dungeon[z_coordinate][roomNumber][4] = 1; //South Door, 1 = true, 0 = false
                dungeon[z_coordinate][roomNumber][5] = 1; //East Door, 1 = true, 0 = false
                dungeon[z_coordinate][roomNumber][6] = 1; //West Door, 1 = true, 0 = false
                dungeon[z_coordinate][roomNumber][7] = 1; // Stairs Up, 1 = true, 0 = false
                dungeon[z_coordinate][roomNumber][8] = 1; // Stairs Down, 1 = true, 0 = false
                dungeon[z_coordinate][roomNumber][9] = 0;
                dungeon[z_coordinate][roomNumber][10] = 0;
                dungeon[z_coordinate][roomNumber][11] = 0;
                dungeon[z_coordinate][roomNumber][12] = 0;
                dungeon[z_coordinate][roomNumber][13] = 0;
                dungeon[z_coordinate][roomNumber][14] = 0;
                dungeon[z_coordinate][roomNumber][15] = 0;
                dungeon[z_coordinate][roomNumber][16] = 0;
                dungeon[z_coordinate][roomNumber][17] = 0;
                dungeon[z_coordinate][roomNumber][18] = 0;
                dungeon[z_coordinate][roomNumber][19] = 0;
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

    //Find the current room player is in
    int floorSize = sizeof(dungeon[pZ])/sizeof(dungeon[pZ][0]); //Don't ask my why this works right now. I'm not sure.
    //cout << "floorSize: " << floorSize << endl;
    int findRoom = 0;
    for(int i = 0; i < floorSize; i++)
    {
        findRoom = Current_Room(pX, pY, dungeon[pZ][i]);
        if(findRoom != -1) pRoom = findRoom;
    }

    //-----     GAME LOOOP       -----
    while (playing)
    {
        cout << "What will you do?: ";
        getline(cin, cmd);

        //Converts input to lower case
        cmd = Lower_Case(cmd);

        // -----    COMMANDS    -----

        //Moves player's grid position
        if(cmd[0] == 'm')
        {
            moveAction = Move(pX, pY, pZ, maxX, maxY, maxZ, pRoom, dungeon[pZ][pRoom],cmd);

            if(moveAction == 1)
            else if(moveAction == 2)
            else if(moveAction == 3)
            else if(moveAction == 4)
            else if(moveAction == 5)
            else if(moveAction == 6)
        }

        else if(cmd[0] == 'l') Look(dungeon[pZ][pRoom]);

        //Prints room number and coordinate position of player
        else if(cmd[0] == 'p') Position(pX, pY, pZ, pRoom);

        //Prints Help Menu
        else if(cmd == "help") Help();

        //Prints Hello!
        else if(cmd == "hello") cout << "Hello!" << endl;

        //Quits game
        else if (cmd == "quit")
            {
                playing = false;
                cout << "Quiting game..." << endl;
                break;
            }

        else cout << "INVALID COMMAND. TYPE HELP FOR A LIST OF COMMANDS" << endl;

        cout << "-----      -----" << endl;
    }

}
