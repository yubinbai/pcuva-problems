#include <cstdio>
#include <vector>
#include <algorithm>
typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
using namespace std;
int main()
{
    while (true)
    {
        int64 M, N, run, num, i, tot = 0;
        scanf("%lld%lld", &N, &M);
        if (M == 0 && N == 0)
            break;
        vector <int> vec(N);
        for (i = 0; i < N; i++)
        {
            scanf("%lld", &num);
            vec[i] = num;
        }
        for (i = 0; i < M; i++)
        {
            scanf("%lld", &num);
            if (binary_search(vec.begin(), vec.end(), num))
                tot++;
        }
        printf("%lld\n", tot);
    }
    return 0;
}