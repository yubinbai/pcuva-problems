#include <cstdio>
#include <cstring>
#define N 200005

int n, f[N], rank[N];
char name[N][25];
const int MaxHashSize = 1000003;
int head[MaxHashSize], next[N];

inline void init_lookup_table()
{
    memset(head, 0, sizeof(head));
}

inline int hash(char *str)
{
    int seed = 131, v = 0;
    while (*str) v = v * seed + (*str++);
    return (v & 0x7FFFFFFF) % MaxHashSize;
}

int try_to_insert(int s)
{
    int h = hash(name[s]);
    int u = head[h];
    while (u)
    {
        if (strcmp(name[u], name[s]) == 0) return u;
        u = next[u];
    }
    next[s] = head[h];
    head[h] = s;
    return s;
}

void init()
{
    for (int i = 0; i < N; ++i)
        f[i] = i, rank[i] = 1;
}
int find(int x)
{
    int i, j = x;
    while (j != f[j])
        j = f[j];
    while (x != j)
    {
        i = f[x];
        f[x] = j;
        x = i;
    }
    return j;
}
int Union(int x, int y)
{
    int a = find(x), b = find(y);
    if (a == b)
        return rank[a];
    rank[a] += rank[b];
    f[b] = a;
    return rank[a];
}

int main()
{
    int T;
    char name1[25], name2[25];
    while (~scanf("%d", &T))
    {
        while (T--)
        {

            init();
            init_lookup_table();

            scanf("%d", &n);
            int pos = 1;
            if (n == 0)
            {
                puts("0");
                continue;
            }
            for (int i = 0; i < n; ++i)
            {
                int a, b;
                scanf("%s", name[pos]);
                if ((a = try_to_insert(pos)) == pos)
                {
                    ++pos;
                }
                scanf("%s", name[pos]);
                if ((b = try_to_insert(pos)) == pos)
                {
                    ++pos;
                }
                printf("%d\n", Union(a, b));
            }
        }
    }
    return 0;
}