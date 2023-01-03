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

    int indice = 0;
    char carattereCorrente = espressione[indice];
    while (carattereCorrente != '\0') { 
        push(carattereCorrente);
        indice++;
        carattereCorrente = espressione[indice];
    }

    char primoValore;
    char secondoValore;
    char operatore;

    while (!vuota() && corretta) {

        top(primoValore);
        pop();
        if (top(secondoValore)) {
            pop();
            if (secondoValore == '!') {
                if (primoValore == 'F') {
                    push('T');
                }
                else if (primoValore == 'T') {
                    push('F');
                }
                else {
                    corretta = false;
                }
            }
            else if (top(operatore)) {
                pop();

                if (operatore == '|') {
                    if (primoValore == 'T' && secondoValore == 'T') {
                        push('T');
                    }
                    else if (primoValore == 'T' && secondoValore == 'F') {
                        push('T');
                    }
                    else if (primoValore == 'F' && secondoValore == 'T') {
                        push('T');
                    }
                    else if (primoValore == 'F' && secondoValore == 'F') {
                        push('F');
                    }
                    else {
                        corretta = false;
                    }
                }
                else if (operatore == '!') {
                    if (secondoValore == 'F') {
                        push('T');
                        push(primoValore);
                    }
                    else if (secondoValore == 'T') {
                        push('F');
                        push(primoValore);
                    }
                    else {
                        corretta = false;
                    }
                }
                else {
                    corretta = false;
                }
            }
            else {
                corretta = false;
            }
        }
    }

    if (primoValore != 'T' && primoValore != 'F') {
        corretta = false;
    }

    deinit();

    return primoValore;
}