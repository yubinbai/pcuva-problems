#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int PAY[300];

int main()
{
    unsigned char ch;
    int t, m, i, j, k, p, n;
    //freopen("in.txt","r",stdin);

    scanf("%d", &t);
    for (n = 1; n <= t; n++)
    {
        scanf("%d\n", &k);
        memset(PAY, 0, sizeof(PAY));

        for (j = 1; j <= k; j++)
        {
            cin >> ch;
            scanf("%d\n", &p);
            PAY[ch] = p;
        }

        p = 0;
        scanf("%d\n", &m);
        for (i = 1; i <= m; i++)
        {
            for (;;)
            {
                scanf("%c", &ch);
                if (ch == 10) break;
                p = p + PAY[ch];
            }
        }

        printf("%d.", p / 100);
        p = p % 100;

        if (p >= 10)
            printf("%d$\n", p);
        else
            printf("0%d$\n", p);
    }
    return 0;
}