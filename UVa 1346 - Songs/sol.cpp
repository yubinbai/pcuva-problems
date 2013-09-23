#include <cstdio>
#include <cstring>
#include <cstdlib>


struct data
{
    int id;
    double l, f;
} a[80000];
int cmp(const void *a, const void *b)
{
    struct data *p = (struct data *)a;
    struct data *q = (struct data *)b;
    return q->f * p->l > p->f * q->l ? 1 : -1;
}
int main()
{
    int n, s;
    while (scanf("%d", &n) == 1)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d%lf%lf", &a[i].id, &a[i].l, &a[i].f);
        }
        scanf("%d", &s);
        qsort(a, n, sizeof(a[0]), cmp);
        printf("%d\n", a[s - 1].id);
    }
    return 0;
}