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

bool isoperand (char c)
{
    return (c == '0' || c == '1');
}

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta) {
    
    // SB: il codice non compila

    char buffer;
    char b1, b2;
    int op;
    init ();
    for (int i=0; corretta && espressione[i] != '\0'; i++)
    {
        switch (espressione[i])
        {
            case '0': break;
            case '1': break;
            case '|': break;
            case '!': break;
            default: corretta = false;
        }
        
        if (corretta)
        {
            do
            {
                op = 0;
                top (buffer);
                if (isoperand(buffer))
                {
                    b1 = buffer;
                    op++;
                }
                else
                {
                    corretta = false;
                }

                if (!pop())
                {
                    break;
                }
                top (buffer);
                if (isoperand(buffer))
                {
                    b2 = buffer
                }

                else
                {
                    if (buffer == '!')
                    push (b1 == '0' ? '1' : '0');
                    continue;
                }

                top (buffer);
                if (isoperand(buffer))
                {
                    corretta = false;
                }

                else
                {
                    if (buffer == '|')
                    {
                        push (b1 == '0' || b2 == '1' ? '1' : '0')
                    }
                }
                pop();

            } while (pop())
        }
    }
}