#include <iostream>
using namespace std;

int main()
{
    float a, b;
    cout << "Inserire il primo valore: ";
    cin >> a;
    cout << "Inserire il secondo valore: ";
    cin >> b;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "I valori scambiati sono " << a << " e " << b << endl;
    return 0;
}