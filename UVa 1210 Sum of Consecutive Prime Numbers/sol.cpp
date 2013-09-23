#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 10000
bool Prime[MAX + 1];
int Count[MAX + 1];
vector< int > P;
void Sieve()
{
    memset(Prime, true, sizeof Prime);
    P.clear();
    Prime[0] = Prime[1] = false;
    for (int i = 2; i <= MAX; i++)
    {
        if (Prime[i])
        {
            P.push_back(i);
            for (int j = i * i; j <= MAX; j += i)
                Prime[j] = false;
        }
    }
}
void Calc()
{
    memset(Count, 0, sizeof Count);
    int N = P.size();
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = i; j < N; j++)
        {
            sum += P[j];
            if (sum > MAX) continue;
            ++Count[sum];
        }
    }
}
int main()
{
    Sieve();
    Calc();
    while (true)
    {
        int N;
        scanf("%d", &N);
        if (!N) break;
        printf("%d\n", Count[N]);
    }
    return 0;
}