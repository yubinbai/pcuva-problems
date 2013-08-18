#include <stdio.h>
#include <string.h>
int main()
{
    int numTest;
    scanf("%d", &numTest);

    for (int itertest = 0; itertest < numTest; ++itertest)
    {
        char word[100];
        scanf("%s", word);
        //printf("%s\n", word);
        int len = strlen(word);

        for (int i = 1; i <= len; i++)
            if (len % i == 0)
            {
                int ok = 1;
                for (int j = i; j < len; j++)
                    if (word[j] != word[j % i])
                    {
                        ok = 0;
                        break;
                    }
                if (ok)
                {
                    printf("%d\n", i);
                    if (itertest != numTest - 1)
                    {
                        printf("\n");
                    }
                    break;
                }
            }
    }
}