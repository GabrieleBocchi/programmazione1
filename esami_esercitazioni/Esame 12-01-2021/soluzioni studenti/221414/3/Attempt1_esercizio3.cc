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
    init();

    int i=0;
    for (; espressione[i] != '\0'; i++) {
        push(espressione[i]);
    }
    char c1, c2;
    char c_old='a';
    while (top(c1) && corretta) {
        if ((c1 == '0' || c1 == '1') && (c_old == '0' || c_old == '1')) {
            pop();
            if (top(c2)) {
                if (c2 == '!') {
                    // SB: due istruzioni in una riga
                    if (c1 == '0') c1 = '1';
                    // SB: due istruzioni in una riga
                    else c1 = '0';
                    pop();
                    top(c2);
                }
                if (c2 == '&') {
                    // SB: due istruzioni in una riga
                    if (c1 == '1' && c_old == '1') c_old = '1';
                    // SB: due istruzioni in una riga
                    else if (c_old != '!') c_old = '0';
                    
                    /* SB: qui il codice dovrebbe mettere " c1 = 'a' ", 
                     * così poi può controllare espressioni malformate con un
                     * numero eccessivo di valori per l'operatore "!", come
                     * per esempio "!11" (veda commento riga 88)
                     */
                }
            }
            else corretta = false;
        }

        /* SB: il codice dovrebbe controllare " c1 == '1' || c1 == '0' ", 
         * altrimenti accetta espressioni malformate con all'inizio 
         * un operatore, come per esempio "!" e "11&"
         */
        // SB: due istruzioni in una riga
        else if (c_old == 'a') c_old = c1;

        else if (c1 == '!') {
            // SB: due istruzioni in una riga
            if (c_old == '0') c_old = '1';
            else c_old = '0';
        }
        /* SB: il codice dovrebbe controllare " c1 != '&' ", 
         * altrimenti accetta espressioni malformate composte da un 
         * numero insufficiente di valori, per esempio come "&1"
         */
        pop();
    }

    /* SB: qui il codice dovrebbe controllare " c1 != 'a' " e 
     * in caso contrario indicare l'espressione come malformata 
     * */

    deinit();

    return c_old;
}