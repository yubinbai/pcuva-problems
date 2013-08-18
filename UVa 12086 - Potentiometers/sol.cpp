#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int LSOne(int n)
{
    return n & (-n);
}

class FenwickTree
{
private:
    vector<int> ft;
public:
    FenwickTree(int n)
    {
        ft.assign(n + 1, 0);
    }
    int rangeSum(int b)
    {
        int sum = 0;
        for (; b; b -= LSOne(b))
            sum += ft[b];
        return sum;
    }
    int rangeSum(int a, int b)
    {
        return rangeSum(b) - (a == 1 ? 0 : rangeSum(a - 1));
    }
    void adjust(int k, int v)
    {
        for (; k < (int) ft.size(); k += LSOne(k))
            ft[k] += v;
    }
};

int pots[200005];

int main()
{
    int n, p1, p2, count = 0;
    char op[4];
    while (scanf("%d", &n), n)
    {
        count++;
        FenwickTree ft(n);

        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &pots[i]);
            ft.adjust(i, pots[i]);
        }

        if (count > 1)
            printf("\n");
        printf("Case %d:\n", count);
        while (scanf("%s", op), strcmp(op, "END") != 0)
        {
            //cout << op << endl;
            scanf("%d %d", &p1, &p2);
            if (strcmp(op, "M") == 0)
            {
                printf("%d\n", ft.rangeSum(p1, p2));
            }
            else if (strcmp(op, "S") == 0)
            {
                int adjamt = p2 - pots[p1];
                ft.adjust(p1, adjamt);
                pots[p1] = p2;
            }
        }

    }

    return 0;
}