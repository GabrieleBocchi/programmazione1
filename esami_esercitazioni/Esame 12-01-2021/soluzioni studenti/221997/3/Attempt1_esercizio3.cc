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
    int i = 0;
    char buffer1, buffer2, operatore, risultato, test;
    bool finito = false;
    while(espressione[i] != '\0'){
        push(espressione[i]);
        i++;
    }


    while(finito == false && corretta == true){
        if(top(buffer1) == 'T' || top(buffer1) == 'F'){
            top(buffer1);
            pop();
            if(top(buffer2) == 'T' || top(buffer2) == 'F'){

                top(buffer2);
                pop();
                if(top(operatore) == '!'){
                    pop();
                    if(buffer2 == 'T'){
                        push('F');
                    }
                    else push('T');
                    push(buffer1);
                }
                else if(top(operatore) == '|'){
                    pop();
                    if(buffer1 == 'F' && buffer2 == 'F'){
                        push('F');
                    }
                    else push('T');
                }
                else{
                    corretta = false;
                } 
            }
            else if(top(operatore) == '!'){
                pop();
                if(buffer1 == 'T'){
                    push('F');
                }
                else push('T');
            }
            else{
                corretta = false;        
            }


        }
        else if(top(test) == false){
            finito = true;
        }
        else{
            corretta = false;
        }    
    }
    
    top(risultato);
    deinit();


    return risultato;
}