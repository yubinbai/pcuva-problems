#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int Map = 0;
    int straight[4];
    int slant[4];
    int length;
    char direction_1, direction_2;
    double x, y, d;
    double root_2 = pow(2.0 , 0.5);
    cout.setf(ios::fixed);
    cout.precision(3);
    while (cin >> length)
    {
        Map ++;
        straight[0] = 0;
        straight[1] = 0;
        straight[2] = 0;
        straight[3] = 0;
        slant[0] = 0;
        slant[1] = 0;
        slant[2] = 0;
        slant[3] = 0;
        x = 0;
        y = 0;
        do
        {
            cin.get(direction_1);
            cin.get(direction_2);
            if (direction_2 == ',' || direction_2 == '.')
            {
                switch (direction_1)
                {
                case 'E':
                    straight[0] += length;
                    break;
                case 'S':
                    straight[1] += length;
                    break;
                case 'W':
                    straight[2] += length;
                    break;
                case 'N':
                    straight[3] += length;
                    break;
                }
            }
            else
            {
                if (direction_1 == 'S')
                {
                    if (direction_2 == 'E')
                    {
                        slant[0] += length;
                    }
                    else
                    {
                        slant[1] += length;
                    }
                }
                else
                {
                    if (direction_2 == 'E')
                    {
                        slant[3] += length;
                    }
                    else
                    {
                        slant[2] += length;
                    }
                }
                cin.get(direction_2);

            }
        }
        while (direction_2 != '.' && cin >> length);
        x = straight[0] - straight[2] + (slant[0] + slant[3] - slant[1] - slant[2]) / root_2;
        y = straight[3] - straight[1] + (slant[2] + slant[3] - slant[0] - slant[1]) / root_2;
        d = pow(x , 2) + pow(y , 2);
        d = pow(d, 0.5);
        cout << "Map #" << Map << endl;
        cout << "The treasure is located at (" << x << "," << y << ")." << endl;
        cout << "The distance to the treasure is " << d << "." << endl << endl;
    }
    return 0;
}