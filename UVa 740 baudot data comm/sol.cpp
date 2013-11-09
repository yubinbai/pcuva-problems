#include <stdio.h>
#include <string.h>
char B[2][33], msg[82];
int main()
{
    int len, i, indx, shft, cnt = 0, spc[3];
    gets(B[0]);
    gets(B[1]);
    for (i = 0; i < 32; i++)
    {
        if (B[0][i] == ' ' && cnt == 0)
            spc[cnt++] = i;
        else if (B[0][i] == ' ' && cnt == 1)
            spc[cnt++] = i;
        else if (B[0][i] == ' ' && cnt == 2)
            spc[cnt] = i;
    }
    while (scanf("%s", msg) == 1)
    {
        shft = 0;
        len = strlen(msg);
        for (i = 0; i < len; i += 5)
        {
            indx = (msg[i] - '0') * 16 + (msg[i + 1] - '0') * 8 + (msg[i + 2] - '0') * 4 + (msg[i + 3] - '0') * 2 + (msg[i + 4] - '0');
            if (indx == spc[1])
                shft = 0;
            else if (indx == spc[2])
                shft = 1;
            else
                printf("%c", B[shft][indx]);
        }
        printf("\n");
    }
    return 0;
}