#include <cstdio>
#include <cstdlib>
const int n_max = 10000;
int prices[n_max];
int compare_price(const void *i, const void *j)
{
    return *reinterpret_cast<const int *>(i) -
           *reinterpret_cast<const int *>(j);
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &prices[i]);
        int m;
        scanf("%d", &m);
        qsort(prices, n, sizeof(int), compare_price);
        int pi, pj;
        for (int i = 0; i < n - 1; i++)
        {
            int p = m - prices[i];
            if (p < prices[i])
                break;
            int *pp = reinterpret_cast<int *>(
                          bsearch(&p, &prices[i + 1], n - (i + 1), sizeof(int), compare_price));
            if (pp)
            {
                pi = i; pj = pp - prices;
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",
               prices[pi], prices[pj]);
    }
    return 0;
}
