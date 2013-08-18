#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <sstream>
#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define getint(n) scanf("%d", &n)
#define pb(a) push_back(a)
#define ll long long
#define SZ size()
#define read() freopen("input.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define pi acos(-1.0)
#define INF 1<<29
#define mod(a) (a>0?a:-a)
using namespace std;
struct DATA
{
    int ara[11];
    char pos;
};
DATA boxes[31];
int number_of_boxes, count_dimentions;
int dir[31];
int dp[31];
bool compare(DATA a, DATA b)
{
    loop(i, count_dimentions)
    {
        if (a.ara[i] > b.ara[i])
        {
            return false;
        }
    }
    return true;
}
bool test(DATA a, DATA b)
{
    loop(i, count_dimentions)
    {
        if (a.ara[i] >= b.ara[i])
        {
            return false;
        }
    }
    return true;
}
int longest(int u)
{
    int &ret = dp[u];
    if ( ret != -1) return ret;
    int maxi = 0;
    for (int v = u + 1; v < number_of_boxes; v++)
    {
        if (test(boxes[u], boxes[v]))
        {
            if (maxi < longest(v))
            {
                maxi = longest(v);
                dir[u] =  v;
            }
        }
    }
    return ret = maxi + 1;
}
int main()
{
    int LIS;
    int from;
    while (scanf("%d %d", &number_of_boxes, &count_dimentions) == 2)
    {
        loop(i, number_of_boxes)
        {
            boxes[i].pos = i;
            loop(j, count_dimentions)
            {
                getint(boxes[i].ara[j]);
            }
        }
        loop(i, number_of_boxes)
        {
            sort(boxes[i].ara, boxes[i].ara + count_dimentions);
        }
        sort(boxes, boxes + number_of_boxes, compare);
        mem(dp, -1);
        mem(dir, -1);
        LIS = -1;
        loop(i, number_of_boxes)
        {
            if (longest(i) > LIS)
            {
                LIS = longest(i);
                from = i;
            }
        }
        printf("%d\n", LIS);
        while (dir[from] != -1)
        {
            printf("%d ", boxes[from].pos + 1);
            from = dir[from];
        }
        printf("%d\n", boxes[from].pos + 1);
    }
    return 0;
}