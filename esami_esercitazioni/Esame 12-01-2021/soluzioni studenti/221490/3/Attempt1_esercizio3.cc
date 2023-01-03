#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione[], bool &corretta);

int main()
{

    int dimensioneMassima = 100;
    char espressioneBooleana[dimensioneMassima];
    bool corretta = true;
    char risultatoEspressione;

    cout << "Inserisci l'espressione: ";
    cin >> espressioneBooleana;

    risultatoEspressione = parseEspressioneBooleanaPrefissa(espressioneBooleana, corretta);

    if (corretta)
    {
        cout << "Risultato: " << risultatoEspressione << endl;
    }
    else
    {
        cout << "Espressione malformata" << endl;
    }

    return 0;
}

char parseEspressioneBooleanaPrefissa(char espressione[], bool &corretta)
{
    bool continua = false;
    init();
    for (int i = 0; i < 100; i++)
    {
        cout << espressione[i];
        push(espressione[i]);
    }
    cout << endl;
    while (!vuota())
    {
        char c;
        top(c);
        cout << c;
    }

    // SB: esercizion non implementato
    
    return '\0';
}