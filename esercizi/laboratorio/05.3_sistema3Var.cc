#include <iostream>
using namespace std;

int main()
{
    float a, b, c;
    cout << "Inserire il valore del primo numero: ";
    cin >> a;
    cout << "Inserire il valore del secondo numero: ";
    cin >> b;
    cout << "Inserire il valore del terzo numero: ";
    cin >> c;
    if (a >= b && a <= c)
        cout << -1 << endl;
    else if (a < b)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}