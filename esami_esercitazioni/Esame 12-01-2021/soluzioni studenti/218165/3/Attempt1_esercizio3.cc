#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta);

bool is_num(char c);
bool leggi_numero(char c);
bool is_or(char c);
bool is_not(char c);

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
    corretta = false;
    init();
    for (int i = 0; espressione[i] != '\0'; i++) {
        if (!push(espressione[i])) {
            cerr << "Espressione è troppo lunga" << endl;
        }
    }
    bool n1, n2;
    char temp;
    if (!top(temp)) {
        corretta = false;
    } else {
        pop();
        if (is_num(temp)) {
            n2 = leggi_numero(temp);
            corretta = true;
            while (top(temp) && corretta) {
                pop();
                if (is_num(temp)) {
                    n1 = leggi_numero(temp);
                    if (top(temp)) {
                        pop();
                        while (is_not(temp)) {
                            n1 = !n1;
                            top(temp);
                            pop();
                        }
                        if (is_or(temp)) {
                            n2 = n1 || n2;
                        } else {
                            corretta = false;
                        }
                    } else {
                        corretta = false;
                    }
                } else if (is_not(temp)) {
                    n2 = !n2;
                } else {
                    corretta = false;
                }
            } 
        }      
    }

    deinit();
    char res = 'F';
    if (corretta) {
        if (n2) {
            res = 'T';
        } else {
            res = 'F';
        }
    }
    return res;
}

bool is_num(char c) {
    return (c == '0' || c == '1');
}

bool leggi_numero(char c) {
    bool res;
    if (c == '1') {
        res = true;
    } else if (c == '0') {
        res = false;
    }
    return res;
}

bool is_or(char c) {
    return (c == '|');
}

bool is_not(char c) {
    return (c == '!');
}