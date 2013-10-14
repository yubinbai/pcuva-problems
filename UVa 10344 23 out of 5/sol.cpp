#include <algorithm>
#include <cstdio>
using namespace std;
int func(int tot, int val, int I)
{
    switch (I)
    {
    case 0: return (tot + val);
    case 1: return (tot - val);
    case 2: return (tot * val);
    }
    return 0;
}
int main()
{
    while (true)
    {
        int num[5];
        for (int i = 0; i < 5; i++)
            scanf("%d", &num[i]);
        if (count(num, num + 5, 0) == 5)
            break;
        bool flag = false;
        sort(num, num + 5);
        do
        {
            for (int a = 0; a < 3; a++)
                for (int b = 0; b < 3; b++)
                    for (int c = 0; c < 3; c++)
                        for (int d = 0; d < 3; d++)
                        {
                            int tot = num[0];
                            tot = func(tot, num[1], a);
                            tot = func(tot, num[2], b);
                            tot = func(tot, num[3], c);
                            tot = func(tot, num[4], d);
                            if (tot == 23)
                            {
                                flag = true;
                                break;
                            }
                        }
        }
        while (next_permutation(num, num + 5));
        if (flag)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }
    return 0;
}