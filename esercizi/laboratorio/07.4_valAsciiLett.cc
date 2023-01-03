#include <iostream>
using namespace std;

int main()
{
    cout << "Valore ASCII delle lettere maiuscole e minuscole dell'alfabeto!" << endl;
    for (int i = 65; i <= 90; i++)
        cout << char(i) << " = " << i << "   " << char(i + 32) << " = " << i + 32 << endl;
    cout << endl;
    return 0;
}