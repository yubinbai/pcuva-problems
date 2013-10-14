#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int input; // number of test cases
    int *mark; // dynamic memory allocation
    int i, j;
    double sum, average, result;
    int student;
    double belowAverage;
    cin >> input;
    for (i = 0; i < input; i++)
    {
        cin >> student;
        sum = 0;
        belowAverage = 0;
        mark = new int[student];
        for (j = 0; j < student; j++)
        {
            cin >> mark[j];
            sum += mark[j];
        }
        average = sum / student;
        for (j = 0; j < student; j++)
        {
            if (mark[j] > average)
                belowAverage += 1;
        }
        result = (belowAverage / student) * 100;
        printf("%.3f%c\n", result, '%');
        delete [] mark;
    }
    return 0;
}