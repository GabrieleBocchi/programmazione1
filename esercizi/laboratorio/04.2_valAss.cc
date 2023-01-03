#include <iostream>
using namespace std;

int main()
{
    float a, b, ris;
    cout << "Inserire il valore di a: ";
    cin >> a;
    cout << "Inserire il valore di b: ";
    cin >> b;
    ris = (a - b) * (a >= b) + (b - a) * (b > a);
    cout << "|" << a << " - " << b << "| = " << ris << endl;
    return 0;
}