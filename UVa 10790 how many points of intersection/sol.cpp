#include <iostream>
using namespace std;
//固定下面的个数，依次增加上面点的个数，公式：n*(n-1)*m*(m-1)/4
int main()
{
    long long m, n;
    int nCases = 0;

    while (cin >> m >> n, m + n != 0)
    {
        long long a = m * m;
        long long b = n * n;
        cout << "Case " << ++nCases << ": "
             << (a * b - a * n - b * m + m * n) / 4 << endl;
    }

    return 0;
}