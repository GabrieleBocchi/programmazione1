#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione[], bool &corretta);

int main()
{

    int dimensioneMassima = 100;
    char espressioneBooleana[dimensioneMassima];
    bool corretta = true;
    char risultatoEspressione;

    cout << "Inserisci l'espressione: ";
    cin >> espressioneBooleana;

    risultatoEspressione = parseEspressioneBooleanaPrefissa(espressioneBooleana, corretta);

    if (corretta)
    {
        cout << "Risultato: " << risultatoEspressione << endl;
    }
    else
    {
        cout << "Espressione malformata" << endl;
    }

    return 0;
}

// SB: suggerisco un nome più descrittivo per questa funzione
char c(bool b)
{
    if(b)
        return 'T';
    else
        return 'F';
}

char parseEspressioneBooleanaPrefissa(char espressione[], bool &corretta)
{
    // Scrivere il codice qui
    init();

    for (int i = 0; espressione[i] != '\0'; i++)
    {
        if (espressione[i] == 'T' || espressione[i] == 'F' || espressione[i] == '|' || espressione[i] == '!')
            push(espressione[i]);
        else
            cout << "Ho ignorato il carattere non valido '" << espressione[i] << "'" << endl;
    }

    bool args[2];
    int nArg = 0;
    char a;
    bool errore = false;

    while (top(a) && !errore)
    {
        pop();

        if (a == 'T' || a == 'F')
        {
            if (nArg < 2)
            {
                // SB: suggerisco di rendere esplicita la precedenza (cioè incrementare nArg dopo l'assegnazione)
                args[nArg++] = a == 'T';
            }
            else
            {
                cout << "Mancano operatori. " << endl;
                errore = true;
            }
        }
        else
        {
            if (a == '|')
            {
                if (nArg == 2)
                {
                    args[0] = (args[0] || args[1]);
                    nArg = 1;
                }
                else
                {
                    cout << "Non ci sono argomenti per eseguire OR. " << endl;
                    errore = true;
                }
            }
            else //if(a == '!')
            {
                if(0 < nArg && nArg < 3)
                {
                    args[nArg-1] = (!args[nArg-1]);
                }
                else
                {
                    cout << "Argomenti errati per eseguire NOT. " << endl;
                    errore = true;
                }
            }
        }
    }

    corretta = !errore;
    deinit();

    if(args[0])
        return 'T';
    else
        return 'F';
        
}