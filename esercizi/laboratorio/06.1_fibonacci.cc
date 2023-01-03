#include <iostream>
using namespace std;

int main()
{
    int n, a = 0, b = 1;
    cout << "Inserire un valore maggiore o uguale a 0: ";
    cin >> n;
    if (n >= 0)
    {
        cout << "Successione di Fibonacci fino alla cifra n." << n << ": ";
        for (int i = 0; i <= n; i++)
        {
            cout << "  " << a << "  ";
            a = a + b;
            a = a + b;
            b = a - b;
            a = a - b;
        }
        cout << endl;
    }
    else
        cout << "Il numero inserito deve essere maggiore o uguale a 0" << endl;
    return 0;
}