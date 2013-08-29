#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    long int k;
    while (cin >> k)
    {
        cin.get();
        string spoly;
        getline(cin, spoly);
        vector<long int> poly;
        vector<long int> sol;
        istringstream iss(spoly);
        long int token;
        while (iss >> token) poly.push_back(token);
        for (int i = 0; i < poly.size() - 1; ++i)
        {
            sol.push_back(poly[i]);
            poly[i] -= sol[i];
            poly[i + 1] -= -sol[i] * k;
        }
        cout << "q(x):";
        for (vector<long int>::iterator it = sol.begin(); it != sol.end(); ++it)
        {
            cout << " " << *it;
        }
        cout << endl << "r = " << poly[poly.size() - 1] << endl << endl;
    }
    return 0;
}