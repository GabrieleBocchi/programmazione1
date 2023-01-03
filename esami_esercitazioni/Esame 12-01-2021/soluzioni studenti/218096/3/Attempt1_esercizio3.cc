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
    
    init();
    char res;

    for(int i=0; espressione[i] != '\0'; i++){
        push(espressione[i]);
    }


    corretta = true;
    bool fine = false;
    while(!vuota() && corretta && !fine){
        char operando1, operando2, operatore;

        /* SB: l'ordine di valutazione delle singole condizioni non è lineare da sinistra a destra. 
         * Questo vuol dire che la seconda condizione "pop()" potrebbe essere valutata prima di 
         * "top(operando1)", compromettendo la valutazione dell'espressione.
         */
        if(top(operando1) && pop()){
            switch(operando1){
                case '1':
                case '0':
                    /* SB: l'ordine di valutazione delle singole condizioni non è lineare da sinistra a destra. 
                     * Questo vuol dire che la seconda condizione "pop()" potrebbe essere valutata prima di 
                     * "top(operando2)", compromettendo la valutazione dell'espressione.
                     */
                    if(top(operando2) && pop()){
                        switch(operando2){
                            case '1':
                            case '0':
                                /* SB: l'ordine di valutazione delle singole condizioni non è lineare da sinistra a destra. 
                                 * Questo vuol dire che la seconda condizione "pop()" potrebbe essere valutata prima di 
                                 * "top(operatore)", compromettendo la valutazione dell'espressione.
                                 */
                                if(top(operatore) && pop()){
                                    if(operatore == '|'){
                                        if(operando1 == '1' || operando2 == '1')
                                            push('1');
                                        else
                                            push('0');
                                    }
                                    /* SB: il codice non considera il caso in cui l'operatore "!" si
                                     * applica al secondo valore, come per esempio in "|!10". Bisognerebbe
                                     * aggiungere un " else if (operatore == '!') "
                                     */
                                    else{
                                        corretta = false;
                                    }
                                }else{
                                    corretta = false;
                                }
                                break;

                            
                            case '!':
                                if(operando1 == '1')
                                    push('0');
                                else
                                    push('1');
                                break;


                            /* SB: manca " case '|': " per controllare espressioni malformate con
                             * un numero di valori insufficiente per l'operatore "|", come per
                             * esempio l'espressione "|1"
                             */
                        }
                    }
                    /* SB: Il codice non gestisce espressioni formate da un solo
                     * valore, come per esempio "1"
                     */

                    break;
                
                default:
                    corretta = false;
                    break;
            }

            if(corretta && top(res)){         // controllo se ho un solo elemento
                pop();
                if(vuota())
                    fine = true;
                else{
                    push(res);
                }
            }
        }

    }

    deinit();


    if(corretta && (res == '1' || res == '0')){
        if(res == '1')
            return 'T';
        else
            return 'F';
    }else{
        corretta = false;
        return 'F';
    }

}