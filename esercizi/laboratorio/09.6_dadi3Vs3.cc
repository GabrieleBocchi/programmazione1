#include <iostream>
using namespace std;

int generaDado();
void ordinaDecrescente(int &n1, int &n2, int &n3);

int main()
{
    srand(time(NULL));
    int a1 = generaDado();
    int a2 = generaDado();
    int a3 = generaDado();
    int d1 = generaDado();
    int d2 = generaDado();
    int d3 = generaDado();

    cout << "Gli attaccanti hanno tirato tre dadi e hanno ottenuto: " << a1 << ", " << a2 << " e " << a3 << endl;
    cout << "I difensori hanno tirato tre dadi e hanno ottenuto: " << d1 << ", " << d2 << " e " << d3 << endl << endl;

    ordinaDecrescente(a1, a2, a3);
    ordinaDecrescente(d1, d2, d3);

    cout << "Valore piu' alto ottenuto dagli attaccanti: " << a1 << endl;
    cout << "Valore piu' alto ottenuto dai difensori: " << d1 << endl;

    if (a1 > d1)
        cout << "Primo scontro vinto dagli attaccanti" << endl << endl;
    else if (a1 < d1)
        cout << "Primo scontro vinto dai difensori" << endl << endl;
    else
        cout << "Primo scontro finito in pareggio" << endl << endl;
    
    cout << "Valore medio ottenuto dagli attaccanti: " << a2 << endl;
    cout << "Valore medio ottenuto dai difensori: " << d2 << endl;

    if (a2 > d2)
        cout << "Secondo scontro vinto dagli attaccanti" << endl << endl;
    else if (a2 < d2)
        cout << "Secondo scontro vinto dai difensori" << endl << endl;
    else
        cout << "Secondo scontro finito in pareggio" << endl << endl;
    
    cout << "Valore piu' basso ottenuto dagli attaccanti: " << a3 << endl;
    cout << "Valore piu' basso ottenuto dai difensori: " << d3 << endl;

    if (a3 > d3)
        cout << "Terzo scontro vinto dagli attaccanti" << endl;
    else if (a3 < d3)
        cout << "Terzo scontro vinto dai difensori" << endl;
    else
        cout << "Terzo scontro finito in pareggio" << endl;
    
    return 0;
}

int generaDado()
{
    return rand() % 6 + 1;
}

void ordinaDecrescente(int &n1, int &n2, int &n3)
{
    int temp;
    if (n1 < n2)
        {
            temp = n1;
            n1 = n2;
            n2 = temp;
        }
    if (n1 < n3)
        {
            temp = n1;
            n1 = n3;
            n3 = temp;
        }
    if (n2 < n3)
        {
            temp = n2;
            n2 = n3;
            n3 = temp;
        }
    return;
}