#include <cstdio>
#include <bitset>
using namespace std;
int TC, givenRow, givenCol, row[8], lineCounter;
bitset<30> rowUsed, leftDiag, rightDiag;
void backtrack(int col)
{
    int tryRow;
    if (col >= 8 && row[givenCol] == givenRow)
    {
        printf("%2d      %d", ++lineCounter, row[0] + 1);
        for (int j = 1; j < 8; j++)
        {
            printf(" %d", row[j] + 1);
        }
        printf("\n");
        return;
    }
    else
    {
        for (tryRow = 0; tryRow < 8; tryRow++)
            if (!rowUsed[tryRow] && !leftDiag[tryRow - col + 8 - 1] && !rightDiag[tryRow + col])
            {
                row[col] = tryRow;
                if (col == givenCol && row[col] != givenRow)
                    continue;
                else
                {
                    rowUsed[tryRow] = leftDiag[tryRow - col + 8 - 1]
                                      = rightDiag[tryRow + col] = true;
                    backtrack(col + 1);
                    rowUsed[tryRow] = leftDiag[tryRow - col + 8 - 1]
                                      = rightDiag[tryRow + col] = false;
                }
            }
    }
}
int main()
{
    scanf("%d", &TC);
    while (TC--)
    {
        scanf("%d %d", &givenRow, &givenCol);
        givenRow--;
        givenCol--;
        for (int i = 0; i < 8; i++)
        {
            row[i] = 0;
        }
        lineCounter = 0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        backtrack(0);
        if (TC) printf("\n");
    }
    return 0;
}