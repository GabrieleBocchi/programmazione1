#include <iostream>
using namespace std;

int potenzaRic(int base, int esponente);

int main()
{
    int base, esponente;
    cout << "Inserire la base: ";
    cin >> base;
    cout << "Inserire l'esponente (maggiore o uguale a 0): ";
    cin >> esponente;
    if (esponente >= 0)
    {
        int ris = potenzaRic(base, esponente);
        cout << base << "^" << esponente << " = " << ris << endl;
    }
    else
        cout << "L'esponente deve essere maggiore o uguale a 0" << endl;
    return 0;
}

int potenzaRic(int base, int esponente)
{
    if (esponente == 0)
        return 1;
    else
        return base * potenzaRic(base, esponente - 1);
}