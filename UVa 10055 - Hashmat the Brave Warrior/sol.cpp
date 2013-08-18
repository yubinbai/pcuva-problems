#include <iostream>

using namespace std;

int main()
{

    long long hS, oS;

    while (cin >> hS >> oS)
    {
        if (hS < oS)
            cout << oS - hS << endl;
        else
            cout << hS - oS << endl;
    }
    return 0;
}