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

  /* SB: gli array partono da 0, non da 1. Questo errore porta ad ignorare
   * il primo elemento dell'espressione, compromettendone la valutazione.
   */
  int i = 1,n_inseriti = 0;
  char pr1 = 'R',pr2 = 'R',temp;

  // SB: variabile non usata (no impatto su punteggio)
  int c = 1;

  corretta = true;
  while(espressione[i] != '\0'){
    push(espressione[i]);
    n_inseriti++;
    i++;
  }

  // SB: se l'espressione è corretta, "temp" sarà sempre uguale a "T" oppure a "F"
  top(temp);
  pr1 = temp;
  pop();
  /* SB: facendo partire il ciclo for da 1, si salta il secondo
   * elemento dell'espressione, compromettendone la valutazione.
   */
  for(i = 1; i < n_inseriti; i++){

    /* SB: all'interno del ciclo "for" non ci sono chiamate alla funzione "top()". 
     * questo significa che l'espressione nella pila non è letta
     */

    push(temp);
    pop();

    // SB: per il commento riga 50, questo 'if' sarà sempre vero.
    if((temp != '&' && temp != '!') && (temp == 'T' || temp == 'F') ){
      pr2 = temp;
    }
    // SB: per il commento riga 61, questo 'else' non sarà mai eseguito
    else{
      if((temp != 'T' && temp != 'F') && (temp == '&' || temp == '!')){

  // SB: errore indentazione
	if(temp == '&' && pr1 != 'R' && pr2 != 'R'){
	  if(pr1 == pr2 && pr1 == 'T'){
	    pr1 = 'T';
	    pr2 = 'R';
	  }else{
	    pr1 = 'F';
	    pr2 = 'R';
	  }
	}else if(temp == '!' && pr1 != 'R' && pr2 != 'R'){
	  if(temp == 'F'){
	    pr1 = 'T';
	    pr2 = 'R';
	  }else{
	    pr1 = 'F';
	    pr2 = 'R';
	  }
	}
      }else{

    // SB: errore indentazione
	  corretta = false;
      }
      
    }
    
  }
  deinit();

  /* SB: per il commento riga 65, il valore contenuto in pr1 sarà sempre 
   * il valore in cima alla pila, mentre gli operatori "&" e "!" non saranno
   * mai considerati
   */
  return pr1;
  
}
