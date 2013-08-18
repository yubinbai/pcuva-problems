#include <stdio.h>

#define MAX_LEN 21

int DP[MAX_LEN][MAX_LEN] = {0};
int correct_order[MAX_LEN] = {0};
int check_order[MAX_LEN] = {0};

int total_len = 0;
int match_len = 0;

int LCS();
int max(int, int );

int main()
{
    int i, tmp;
    scanf("%d", &total_len);
    for (i = 1; i <= total_len; i++)
    {
        scanf("%d", &tmp);
        correct_order[tmp] = i;
    }
    while (1)
    {
        for (i = 1; i <= total_len; i++)
        {
            if ( scanf("%d", &tmp) == EOF)return 0;
            check_order[tmp] = i;
        }
        printf("%d\n", LCS());
    }
    return 0;
}

int LCS()
{
    int i, j;
    for (i = 1; i <= total_len; i++)
    {
        for (j = 1; j <= total_len; j++)
        {
            if (correct_order[i] == check_order[j])
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else
            {
                DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
            }
        }
    }
    return DP[total_len][total_len];
}

int max(int a, int b)
{
    if (a > b)return a;
    else return b;
}