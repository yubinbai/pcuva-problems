#include <cstdio>
int value(char c)
{
    for (char a = '2'; a <= '9'; ++a)
        if (a == c) return a - '0';
    return 10;
}
int main(void)
{
    char cards[52][4];
    int stack[52], T;
    scanf("%d", &T);
    for (int c = 0; c++ < T; )
    {
        for (int i = 0; i < 52; ++i)
        {
            scanf("%s", cards[i]);
            stack[i] = value(cards[i][0]);
        }
        int y = 0, top = 27;
        for (int i = 0; i < 3; ++i)
        {
            int v = stack[--top];
            y += v;
            top -= 10 - v;
        }
        if (y >= top)
            y = y - top + 26;
        printf("Case %d: %s\n", c, cards[y]);
    }
    return 0;
}
