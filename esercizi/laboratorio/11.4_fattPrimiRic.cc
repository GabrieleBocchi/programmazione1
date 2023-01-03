#include <iostream>
using namespace std;

void scomponi(int n, int divisore);
bool isPrimo(int n, int divisore);

int main()
{
    int n;
    cout << "Inserire un numero: ";
    cin >> n;
    if (n >= 2)
    {
        cout << "Il numero " << n << " puo' essere scomposto nei seguenti fattori primi: ";
        scomponi(n, 2);
        cout << endl;
    }
    else
        cout << "Il numero " << n << " non puo' essere scomposto in fattori primi" << endl;
    return 0;
}

void scomponi(int n, int divisore)
{
    if (n == 1)
        return;
    if (n % divisore == 0 && isPrimo(divisore, 2) == true)
    {
        cout << divisore << "  ";
        scomponi(n / divisore, 2);
    }
    else
        scomponi(n, divisore + 1);
    return;
}

bool isPrimo(int n, int divisore)
{
    if (n == divisore)
        return true;
    else if (n % divisore != 0)
        return isPrimo(n, divisore + 1);
    else
        return false;
}