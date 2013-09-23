#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <algorithm>
#include <math.h>
using namespace std;
static void
factorize(int number)
{
    vector<int> factors;
    cout << number << " = ";
    if (number < 0)
    {
        factors.push_back(-1);
        number = abs(number);
    }
    for (int i = 2; i <= sqrt(number);)
    {
        if (number % i == 0)
        {
            factors.push_back(i);
            number /= i;
        }
        else
            i++;
    }
    if (number > 1)
        factors.push_back(number);
    for (vector<int>::iterator it = factors.begin();
            it != factors.end(); ++it)
    {
        if (it != factors.begin())
            cout << " x ";
        cout << *it;
    }
    cout << endl;
}
int
main(void)
{
    string line;
    vector<int> numbers;
    while (getline(cin, line))
    {
        if (line.empty() || line[0] == '\n')
            break;
        istringstream tmp(line);
        int number;
        tmp >> number;
        if (number == 0)
            break;
        numbers.push_back(number);
    }
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
        factorize(*it);
}
