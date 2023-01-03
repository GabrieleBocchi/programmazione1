#include <iostream>
#include <algorithm>
using namespace std;

int generaDado();
int massimo(int n1, int n2);
int minimo(int n1, int n2);

int main()
{
    srand(time(NULL));
    int a1 = generaDado();
    int a2 = generaDado();
    int d1 = generaDado();
    int d2 = generaDado();
    int temp;

    cout << "Gli attaccanti hanno tirato due dadi e hanno ottenuto " << a1 << " e " << a2 << endl;
    cout << "I difensori hanno tirato due dadi e hanno ottenuto " << d1 << " e " << d2 << endl << endl;

    temp = a1;
    a1 = massimo(a1, a2);
    a2 = minimo(temp, a2);
    temp = d1;
    d1 = massimo(d1, d2);
    d2 = minimo(temp, d2);

    cout << "Valore piu' alto ottenuto dagli attaccanti: " << a1 << endl;
    cout << "Valore piu' alto ottenuto dai difensori: " << d1 << endl;

    if (a1 > d1)
        cout << "Primo scontro vinto dagli attaccanti" << endl << endl;
    else if (a1 < d1)
        cout << "Primo scontro vinto dai difensori" << endl << endl;
    else
        cout << "Primo scontro finito in pareggio" << endl << endl;

    cout << "Valore piu' basso ottenuto dagli attaccanti: " << a2 << endl;
    cout << "Valore piu' basso ottenuto dai difensori: " << d2 << endl;

    if (a2 > d2)
        cout << "Secondo scontro vinto dagli attaccanti" << endl;
    else if (a2 < d2)
        cout << "Secondo scontro vinto dai difensori" << endl;
    else
        cout << "Secondo scontro finito in pareggio" << endl;
    
    return 0;
}

int generaDado()
{
    return rand() % 6 + 1;
}

int massimo(int n1, int n2)
{
    return max(n1, n2);
}

int minimo(int n1, int n2)
{
    return min(n1, n2);
}