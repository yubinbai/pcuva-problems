#include "stdio.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct NameId
{
    string name;
    int id;
};

int main()
{
    //freopen("input.txt", "r", stdin);

    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        int n;
        cin >> n;
        cin.ignore();

        map<string, int> desiredMap;
        vector<NameId> original;
        vector<string> desiredVector;
        NameId nameId;
        string name;

        // Read the original order
        for (int j = 0; j < n; j++)
        {
            getline(cin, name);
            nameId.id = 0; // we don't know the id yet, we need to read the desired order first
            nameId.name = name;
            original.push_back(nameId);
        }

        // Read the desired order
        for (int j = 0; j < n; j++)
        {
            getline(cin, name);
            desiredMap[name] = j; // the first desired element will be 0, the 2nd 1 and so forth
            desiredVector.push_back(name); // just the same relationship but as vector so we can acess it via index
        }

        // Now write the correct id for the original order
        for (int j = 0; j < n; j++)
        {
            original[j].id = desiredMap[original[j].name];
        }

        // A turtle is said to be in reverse if its number is less than the biggest number of the turtles above it in
        int biggest = -1, biggestReverse = -1;
        for (int j = 0; j < n; j++)
        {
            if (original[j].id > biggest)
                biggest = original[j].id;
            else if (original[j].id > biggestReverse)
                biggestReverse = original[j].id;
        }

        // We just have to print the names now
        for (int j = biggestReverse; j >= 0; j--)
        {
            cout << desiredVector[j] << endl;
        }

        cout << endl;
    }

    return 0;
}