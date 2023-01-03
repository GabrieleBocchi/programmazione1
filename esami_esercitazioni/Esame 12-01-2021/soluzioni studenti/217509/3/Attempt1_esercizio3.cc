#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta);

bool readOperator(int& op, char c); 

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
    while(espressione[indice] != '\0'){
        push(espressione[indice]); 
        indice += 1; 
    }
    
    int op1 = 0, op2 = 0;  
    corretta = true; 
    char carattereCorrente; 
    while(top(carattereCorrente) && corretta){
        if(op1 == 0){
            corretta = readOperator(op1, carattereCorrente); 
        }

        /*
         * SB: l'operatore '!' verrà sempre applicato a 'op1' e non verrà mai applicato a 'op2'.
         * Di consequenza, espressioni che applicano l'operatore '!' a 'op2' (come per esempio '&!FT') 
         * risulteranno erroneamente valutate. Bisognerebbe controllare che l'operatore 'op2' sia = 0
         * (veda esempio sotto).
         * 
         * else if(carattereCorrente == '!'){
         *   if (op2 == 0)
         *      op1 *= -1;  
         *   else 
         *      op2 *= -1; 
         * }
         * 
         */
        else if(carattereCorrente == '!'){
            op1 *= -1;  
        }
        else if(op2 == 0){
            corretta = readOperator(op2, carattereCorrente); 
        }
        else if(carattereCorrente == '&'){
            
            /*
             * SB: la condizione dovrebbe essere "op1 == 1 && op2 == 1", 
             * altrimenti espressioni come "&TT" sono erroneamente valutate in "F" 
             */
            if(op1 > 1 && op2 > 1) 
            
                op1 = 1; 
            else 
                op1 = -1; 
            op2 = 0;  
        }
        else{
            corretta = false; 
        }
        pop(); 
    }
    deinit(); 
    return (op1 == 1) ? 'T' : 'F'; 
}

bool readOperator(int& op, char c){
    bool ret = true; 
    switch(c){
        case 'T': 
            op = 1; 
        // SB: indentazione del 'break' (no impatto sul punteggio)
        break; 
        case 'F': 
            op = -1; 
            break; 
        default: 
            ret = false; 
    }
    
    return ret; 
}