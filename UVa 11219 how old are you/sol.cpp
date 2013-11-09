#include<iostream>
#include "stdio.h"
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int cd = 0, cm = 0, cy = 0, bd = 0, bm = 0, by = 0;
        scanf("%d/%d/%d", &cd, &cm, &cy);
        scanf("%d/%d/%d", &bd, &bm, &by);
        cout << "Case #" << i << ": ";
        int age = cy - by;
        if (cm < bm)
            age -= 1;
        if (cm == bm && cd < bd)
            age -= 1;
        if (age < 0)
            cout << "Invalid birth date" << endl;
        else if (age > 130)
            cout << "Check birth date" << endl;
        else
            cout << age << endl;
    }
    return 0;
}