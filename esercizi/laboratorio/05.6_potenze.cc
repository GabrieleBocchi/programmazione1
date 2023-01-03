#include <iostream>
using namespace std;

int main()
{
    float a, ris = 1;
    int n, i = 1;
    cout << "Inserire un valore per la base: ";
    cin >> a;
    cout << "Inserire un valore maggiore o uguale a 1 per l'esponente: ";
    cin >> n;
    if (n >= 1)
    {
        cout << a << "^" << n << " = ";
        while (i <= n)
        {
            ris *= a;
            cout << "  " << ris << "  ";
            i++;
        }
        cout << endl;
    }
    else
        cout << "L'esponente deve essere maggiore o uguale a 1" << endl;
    return 0;
}