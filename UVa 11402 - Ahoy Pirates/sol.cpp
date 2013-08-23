#include <cstdio>
//#define DBG
#define LEFT(x)    (1 + (x << 1))
#define RIGHT(x) (2 + (x << 1))
const int N = 1048576;
bool bucaneer[N];
struct node
{
    char upd;
    int b, e, m, v;
} nodes[N << 2];
void init(int idx, int left, int right)
{
    node &n = nodes[idx];
    n.m = ((n.b = left) + (n.e = right)) >> 1;
    n.upd = ' ';
    if (n.b != n.e)
    {
        init(LEFT(idx), left, n.m);
        init(RIGHT(idx), n.m + 1, right);
        n.v = nodes[LEFT(idx)].v + nodes[RIGHT(idx)].v;
    }
    else n.v = bucaneer[n.b];
}
void set_update(int idx, char type)
{
    node &n = nodes[idx];
    if (type == 'I')
    {
        switch (n.upd)
        {
        case ' ': n.upd = 'I'; break;
        case 'I': n.upd = ' '; break;
        case 'E': n.upd = 'F'; break;
        case 'F': n.upd = 'E'; break;
        }
    }
    else n.upd = type;
}
void do_update(int idx)
{
    node &n = nodes[idx];
    if (n.upd == ' ') return;
    switch (n.upd)
    {
    case 'I': n.v = n.e - n.b + 1 - n.v; break;
    case 'E': n.v = 0; break;
    case 'F': n.v = n.e - n.b + 1 ; break;
    }
    set_update(LEFT(idx), n.upd);
    set_update(RIGHT(idx), n.upd);
    n.upd = ' ';
}
void update(int idx, int left, int right, char type)
{
    node &n = nodes[idx];
    if (left <= n.b && n.e <= right) // fits into interval, apply the update
        set_update(idx, type);
    do_update(idx);
    if (left > n.e || right < n.b) return; // nothing else to do here
    if (!(left <= n.b && n.e <= right)) // will need to update children to update current node
    {
        update(LEFT(idx), left, right, type);
        update(RIGHT(idx), left, right, type);
        n.v = nodes[LEFT(idx)].v + nodes[RIGHT(idx)].v;
    }
}
int query(int idx, int left, int right)
{
    int r = 0;
    node &n = nodes[idx];
    do_update(idx);
    if (left > n.e || right < n.b) r = 0;
    else if (left <= n.b && n.e <= right) r = n.v;
    else
    {
        r = query(LEFT(idx), left, right) + query(RIGHT(idx), left, right);
        n.v = nodes[LEFT(idx)].v + nodes[RIGHT(idx)].v;
    }
    return r;
}
int main(void)
{
    int tcn; scanf("%d", &tcn);
    for (int i = 0, j, k, l; i++ < tcn; )
    {
        int a, b, pirates = 0, reps, queries, qc = 0, specs;
        char cmd, s[64];
        for (scanf("%d", &specs); specs--; )
        {
            scanf("%d %s", &reps, s);
            for (j = 0; s[j]; ++j) s[j] -= '0';
            for (k = 0; k < reps; ++k) for (l = 0; l < j; ++l)
                    bucaneer[pirates++] = s[l];
        }
        init(0, 0, pirates - 1);
        printf("Case %d:\n", i);
        for (scanf("%d", &queries); queries--; )
        {
            scanf(" %c %d %d", &cmd, &a, &b);
            if (cmd == 'S') printf("Q%d: %d\n", ++qc, query(0, a, b));
            else update(0, a, b, cmd);
        }
    }
    return 0;
}