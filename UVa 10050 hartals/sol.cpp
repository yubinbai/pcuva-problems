#include <stdio.h>
int parties[101];
int main()
{
    int I, J, T, N, P, COUNT;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        scanf("%d", &P);
        for (I = 0 ; I < P ; I++)
        {
            scanf("%d", &parties[I]);
        }
        for (I = 1, COUNT = 0 ; I <= N ; I++)
        {
            if ((I % 7) != 6 && (I % 7) != 0)
            {
                for (J = 0 ; J < P ; J++)
                {
                    if (!(I % parties[J]))
                    {
                        COUNT++;
                        break;
                    }
                }
            }
        }
        printf("%d\n", COUNT);
    }
    return 0;
}