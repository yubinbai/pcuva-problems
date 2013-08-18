#include <iostream>

using namespace std;

int main()
{
    int ugly[1500];
    int factor2, factor3, factor5;

    ugly[0] = 1;
    factor2 = factor3 = factor5 = 0;
    for (int i = 1; i < 1500; i++)
    {
        int factor2Ugly = ugly[factor2] * 2;
        int factor3Ugly = ugly[factor3] * 3;
        int factor5Ugly = ugly[factor5] * 5;
        if (factor2Ugly <= factor3Ugly && factor2Ugly <= factor5Ugly)
        {
            ugly[i] = factor2Ugly;
            factor2 ++;
        }
        if (factor3Ugly <= factor2Ugly && factor3Ugly <= factor5Ugly)
        {
            ugly[i] = factor3Ugly;
            factor3 ++;
        }
        if (factor5Ugly <= factor2Ugly && factor5Ugly <= factor3Ugly)
        {
            ugly[i] = factor5Ugly;
            factor5 ++;
        }
    }
    cout << "The 1500'th ugly number is " << ugly[1499] << "." << endl;

    return 0;
}