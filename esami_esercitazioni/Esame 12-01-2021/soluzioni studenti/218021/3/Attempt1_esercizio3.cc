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
    // Scrivere il codice qui
  int lunghezza = 0;
  corretta = true;
 
  /* SB: la dichiarazione di una variabile "pila" è ridondante in quanto la pila è già
   * contenuta in "pila.cc". Inoltre, le varie funzioni ("init()", "push()", ...) agiscono
   * sulla pila in "pila.cc", non su quella qui definita. 
   */
  lista pila;
  init();

  while(espressione[lunghezza] != '\0' && lunghezza < 100) {
    lunghezza++;
  }

  for(int i = lunghezza - 1; i >= 0; i--) {
    if(espressione[i] == 'T' || espressione[i] == 'F') {
      char elem;
      
      if(espressione[i] == 'T') {
	push('T');
      }
      else {
	push('F');
      }
      top(elem);
      cout << elem<< " iniu" << endl;
    }
    else if(espressione[i] == '!') {
      char elem;
      top(elem);
      cout << elem << endl; 
      if(!vuota()) {

 
	char primo;
	top(primo);
	pop();
	if(primo == 'F') {
	  push('T');
	}
	else {
	  push('F');
	}
      }
      else {
	corretta = false;
      }
     
    }
    else if(espressione[i] == '&') {
      char elem;

      /* SB: la variabile "pila" qui definita non è inizializzata (leggere commento riga 38). 
       * Questo implica un comportamento imprevedibile del codice.
       */
      if(top(elem) && pila->next != NULL) {

 
	char elem;
	top(elem);
	pop();
  /* SB: la seconda invocazione alla funzione "pop" rimuove un elemento senza considerarlo. In pratica, 
   * si confronta il primo elemento della pila con il terzo, mentre il secondo elemento viene perso
   */
	pop();

  /* SB: la variabile "pila" qui definita non è inizializzata (leggere commento riga 38). 
  * Questo implica un comportamento imprevedibile del codice.
  */
	if(elem == 'F' || pila->next->value == 'F') {
	  push('F');
	}
	else {
	  push('T');
	}
      }
      else {
	corretta = false;
      }
    }
  }

  char res;
  top(res);
  return res;
}
