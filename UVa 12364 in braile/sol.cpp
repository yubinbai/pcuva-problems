#include <cstdio>
#include <cstring>
const char *nums[10] =
{
    ".***.." , // 0
    "*....." , // 1
    "*.*..." , // 2
    "**...." , // 3
    "**.*.." , // 4
    "*..*.." , // 5
    "***..." , // 6
    "****.." , // 7
    "*.**.." , // 8
    ".**..." , // 9
};
char output[3][1024];
char answer[1024];
char digits[1024];
char input[1024][128];
char type[16];
int main(void)
{
    for (int d; scanf("%d", &d) == 1 && d; )
    {
        scanf("%s", type);
        if (type[0] == 'S')
        {
            scanf("%s", digits);
            for (int line = 0; line < 3; ++line)
            {
                char *p = output[line];
                for (int i = 0; digits[i]; ++i)
                {
                    int z = digits[i] - '0';
                    *p++ = nums[z][2 * line];
                    *p++ = nums[z][2 * line + 1];
                    *p++ = ' ';
                }
                *--p = 0;
                puts(output[line]);
            }
        }
        else
        {
            for (int line = 0; line < 3; ++line)
                for (int i = 0; i < d; ++i)
                    scanf("%s", input[i] + 2 * line);
            for (int i = 0, j; i < d; ++i)
            {
                for (j = 0; strcmp(input[i], nums[j]); ++j);
                putchar('0' + j);
            }
            puts("");
        }
    }
    return 0;
}