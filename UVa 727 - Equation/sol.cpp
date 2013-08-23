#include<iostream>
#include<stack>
#include "stdio.h"
#include "string.h"
using namespace std;

int weight(char);

int main()
{
    char inp[3], inexp[70], ch, postexp[70];
    stack<char>stk;
    int i, j, k, t, f = 1;

    scanf("%d\n", &t);

    for (i = 1; i <= t; i++)
    {
        k = 0;
        stk.push('(');
        while (gets(inp) && strlen(inp))
            inexp[k++] = inp[0];
        inexp[k] = ')', inexp[k + 1] = '\0', k = 0;

        for (j = 0; inexp[j]; j++)
        {
            switch (inexp[j])
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                postexp[k++] = inexp[j];
                break;
            case '(':
                stk.push('(');
                break;
            case ')':
                ch = stk.top();
                stk.pop();
                while (ch != '(')
                {
                    postexp[k++] = ch;
                    ch = stk.top();
                    stk.pop();
                }
                break;
            default:
                if (stk.empty())
                {
                    stk.push(inexp[j]);
                    continue;
                }

                ch = stk.top();
                while (weight(inexp[j]) <= weight(ch))
                {
                    stk.pop();
                    postexp[k++] = ch;
                    ch = stk.top();
                }
                stk.push(inexp[j]);
            }
        }
        postexp[k] = '\0';

        if (f == 1)
            printf("%s\n", postexp);
        else
            printf("\n%s\n", postexp);
        f = 0;
        while (!stk.empty())
            stk.pop();
    }
    return 0;
}

int weight(char opt)
{
    switch (opt)
    {
    case '*':
    case '/':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}