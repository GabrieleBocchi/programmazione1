#include <iostream>

#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione[], bool& corretta);

int main() {
    int dimensioneMassima = 100;
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

char parseEspressioneBooleanaPrefissa(char espressione[], bool& corretta) {
    // Scrivere il codice qui

    bool risultato = true;
    //porto l'indice i alla fine dell'array
    int i = 0;
    while (espressione[i] != '\0')
        i++;

    //ora i = dimensione dell'array, quindi lo decremeno per poter leggere le celle dell'array
    i--;
    //inizializzo la pila
    init();

    //continuo a ciclare fino a quando termino le operazioni o incontro un errore
    while (i >= 0 && corretta) {

        //se trovo 1 o 0, inserisco il valore nella pila
        if (espressione[i] == '1' || espressione[i] == '0') {
            push(espressione[i]);
        }

        //se trovo ! controllo che la pila non sia vuota, e nego il valore in cima alla pila
        if (espressione[i] == '!') {
            if (vuota()) {
                corretta = false;
            } else {
                //estraggo il valore dalla pila
                char valore;
                top(valore);
                pop();

                //lo nego
                int valoreNegato = 1 - (valore - '0');
                //inserisco il valore negato
                push(valoreNegato + '0');

                /* SB: il codice non gestisce espressioni in cui l'ultimo operatore
                 * ad essere valutato è l'operatore "|", in quanto la variabile "risultato" 
                 * non viene aggiornata (bisogna aggiungere come istruzione 
                 * " risultato = ( valore == '0' ) ? true : false; " 
                 * )
                 * Per esempio, l'espressione "!1" viene erroneamente valutata a "1"
                 */
                
            }
        }

        //se trovo | controllo che la pila abbia almeno due elementi, e effettuo l'operazione or tra i due elementi
        if (espressione[i] == '|') {
            if (vuota()) {
                corretta = false;
            } else {
                //estraggo il primo valore
                char valore1;
                top(valore1);
                pop();

                if (vuota()) {
                    corretta = false;
                } else {

                    //estraggo il primo valore
                    char valore2;
                    top(valore2);
                    pop();

                    //faccio valore1 OR valore2 e segno il risultato
                    if (valore1 == '1' || valore2 == '1') {
                        risultato = true && risultato;
                        push('1');
                    } else {
                        risultato = false && risultato;
                        push('0');
                    }
                }
            }
        }

        i--;
    }

    deinit();

    return (risultato) ? '1' : '0';
}