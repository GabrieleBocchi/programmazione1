#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta);

int main() { 

    char v1 = '1';
    cout << (int) v1 << endl;

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
    init();
    int i = 0;
    char v1, v2, expr;
    bool ris;
    corretta = true;

    while(espressione[i] != '\0'){
        push(espressione[i]);
        i++;
    }
    
    while(!vuota() && corretta){
        top(v1);
        pop();
        if(v1 == '1' || v1 == '0'){

            /* SB: non viene controllato il valore di ritorno della funzione "top()". Di
             * conseguenza, il codice non gestisce espressioni composte da un solo valore (come "1")
             */ 
            top(v2);
            pop();

            if(v2 == '1' || v2 == '0'){
                // SB: come sopra, non viene controllato il valore di ritorno della funzione "top()"
                top(expr);
                pop();
                if(expr == '&'){
                    /* SB: il cast a booleano converte il carattere 'v1' ad intero e poi considera
                     * ogni numero diverso da 0 come "true" e 0 come "false". Dato che la rappresentazione
                     * intera (ASCII) dei caratteri '0' e '1' è, rispettivamente, 48 e 49, il risultato
                     * sarà sempre "true"
                     */
                    ris = (bool)v1 && (bool)v2;

                    /* SB: il cast a carattere converte il booleano "ris" ad intero e poi a carattere
                     * secondo la specifica ASCII (quindi i caratteri con codifica 0 e 1, che non corrispondono
                     * a '0' e '1')
                     */
                    push ((char) ris);
                }
                /* SB: manca la gestione di un caso, quello in cui l'operatore "!"
                 * viene applicato al secondo valore (per esempio, &!11)
                 */ 
                else
                    corretta = false;
            }
            else if (v2 == '!'){
                // SB: stessi commenti sulle conversioni di cui sopra
                ris = !(bool)v1;
                push ((char) ris);
            }
            // SB: il codice non accetta espressioni composte da un solo carattere (come "1")
            else
                corretta = false;
        }
        // SB: in questo modo, il codice accetta espressioni malformate come "&" e "!"
        else if(vuota())
            corretta = true;
        else
            corretta = false;
    }

    deinit();

    return v1;
}