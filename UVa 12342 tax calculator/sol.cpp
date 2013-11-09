#include <cstdio>
#define min(A, B)  ((A) < (B) ? (A) : (B))
#define max(A, B)  ((A) > (B) ? (A) : (B))
#define ceil(V)    ((V - int(V) == 0) ? int(V) : int(V + 1) )
int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        double Inc, Tax = 0;
        scanf("%lf", &Inc);
        Inc -= 180000;
        if (Inc > 0)
        {
            Tax += (min(300000.0, Inc) * 10) / 100;
            Inc -= 300000;
        }
        if (Inc > 0)
        {
            Tax += (min(400000.0, Inc) * 15) / 100;
            Inc -= 400000;
        }
        if (Inc > 0)
        {
            Tax += (min(300000.0, Inc) * 20) / 100;
            Inc -= 300000;
        }
        if (Inc > 0)
        {
            Tax += (Inc * 25.0) / 100;
        }
        if (Tax > 0)
        {
            Tax = max(2000.0, ceil(Tax));
        }
        printf("Case %d: %.0lf\n", t, Tax);
    }
    return 0;
}