#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char str[1000];
double fun(int &);
int main()
{
    int t, t_cnt = 0;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        double pnum = 0, unum = 0, inum = 0;
        bool U = false, I = false, P = false;
        int len, i = 0;

        memset(str, 0, sizeof(str));

        gets(str);
        len = strlen(str);
        while (i < len)
        {
            if (str[i] == '=')
            {
                if (str[i - 1] == 'P' && i > 0)
                {
                    P = true;
                    pnum = fun(i);
                }
                else if (str[i - 1] == 'U' && i > 0)
                {
                    U = true;
                    unum = fun(i);
                }
                else if (str[i - 1] == 'I' && i > 0)
                {
                    I = true;
                    inum = fun(i);
                }
            }
            else i++;
        }
        printf("Problem #%d\n", ++t_cnt);
        if (!P) printf("P=%.2lfW\n", unum * inum);
        else if (!I) printf("I=%.2lfA\n", pnum / unum);
        else printf("U=%.2lfV\n", pnum / inum);
        puts("");
    }
    return 0;
}
double fun(int &pos)
{
    int y = 0;
    double ans = 0;
    while (isdigit(str[++pos]) || str[pos] == '.')
    {
        if (isdigit(str[pos])) ans = ans * 10.0 + (double)(str[pos] - '0');
        else y = pos;
    }
    if (y != 0)
    {
        int cnt = pos - 1 - y;
        for (int j = 0; j < cnt; j++) ans /= 10.0;
    }
    if (str[pos] == 'm') ans /= 1000;
    else if (str[pos] == 'k') ans *= 1000;
    else if (str[pos] == 'M') ans *= 1000000;
    //printf("num=%.2lf\n",ans);
    return ans;
}
