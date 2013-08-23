#include <cstdio>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#define N 9
using namespace std;

typedef vector<int> V;

map<V, string> visit;
queue<V> q;

void push(V &v, string &path, char c)
{
    if (!visit.count(v))
    {
        q.push(v);
        string nextP = path;
        nextP.insert(nextP.end(), c);
        visit[v] = nextP;
    }
}

int main()
{
    int i, tmp;
    V now;
    for (i = 1; i <= N; i++)
        now.push_back(i % N);
    visit[now] = "";
    q.push(now);
    while (!q.empty())
    {
        now = q.front();
        string path = visit[now];
        q.pop();
        int index;
        for (index = 0; index < N; index++)
            if (!now[index]) break; // find the empty slot
        if (index % 3 != 2)
        {
            V nextV = now;
            swap(nextV[index], nextV[index + 1]);
            push(nextV, path, 'l');
        }
        if (index % 3)
        {
            V nextV = now;
            swap(nextV[index], nextV[index - 1]);
            push(nextV, path, 'r');
        }
        if (index > 2)
        {
            V nextV = now;
            swap(nextV[index], nextV[index - 3]);
            push(nextV, path, 'd');
        }
        if (index < 6)
        {
            V nextV = now;
            swap(nextV[index], nextV[index + 3]);
            push(nextV, path, 'u');
        }
    } // finished construct path
    int T;
    scanf("%d", &T);
    getchar();
    while (T--)
    {
        getchar();
        char temp[20];
        gets(temp);
        V ans;
        for (i = 0; temp[i]; i++)
            if ('0' < temp[i] && temp[i] <= '9') ans.push_back(temp[i] - '0');
            else if (temp[i] == 'x') ans.push_back(0);
        bool find = visit.count(ans);
        if (find)
        {
            string path = visit[ans];
            reverse(path.begin(), path.end());
            puts(path.c_str());
        }
        else
        {
            puts("unsolvable");
        }
        if (T) puts("");
    }
    return 0;
}