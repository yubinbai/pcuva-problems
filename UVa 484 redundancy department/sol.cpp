#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
int
main(void)
{
    string line;
    map<int, int> number_map;
    vector<int> numbers;
    while (getline(cin, line))
    {
        if (line.empty())
            break;
        istringstream tmp(line);
        int number;
        while (tmp >> number)
        {
            map<int, int>::iterator it = number_map.find(number);
            if (it != number_map.end())
                it->second++;
            else
            {
                number_map[number] = 1;
                numbers.push_back(number);
            }
        }
    }
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
    {
        cout << *it << " " << number_map[*it] << endl;
    }
}