#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta);
bool is_op(char c);
char es_and(char c1, char c2);
char es_not(char c1);

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
    char op1, op2, op3;
    bool res;
    if(top(op1)) {
        res = pop();
        if(top(op2) && !is_op(op2)) {

        } else {
            op1 = es_not(op1);
        }
    }
}

bool is_op(char c) {
  return ((c == 'T' || c == 'F') ? true : false);
}

char es_and(char c1, char c2) {
    return ((c1 == 'T' && c2 == 'T') ? 'T' : 'F');
}

char es_not(char c1) {
    return ((c1 == 'T') ? 'F' : 'T');
}