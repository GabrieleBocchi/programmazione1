#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione[], bool &corretta);
void notExp(char n);

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

char parseEspressioneBooleanaPrefissa(char espressione[], bool &corretta)
{
    init();
    for (int i = 0; espressione[i] != '\0'; i++)
    {
        push(espressione[i]);
    }

    char toReturn;
    while (!vuota())
    {
        char n;
        if (top(n))
        {
            if (n == 'T' || n == 'F')
            {
                pop();

                char n2;
                if (top(n2))
                {
                    pop();
                    if (n2 == '!')
                    {
                        notExp(n);
                    }
                    else if (n2 == 'F' || n2 == 'T')
                    {
                        char n3;
                        if (top(n3))
                        {
                            if (n3 == '&')
                            {
                                pop();
                                char toPush;
                                toPush = (n == 'T' && n2 == 'T') ? 'T' : 'F';

                                push(toPush);
                            }
                            else if (n3 == '!')
                            {
                                pop();
                                notExp(n2);
                                push(n);
                            }
                            else
                            {
                                corretta = false;

                                // SB: deinit ridondante (ma non errore)
                                deinit();
                            }
                        }
                        else
                        {
                            corretta = false;

                            // SB: deinit ridondante (ma non errore)
                            deinit();
                        }
                    }
                    else
                    {
                        corretta = false;

                        // SB: deinit ridondante (ma non errore)
                        deinit();
                    }
                }
                else
                {
                    toReturn = n;
                }
            }
            else
            {
                corretta = false;

                // SB: deinit ridondante (ma non errore)
                deinit();
            }
        }
    }

    deinit();

    return (toReturn);
}

void notExp(char n)
{
    char toPush;
    if (n == 'T')
    {
        toPush = 'F';
    }
    else
    {
        toPush = 'T';
    }
    push(toPush);
}