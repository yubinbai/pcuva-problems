#include <cstring>
#include <iostream>
#include <cstdio>
#include <string>
#include <utility>
using namespace std;

const int MAXN = 100;
int G[MAXN][MAXN];
int ns, np;
int A[MAXN][MAXN];
bool vis[MAXN][MAXN];
string sw[MAXN], pw[MAXN];
pair<int, int> next[MAXN][MAXN];
bool first;

bool read_input()
{
    first = true;
    memset(G, 0, sizeof(G));
    memset(vis, 0, sizeof(vis));
    ns = np = 0;
        while (cin >> sw[ns]) if (sw[ns] == "#") break; else ns++;
        while (cin >> pw[np]) if (pw[np] == "#") break; else np++;
    return !cin.fail();
}

int f(int i, int j)
{
    if (i < 0 || j < 0)
        return 0;
    if (vis[i][j])
        return A[i][j];
    vis[i][j] = true;

    int max = -1;
    if (max < f(i - 1, j))
    {
        max = f(i - 1, j);
        next[i][j] = make_pair(i - 1, j);
    }
    if (max < f(i, j - 1))
    {
        max = f(i, j - 1);
        next[i][j] = make_pair(i, j - 1);
    }
    //      if(G[i][j] && max < f(i-1, j-1)+1) max = f(i-1, j-1)+1;
    if (sw[i] == pw[j] && max < f(i - 1, j - 1) + 1)
    {
        max = f(i - 1, j - 1) + 1;
        next[i][j] = make_pair(i - 1, j - 1);
    }

    return A[i][j] = max;
}

void print_ans(int i, int j)
{
    if (i < 0 || j < 0) return;
    pair<int, int> st = next[i][j];

    print_ans(st.first, st.second);

    if (i - st.first == 1 && j - st.second == 1)
    {
        if (first) first = false;
        else printf(" ");
        cout << sw[i];
    }
}

int main()
{
    while (read_input())
    {
        f(ns - 1, np - 1);
        print_ans(ns - 1, np - 1);
        printf("\n");
    }

    return 0;
}