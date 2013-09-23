#include <cstdio>
long long power(long long A, long long B, long long C)
{
    if (B == 0) return (1 % C);
    if (B == 1) return (A % C);
    long long V = power(A, B / 2, C);
    V = (V % C * V % C) % C;
    if (B & 1)
        V = (V % C * A % C) % C;
    return V;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        long long A, B, C;
        scanf("%lld%lld%lld", &A, &B, &C);
        printf("%lld\n", power(A, B, C));
    }
    return 0;
}