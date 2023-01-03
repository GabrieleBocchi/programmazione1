#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta);
void NOT(char& tmp);
char AND(char tmp, char tmp2);
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
    
    // SB: manca la "init()"

    int indice=0;
    
    while(espressione[indice]!='\0'){
        
        indice++;
    }
    indice--;
    
    if(espressione[indice]=='0' || espressione[indice]=='1'){
        
        push(espressione[indice]);
        
        indice--;
        char tmp;
        
        bool esegu=false;
        int numeri=1;
        while(indice>=0 && corretta){
            
            if(espressione[indice]=='!'){
                
                top(tmp);
                NOT(tmp);
                pop();
                push(tmp);
                
            }else if(!esegu && espressione[indice]=='&'){
                
                corretta=false;
                
            }else if(espressione[indice]=='0' || espressione[indice]=='1'){
                
                push(espressione[indice]);
                numeri++;
                
                if(numeri==2){
                    esegu=true;
                }
            }else if(esegu && espressione[indice]=='&'){
                
                char tmp2;
                top(tmp);
                pop();
                top(tmp2);
                push(AND(tmp,tmp2));
                numeri=1;
            }
            indice--;
            if(numeri>2 && indice<0){
                corretta=false;
            }
            
        }
        
    }else{
        corretta=false;
    }
    char ris;
    top(ris);

    // SB: manca la "deinit()"

    return ris;
}



void NOT(char& tmp){
    
    if(tmp=='0'){
        tmp='1';
    }else{
        tmp='0';
    }
    
}

char AND(char tmp, char tmp2){
    
    if(tmp=='1' && tmp2=='1'){
        return '1';
    }else{
        return '0';
    }
    
}
