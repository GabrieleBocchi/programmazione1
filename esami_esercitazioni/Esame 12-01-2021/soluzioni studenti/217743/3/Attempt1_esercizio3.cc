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

    // SB: meglio fare la 'deinit()' dentro alla stessa funzione dove si fa la 'init()' (no impatto sul punteggio)
    deinit();
    return 0;
}

char parseEspressioneBooleanaPrefissa(char espressione[], bool &corretta)
{
    init();

    /* SB: non viene controllata la correttezza dell'espressione booleana
     * (la variabile 'corretta' avrà sempre valore 'true')
     */
    corretta = true;
    bool b, a, res;
    char ris;
    int i = 0;
    char c, c2;

    /* SB: con questo ciclo while, si stanno sempre caricando 100 caratteri sulla pila. 
     * Tuttavia, bisogna fermarsi alla fine della espressione booleana (cioè quando si
     * raggiunge il carattere '\0'). La condizione dovrebbe essere quindi qualcosa del tipo
     * " espressione[i] != '\0' " (guardare la soluzione fornita per confronto)
     */
    while (push(espressione[i]) && i < 100)
    {
        i++;
    }

    while (top(c))
    {
        if (c == 'T')
        {
            b = true;
        }
        else if (c == 'F')
        {
            b = false;
        }

        pop();

        /* SB: il valore di ritorno della funzione 'top()' non è controllato. La variabile
         * 'c2' potrebbe essere inizializzata ad un valore random, causando un comportamento 
         * imprevedibile del codice
         */
        top(c2);
        pop();

        /* SB: essendo una espressione booleana prefissa, ci si aspettano 2 valori 
         * prima dell'operatore '&'.
         */
        if (c2 == '&')
        {

            /* SB: assumendo un secondo operatore dopo "&", si sta valutando 
             * una espressione infissa, non prefissa
             */
            top(c2);

            if (c2 == 'T')
            {
                a = true;
            }
            else if (c2 == 'F')
            {
                a = false;
            }

            res = b && a;
            if (res == true)
            {
                ris = 'T';
            }
            else
            {
                ris = 'F';
            }
        }else if (c2 == '!')
        {
            b = !b;
            
            /* SB: non è detto che ci siano altri valori, per esempio se l'espressione 
             * booleana è '!F'. Il valore di ritorno della funzione 'top(c2)' 
             * non è controllato. Il codice da qui fino a fine blocco (riga 137 dovrebbe)
             * essere cancellato.
             */
            top(c2);
            if (c2 == 'T')
            {
                a = true;
            }
            else if (c2 == 'F')
            {
                a = false;
            }

            /* SB: se " c2 == '!' ", allora non bisogna fare l'AND dei due valori
             */
            res = b && a;
            if (res == true)
            {
                ris = 'T';
            }
            else
            {
                ris = 'F';
            }
        }
    };
    return ris;
}