#include <iostream>
#include <cstdlib>
using namespace std;

int generaDado();

int main()
{
    int cont = 0;
    srand(time(NULL));
    for (int i = 1; i <= 6; i++)
        if (generaDado() == 1)
            cont++;
    int n;
    cout << "Sono stati lanciati 6 dadi, indovina quanti di essi sono risultati 1: ";
    do
    {
        cin >> n;
        if (n == cont)
            cout << "Hai indovinato, complimenti" << endl;
        else
            cout << "Mi dispiace non hai indovinato, riprova: ";
    } while (n != cont);
    return 0;
}

int generaDado()
{
    return rand() % 6 + 1;
}