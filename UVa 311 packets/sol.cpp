#include <cstdio>

int main()
{
    int a, b, c, d, e, f, ans;
    while (scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f), a || b || c || d || e || f)
    {
        ans = f + e + d + c / 4 + (c % 4 == 0 ? 0 : 1);///至少要这么多
        a -= 11 * e;
        b -= 5 * d; ///尽管减，就算<0也没关系
        switch (c % 4)
        {
        case 3: a -= 5, b -= 1; break;
        case 2: a -= 6, b -= 3; break;
        case 1: a -= 7, b -= 5; break;
        }
        if (b < 0)///偏差修正
        {
            a += b * 4;
            b = 0;
        }
        ans += b / 9 + (b % 9 == 0 ? 0 : 1);///补遗
        if (b % 9)
            a -= 36 - (b % 9 * 4);
        if (a > 0)
            ans += a / 36 + (a % 36 == 0 ? 0 : 1);///补遗
        printf("%d\n", ans);
    }
    return 0;
}
