#include "pila.h"
#include <iostream>

using namespace std;

int stringLength(const char *str);
char parseEspressioneBooleanaPrefissa(char espressione[], bool &corretta);

int main() {

    const int dimensioneMassima = 100;
    char espressioneBooleana[dimensioneMassima];
    bool corretta = true;
    char risultatoEspressione;

    cout << "Inserisci l'espressione: ";
    cin >> espressioneBooleana;

    risultatoEspressione = parseEspressioneBooleanaPrefissa(espressioneBooleana, corretta);

    if (corretta) {
        cout << "Risultato: " << risultatoEspressione << endl;
    } else {
        cout << "Espressione malformata" << endl;
    }

    return 0;
}

int stringLength(const char *str) {
    int length = 0;
    while (*str++ != '\0') {
        length++;
    }
    return length;
}

char parseEspressioneBooleanaPrefissa(char espressione[], bool &corretta) {
    char c1, c2;
    init();
    corretta = true;

    for (int i = stringLength(espressione) - 1; corretta && i >= 0; i--) {
        const char current = espressione[i];

        switch (current) {
        case 'T':
        case 't':
            push('T');
            break;
        case 'F':
        case 'f':
            push('F');
            break;
        case '|':

            /* SB: in C++, l'ordine della valutazione delle condizioni non è specificata. Questo vuol dire
             * che è possibile che vengano prima eseguite le chiamate a "pop()" e poi le "top()", compromettendo
             * così la valutazione dell'espressione booleana
             */
            if (top(c1) && pop() && top(c2) && pop()) {
                push((c1 == 'T' || c2 == 'T') ? 'T' : 'F');
            } else {
                corretta = false;
            }
            break;
        case '!':

            /* SB: in C++, l'ordine della valutazione delle condizioni non è specificata. Questo vuol dire
             * che è possibile che venga prima eseguita la chiamata a "pop()" e poi la "top()", compromettendo
             * così la valutazione dell'espressione booleana
             */
            if (top(c1) && pop()) {
                push(!(c1 == 'T') ? 'T' : 'F');
            } else {
                corretta = false;
            }
            break;
        default:
            corretta = false;
        }
    }

    /* SB: in C++, l'ordine della valutazione delle condizioni non è specificata. Questo vuol dire
     * che è possibile che venga prima eseguita la chiamata a "pop()" e poi la "top()", compromettendo
     * così la valutazione dell'espressione booleana
     */
    corretta = corretta && top(c1) && pop() && vuota();
    deinit();
    return c1;
}