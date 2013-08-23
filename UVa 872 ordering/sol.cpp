#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
int n;
bool flag;
char xmap[26];
int mapx[256];
int graph[26][26];
int in[26];
int ordering[26];
void solve(int curr)
{
    if (curr == n)
    {
        flag = true;
        cout << xmap[ordering[0]];
        for (int i = 1; i < n; ++i)
        {
            cout << " " << xmap[ordering[i]];
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
            if (!in[i])
            {
                in[i]++;
                ordering[curr] = i;
                for (int j = 0; j < n; ++j)
                {
                    if (graph[i][j])
                        in[j]--;
                }
                solve(curr + 1);
                for (int j = 0; j < n; ++j)
                {
                    if (graph[i][j])
                        in[j]++;
                }
                in[i]--;
            }
    }
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t; getchar();
    while (t--)
    {
        memset(xmap, 0, sizeof(xmap));
        memset(mapx, 0, sizeof(mapx));
        memset(graph, 0, sizeof(graph));
        memset(in, 0, sizeof(in));
        memset(ordering, 0, sizeof(ordering));
        flag = false;
        n = 0;
        getchar();
        string line;
        getline(cin, line);
        for (int i = 0; i < line.size(); i += 2)
        {
            char x = line[i];
            xmap[n] = x;
            mapx[x] = n;
            n++;
        }
        getline(cin, line);
        for (int i = 0; i < line.size(); i += 4)
        {
            char x = line[i];
            char y = line[i + 2];
            graph[mapx[x]][mapx[y]] = 1;
            in[mapx[y]]++;
        }
        solve(0);
        if (!flag)
            cout << "NO" << endl;
        if (t)
            cout << endl;
    }
    return 0;
}