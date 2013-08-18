#include <iostream>

using namespace std;

int main()
{
    int cases;
    int farmers;
    long premium;
    long size, animals, environment;

    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        cin >> farmers;
        premium = 0;
        for (int j = 0; j < farmers; j++)
        {
            cin >> size >> animals >> environment;
            premium += size * environment;
        }
        cout << premium << endl;
    }

    return 0;
}