#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    char p1[200], p2[200];
    while (1)
    {
        scanf("%d", &n);
        if (n == -1) break;
        printf("Round %d\n", n);
        scanf("%s\n%s", p1, p2);
        int h1 = strlen(p1), h2 = strlen(p2), stroke = 0, happy = 0;
        for (int i = 0; i < h2; i++)
        {
            int v = 0;
            for (int j = 0; j < h1; j++)
            {
                if (p1[j] == p2[i])
                {
                    p1[j] = 0;
                    v = 1;
                    happy++;
                }
            }
            if (!v) stroke++;
            if (stroke == 7 || happy == h1) break;
        }
        if (stroke == 7) puts("You lose.");
        else if (happy == h1) puts("You win.");
        else puts("You chickened out.");
    }
    return 0;
}
