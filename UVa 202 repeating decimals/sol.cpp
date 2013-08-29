#include<cstdio>
int a, b;
bool used[30000];
int stack[30000];
int top;
int i, j;
int main()
{
    while (scanf("%d%d", &a, &b) != EOF)
    {
        top = 0;
        printf("%d/%d = %d.", a, b, a / b);
        a %= b;
        a *= 10;
        while (!used[a])
        {
            stack[top++] = a; // remainder
            used[a] = 1;
            a %= b;
            a *= 10;
        }
        for (i = 0; stack[i] != a; i++)
        {
            printf("%d", stack[i] / b);
            used[stack[i]] = 0;
        }
        printf("(");
        j = i;
        for (; i < top && i < 50; i++)
        {
            printf("%d", stack[i] / b);
            used[stack[i]] = 0;
        }
        if (i < top)
        {
            printf("...");
            for (; i < top; i++) used[stack[i]] = 0;
        }
        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n", top - j);
        printf("\n");
    }
    return 0;
}