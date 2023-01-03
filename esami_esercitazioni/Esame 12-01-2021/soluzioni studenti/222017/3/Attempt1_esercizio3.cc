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
    // Scrivere il codice qui
    init();

    for (int i = 0; espressione[i] != '\0'; i++){
        push(espressione[i]);
    }

    char v, res;
    int out;
    while(!vuota()){
        if (top(v) == '|'){

        } else if(top(v) == '!'){
            
        }else{
            corretta = false; 
        }
    }
    deinit();

    // SB: esercizio non implementato

    return res;
}