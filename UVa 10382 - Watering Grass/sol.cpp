#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#define MAXN 10005
using namespace std;
int n, nIndex;
double l, w;


struct Node
{
    double left;
    double right;
    friend bool operator < (const Node &a, const Node &b)
    {
        return a.left < b.left;
    }
} arr[MAXN];

int main()
{
    double p, r;
    while (scanf("%d%lf%lf", &n, &l, &w) != EOF)
    {
        nIndex = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%lf%lf", &p, &r);
            if (w / 2 >= r)
                continue; //直径小于宽度的不考虑
            double t = sqrt(r * r - w * w / 4.0);
            arr[nIndex].left = p - t;
            arr[nIndex].right = p + t;
            ++nIndex;
        }

        sort(arr, arr + nIndex);
        int cnt = 0;
        double left = 0, right = 0;
        bool flag = false;

        if (arr[0].left <= 0 )
        {
            int i = 0;

            while (i < nIndex)
            {

                int j = i;
                while (j < nIndex && left >= arr[j].left)
                {
                    if (arr[j].right > right)
                        right = arr[j].right;
                    ++j;
                }
                if (j == i) break; // 如果上面的循环体没有执行，说明之后都没有满足的了

                ++cnt;
                left = right;
                i = j;

                if (left >= l)
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) printf("%d\n", cnt);
        else printf("-1\n");
    }
    return 0;
}
