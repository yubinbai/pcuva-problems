#include<iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int e, f, c;
        cin >> e >> f >> c;
        int init = e + f, total = 0, rem = init % c;
        while (init >= c)
        {
            int fresh = init / c;
            init = fresh + rem;
            rem = init % c;
            total += fresh;
        }
        cout << total << endl;
    }
}