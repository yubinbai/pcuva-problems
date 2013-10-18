#include <iostream>
#include <string>
using namespace std;
int main()
{
    long long test, friends, boxes, result, i, j;
    long long k, k2, finalResult;
    cin >> test;
    while (test--)
    {
        cin >> friends >> boxes;
        finalResult = 0;
        for (i = 0; i < boxes; ++i)
        {
            cin >> k;
            result = 1;
            for (j = 0; j < k; ++j)
            {
                cin >> k2;
                result = (k2 * result) % friends;
            }
            finalResult += result % friends;
            finalResult %= friends;
        }
        cout << finalResult << endl;
    }
    return 0;
}