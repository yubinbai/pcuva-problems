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
#define SZ(a) int(a.size())
#define read() freopen("input.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define pi acos(-1.0)
#define INF 1<<29
#define mod abs
#define pf printf
#define sf scanf
#define pdd pair<double, double>
#define fr first
#define sc second
#define mp make_pair

using namespace std;

#define MAXX 102

int cntPoints;
pdd points[MAXX];
int parent[MAXX];

template<typename T>
T sqr(T a)
{
    return a * a;
}

int find(int u)
{
    if (parent[u] == u)
    {
        return u;
    }
    return parent[u] = find(parent[u]);
}







int main()
{
    int kases;
    getint(kases);
    double p, q;
    double minCost;
    bool blank = false;

    while (kases--)
    {
        getint(cntPoints);
        loop(i, cntPoints)
        {
            sf("%lf %lf", &p, &q);
            points[i] = mp(p, q);
        }



        vector<pair<double, pair<int, int> > > dists;

        loop(i, cntPoints)
        {
            FOR(j, i + 1, cntPoints)
            {
                dists.pb(  mp(  sqrt( sqr(points[i].fr - points[j].fr) + sqr(points[i].sc - points[j].sc)  ) , mp(i, j)   )    );
            }
        }

        sort(all(dists));
        loop(i, cntPoints)
        {
            parent[i] = i;
        }

        minCost = 0;
        int u, v;

        loop(i, SZ(dists))
        {
            u = find(dists[i].sc.fr);
            v = find(dists[i].sc.sc);

            if (u != v)
            {
                parent[u] = v;
                minCost += dists[i].fr;
            }
        }

        if (blank) pf("\n");
        else blank = true;

        pf("%.2lf\n", minCost);




    }


    return 0;
}