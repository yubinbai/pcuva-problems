#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define max 20000000
char seive[max];
int prime[100002];
//modified seive of eratosthenes
void genSeive()
{
    int i, j, sq;
    seive[0] = seive[1] = 1;
    sq = sqrt( (double) max);
    for (i = 2; i <= sq; ++i)
    {
        if (!seive[i])
        {
            for (j = i * i; j < max; j += i)
                seive[j] = 1;
        }
    }
    //for twin prime modification
    j = 0;
    for (i = 2; i < max; ++i)
    {
        if (!seive[i] && !seive[i + 2])
            prime[++j] = i;
        if (j == 100001) break;
    }
}
int main()
{
    genSeive();
    int n;
    while (cin >> n)
    {
        cout << "(" << prime[n] << ", " << prime[n] + 2 << ")" << endl;
    }
    return 0;
}