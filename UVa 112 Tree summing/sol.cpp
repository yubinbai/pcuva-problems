#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXN 1000

int main()
{
    char ch, ch1, ch2, ch3, ch4;
    int digit[MAXN];
    int left, right, num, sum, flag, cnt, start, rear, success, negativeSign;

    while (scanf("%d", &num) != EOF)
    {
        memset(digit, 0, sizeof(digit));
        rear = left = right = sum = flag = cnt = 0;
        start = 1, success = 0, negativeSign = 1;
        ch1 = ch2 = ch3 = ch4 = '?';
        while (left != right || start)
        {
            scanf("%c", &ch);
            if (isdigit(ch) || ch == '(' || ch == ')' || ch == '-')
            {
                if (isdigit(ch) || ch == '-')
                {
                    if (isdigit(ch))
                        digit[rear] = digit[rear] * 10 + (ch - '0');
                    else negativeSign = -1;
                    flag = 1;
                }
                else if (flag)
                {
                    flag = 0;
                    digit[rear] = negativeSign * digit[rear];
                    sum += digit[rear];
                    negativeSign = 1;
                    rear++;
                }

                ch4 = ch3, ch3 = ch2, ch2 = ch1, ch1 = ch;
                if (ch4 == '(' && ch3 == ')' && ch2 == '(' && ch1 == ')')
                {
                    if (sum == num)
                    {
                        success = 1;
                    }
                    ch4 = ch3 = ch2 = ch1 = '?';
                }
                else if (ch2 != '(' && ch1 == ')')
                {
                    sum -= digit[rear - 1];
                    digit[rear - 1] = 0;
                    rear--;
                }
                if (ch == '(') left++;
                else if (ch == ')') right++;
                if (left != right) start = 0;
            }

        }
        if (success) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}