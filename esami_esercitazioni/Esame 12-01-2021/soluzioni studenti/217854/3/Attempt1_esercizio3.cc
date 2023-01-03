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
    char res = ' ';
    init();

    /* SB: l'espressione booleana non viene caricata nella pila prima di essere valutata.
     * In pratica, il codice parse espressioni booleane post-fisse, non pre-fisse
     */

    int i = 0;
    while(espressione[i] != '\0') {

        /* SB: le varie condizioni dovrebbero essere congiunte da "&&", non da "||". 
         * Altrimenti, l'espressione risulta sempre falsa.
         */
        if(espressione[i] != 'T' || espressione[i] != 'F' || espressione[i] != '&' || espressione[i] != '!') {
            corretta = false;

            /* SB: piuttosto di avere return multipli, si poteva aggiungere "&& corretta" alla condizione
             * del ciclo while (no impatto sul punteggio)
             */
            return res;
        }
        else {
            if(espressione[i] == 'T' || espressione[i] == 'F') {
                push(espressione[i]);
            }
            if(espressione[i] == '!') {
                char c;
                top(c);
                pop();
                if(c == 'T')
                    push('F');
                else if(c == 'F')
                    push('T');
                else {
                    corretta = false;
                    return res;
                }
            }
            if(espressione[i] == '&') {
                char c1, c2;

                /* SB: il risultato delle funzioni 'pop' non viene controllato per verificare che vi siano
                 * abbastanza elementi nella pila
                 */
                top(c1);
                pop();
                top(c2);
                pop();

                /* SB: per come sono scritti le condizioni sottostanti, un'espressione 
                 * come "&F" viene valuata a "F", quando dovrebbe invece essere malformata
                 */
                if (c1 == 'T' && c2 == 'T')
                    push('T');
                else if (c1 == 'F' || c2 == 'F')
                    push('F');
                else {
                    corretta = false;
                    return res;
                }
            }
        }
        i++;
    }
    
    top(res);
    deinit();

    return res;
}