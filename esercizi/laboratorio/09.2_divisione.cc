#include <iostream>
using namespace std;

int divisione(int a, int b, int &resto);

int main()
{
    int a, b, resto;
    cout << "Inserire il primo numero: ";
    cin >> a;
    do
    {
        cout << "Inserire il secondo numero (diverso da 0): ";
        cin >> b;
    } while (b == 0);
    int ris = divisione(a, b, resto);
    cout << a << " / " << b << " = " << ris << " con resto " << resto << endl;
    return 0;
}

int divisione(int a, int b, int &resto)
{
    int ris = 0;
    int a_copia = a;
    if (a >= 0 && b > 0)
        while (a_copia >= b)
        {
            ris++;
            a_copia -= b;
        }
    else if (a >= 0 && b < 0)
        while (a_copia >= -b)
        {
            ris--;
            a_copia += b;
        }
    else if (a < 0 && b > 0)
        while (a_copia <= -b)
        {
            ris--;
            a_copia += b;
        }
    else
        while (a_copia <= b)
        {
            ris++;
            a_copia -= b;
        }
    resto = a % b;
    return ris;
}