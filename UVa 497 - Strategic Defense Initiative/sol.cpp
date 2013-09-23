#include <stdio.h>
#include <ctype.h>
#define SIZE    100000
#define FORI(i, val, cond)  for ((i) = (val); (cond); ++(i))
#define FORIZ(i, cond)      FORI((i), 0, (cond))
#define FORD(i, val, cond)  for ((i) = (val); (cond); --(i))
#define FORDZ(i, cond)      FORD((i), 0, (cond))
static FILE *fp;
static char tmp[SIZE];
static int input[SIZE];
static int lis[SIZE];
static int dp[SIZE];


int bsearch(int wanted, int high)
{
    int low = 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) >> 1;
        if (lis[mid] < wanted) low = mid + 1;
        else if (lis[mid] > wanted) high = mid - 1;
        else return mid;
    }
    return low;
}


int main(int argc, const char *argv[])
{
    int i, cases, p, bak, cnt, lis_idx;
    scanf("%d", &cases);
    fgets(tmp, SIZE, stdin);
    fgets(tmp, SIZE, stdin);
    while (cases--)
    {
        cnt = 0;
        while (fgets(tmp, SIZE, stdin) && tmp[0] != '\n')
            sscanf(tmp, "%d", &input[++cnt]);
        /* load done, processing */
        lis[1] = input[1];
        dp[1] = lis_idx = 1;
        FORI(i, 1, i <= cnt)
        {
            if (lis[lis_idx] < input[i])
            {
                lis[++lis_idx] = input[i];
                dp[i] = lis_idx;
            }
            else if (lis[lis_idx] == input[i]) dp[i] = lis_idx;
            else
            {
                p = bsearch(input[i], lis_idx);
                lis[p] = input[i];
                dp[i] = p;
            }
        }
        printf("Max hits: %d\n", lis_idx);
        bak = lis_idx;
        while (lis_idx--)
        {
            while (dp[i] != lis_idx) --i;
            lis[lis_idx] = input[i];
        }
        FORI(i, 1, i <= bak) printf("%d\n", lis[i]);
        if (cases) putchar('\n');
    }
    return 0;
}
