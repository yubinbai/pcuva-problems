#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
int N, k;
int counter;
bool ATM(vector < int > &t, int rest, int &student)
{
    while (rest != 0)
    {
        if (rest < t[student])
        {
            t[student] -= rest;
            rest = 0;
        }
        else
        {
            rest -= t[student];
            t[student] = 0;
            cout << setw(3) << student + 1;
            counter++;
            if (count(t.begin(), t.end(), 0) == N)
                return false;
        }
        do
        {
            student = (student + 1) % N;
        }
        while (t[student] == 0);
    }
    return true;
}
void grant(void)
{
    vector < int > t(N);
    fill(t.begin(), t.end(), 40);
    int student = 0, i = 1;
    counter = 0;
    while (true)
    {
        if (!ATM(t, i, student))
            break;
        i = i % k + 1;
    }
    cout << endl;
}
int main(void)
{
    while (true)
    {
        cin >> N >> k;
        if (!N && !k)
            break;
        grant();
    }
    return 0;
}