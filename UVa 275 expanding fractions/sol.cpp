#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    while (true)
    {
        int numerator, denominator;
        cin >> numerator >> denominator;
        if (!numerator && !denominator)
            break;
        int quotient = numerator / denominator;
        numerator -= quotient * denominator;
        map<int, size_t> remainders;
        vector<int> quotients;
        remainders.insert(make_pair(numerator, quotients.size()));
        size_t repeat;
        while (true)
        {
            if (numerator < denominator)
                numerator *= 10;
            quotient = numerator / denominator;
            quotients.push_back(quotient);
            numerator -= quotient * denominator;
            pair<map<int, size_t>::iterator, bool> result =
                remainders.insert(make_pair(numerator, quotients.size()));
            if (!result.second)
            {
                repeat = result.first->second;
                break;
            }
        }
        size_t nr_repeat = quotients.size() - repeat;
        if (!numerator)
        {
            quotients.pop_back();
            nr_repeat = 0;
        }
        const size_t max_nr_print = 50;
        cout << '.';
        int nr_printed = 1;
        size_t i = 0, j = quotients.size();
        for ( ; i < j; i++)
        {
            cout << quotients[i];
            if (++nr_printed == max_nr_print)
            {
                cout << endl;
                nr_printed = 0;
            }
        }
        if (nr_printed)
            cout << endl;
        if (nr_repeat)
            cout << "The last " << j - repeat <<
                 " digits repeat forever.\n\n";
        else
            cout << "This expansion terminates.\n\n";
    }
    return 0;
}
