#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    int h, w;
    while (cin >> h >> w)
    {
        if (h == 0 && w == 0)
            break;
        int n;
        if (w == 1)
        {
            n = 1;
        }
        else
        {
            n = 2;
            double loghlogw = log (h) / log (w);
            while (fabs(log(n + 1) / log(n) - loghlogw) > 1e-10)
                n++;
        }
        int k = 0;
        int temp = h;
        while ((temp /= (n + 1)) >= 1)
            k++;
        int not_working;
        if (n > 1)
            not_working = (pow(static_cast<double>(n), k) - 1) / (n - 1);
        else
        {
            not_working = log2(h);
        }
        int height = -(pow(static_cast<double>(n), k + 1) * (h / pow(static_cast<double>(n + 1), k)) - h * (n + 1));
        cout << not_working << " " << height << endl;
    }
}