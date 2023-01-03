#include <iostream>
using namespace std;

int main()
{
    char a;
    cout << "Inserire una lettera: ";
    cin >> a;
    if (a == 65 || a == 69 || a == 73 || a == 79 || a == 85 || a == 97 || a == 101 || a == 105 || a == 111 || a == 117)
        cout << "Hai inserito una vocale" << endl;
    else if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
        cout << "Hai inserito una consonante" << endl;
    else
        cout << "Non hai inserito una lettera" << endl;
    return 0;
}