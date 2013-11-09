#include<iostream>
#include "stdio.h"
#include "stdlib.h"
#include<cctype>
#include<string>
using namespace std;
int main()
{
    int t = 0;
    char ch[256];
    fgets ( ch, 256, stdin );
    t = atoi (ch);
    for (int i = 1; i <= t; i++)
    {
        int j = 0;
        string user;
        string judge;
        getline(cin, user, '\n');
        getline(cin, judge, '\n');
        if (user == judge)
        {
            cout << "Case " << i << ": Yes" << endl;
            continue;
        }
        for (j = 0; j < user.length(); j++)
        {
            if (isspace(user[j]))
            {
                user.erase(j, 1);
                j--;
            }
        }
        if (user == judge)
            cout << "Case " << i << ": Output Format Error" << endl;
        else
            cout << "Case " << i << ": Wrong Answer" << endl;
    }
    return 0;
}