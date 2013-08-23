#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
using namespace std;
#define MAXN 1010

int t , len;
int x[MAXN] , y[MAXN];
int vis[MAXN];

int solve()
{
    int max = 1 , tmp_max;
    int i , j , k;
    int tmp_x1 , tmp_y1 , tmp_x2 , tmp_y2;
    for (i = 0 ; i < len ; i++) //枚举点A
    {
        for (j = i + 1 ; j < len ; j++) //枚举点B
        {
            tmp_x1 = x[j] - x[i] ; tmp_y1 = y[j] - y[i];
            tmp_max = 2;
            for (k = j + 1 ; k < len ; k++) //枚举点C
            {
                tmp_x2 = x[k] - x[i] ; tmp_y2 = y[k] - y[i];
                if (tmp_y1 * tmp_x2 == tmp_y2 * tmp_x1)
                    tmp_max++;
            }
            if (max < tmp_max) max = tmp_max; //更新max
        }
    }
    printf("%d\n" , max);
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int i;
    char ch[100];
    scanf("%d%*c" , &t);
    getchar();//这里换行
    while (t--)
    {
        i = 0;
        while (gets(ch))
        {
            if (!ch[0] && i) break; //注意如果gets没有读入东西则第一个为NULL即0
            sscanf(ch , "%d%d", &x[i] , &y[i]);
            i++;
        }
        len = i ;
        solve(); if (t) printf("\n");
    }
    return 0;
}