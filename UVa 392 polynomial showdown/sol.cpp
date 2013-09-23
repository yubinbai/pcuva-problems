#include <iostream>
using namespace std;
void output(int coef[])
{
    bool printable = false;
    bool first = true;
    for (int i = 0; i < 9; i++)
    {
        if (coef[i] != 0)
            printable = true;
        else
            continue;
        if (printable)
        {
            bool neg = false;
            if (coef[i] == 0)
                continue;
            else if (coef[i] < 0)
            {
                neg = true;
                coef[i] *= -1;
            }
            if (!neg)
            {
                if (!first)
                    cout << " + ";
            }
            else if (!first)
                cout << " - ";
            else
                cout << "-";
            if ((i == 8) || (coef[i] != 1))
                cout << coef[i];
            first = false;
            if (i < 7)
                cout << "x^" << 8 - i;
            else if (i == 7)
                cout << "x";
        }
    }
    if (!printable)
        cout << "0";
    cout << endl;
}
int main(void)
{
    while (true)
    {
        int coef[9];
        for (int i = 0; i < 9; i++)
            cin >> coef[i];
        if (cin.eof())
            break;
        output(coef);
    }
    return 0;
}