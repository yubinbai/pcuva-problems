#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MX = 10000;
struct Type
{
    char id;
    int value;
} id[MX];
int dr[] = {0, -1, 0, 1};
int dc[] = { -1, 0, 1, 0};
char graph[MX][MX];
int nc, h, w;
inline bool comp(Type a, Type b)
{
    if (a.value != b.value)
        return a.value > b.value;
    return a.id < b.id;
}
void init()
{
    int k = h * w;
    for (int i = 0; i < k; ++i)
        id[i].value = 0;
}
void setRank(char c, int r)
{
    for (int i = 0; i < nc; ++i)
    {
        if (id[i].id == c)
        {
            id[i].value += r;
            return;
        }
    }
    id[nc].id = c;
    id[nc].value = r;
    ++nc;
}
void dfsVisit(int a, int b)
{
    int i, j, r, c;
    char tempC = graph[a][b];
    graph[a][b] = 'G';
    for (i = 0; i < 4; ++i)
    {
        r = dr[i] + a;
        c = dc[i] + b;
        if (r >= 0 && r < h && c >= 0 && c < w && graph[r][c] == tempC)
            dfsVisit(r, c);
    }
    graph[a][b] = 'B';
}
void dfs()
{
    int i, j;
    for (i = 0; i < h; ++i)
    {
        for (j = 0; j < w; ++j)
        {
            if (graph[i][j] != 'G' && graph[i][j] != 'B')
            {
                setRank(graph[i][j], 1);
                dfsVisit(i, j);
            }
        }
    }
}
int main()
{
    int test, i, cases = 0;
    char temp[100];
    cin >> test;
    while (test--)
    {
        cin >> h >> w;
        cin.getline(temp, sizeof(temp));
        nc = 0;
        init();
        for (i = 0; i < h; ++i)
            cin.getline(graph[i], sizeof(graph[i]));
        dfs();
        sort(id, id + nc, comp);
        cout << "World #" << ++cases << endl;
        for (i = 0; i < nc; ++i)
            cout << id[i].id << ": " << id[i].value << endl;
    }
    return 0;
}