#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta);
char valuta( char, char);
bool controllo(char[]);
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
    char tmp='1';

    // SB: variabile non utilizzata
    lista pila;

    init();
    for(int i=0; espressione[i]!='\0';i++){
        push(espressione[i]);

    } 

    corretta=controllo(espressione);
    char a;
    if(corretta){
        while(!vuota())tmp=valuta(tmp, top(a));
    }
    deinit();
    return tmp;
}

char valuta(char a, char b){
    // SB: manca la chiamata alla funzione "pop()"" per rimuovere i valori dalla pila. Questo conduce ad un ciclo infinito

    if(b=='&')return a;
    else if(b=='!'){
        if(a=='0')return '1';
        else return '0';
    }
    else{
        // SB: la conversione da carattere ad intero segue la codifica ASCII. Questo vuole
        // dire che il carattere '0' è convertito nell'intero 48, mentre '1' in 49
        if(int(a)+int(b)==2)return '1';
        else return '0';
    }
}

bool controllo(char espressione[]){
    // SB: meglio scrivere "and" come "&&" e "or" come "||" (no impatto su punteggio)
    bool flag=true;
    // SB: il codice non tiene conto che l'espressione può iniziare pure con l'operatore "!" oppure essere un singolo valore "1" o "0"
    if(espressione[0]!='&')flag=false;
    int i=0;
    for(; espressione[i]!='\0' and flag;i++){
        // SB: accesso ad area di memoria fuori dal limite dell'array ("espressione[i-1]")
        if(espressione[i]=='&' and ((espressione[i-1]=='!' or espressione[i-1]=='&') or (espressione[i+1]=='&')))flag=false;
        else if((espressione[i]=='1' or espressione[i]=='0')and(espressione[i-1]=='1' or espressione[i-1]=='0')and(espressione[i+1]=='1' or espressione[i+1]=='0'))flag=false;
    }
    if(espressione[i]=='&')flag=false;
    return flag;
}