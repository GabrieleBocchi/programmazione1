#include <iostream>
using namespace std;

int fattorialeRic(int n);

int main()
{
    int n;
    cout << "Inserire un numero maggiore di 0: ";
    cin >> n;
    if (n >= 0)
    {
        int ris = fattorialeRic(n);
        cout << "Il fattoriale di " << n << " e': " << ris << endl;
    }
    else
        cout << "Il numero inserito deve essere maggiore o uguale a 0" << endl;
    return 0;
}

int fattorialeRic(int n)
{
    if (n == 0)
        return 1;
    else
        return n * fattorialeRic(n - 1);
}