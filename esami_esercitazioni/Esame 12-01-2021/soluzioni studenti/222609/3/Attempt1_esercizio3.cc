#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta);

int main() { 
    const int dimensioneMassima = 100;
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

bool is_bool(char n) {
    return (n == '1' || n == '0');
}

bool is_op(char n) {
    return (n == '!' || n == '|');
}

bool is_valid_operator(char n) {
    return (is_bool(n) || is_op(n));
}

bool get_bool(char n) {
    bool retval = true;
    if(!is_bool(n)) retval = false;
    if(n == '0') retval = false;

    return retval;
}

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta) {
    char retval = '-';
    int x = 0;
    char c = espressione[0];

    // SB: variabile inutilizzata
    bool current = false;
    // SB: variabile inutilizzata
    bool negate_next_exp = false;

    // inserisco tutti i caratteri
    init();
    while(c != '\0') {
        if(is_valid_operator(c))
            push(c);
        c = espressione[x];
        x++;
    }

    char n1 = 'n',
        n2 = 'n',
        op = 'n';
    while(!vuota()) {

        // SB: il codice deve controllare che il primo valore della pila sia "1" oppure "0"
        if(n1 == 'n') {
            top(n1);
            pop(); // prendo il primo operatore
        } else if(n2 == 'n') {

            /* SB: il codice non controlla il valore di ritorno della funzione "top()".
             * Questo significa che il codice non identifica come malformate espressioni come "!"
             */
            top(n2);
            pop(); // prendo il secondo operatore
            // se incontro ! è operazione unaria
            if(is_op(n2) && n2 == '!') {
                // prendo il primo operatore e lo inverto
                bool n1b = get_bool(n1);

                // poi inserisco il nuovo risultato
                if(n1b)
                    push('0');
                else
                    push('1');
                
                // resetto le condizioni
                n1 = 'n';
                n2 = 'n';
                op = 'n';
            }
            /* SB: aggiungere condizione "else" per indicare che l'espressione è malformata
             * (per esempio, l'espressione "|1" non viene indicata come malformata)
             */

        } else if(op == 'n') {
            /* SB: il codice non controlla il valore di ritorno della funzione "top()".
             * Questo significa che il codice non identifica come malformate espressioni come "11"
             */
            top(op);
            pop();
        } else if(is_bool(n1) && is_bool(n2) && is_op(op) && op == '|') {
            // caso base di operazione OR
            bool n1b = get_bool(n1);
            bool n2b = get_bool(n2);
            if(n1b || n2b)
                push('1');
            else
                push('0');
            
            n1 = 'n';
            n2 = 'n';
            op = 'n';
            // OR !
        } else if(is_bool(n1) && is_bool(n2) && is_op(op) && op == '!') {
            // se incontro ! dopo aver già trovato due boolean
            // (esempio: |!10)
            // prima inverto, reinserisco i dati e ricomincio
            bool n1b = get_bool(n1);
            bool n2b = get_bool(n2);
            push(n2b ? '0' : '1'); // espressione negata
            push(n1b ? '1' : '0');

            // reset
            n1 = 'n';
            n2 = 'n';
            op = 'n';
        } else if(is_bool(n1) && n2 == '|') {
            cerr << "Espressione malformata" << endl;
            exit(0);
        } else {
            cerr << "Errore" << endl;
            exit(1);
        }
    }

    // SB: manca la "deinit()"

    // l'ultimo top sarà effettuato su n1
    // in formato 0/1 come da traccia
    // lo copio in retval e lo restituisco
    retval = n1;
    return retval;
}