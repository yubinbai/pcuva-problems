#include <iostream>
#include <queue>
#include "stdio.h"
#include "memory.h"
#include <map>
using namespace std;
int n, s;
int longest;
int destiny;
int visited[101];
vector< vector<int> > L(101);
void bfs()
{
    queue< pair<int, int> > Q;
    Q.push(make_pair(s, 0));
    pair<int, int> aux;
    while (!Q.empty())
    {
        aux = Q.front();
        Q.pop();
        if (aux.second > visited[aux.first])
        {
            visited[aux.first] = aux.second;
            if (aux.second > longest)
            {
                longest = aux.second;
                destiny = aux.first;
            }
            else if (aux.second == longest && aux.first < destiny) destiny = aux.first;
            for (int i = 0; i < L[aux.first].size(); i++)
                Q.push(make_pair(L[aux.first][i], aux.second + 1));
        }
    }
}
int main()
{
    int caseNumber = 1, p, q;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%d", &s);
        for (int i = 1; i <= n; i++) L[i].clear();
        while (1)
        {
            scanf("%d %d", &p, &q);
            if (p == 0 && q == 0) break;
            L[p].push_back(q);
        }
        destiny = s;
        longest = 0;
        memset(visited, -1, sizeof(visited));
        bfs();
        cout << "Case " << caseNumber << ": The longest path from " << s << " has length " << longest << ", finishing at " << destiny << "." << endl << endl;
        caseNumber++;
    }
    return 0;
}
