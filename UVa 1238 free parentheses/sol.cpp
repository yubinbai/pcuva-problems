#include <cstring>
#include <iterator>
#include <algorithm>
#include <set>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <map>
#include <utility>

#define PLUS 1
#define MINUS -1

using namespace std;

bool table[61][31][7000];

template<typename I>
void rec(set<int> &resultset, I iter, I end, int result, int open)
{
    {
        if (table[end - iter][open][result + 3000]) return;
        table[end - iter][open][result + 3000] = true;
    }

    if (iter == end)
    {
        resultset.insert(result);
        return;
    }

    int next = *(iter + 1);
    int sign = open % 2 ? MINUS : PLUS;

    if (*iter == MINUS)
    {
        open++;
    }

    do
    {
        rec(resultset, iter + 2, end, result + sign * (*iter) * next, open);
    }
    while (open--);
}

void cleartable()
{
    memset(&table[0][0][0], 0, sizeof(table));
}

template <typename I>
int solve(I start, I end, int n)
{
    int result = 0;

    set<int> resultset;

    cleartable();
    rec(resultset, start + 1, end , *start, 0);

    return resultset.size();
}

int main()
{
    char str[200];

    while (cin.getline(&str[0], 200))
    {
        int members[61];
        int i = 0;

        char *z = &str[0];
        char c;
        int n = 0;
        while ((c = *z) != '\0')
        {
            z++;
            switch (c)
            {
            case ' ':
                break;
            case '-':
                members[i++] = MINUS;
                n++;
                break;
            case '+':
                members[i++] = PLUS;
                n++;
                break;
            default:
                z--;
                members[i++] = strtol(z, &z, 10);
            }
        }

        int *m = &members[0];
        cout << solve(m, m + i, n) << endl;
    }

    return 0;
}
