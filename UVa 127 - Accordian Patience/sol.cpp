#include<iostream>
#include<stack>
#include<list>
#include<cstdio>

using namespace std;

struct card
{
    char x, y;
    card(char a, char b): x(a), y(b) {}
};

bool judge(card a, card b)
{
    if (a.x == b.x || a.y == b.y)return true;
    return false;
}

list<stack<card> >::iterator pre3(const list<stack<card> >::iterator i)
{
    list<stack<card> >::iterator a = i;
    return ------a;
}

list<stack<card> >::iterator pre1(const list<stack<card> >::iterator i)
{
    list<stack<card> >::iterator a = i;
    return --a;
}

int main()
{
    char s[3];
    list<stack<card> > cards;
    list<stack<card> >::iterator i;
    while (scanf("%s", s), s[0] != '#')
    {
        card c(s[0], s[1]);
        stack<card>temp;
        temp.push(c);
        cards.push_back(temp);
        if (cards.size() == 52)
        {
            bool ismoved = 1;
            while (ismoved)
            {
                ismoved = false;
                size_t count;
                for (i = cards.begin(), count = 0; i != cards.end(); i++, count++)
                {
                    if (count > 2 && judge(i->top(), pre3(i)->top()))
                    {
                        pre3(i)->push(i->top());
                        i->pop();
                        ismoved = true;
                        if (i->empty())
                            cards.erase(i);
                        break;
                    }
                    if (count > 0 && judge(i->top(), pre1(i)->top()))
                    {
                        pre1(i)->push(i->top());
                        i->pop();
                        ismoved = true;
                        if (i->empty())
                            cards.erase(i);
                        break;
                    }
                }
            }
            if (cards.size() == 1)
                printf("%d pile remaining:", cards.size());
            else
                printf("%d piles remaining:", cards.size());
            for (i = cards.begin(); i != cards.end(); i++)
            {
                printf(" %d", i->size());
            }
            printf("\n");
            ismoved = true;
            cards.clear();
        }
    }
    return 0;
}
