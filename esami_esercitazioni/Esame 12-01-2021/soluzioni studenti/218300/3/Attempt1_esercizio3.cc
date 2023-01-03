#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta);
void notTF (char & val);
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
  char val, temp1, temp2;
  bool error = false;
  init();
  int i = 0;
  while (espressione[i]=='T'||espressione[i]=='F'||espressione[i]=='&'||espressione[i]=='!'){
    push (espressione[i]);
    i++;
  }
  top(val);
  pop();

  while (top(temp1)&& error == false){
    if (temp1 == '!'){
      notTF (val);
    }
    else if(temp1 == '&'){
      error = true;
      corretta = false;
    }
    else{
      pop();
      top(temp2);

      
      if (temp2=='!'){

	notTF (temp1);

	pop();
	top(temp2);
	if (temp2!='&'){
	  error = true;
	  corretta = false;
	}
	else {
	  if(temp1=='T'&& val == 'T'){
	    val = 'T';
	  }
	  else {
	    val = 'F';
	  }
	}
      }

      /* SB: l'operatore "&" non è gestito se non preceduto immediatamente dall'operatore "!". Per esempio
       * "&!FF" viene valutata correttamente, mentre
       * "&F!F" non viene valutata correttamente
       */
    }
    
    pop();
  }
  deinit ();

  /* SB: non viene controllato che il valore di ritorno sia "T" oppure "F". Se l'espressione 
   * in input è '!' oppure '&', la funzione ritornerà rispettivamente '!' e '&'
   */
  return val;
}

void notTF (char & val){
  if (val == 'F'){
    val = 'T';
  }
  else{
    val = 'F';
  }
}
