#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta);
bool operazione(bool & corretta);
bool traduttore(char valore);
bool operatore_bool(bool va1,bool val2);

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
    int i=0;
    bool output;
    init();
    while(espressione[i]!='\0'){
        push(espressione[i]);
        i++;
    }
    output=operazione(corretta);
    deinit();
    return (output)?'T':'F';
}

/* SB: questa funzione non è stata dichiarata insieme alle altre (no impatto sul punteggio).
 * Inoltre, molto del codice di "operazione2" è duplicato rispetto alla funzione "operazione"
 */
bool operazione2(bool & corretta){
    char param1,operatore;
    bool successo=true;
    bool risultato_operazione;
    successo=top(param1);
    pop();
    successo=top(operatore);
    pop();
    if(successo){
        if(param1!='T' && param1!='F'){
            corretta=false;
        }if(operatore=='!'){
            successo=top(operatore);
            pop();
            if(param1=='T'){
                param1='F';
            }else{
                param1='T';
            }
        }
        successo=top(operatore);
        pop();
        char tmp;
        if(top(tmp)){

            /* SB: al posto della ricorsione, più semplicemente bastava un ciclo 'while' che
             * come condizione controllata se la pila fosse vuota oppure no.
             */
            risultato_operazione=operatore_bool(traduttore(param1),operazione2(corretta));
        }else{
            risultato_operazione=traduttore(param1);
        }
    }else{
        corretta=false;
        risultato_operazione=false;
    }
    return risultato_operazione;
}

bool operazione(bool & corretta){
    corretta=true;
    char param1,param2,operatore;
    bool successo=true;

    /* SB: il valore assegnato alla variabile 'successo' non è controllato. Per questo motivo,
     * espressioni booleane composta da un singolo valore non sono valutate correttamente
     */
    successo=top(param1);
    pop();
    successo=top(param2);
    pop();
    if(param1!='T' && param1!='F'){
        corretta=false;
    }if(param2=='!'){
        successo=top(param2);
        pop();
        if(param1=='T'){
            param1='F';
        }else{
            param1='T';
        }
    }else if(param2!='T' && param2!='F'){
        corretta=false;
    }

    /* SB: qui si assume che l'operatore sia un "&". Tuttavia, questo non considera
     * espressioni come "&!T!T", in cui ci sono due "!", oppure espressioni come "!F"
     * in cui non c'è un operatore "&". Inoltre, non viene controllato che il valore
     * di "operatore" sie effettivamente un carattere valido
     */
    successo=top(operatore);
    pop();

    bool risultato_operazione=operatore_bool(traduttore(param1),traduttore(param2));
    char tmp;

    if(top(tmp)){
        risultato_operazione=operatore_bool(risultato_operazione,operazione2(corretta));
    }else{
        cout << "Comandi finiti!" << endl;
    }
    return risultato_operazione;
}

bool traduttore(char valore){
    return (valore=='T')?true:false;
}

bool operatore_bool(bool va1,bool val2){

    /* SB: l'operatore '&' è l'operatore AND bitwise, non l'operatore AND logico 
     * (che invece si rappresente con '&&').
     * La scrittura corretta sarebbe stata "val1 && val2". E' una imprecisione
     * significativa, tuttavia, per come sono definiti i tipo booleani, la funzione 
     * si comporta comunque correttamente
     */
    return (va1&val2)?true:false;
}

/*

void init();
void deinit();
bool push(char);
bool top(char &);
bool pop();
bool vuota();


*/
