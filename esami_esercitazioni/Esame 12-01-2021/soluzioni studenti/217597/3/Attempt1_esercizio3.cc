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


// SB: il parametro formale "corretta" non è usato
// SB: la funzione è semplificabile a " (n == '1' ? true : false)"
char n_to_b(char n, bool &corretta) {
    bool res = false;
    switch(n) {
        case '1':
            res = true;
            break;
        
        case '0':
            res = false;
            break;
    }
    return res;
}

bool lettura_dato(char espressione [], int &len, bool &corretta) {
    bool res = true;

    if(len <= 0)
        corretta = false;
    else
        // leggo il dato
        res = n_to_b(espressione[len], corretta);
    len--;

    if(corretta)
        // lettura eventuale not
        if(len > 0 && espressione[len] == '!') {
            res = !res;
            len--;
        }

    return res;
}

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta) {

    // SB: il codice non usa la pila, come invece espressamente richiesto dalla consegna

    corretta  = true;
    bool op1, op2;

    // calcolo lunghezza espressione
    int len = 0;

    // SB: errore di indentazione
    while(espressione[len++] != '\0');
    len -= 2; // posizione = ultimo carattere

    // lettura primo dato
    op2 = lettura_dato(espressione, len, corretta);

    /* SB: assumendo che sia presente un secondo dato, il codice non accetta
     * espressioni composta da un singolo valore, come per esempio "1". Inoltre,
     * il codice non valuta correttamente espressioni come "!1"
     */
    // lettura secondo dato
    if(corretta)
        op1 = lettura_dato(espressione, len, corretta);

    // lettura dati/operandi successivi
    while(len >= 0 && corretta) {
        bool recognized = false;

        // se è un operando
        if(espressione[len] == '|') {
            op1 = (op1 || op2);
            len--;
            recognized = true;
        }
        // SB: meglio scrivere "or" come "||" (no impatto su punteggio)
        // SB: "else if" (no impatto su punteggio)
        // se è un dato
        if(espressione[len] == '1' or espressione[len] == '0') {
            op1 = lettura_dato(espressione, len, corretta);
            recognized = true;
        }
        // SB: "else if" (no impatto su punteggio)
        // se è negazione
        if(corretta && espressione[len] == '!') {
            op1 = !op1;
            recognized = true;
            len--;
        } 

        // carattere non riconosciuto
        if(!recognized)
            corretta = false;
    }

    char res = 'N';
    if(corretta) {
        if(op1)
            res = '1';
        else
            res = '0';
    }

    return res;
}

