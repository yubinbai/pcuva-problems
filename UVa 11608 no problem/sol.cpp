#include<iostream>
using namespace std;
int remain;
int in[12];
int out[12];
int problem(int i)
{
    if (out[i] <= remain)
    {
        remain += (in[i] - out[i]);
        return 1;
    }
    remain += in[i];
    return 0;
}
int main()
{
    int tc = 1;
    while (cin >> remain && remain >= 0)
    {
        for (int i = 0; i < 12; i++)cin >> in[i];
        for (int i = 0; i < 12; i++)cin >> out[i];
        cout << "Case " << tc++ << ":" << endl;
        for (int i = 0; i < 12; i++)
            if (problem(i))
                cout << "No problem! :D\n";
            else
                cout << "No problem. :(\n";
    }
    return 0;
}