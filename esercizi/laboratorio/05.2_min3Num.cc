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
    if (a <= b && a <= c)
        cout << "Il numero piu' piccolo che e' stato inserito e': " << a << endl;
    else if (b <= c)
        cout << "Il numero piu' piccolo che e' stato inserito e': " << b << endl;
    else
        cout << "Il numero piu' piccolo che e' stato inserito e': " << c << endl;
    return 0;
}