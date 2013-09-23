#include <iostream>
using namespace std;
int array[151], data[151];
int main()
{
    int i, j, k, l, counter, counts;
    bool flag;
    int dFinal = 2; // to store variable 3<=n<150
    for (i = 3; i < 151; ++i)
    {
        for (j = 1; j <= 1000; ++j)
        {
            for (l = 1; l <= i; ++l)
                array[l] = 0;
            flag = true;
            // counter used for counting how many array[zeros] exists
            counter = counts = 0;
            array[1] = 1;
            k = 1;
            // main calculation
            while (counter != (i - 2))
            {
                k = (k % i) + 1;
                if (array[k] == 0)
                    counts++;
                if (counts == j)
                {
                    array[k] = 1;
                    if (array[2] == 1)
                    {
                        flag = false;
                        break;
                    }
                    counts = 0;
                    counter++;
                }
            }
            if (flag)
            {
                data[++dFinal] = j;
                break;
            }
        }
    }
    int input;
    while (cin >> input)
    {
        if (input == 0) break;
        cout << data[input] << endl;
    }
    return 0;
}