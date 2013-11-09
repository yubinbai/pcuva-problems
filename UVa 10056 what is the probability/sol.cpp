#include<stdio.h>
#include<string.h>
#include<math.h>
int N, I;
double P;
void solve()
{
    scanf("%d%lf%d", &N, &P, &I);
    if (fabs(P) < 1e-9)
        printf("0.0000\n");
    else
        printf("%.4lf\n", P * pow(1 - P, I - 1) / (1 - pow(1 - P, N)));
}
int main()
{
    int tt, t;
    scanf("%d", &t);
    while (t --)
    {
        solve();
    }
    return 0;
}