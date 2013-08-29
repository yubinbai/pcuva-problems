#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 20;
char str[N], str1[N], str2[N];
int dir[6][6] = { {0, 1, 2, 3, 4, 5}, {1, 5, 2, 3, 0, 4}, {2, 1, 5, 0, 4, 3}, {3, 1, 0, 5, 4, 2},
    {4, 0, 2, 3, 5, 1}, {5, 4, 2, 3, 1, 0}
};
bool fun();
int main()
{
    while (scanf("%s", str) != EOF)
    {
        for (int i = 0; i < 6; i++) str1[i] = str[i];
        for (int i = 0; i < 6; i++) str2[i] = str[i + 6];
        if (fun()) puts("TRUE");
        else puts("FALSE");
    }
    return 0;
}
bool fun()
{
    char temp[N] = {0};
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            temp[j] = str1[dir[i][j]];
        }
        for (int j = 0; j < 4; j++)
        {
            char cha;
            cha = temp[1];
            temp[1] = temp[2];
            temp[2] = temp[4];
            temp[4] = temp[3];
            temp[3] = cha;
            if (strcmp(temp, str2) == 0) return true;
        }
    }
    return false;
}
