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
                if (primoValore == '0') {
                    push('1');
                }
                else if (primoValore == '1') {
                    push('0');
                }
                else {
                    corretta = false;
                }
            }
            else if (top(operatore)) {
                pop();

                if (operatore == '|') {
                    if (primoValore == '1' && secondoValore == '1') {
                        push('1');
                    }
                    else if (primoValore == '1' && secondoValore == '0') {
                        push('1');
                    }
                    else if (primoValore == '0' && secondoValore == '1') {
                        push('1');
                    }
                    else if (primoValore == '0' && secondoValore == '0') {
                        push('0');
                    }
                    else {
                        corretta = false;
                    }
                }
                else if (operatore == '!') {
                    if (secondoValore == '0') {
                        push('1');
                        push(primoValore);
                    }
                    else if (secondoValore == '1') {
                        push('0');
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

    if (primoValore != '0' && primoValore != '1') {
        corretta = false;
    }

    deinit();

    return primoValore;
}