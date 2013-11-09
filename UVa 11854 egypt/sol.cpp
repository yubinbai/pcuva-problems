#include<iostream>
using namespace std;
int main ()
{
    int side1 , side2 , side3;
    while (cin >> side1 >> side2 >> side3)
    {
        if (side1 == 0 && side2 == 0 && side3 == 0)
        {
            break;
        }
        else if (side1 * side1 + side2 * side2 == side3 * side3 ||
                 side1 * side1 + side3 * side3 == side2 * side2 ||
                 side3 * side3 + side2 * side2 == side1 * side1)
        {
            cout << "right" << endl;
        }
        else
        {
            cout << "wrong" << endl;
        }
    }
    return 0;
}