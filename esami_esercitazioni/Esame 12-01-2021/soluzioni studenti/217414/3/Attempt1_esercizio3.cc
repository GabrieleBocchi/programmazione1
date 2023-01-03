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

char parseEspressioneBooleanaPrefissa(char espressione[], bool &corretta)
{
    // Scrivere il codice qui
    init();
    char c, resc = 'F';
    bool ceck = false;
    bool res1, res2;
    for (int i = 0; espressione[i] != '\0'; i++)
    {
        push(espressione[i]);
    }
    if (top(c))
    {
        if (c == '0' || c == '1')
        {
            /* SB: il cast a booleano converte il carattere 'c' ad intero e poi considera
             * ogni numero diverso da 0 come "true" e 0 come "false". Dato che la rappresentazione
             * intera (ASCII) dei caratteri '0' e '1' è, rispettivamente, 48 e 49, il risultato
             * sarà sempre "true"
             */
            res1 = (bool)c;
            pop();
            while (top(c) && corretta)
            {
                pop();

                /* SB: l'ordine di valutazione delle singole condizioni non è lineare da sinistra a destra. 
                 * Questo vuol dire che la seconda condizione "top(c)" potrebbe essere valutata prima (o dopo) di 
                 * "c == '!'"
                 */
                /* SB: richiedendo un ulteriore valore dalla pila, il codice segnala come malformate espressioni
                 * che in realtà sono ben formate, per esempio "!1"
                 */
                if(c == '!' && top(c))
                {
                    pop();
                    if(c == '0')
                    {
                        res1 = 1;
                        ceck = true;
                    }
                    else if(c == '1')
                    {
                        res1 = 0;
                        ceck = true;
                    }
                }
                /* SB: aggiungere "&& ceck" alla condizione obbliga ad avere prima una negazione
                 * e poi un OR logico. Il codice non riesce a valutare espressioni senza l'operatore
                 * NOT, per esempio "|11"
                 */
                else if(c == '|' && ceck)
                {
                    res1 = res1 || res2;
                }
                else if(c == '0')
                {
                    res2 = false;
                }
                else if(c == '1')
                {
                    res2 = true;
                }
                else
                {
                    corretta = false;
                }
            }
            if(res1)
            {
                resc = 'T';
            }
        }
        else
        {
            corretta = false;
        }
    }
    else
    {
        corretta = false;
    }

    // SB: manca la "deinit()"

    return resc;
}