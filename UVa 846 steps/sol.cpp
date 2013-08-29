#include <iostream>

using namespace std;

int main()
{
    int nc; /* number of cases */
    int m, n; /* numbers */
    int diff; /* difference between numbers */
    int steps; /* number of steps */

    cin >> nc;

    /* for each case.. */
    for (int i = 0; i < nc; i++)
    {
        cin >> m >> n;

        diff = n - m;
        steps = 0;

        /*
         * Compute quarter-squares sequence. This sequence represents
         * the maximum sum a number of steps can amount to
         */
        if (diff != 0)
        {
            unsigned int k = 0;     /* the limit for the sum of steps */
            unsigned int f = 2; /* divided by two, it represents the size of the next step */

            while (k < diff)
            {
                k += (f / 2); /* next step */
                steps++;
                f++;
            }

        }
        cout << steps << endl;
    }

    return 0;
}
