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
    for (int i = 0; espressione[i]!='\0'; i++) {
        if (!push(espressione[i])) 
            cout << "Error while pushing a value." << endl;
        
    }
    char current = '2';
    char value1 = '2', value2 = '2';
    while (!vuota() && corretta) {
        top(current); // Non mi serve controllarne il return perche' sopra controllo che non sia vuota
        pop(); // Idem qua
        if (current == '!') {
            if (value2 != '2') {
                if (value2 == '0')
                    value2 = '1';
                else
                    value2 = '0';
                if (!push(value2))
                    cout << "Error while pushing value." << endl;
                value2 = '2';  // Svuoto value2
            } else if (value1 != '2') {
                if (value1 == '0')
                    value1 = '1';
                else 
                    value1 = '0';
                if (!push(value1))
                    cout << "Error while pushing value." << endl;
                value1 = '2';  // Svuoto value1
            } else // Espressione malformata
                corretta = false;
        } else if (current == '|') {
            if (value1 == '2' || value2 == '2') {   // Espressione malformata
                corretta = false;
            }
            else if (value1 == '1' || value2 == '1') {// OR
                if (!push('1'))
                    cout << "Error while pushing value." << endl;
                value1 = '2';  // Svuoto entrambi
                value2 = '2';
            } else {
                if (!push('0'))
                    cout << "Error while pushing value." << endl;
                value1 = '2';  // Svuoto entrambi
                value2 = '2';
            }
        } else {
            if (value1 == '2')  // Controllo che value1 sia "vuoto" (cioe' assegnato a '2')
                value1 = current;
            else if (value2 == '2')
                value2 = current;
            else // Espressione malformata
                corretta = false;
        }
    }

    // SB: manca la "deinit"

    if (value2 != '2' || value1 == '2')  // Espressione malformata
        corretta = false;
    return value1;
    
}