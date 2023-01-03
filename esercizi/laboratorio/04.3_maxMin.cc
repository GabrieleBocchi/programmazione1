#include <iostream>
using namespace std;

int main()
{
    float a, b, max, min;
    cout << "Inserire il valore di a: ";
    cin >> a;
    cout << "Inserire il valore di b: ";
    cin >> b;
    max = a * (a >= b) + b * (b > a);
    min = a + b - max;
    cout << "Il numero maggiore fra i due e' " << max << " mentre il minore e' " << min << endl;
    return 0;
}