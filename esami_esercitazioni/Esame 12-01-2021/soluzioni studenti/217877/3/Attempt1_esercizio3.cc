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
  int i = 0;
  char buffer, buffer1;
  char res;

  // SB: variabile inutilizzata
  int lunghezza;
  for(i = 0; espressione[i] != '\0'; i++);
  i--;
  while (i >= 0 && corretta){
    if(espressione[i] == 'T' || espressione[i] == 'F')
      push(espressione[i]);
    if(espressione[i] == '!'){
      if(vuota())
	corretta = false;
      else{
	top(buffer);
	pop();
        
  /* SB: l'istruzione in riga 55 è da riscrivere come
   * res = (((buffer == 'T')? 'F' : 'T'));
   * push(res);
   */
	push(((buffer == 'T')? 'F' : 'T'));
      }
       
    }
    if(espressione[i] == '|' && corretta){
      if(vuota()){
	corretta = false;
      }
      else{
	top(buffer);
	pop();
	if(vuota())
	  corretta = false;
	else{
	  top(buffer1);
	  pop();
	  res = ((buffer == 'T' || buffer1 == 'T')? 'T' : 'F');
	  push(res);
	}
      }
    }
    i--;
  }

  /* SB: il codice controlla che l'espressione abbia il numero minimo di 
   * valori necessari per gli operatori, ma non controlla se sono presenti
   * delle variabili aggiuntive. Per esempio, la (incorretta) espressione
   * "T|FF" viene comunque valutata a "F" invece che essere indicata come 
   * malformata. Basterebbe controllare se la pila è vuota oppure no prima
   * di fare le "deinit()";
   */

  deinit();


  /* SB: la variabile "res" viene inizializzata solo se nell'espressione booleana
   * è presente un operatore "|". Di conseguenza, il codice non riesce a valutare 
   * espressioni come "!F" e "T".
   */
  return res;
}
