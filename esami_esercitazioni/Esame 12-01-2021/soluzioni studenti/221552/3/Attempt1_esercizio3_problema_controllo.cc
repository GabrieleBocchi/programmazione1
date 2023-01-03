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
    int len = 0;
    int i = 0, counter = 0, p_esclamativo = 0, e_commerciale = 0;
    char prev1, prev2, current, return_value = 0;
    while (espressione[i] != '\0'){
        len++;
        i++;
    }
    
    for (int j = len; j >= 0; j--){
        if (espressione[j] == '&'){
            e_commerciale++;
        }
        else if (espressione[j] == '!'){
            p_esclamativo++;
        }
        /*
        else if (espressione[j] != '1' && espressione[j] != '0' && espressione[j] != '\0' && espressione[j] != '&' && espressione[j] != '!'){
            corretta = false;
        }
        */
    }
    if (e_commerciale == 0) {
        corretta = false;
    }
    else if (corretta == true) {
        for (int j = len; j >= 0; j--){
            counter++;
            current = espressione[j];

            if ((counter+1)%3 == 0){
                prev1 = espressione[j-1];
                prev2 = espressione[j-2];
                cout << prev1 << ' ' << prev2 << endl;
                if ((prev1 != '!' && prev1 != '&' && prev2 != '!' && prev2 != '&' && current != '!' && current != '&') || (prev1 == '&') || (prev2 == '!' || prev2 == '&')){
                    corretta = false;
                }
                else{

                    if (prev1 == '!'){
                        if (prev2 == '0') prev2 = '1';
                        else if (prev2 == '1') prev2 = '0';
                    }

                    if (current == '0' || current == '1'){

                        if (espressione[j+1] == '&'){

                            if (prev1 == prev2){
                                return_value = '1';
                            }
                            else{
                                return_value = '0';
                            }
                        } 
                        else if(espressione[j+1] == '!'){

                            if (current == '0') current = '1';

                            else if (current == '1') current = '0';

                            if (espressione[j+2] == '&'){

                                if (prev1 == prev2){
                                    return_value = '1';
                                }
                                else{
                                    return_value = '0';
                                }
                            }
                        }
                        else{
                            corretta = false;
                        }
                    }
                }
            }
        }
    }
    return return_value;
}