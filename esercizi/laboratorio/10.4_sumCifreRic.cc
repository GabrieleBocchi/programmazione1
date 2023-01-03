#include <iostream>
using namespace std;

int sommaCifreRic(int n);

int main()
{
    int n, ris = 0;
    cout << "Inserire un numero: ";
    cin >> n;
    ris = sommaCifreRic(n);
    cout << "La somma delle cifre del numero " << n << " e': " << ris << endl;
    return 0;
}

int sommaCifreRic(int n)
{
    if (n == 0)
        return 0;
    else
        return n % 10 + sommaCifreRic(n / 10);
}