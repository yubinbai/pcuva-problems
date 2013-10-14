#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int catalan[] = {0, 1, 2, 5, 14, 42, 132, 429, 1430, 4862,
                     16796, 58786, 208012, 742900, 2674440, 9694845, 35357670,
                     129644790, 477638700, 1767263190
                    };
    int max = 20;
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= 20; i++)
        {
            if (n == catalan[i])
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}