#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
#include<string>
#include<vector>
#define tr(c,it) for(typeof(c.begin())it=c.begin();it!=c.end();it++)
using namespace std;
map<string, int> m;
vector< vector<int> > adj(10000);
unsigned int fs, fe, i, j, k, ls, le, n, nn, papers, queries, scen, sn;
int e_num[10000];
bool jump[127], last;
string erdos("Erdos, P."), name;
char fn[3000], ln[3000], remain[10000];
const char *trac = "-------------------";
void read_paper()
{
    gets(remain);
    if (remain[0] == 0)
    {
        i--;
        return;
    }
    int idx[1000];
    k = nn = last = 0;
    while (!last)
    {
        while (jump[remain[k]]) k++; fs = k;
        while (!jump[remain[k]]) k++; fe = k;
        if (remain[k] == ':') break;
        while (jump[remain[k]]) k++; ls = k;
        while (!jump[remain[k]]) k++; le = k - 1;
        if (remain[k] == ':') last = true, le++;
        name = string(remain + fs, remain + fe) + " " + string(remain + ls, remain + le);
        if (m.find(name) != m.end()) idx[nn++] = m[name];
        else m.insert(make_pair(name, n)), n++, idx[nn++] = m[name];
    }
    for (j = 0; j < nn; j++)
        for (k = j + 1; k < nn; k++)
            adj[idx[k]].push_back(idx[j]),
                adj[idx[j]].push_back(idx[k]);
}
void bfs()
{
    queue< pair<int, int> > q;
    bool v[n]; memset(v, 0, n);
    int aux, e;
    if (m.find(erdos) != m.end())
    {
        q.push( make_pair(m[erdos], 0) );
        v[m[erdos]] = 1;
    }
    while (!q.empty())
    {
        aux = q.front().first;  e = q.front().second;
        q.pop(); e_num[aux] = e;
        tr(adj[aux], it)
        if (!v[(*it)]) v[(*it)] = 1, q.push(make_pair((*it), e + 1));
    }
}
int main(void)
{
    scanf("%u", &scen); n = sn = 0;
    memset(jump, 0, 127);
    jump[' '] = jump[':'] = 1;
    while (scen--)
    {
        for (i = 0; i < n; i++) adj[i].clear();
        m.clear();
        memset(e_num, -1, sizeof(e_num));
        scanf("%u%u", &papers, &queries); getchar();
        for (n = i = 0; i < papers; i++) read_paper();
        bfs();
        printf("Scenario %u\n", ++sn);
        for (i = 0; i < queries; i++)
        {
            scanf("%s%s", &fn, &ln);
            name = string(fn) + " " + string(ln);
            if (m.find(name) != m.end())
            {
                printf("%s ", name.c_str());
                if (e_num[m[name]] != -1) printf("%u\n", e_num[m[name]]);
                else printf("infinity\n");
            }
            else printf("%s infinity\n", name.c_str());
        }
    }
    return 0;
}
