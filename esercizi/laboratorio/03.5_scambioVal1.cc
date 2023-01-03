#include <iostream>
using namespace std;

int main()
{
    float a, b, t;
    cout << "Inserire il primo valore: ";
    cin >> a;
    cout << "Inserire il secondo valore: ";
    cin >> b;
    t = a;
    a = b;
    b = t;
    cout << "I valori scambiati sono " << a << " e " << b << endl;
    return 0;
}