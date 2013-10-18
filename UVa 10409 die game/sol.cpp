#include <iostream>
#include "string.h"
using namespace std;
// prototypes
void callEast(int &top, int &bottom, int &east, int &west, int &north, int &south);
void callWest(int &top, int &bottom, int &east, int &west, int &north, int &south);
void callNorth(int &top, int &bottom, int &east, int &west, int &north, int &south);
void callSouth(int &top, int &bottom, int &east, int &west, int &north, int &south);
//==========================================================================
int main()
{
    int top, bottom, east, west, north, south;
    int command;
    char str[100];
    int i;
    while (cin >> command)
    {
        if (command == 0) break;
        // first initialized
        top = 1; bottom = 6; east = 4; west = 3; north = 2; south = 5;
        for (i = 0; i < command; i++)
        {
            cin >> str;
            if (strcmp(str, "north") == 0)
                callNorth(top, bottom, east, west, north, south);
            else if (strcmp(str, "south") == 0)
                callSouth(top, bottom, east, west, north, south);
            else if (strcmp(str, "east") == 0)
                callEast(top, bottom, east, west, north, south);
            else if (strcmp(str, "west") == 0)
                callWest(top, bottom, east, west, north, south);
        }
        cout << top << endl;
    }
    return 0;
}
//============================================================================
void callNorth(int &top, int &bottom, int &east, int &west, int &north, int &south)
{
    int tempBottom = bottom;
    int tempTop = top;
    top = south;
    bottom = north;
    south = tempBottom;
    north = tempTop;
}
void callSouth(int &top, int &bottom, int &east, int &west, int &north, int &south)
{
    int tempBottom = bottom;
    int tempTop = top;
    top = north;
    bottom = south;
    south = tempTop;
    north = tempBottom;
}
void callEast(int &top, int &bottom, int &east, int &west, int &north, int &south)
{
    int tempBottom = bottom;
    int tempTop = top;
    top = west;
    bottom = east;
    west = tempBottom;
    east = tempTop;
}
void callWest(int &top, int &bottom, int &east, int &west, int &north, int &south)
{
    int tempBottom = bottom;
    int tempTop = top;
    top = east;
    bottom = west;
    east = tempBottom;
    west = tempTop;
}