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
    int index = 0;

    // SB: l'indice "index" non viene incrementato, portando ad un ciclo infinito
    while(espressione[index] != '\0'){
        push(espressione[index]);
    }

    // SB: servono almeno due variabili per valutare l'espressione booleana
    // in caso l'operatore sia "&"
    char c;
    bool reverse = false;
    while(!vuota()){
        top(c);
        if (c == '1'){
            if(!reverse){
                corretta = true;
            } else {
                corretta = false;
            }
        } else if(c == '0') {
            if(!reverse){
                corretta = false;
            } else {
                corretta = true;
            }
        } else if (c == '&') {

            // SB: l'operatore "&" non è implementato
            reverse = false;
        } else if (c == '!') {

            // SB: l'operatore "!" non è implementato
            reverse = true;
        }
        pop();
    }
    deinit();
    return *espressione;
}