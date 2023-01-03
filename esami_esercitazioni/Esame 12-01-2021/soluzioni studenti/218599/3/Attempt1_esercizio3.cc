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

static bool is_VorF(const char c)
{
    return (c=='T' || c=='F');
}

// SB: la funzione si poteva semplificare in " (c == 'T') ? 'F' : 'T' "
static char not_op(char c)
{   
    char ret;
    switch (c)
    {
        // SB: errore di indentazione
        case 'T':
        ret = 'F';
        break;
        case 'F':
        ret = 'T';
        break;
    }

    return ret;
}

static char or_op(char a, char b)
{
    bool b_a = (a == 'T');
    bool b_b = (b == 'T');
    
    return ((b_a | b_b) ? 'T' : 'F');
}

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta) {

    for (int i = 0; espressione[i] != 0; i++) {
        push(espressione[i]);
    }

    corretta = true;
    char a, b, op;
    while (!vuota() && corretta) {
        top(a);
        pop();
        if (vuota()) {
            if (is_VorF(a))
                corretta = true;
            else {
                corretta = false;        
            }
        }
        else { 
            if (is_VorF(a)) {
                top(b);
                pop();
                if (b == '!') {
                    push(not_op(a));
                    corretta = true;
                }
                else if (is_VorF(b)){
                    top(op);
                    pop();
                    if (op == '|') {
                        push(or_op(a, b));
                        corretta = true;
                    }

                    /* SB: il codice non considera il caso in cui l'operatore "!" si applica
                     * al secondo valore. Questo porta a dare per errate espressioni come "|!TT"
                     */

                    else{
                        corretta = false;                
                    }
                }
                else{
                    corretta = false;            
                }
            }
            else {
               corretta = false;        
            }
        }
    }

    return a;
}