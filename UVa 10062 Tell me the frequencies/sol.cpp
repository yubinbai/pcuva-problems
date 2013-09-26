#include <iostream>
#include <string.h>
using namespace std;
int getMax(int array[]);
int main()
{
    char str[1005];
    int freq[150];
    int i, j;
    int size;
    int c; // use for counting frequencies
    int max;
    int flag = 0;
    while (cin.getline(str, sizeof(str)) && !cin.eof())
    {
        size = strlen(str);
        for (i = 32; i <= 127; i++)
        {
            c = 0;
            for (j = 0; j < size; j++)
            {
                if (i == str[j])
                    ++c;
            }
            freq[i] = c;
        }
        max = getMax(freq);
        if (flag)
            cout << endl;
        flag = 1;
        for (i = 1; i <= max; i++)
        {
            for (j = 127; j >= 32; --j)
            {
                if (i == freq[j])
                    cout << j << " " << freq[j] << endl;
            }
        }
    }
    return 0;
}
int getMax(int array[])
{
    int max = 0;
    int i;
    for (i = 32; i <= 127; i++)
    {
        if (max < array[i])
            max = array[i];
    }
    return max;
}