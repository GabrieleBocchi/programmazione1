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
    char ris;
    init();
    int i = 0;
    if (false){//espressione[0] != '&' or espressione[0] != '!'){
    //    corretta = false;
    }
    else{
        while(espressione[i] != '\0' ){
            push(espressione[i]);
            i++;
        }
    }
    char operatore;
    char op1, op2;

    // SB: meglio scrivere "and" come "&&" (no impatto su punteggio)
    /* SB: la pila non sarà mai vuota, visto che viene sempre
     * sempre fatta un'operazione "push" all'interno del ciclo.
     * Questo conduce ad un ciclo infinito.
     */
    while(!vuota() and corretta == true){

        /* SB: i valori di ritorno delle chiamate alla funzione "top()" 
         * non vengono controllati. Il codice quindi non gestisce espressioni
         * formate da un carattere, per esempio "F".
         */
        top(op1);
        pop();
        top(op2);
        pop();
        top(operatore);
        
        // SB: meglio scrivere "or" come "||" (no impatto su punteggio)
        if (op2 == '!' or op2 == '&'){
            operatore = op2;
            if (operatore == '&'){
                //corretta = false;
            }
            else{
                if (op1 == '1'){
                    ris = '0';
                }
                else{
                    ris = '1';
                }
            }
            push(ris);
        }
        else{
            /* SB: la condizione contiene un assignamento "=" non una eguaglianza logica "=="
             */
            if (operatore = '!'){
                //corretta = false;
            }
            else{
                // SB: meglio scrivere "and" come "&&" (no impatto su punteggio)
                if (op1 == '1' and op2 == '1'){
                    ris = '1';
                }
                else{
                    ris = '0';
                }
            }
            push(ris);
        }
    }

    // SB: manca la deallocazione ("deinit()")

    return ris;
    // Scrivere il codice qui
}