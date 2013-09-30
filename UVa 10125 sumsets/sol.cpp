#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
const int MAXN = 1003;
using namespace std;
int S[MAXN], n, ans;
struct Node
{
    int sum;
    int a, b;
    friend bool operator < (const Node &a, const Node &b)
    {
        return a.sum < b.sum;
    }
};
Node sum[MAXN *MAXN];
int rear;
bool solve()
{
    Node tmp;
    ans = -2147483646;
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j < n; ++j)if (i != j)
            {
                int t = S[i] - S[j];
                tmp.sum = t; tmp.a = i; tmp.b = j;
                Node *p = lower_bound(sum, sum + rear, tmp);
                if (p->sum == t && S[i] > ans)
                {
                    while (p->sum == t)
                    {
                        if (p->a != i && p->a != j && p->b != i && p->b != j)
                        {
                            ans = S[i];
                            return true;
                        }
                        ++p;
                    }
                }
            }
    }
    return false;
}
int main()
{
    while (scanf("%d", &n), n)
    {
        for (int i = 0; i < n; ++i) scanf("%d", &S[i]);
        sort(S, S + n);
        rear = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)if (i != j)
                {
                    sum[rear].sum = S[i] + S[j];
                    sum[rear].a = i, sum[rear++].b = j;
                }
        }
        sort(sum, sum + rear);
        if (solve()) printf("%d\n", ans);
        else printf("no solution\n");
    }
    return 0;
}