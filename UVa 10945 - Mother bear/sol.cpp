#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
    int i, len, count, j, k, len1;
    char ch[1000], input[1000], revers[1000];
    memset(input, '\0', sizeof(input));
    memset(revers, '\0', sizeof(revers));
    while (gets(ch))
    {
        if (strcmp(ch, "DONE") == 0)
            break;
        len = strlen(ch);
        count = 0;
        for (i = 0; i < len; i++)
        {
            if (ch[i] >= 65 && ch[i] <= 90)
                input[count++] = ch[i] + 32;
            else if (ch[i] >= 97 && ch[i] <= 122)
                input[count++] = ch[i];
        }
        len1 = strlen(input);
        k = 0;
        for (j = len1 - 1; j > -1; j--)
            revers[k++] = input[j];
        if (strcmp(input, revers) == 0)
            printf("You won't be eaten!\n");
        else
            printf("Uh oh..\n");
        memset(ch, '\0', sizeof(ch));
        memset(input, '\0', sizeof(input));
        memset(revers, '\0', sizeof(revers));
    }
    return 0;
}
