#include <fcntl.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <cstdio>
#include <ctype.h>
#include <algorithm>
#include <set>

using namespace std;

vector<int> nums;

int BackDigitsDiffCountOf(int n1, int n2)
{
    int lastDiffDigitPosition = 0;
    int index = 1;
    while (n1 > 0)
    {
        int n1Digit = n1 % 10;
        int n2Digit = n2 % 10;

        if (n1Digit != n2Digit)
        {
            lastDiffDigitPosition = index;
        }
        n1 /= 10;
        n2 /= 10;
        index++;
    }
    return lastDiffDigitPosition;
}

void printResults()
{
    printf("0");
    if (nums.size() == 1)
    {
        printf("%d\n", nums[0]);
    }
    else if (nums.size() > 1)
    {
        long first = nums[0];
        int last = nums.back();
        int lastDigitCount = floor(log10(last)) + 1;
        int firstDigitCount = floor(log10(first)) + 1;
        if (lastDigitCount > firstDigitCount)
        {
            printf("%d-%d\n", first, last);
        }
        else
        {
            int diffCount = BackDigitsDiffCountOf(first, last);
            printf("%d-%d\n", first, last % (int)pow(10, diffCount));
        }
    }
}

int main()
{
    int numCount;
    int tc = 0;
    while (scanf("%d\n", &numCount) && numCount != 0)
    {
        nums.clear();
        tc++;
        printf("Case %d:\n", tc);
        for (unsigned i = 0; i < numCount; i++)
        {
            int current;
            scanf("%d\n", &current);
            if (nums.empty())
            {
                nums.push_back(current);
            }
            else if (nums.back() + 1 == current)
            {
                nums.push_back(current);
            }
            else
            {
                printResults();
                nums.clear();
                nums.push_back(current);
            }
        }
        if (!nums.empty())
        {
            printResults();
        }
        printf("\n");
    }
    return 0;

}