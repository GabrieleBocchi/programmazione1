#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta);

int main() { 

    const int dimensioneMassima = 100;
    char espressioneBooleana [dimensioneMassima];
    bool corretta = true;
    char risultatoEspressione;
    init();

    cout << "Inserisci l'espressione: ";
    cin >> espressioneBooleana;

    risultatoEspressione = parseEspressioneBooleanaPrefissa(espressioneBooleana, corretta);

    if (corretta) {
        cout << "Risultato: " << risultatoEspressione << endl;
    }
    else {
        cout << "Espressione malformata" << endl;
    }

    deinit();
    
    return 0;
}


char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta) {
  char c1 = '3', c2 = '3', temp, operatore = '3';
  for(int i=0; espressione[i] != '\0'; i++){
    push(espressione[i]);
  }

  /* SB: ci sono return multipli nella funzione (bastava aggiungere 
   * una condizione al ciclo while "&& corretta")
   */

  while(!vuota()){
    top(temp);
    if(temp != '1' && temp != '0' && temp != '&' && temp != '!'){
      corretta = false;
      return '0';
    }

    if(temp == '1' || temp == '0'){
      if( c1 == '3')
        top(c1);
      else if(c2 == '3')
        top(c2);
      else{
        corretta = false;
        return '0';
      }
    }
    else if(temp == '&' || temp == '!'){
      if(operatore == '3')
        operatore = temp;
      else{
        corretta = false;
        return '0';
      }
    }
    if(operatore == '!'){
      if(c2 == '3'){
        if(c1 == '1')
          c1 = '0';

        /* SB: bisogna controllare comunque che ("c1 != 3"), altrimenti il codice 
         * accetta espressioni malformate come "!". 
         */
        else
          c1 = '1';
      }else if(c2 == '1')
        c2 = '0';
      else
        c2 = '1';
      operatore = '3';
    }else if(operatore == '&'){
      if(c1 == '3' || c2 == '3'){
        corretta = false;
        return '0';
      }else{
        /* SB: purtroppo questo codice valuta a "1" espressioni come "&00"
         */
        if(c1 == c2)
          c1 = '1';
        else
          c1 = '0';
        c2 = '3';
        operatore = '3';
      }
    }
    pop();
  }

  /* SB: manca un controllo per c2. Se "c2 != 3" alla fine della funzione,
   * allora l'espressione è malformata (per esempio "1!1" viene indicata
   * come ben formata dal suo codice)
   */

  return c1;
}