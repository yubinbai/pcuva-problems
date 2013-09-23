#include <stdio.h>
#include <iostream>
int main ()
{
    char A[150][150], Input [150];
    long M, N, I, J, Case = 0, Flag = 0;
    while (1)
    {
        gets(Input);
        sscanf(Input, "%ld%ld", &M, &N);
        if (M == 0 && N == 0)
            break;
        long B[150][150] = {0};
        for (I = 0; I < M; I++)
            gets (A[I]);
        for (I = 0; I < M; I++ )
        {
            for (J = 0; J < N; J++)
            {
                if (A[I][J] == '*')
                {
                    B[I][J + 1]++;
                    B[I + 1][J + 1]++;
                    B[I + 1][J]++;
                    B[I + 1][J - 1]++;
                    B[I][J - 1]++;
                    B[I - 1][J - 1]++;
                    B[I - 1][J]++;
                    B[I - 1][J + 1]++;
                }
            }
        }
        if (Flag == 1)
            printf("\n");
        Flag = 1;
        printf("Field #%ld:\n", ++Case);
        for (I = 0; I < M; I++)
        {
            for (J = 0; J < N; J++)
            {
                if (A[I][J] == '*')
                    printf("%c", A[I][J]);
                else
                    printf("%ld", B[I][J]);
            }
            printf("\n");
        }
    }
    return 0;
}