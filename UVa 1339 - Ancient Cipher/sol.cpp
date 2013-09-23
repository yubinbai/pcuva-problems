#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    char x[101], y[101];
    while (gets(x))
    {
        gets(y);
        int len = strlen(x);
        int arr1[26], arr2[26];
        for (int i = 0; i < 26; i++)
        {
            arr1[i] = arr2[i] = 0;
        }
        for (int i = 0; i < len; i++)
        {
            arr1[x[i] - 65]++;
            arr2[y[i] - 65]++;
        }
        sort(arr1, arr1 + sizeof (arr1) / sizeof (arr1[0]));
        sort(arr2, arr2 + sizeof (arr2) / sizeof (arr2[0]));
        bool flag = true;
        for (int i = 0; i < 26; i++)
        {
            if (arr1[i] != arr2[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}