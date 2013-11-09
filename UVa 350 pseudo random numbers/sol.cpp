#include <iostream>
using namespace std;
int main()
{
    long z, i, m, l;
    long count;
    long caseCount = 0;
    long dataSet[10000];
    long x, y, temp;
    bool flag;
    while (cin >> z >> i >> m >> l)
    {
        if (!z && !i && !m && !l) break;
        for (x = 0; x < 10000; ++x)
            dataSet[x] = 0;
        dataSet[0] = l;
        flag = true;
        y = 1;
        temp = l;
        while (flag)
        {
            temp = (z * temp + i) % m;
            dataSet[y] = temp;
            for (x = y - 1; x > 0; --x)
            {
                if (dataSet[y] == dataSet[x])
                {
                    count = y;
                    flag = false;
                    break;
                }
            }
            ++y;
        }
        ++caseCount;
        cout << "Case " << caseCount << ": " << --count << endl;
    }
    return 0;
}