#include <iostream>
#include "21.2_parPalindroma1.h"
#include "21.2_parPalindroma2.h"
using namespace std;

int main()
{
    pila_init();
    coda_init();
    char parola[100];
    cout << "Inserire una parola: ";
    cin >> parola;
    for (int i = 0; parola[i] != '\0'; i++)
    {
        pila_push((int)parola[i]);
        coda_enqueue((int)parola[i]);
    }
    int value1, value2;
    bool isPalindroma = true;
    for (int i = 0; pila_top(value1) && coda_first(value2) && isPalindroma; i++)
    {
        pila_pop();
        coda_dequeue();
        if (value1 != value2)
            isPalindroma = false;
    }
    if (isPalindroma)
        cout << endl << "La parola inserita e' palindroma" << endl;
    else
        cout << endl << "La parola inserita non e' palindroma" << endl;
    pila_deinit();
    coda_deinit();
    return 0;
}