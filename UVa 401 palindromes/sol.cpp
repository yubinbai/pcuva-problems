#include <stdio.h>
#define MAXN 200
int main()
{
    char reverse[27] = "A   3  HIL JM O   2TUVWXY5";
    char reverse_number[10] = "1SE Z  8 ";
    char input[MAXN];
    while (scanf("%s", input) != EOF)
    {
        bool palindrome_flag = true;
        bool mirrored_flag = true;
        int totalChar = 0;
        while (input[totalChar] != '\0')
        {
            totalChar++;
        }
        //Detected the string is palindrome or not
        for (int i = 0, j = totalChar - 1; i <= j; i++, j--)
        {
            if (input[i] != input[j])
            {
                palindrome_flag = false;
                break;
            }
        }
        //Detected the string is mirrored string or not
        for (int i = 0, j = totalChar - 1; i <= j; i++, j--)
        {
            if (input[i] >= 'A' && input[i] <= 'Z')
            {
                if (reverse[input[i] - 'A'] == ' ' || input[j] != reverse[input[i] - 'A'])
                {
                    mirrored_flag = false;
                    break;
                }
            }
            else
            {
                if (reverse_number[input[i] - '1'] == ' ' || input[j] != reverse_number[input[i] - '1'])
                {
                    mirrored_flag = false;
                    break;
                }
            }
        }
        if (palindrome_flag && mirrored_flag)
            printf("%s -- is a mirrored palindrome.\n", input);
        else if (palindrome_flag)
            printf("%s -- is a regular palindrome.\n", input);
        else if (mirrored_flag)
            printf("%s -- is a mirrored string.\n", input);
        else
            printf("%s -- is not a palindrome.\n", input);
        //need more one empty line
        printf("\n");
    }
    return 0;
}
