#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta);
int dimArray(char espressione[]);

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
    corretta = true;
    int dim = dimArray(espressione);
    init();
    for(int i = 0; i < dim; i++) {
        push(espressione[i]);
    }


    bool arg1 = NULL, arg2 = NULL;
    // SB: variabile inutilizzata
    char op ;
    char currChar;

    top(currChar);
    if (currChar == '0') {
        arg1 = false;
    } else if (currChar == '1') {
        arg1 = true;
    } else {
        corretta = false;
        return 'e';
    }
    pop();

    // SB: "!vuota()"
    while (!vuota) {
        top(currChar);
        if (currChar == '!') {
            arg1 = !arg1;
        }else if (currChar == '0') {
            arg2 = false;
        } else if (currChar == '1') {
            arg2 = true;
        } 
        /* SB: il codice non considera la possibilità di ricevere un'espressione
         * che consiste in un solo valore, per esempio come "1"
         */
        else {
            corretta = false;
            return 'e';
        }

        /* SB: il codice non considera la possibilità di ricevere un'espressione
         * che applica l'operatore "!" al secondo valore, per esempio come "&!11"
         */
        pop();
        top(currChar);
        if (currChar == '&') {
            // SB: bisognava confrontare "arg1" con "arg2", non negare "arg1". Operatore & non implementato.
            arg1 = !arg1;
        }else if (currChar == '0') {
            arg2 = false;
        } else if (currChar == '1') {
            arg2 = true;
        } else {
            corretta = false;
            return 'e';
        }

    }
    


}

int dimArray(char espressione[]) {
    char carattere;
    int indice = 0;

    /* SB: il ciclo "while" era la corretta scelta per calcolare la
     * dimensione dell'array. Questo codice ritorna la dimensione
     * contando anche il carattere terminatore ('\0')
     */
    do {
        carattere = espressione[indice];
        indice++;
    } while(carattere != '\0');

    return indice;
}