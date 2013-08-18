#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

string sumar(string n1, string n2)
{
    string num1;
    string num2;

    string resultado;
    int sizeNum2;

    int carry = 0;
    int diff = 0;
    int nTemp1;
    int nTemp2;
    int rTemp;

    if (n1.size() <= n2.size())
    {
        num1 = n1;
        num2 = n2;

    }
    else
    {
        num2 = n1;
        num1 = n2;
    }

    sizeNum2 = num2.size();

    resultado.resize(num2.size(), ' ');
    diff = num2.size()  - num1.size();

    for (int i = sizeNum2 - 1; i >= 0; i--)
    {
        if (i - diff >= 0)
        {

            nTemp1 = num1[i - diff] - 48;
        }
        else
        {
            nTemp1 = 0;
        }
        nTemp2 = num2[i] - 48;
        rTemp = nTemp1 + nTemp2 + carry;

        if (rTemp >= 10)
        {

            resultado[i] = (rTemp - 10 ) + 48 ;
            carry = 1;
        }
        else
        {
            resultado[i] = rTemp + 48 ;
            carry = 0;
        }
    }

    if (carry == 1)
    {
        string uno = " ";
        uno[0] = 49;
        resultado = uno + resultado;
    }
    return resultado;
}

string fib(int n)
{
    string fib1 = "1";
    string fib0 = "0";
    string fibResult = "0";

    for (int i = 0; i < n; i++)
    {
        fibResult = sumar(fib1, fib0);
        fib1 = fib0;
        fib0 = fibResult;
    }
    return fibResult;
}

int main(int argc, char *argv[])
{
    int m;
    int sizeVFibs = 0;

    vector <string> vFibs;
    vFibs.push_back("0");
    vFibs.push_back("1");
    vFibs.push_back("1");

    while (cin >> m )
    {
        sizeVFibs = vFibs.size();
        if (sizeVFibs <= m)
        {
            string fib1 = vFibs.at(sizeVFibs - 2);
            string fib0 = vFibs.at(sizeVFibs - 1);
            string fibResult = "0";
            for (int i = sizeVFibs - 1; i < m; i++)
            {
                fibResult = sumar(fib1, fib0);
                vFibs.push_back(fibResult);
                fib1 = fib0;
                fib0 = fibResult;
            }
            cout << "The Fibonacci number for " << m << " is " << fibResult << endl;
        }
        else
        {
            if (m == 1 || m == 2)
            {
                cout << "The Fibonacci number for " << m << " is 1" << endl;
            }
            else if (m == 0)
            {
                cout << "The Fibonacci number for " << m << " is 0" << endl;
            }
            else
            {
                cout << "The Fibonacci number for " << m << " is " << sumar(vFibs[m - 2], vFibs[m - 1]) << endl;
            }
        }
    }
    return 0;
}
