#include <iostream>
#include <string>

using namespace std;

int main()
{

    string frase;
    while (getline (cin, frase))
    {
        int tam = frase.size();
        char c;
        int num;
        for (int i = 0; i < tam; i++)
        {
            num = frase[i];
            c = num - 7;
            cout << c;
        }
        cout << endl;
    }

    return 0;
}