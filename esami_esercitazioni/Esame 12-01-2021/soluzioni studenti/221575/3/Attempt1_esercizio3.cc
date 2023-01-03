#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta);

int main() { 

    int dimensioneMassima = 100;
    char espressioneBooleana [dimensioneMassima];
    bool corretta = true;
    char risultatoEspressione;

    cout << "Inserisci l'espressione: ";
    cin >> espressioneBooleana;

    risultatoEspressione = parseEspressioneBooleanaPrefissa(espressioneBooleana, corretta);

    if (corretta) {
        cout << "Risultato: " << risultatoEspressione << endl;
    }
    else {
        cout << "Espressione malformata" << endl;
    }
    
    return 0;
}


char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta) {
    // Scrivere il codice qui
    int i=0;
    char retval = true;
    char argomento1;
    char argomento2;
    char operatore;

    init();

    // SB: non incrementando l'indice "i", questo è un ciclo infinito
    while (espressione[i] != '\0') {
        push(espressione[i]);
    }
    // metto nelle variabili i primi argomenti e l'operatore 
    // partendo dalla fine della stringa (leggo da destra a sinistra)
    while (!vuota()) {
        top(argomento1);
        pop();
        top(argomento2);
        pop();
        top(operatore);

        // SB: operatori non implementati

        
    }

    // SB: manca la "deinit()"

    return retval;
}