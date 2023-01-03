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
    char res;
    init();
    
    for(int i = 0 ; espressione[i] != '\0' ; i++){
        push(espressione[i]);
    }

    char car;

    while(top(car)){
        char tmp;
        pop();

        /* SB: non viene controllato il valore di ritorno della funzione "top()". 
         * Espressioni booleane come "1" non hanno due elementi
         */
        top(tmp);
        pop();

        if (tmp == '!'){
            if (tmp == '0'){
                // SB: questa è un uguaglianza, non una assegnazione ("=")
                tmp == '1';
            }else{
                // SB: questa è un uguaglianza, non una assegnazione ("=")
                tmp = '0';
            }            
        }else{
            /* SB: essendo "tmp1" passata per riferimento, il valore in cima alla
             * pila è già stato assegnato a "tmp1". Scrivere "char tmp1=top(tmp1);"
             * fa si che "tmp1" contenga il valore di ritorno della funzione "top()",
             * non l'elemento in cima alla pila.
             */
            char tmp1=top(tmp1);
            pop();
            if (tmp1 == '|'){
                // SB: importante aggiungere delle parentesi
                if (tmp == car == 0){
                    push('0');
                }else{
                    push('1');
                }
            }
        }

        if (car == 0){
           // SB: per colpa di questa istruzione, il codice non compila. Inoltre, la funzione non potrebbe ritornare mai "F"
           res = T;
        }else{
            corretta = false;
        }
    }

    deinit();

    return res;

}