#include <iostream>
#include <cstdlib>
using namespace std;

int generaDado();

int main()
{
    srand(time(NULL));
    int dado1 = generaDado();
    int dado2 = generaDado();
    cout << "L'attaccante ha tirado il dado e ha ottenuto: " << dado1 << endl;
    cout << "Il difensore ha tirado il dado e ha ottenuto: " << dado2 << endl;
    if (dado1 > dado2)
        cout << "L'attaccante ha vinto" << endl;
    else if (dado1 < dado2)
        cout << "Il difensore ha vinto" << endl;
    else
        cout << "Nessun vincitore, pareggio" << endl;
    return 0;
}

int generaDado()
{
    return rand() % 6 + 1;
}