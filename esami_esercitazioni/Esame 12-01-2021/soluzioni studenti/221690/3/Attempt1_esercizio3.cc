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
    
    // SB: "deinit()" e "return" multipli in funzione
    // SB: il codice è complicato. Inoltre, suggerisco di assegnare alle variabili nomi più informativi

    init();
    char c, c1;
    int inv_and[50];
    int iia = 0, num_and = 0;
    bool inv = false;
    int op = 0;
    for (int i = 0; espressione[i] != '\0'; i++) {
        c = espressione[i];
        if (c == '!') inv = true;
        else {
            if (c == '&') {
                if (op > 0) op += 1;
                else op += 2;
                if (inv) {
                    inv_and[iia] = iia;
                    iia++;
                    inv = false;
                }
                num_and++;
            }
            else {
                if (op == 0) {
                    if (i == 0 && espressione[i + 1] == '\0') {
                        return c;
                    }
                    corretta = false;
                    deinit();
                    return('0');
                }
                else {
                    op--;
                    if (inv) {
                        c == '0' ? c = '1' : c = '0';
                        inv = false;
                    }
                    push(c);
                }
            }
        }
    }
    iia--;
    num_and--;
    if (op != 0) {
        corretta = false;
        deinit();
        return('0');
    }

    // SB: il codice non gestisce il caso in cui l'espressione sia composta da un singolo operatore "!" 
    top(c);
    pop();
    while (!vuota()) {

        // SB: se la pila non è vuota, è impossibile che la funzione "top()" ritorni "false"
        if (!top(c1)) {
            corretta = false;
            deinit();
            return('0');
        }
        pop();
        if (!(c == '1' && c1 == '1')) {
            if (num_and == inv_and[iia]) {
                iia--;
                c = '1';
            }
            else {
                c = '0';
            }
        }
        else {
            if (num_and == inv_and[iia]) {
                iia--;
                c = '0';
            }
        }
        num_and--;
    }
    deinit();
    return(c);
}