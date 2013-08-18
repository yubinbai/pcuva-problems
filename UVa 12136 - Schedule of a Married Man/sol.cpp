#include <cstdio>
void get_time(int &a, int &b)
{
    int a1, a2, b1, b2;
    scanf("%2d:%2d %2d:%2d", &a1, &a2, &b1, &b2);
    a = 60 * a1 + a2;
    b = 60 * b1 + b2;
}
int main(void)
{
    int t; scanf("%d", &t);
    for (int cnum = 0; cnum++ < t; )
    {
        int a, b, c, d;
        get_time(a, b);
        get_time(c, d);
        if ((a <= c && c <= b) || (a <= d && d <= b) || (c <= a && b <= d))
            printf("Case %d: Mrs Meeting\n", cnum);
        else printf("Case %d: Hits Meeting\n", cnum);
    }
    return 0;
}