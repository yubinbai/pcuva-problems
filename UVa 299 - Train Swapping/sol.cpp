#include <stdio.h>
int main ()
{
    long Case, A[52], Num, Count, I, J, Temp;
    scanf("%ld", &Case);
    while ( Case )
    {
        scanf("%ld", &Num);
        for (I = 0; I < Num; I++)
            scanf("%ld", &A[I]);
        Count = 0;
        for (I = 0; I < Num; I++)
        {
            for (J = I + 1; J < Num; J++)
            {
                if (A [I] > A [J])
                {
                    Temp = A [I];
                    A [I] = A [J];
                    A [J] = Temp;
                    Count++;
                }
            }
        }
        printf("Optimal train swapping takes %ld swaps.\n", Count);
        Case--;
    }
    return 0;
}