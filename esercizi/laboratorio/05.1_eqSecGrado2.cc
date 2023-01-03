#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a, b, c, delta, x1, x2;
    cout << "Inserire il coefficente di x^2: ";
    cin >> a;
    cout << "Inserire il coefficente di x: ";
    cin >> b;
    cout << "Inserire il termine noto: ";
    cin >> c;
    delta = b * b - 4 * a * c;
    if (delta >= 0)
    {
        x1 = (-b + sqrt(delta)) / 2 * a;
        x2 = (-b - sqrt(delta)) / 2 * a;
        cout << "Le soluzioni sono " << x1 << " e " << x2 << endl;
    }
    else
        cout << "Le soluzioni non sono numeri reali" << endl;
    return 0;
}