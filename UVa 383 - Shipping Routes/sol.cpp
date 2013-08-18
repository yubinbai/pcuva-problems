#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL long long
#define For(i, a, b) for ( int i = (a); i < (b); i++ )
#define Fors(i, sz) for ( size_t i = 0; i < sz.size (); i++ )
#define Set(a, s) memset (a, s, sizeof (a))
using namespace std;
int matrix [35] [35];
int vis [35];
int numberOfWarehouse;
struct node
{
    int vertex;
    int hop;
    node (int p, int q)
    {
        vertex = p;
        hop = q;
    }
    node () { }
} a;
void reset ()
{
    for ( int i = 0; i < 35; i++ )
    {
        for ( int j = 0; j < 35; j++ )
            matrix [i] [j] = INF_MAX;
    }
}
int bfs (int s, int d)
{
    a.vertex = s;
    a.hop = 0;
    queue <node> q;
    q.push(a);
    while ( !q.empty() )
    {
        a = q.front();
        q.pop();
        if ( a.vertex == d ) return a.hop;
        vis [a.vertex] = true;
        for ( int i = 1; i <= numberOfWarehouse; i++ )
        {
            if ( matrix [a.vertex] [i] != INF_MAX && !vis [i] )
            {
                q.push (node (i, a.hop + 1));
            }
        }
    }
    return -1;
}
int main(int argc, char **argv)
{
    //freopen ("in.txt", "r", stdin);
    //freopen ("out.txt", "w", stdout);
    int testCase;
    scanf ("%d", &testCase);
    int cases = 0;
    printf ("SHIPPING ROUTES OUTPUT\n\n");
    while ( testCase-- )
    {
        int edges, query;
        scanf ("%d %d %d", &numberOfWarehouse, &edges, &query);
        map <string, int> warehouseIndex;
        reset ();
        for ( int i = 1; i <= numberOfWarehouse; i++ )
        {
            string s; cin >> s;
            warehouseIndex [s] = i;
        }
        for ( int i = 1; i <= edges; i++ )
        {
            string a, b;
            cin >> a >> b;
            matrix [warehouseIndex [a]] [warehouseIndex [b]] = matrix [warehouseIndex [b]] [warehouseIndex [a]] = 1;
        }
        printf ("DATA SET  %d\n\n", ++cases);
        for ( int i = 1; i <= query; i++ )
        {
            int c;
            string a, b;
            cin >> c >> a >> b;
            memset (vis, false, sizeof (vis));
            int cost = bfs (warehouseIndex [a], warehouseIndex [b]);
            if ( cost == -1 ) printf ("NO SHIPMENT POSSIBLE\n");
            else printf ("$%d\n", cost * c * 100);
        }
        printf ("\n");
    }
    printf ("END OF OUTPUT\n");
    return 0;
}