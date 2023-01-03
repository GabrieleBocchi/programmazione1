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

    // SB: il codice non compila

    index = 0;
    char risultato;
    stack s;
    init(s);
    char operando;
    char operando2;

    while(espressione[index] != '\0'){
        
        if((espressione[index] >= '0' && espressione[index] <= '1')){
            push(s, espressione[index]);
            index++;
        }

        else if(espressione[index] == '!'){
            bool esiste = top(operando);
            if(!esiste){
                corretta = false;
            }else{
                pop(s);
                (operando == '1' ? push(s, '0'): push(s, '1'));
            }
        }
        else if(espressione[index] == '|'){
            bool esiste1 = top(operando);
            pop(s);
            bool esiste2 = top(operando2);
            if(!esiste1 && !esiste2){
                corretta = false;
            }else{
                pop(s);
                if(operando1 == '1' || operando2 == '1'){
                    push(s, '1');
                }else{
                    push(s, '0');
                }
            }
        }

    }

    return risultato;
}