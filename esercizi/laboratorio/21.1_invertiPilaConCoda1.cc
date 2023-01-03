#include <iostream>
#include "21.1_invertiPilaConCoda1.h"
#include "21.1_invertiPilaConCoda2.h"
using namespace std;

int main()
{
    pila_init();
    coda_init();
    int n, value;
    cout << "Inserire quanti numeri si vuole inserire nella pila: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Inserire numero: ";
        cin >> value;
        pila_push(value);
    }
    cout << endl << "E' stata creata la pila: " << endl << endl;
    pila_print();
    for (int i = 0; i < n; i++)
    {
        pila_top(value);
        coda_enqueue(value);
        pila_pop();
    }
    for (int i = 0; i < n; i++)
    {
        coda_first(value);
        pila_push(value);
        coda_dequeue();
    }
    cout << endl << "Pila invertita correttamente: " << endl << endl;
    pila_print();
    pila_deinit();
    coda_deinit();
    return 0;
}