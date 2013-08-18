#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
struct player
{
    char n[32];
    int a, d;
    bool operator<(const player x) const
    {
        return (a > x.a) || (a == x.a && d < x.d) ||
               (a == x.a && d == x.d && strcmp(n, x.n) < 0);
    }

} p[16];
bool sortname(const player y, const player x)
{
    return strcmp(y.n, x.n) < 0;
}
int main(void)
{
    int t;
    scanf("%d\n", &t);
    for (int cnum = 0; cnum < t; )
    {
        for (int i = 0; i < 10; ++i)
            scanf("%s %d %d", &p[i].n, &p[i].a, &p[i].d);
        sort(p, p + 10);
        sort(p, p + 5, sortname);
        sort(p + 5, p + 10, sortname);
        printf("Case %d:\n", ++cnum);
        printf("(%s, %s, %s, %s, %s)\n", p[0].n, p[1].n, p[2].n, p[3].n, p[4].n);
        printf("(%s, %s, %s, %s, %s)\n", p[5].n, p[6].n, p[7].n, p[8].n, p[9].n);
    }
    return 0;
}