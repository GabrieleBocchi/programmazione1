#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta);

int main()
{

    int dimensioneMassima = 100;
    char espressioneBooleana [dimensioneMassima];
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


char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta)
{

    init();

    // SB: variabile non usata
    bool ritorno = true;
    // SB: variabile non usata
    char prova;
    char piccolaEspressione[3];
    bool esci = false;

    for(int i=0; espressione[i] != '\0'; i++)
    {
        push(espressione[i]);
    }

    while(!vuota())
    {
        esci = true;
        int i=0;

        /* SB: questo codice non identifica espressioni malformate composta da
         * soli operatori (per esempio "!!"). 
         * 
         * SB: questo codice segnala come malformate espressioni (che in realtà
         * sono ben formate) composte da un solo valore (per esempio "0"). Il
         * motivo è che non viene controllato il valore di ritorno della funzione "top()"
         * per assicurarsi che vi siano ancora elementi nella pila.
         */
        for(i=0; esci; i++)
        {
            top(piccolaEspressione[i]);
            pop();

            // SB: due istruzioni sulla stessa linea
            if(piccolaEspressione[i] != '1' && piccolaEspressione[i] != '0') esci = false;
        }

        /* SB: il codice seguente è molto disordinato. Suggerisco di usare delle parentesi
         * graffe per racchiuedere lo scope delle istruzioni condizioniali, specialmente
         * quando non ovvio. C++ non è Python dove basta l'indentazione per ordinare il codice
         */

        // SB: perché non unire questa condizione con quella sotto tramite "&&"?
        if(i == 2)
            // SB: due istruzioni sulla stessa linea
            if(piccolaEspressione[1] != '!') corretta = false;
        // SB: perché non unire questa condizione con quella sotto tramite "&&"?
        // SB: "else if"
        if(i == 3)
            /* SB: questo codice segnala come malformate espressioni (che in realtà
             * sono ben formate) che negano il secondo valore (per esempio "&!11"). 
             * Bisognerebbe aggiungere un altro "if" per controllare questa evenienza 
             * ed implementare la corretta logica di seguito.
             */
            // SB: due istruzioni sulla stessa linea
            if(piccolaEspressione[2] != '&') corretta = false;
        
        
        if(piccolaEspressione[1] == '!')
            // SB: due istruzioni sulla stessa linea
            if(piccolaEspressione[0] == '0') push('1');
            // SB: due istruzioni sulla stessa linea
            else push('0');
        
        else if(piccolaEspressione[2] == '&')
            /* SB: questo codice non valuta correttamente espressioni come "&00". La condizione
             * dell'if doveva essere "(piccolaEspressione[0] == 1 && piccolaEspressione[1] == 1)"
             */
            if(piccolaEspressione[0] == piccolaEspressione[1])
                push('1');
            // SB: due istruzioni sulla stessa linea
            else push('0');

        top(piccolaEspressione[0]);
        pop();
        if(vuota()){
            deinit();
            if(piccolaEspressione[0] == '1')
                return '1';
            // SB: due istruzioni sulla stessa linea
            else return '0';
        }
        // SB: due istruzioni sulla stessa linea
        else push(piccolaEspressione[0]);
    }
}

