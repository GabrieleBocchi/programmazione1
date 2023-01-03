#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta);
void inserisci(char espressione[]);

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
    //inizializzo la pila
    init();

    /* SB: guardando il codice, credo non sia stata compresa appieno la
     * consegna. La funzione "parseEspressioneBooleanaPrefissa" deve valutare
     * l'espressione booleana e ritornare un carattere "T" o "F" corrispondente
     * alla valutazione dell'espressione. Se l'espressione dovesse essere mal
     * scritta (quindi invalutabile, per esempio come "&T"), si deve ritornare
     * questa informazione attraverso la variabile "corretta". Tuttavia, la
     * valutazione dell'espressione è una cosa distinta dalla correttezza 
     * dell'espressione.
     */

    // SB: variabile non utilizzata
    char buffer[100];
    char a ;
    inserisci(espressione);

    // SB: facendo prima "pop" e poi "top", il primo elemento della pila viene perso
    //finche non è finita la pila
    while(!pop())
    {
        // prendo il carattere
        top(a);
        switch(a)
        {
            case 'T': corretta ; break;
            case '|': corretta = corretta |corretta ; break;
            case 'F': corretta = false; break;
            case '!': corretta = !corretta; break;
            default: return false;
        }
    }

    if(corretta)
    {
        a = 'T';
    }
    else{
        a = 'F';
    }
    //deinizzializzo la pila
    deinit();
    return a;
}

void inserisci(char espressione[])
{
    int indice = 0;
    
    while(espressione[indice] != '\0')
    {
        indice++;
    }

    /* SB: la condizione di partenza giusta sarebbe "int i = indice - 1", 
     * altrimenti inserisce anche il carattere '\0' nella pila.
     * In ogni caso, la pila viene caricata al rovescio e quindi la cima
     * della pila corrisponde al primo carattere dell'espressione.
     */
     for(int i = indice; i>= 0; i--)
    {
        //inserisco gli elementi nella pila
        push(espressione[i]);
    }
   
}

