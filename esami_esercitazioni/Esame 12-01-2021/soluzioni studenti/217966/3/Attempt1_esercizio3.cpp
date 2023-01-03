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
    int i=0;
    char c1,c2,c3;
    
    while(espressione[i]!='\n'){    //Riempio stack

        push(espressione[i]);
        i++;

    }

    //do{

        top(c1);
        cout <<c1;
        if(c1=='!' || c1=='|'){
            corretta == false;
            return 0;
        }

    //}while(i!=0);


    // SB: esercizio non implementato

}