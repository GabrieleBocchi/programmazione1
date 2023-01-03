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
    int i = 0;

    while (espressione[i] != '\0') {

        push(espressione[i]);
    }

    if (vuota()) {

        corretta = false;
        return ' ';
    }

    char carattere;
    top(carattere);
    pop();
    while (!vuota()) {

        char operazione[2];
        int i = 0;
        
        while (carattere != '!' || carattere != '|') {

            operazione[i] = carattere; 
            i++;
            pop();
        }
        pop();
        char risultato;

        if (carattere == '!') {
        
            if (operazione[0] == 'T') {

                risultato = 'F';
            }
            else {

                risultato = 'T';
            }
        }
        else if (carattere == '/') {

            if (operazione[0] == 'F' && operazione[1] == 'F') {
                risultato = 'F';
            }
            else {
                risultato = 'T';
            }   
        }
        pop();
        push(risultato);
        }
        return carattere;
    }