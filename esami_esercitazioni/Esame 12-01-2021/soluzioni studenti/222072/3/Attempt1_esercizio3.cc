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
  
  int len = 0;
  for (int i = 0; espressione[i] != '\0'; i++) {
    len++;
  }
  
  init ();
  char exp1, exp2, risultato;
  bool op1, op2, res;
  
  for (int i = len-1; i >= 0 && corretta; i--) {
    if (espressione[i] == 'T' || espressione[i] == 'F') {
      push (espressione[i]);
    }
    else if (espressione[i] == '|') {

      if ( top(exp1) ) 
	pop ();
      else
	corretta = false;
      if ( top(exp2) )
	pop ();
      else
	corretta = false;

      if (vuota()) {
      op1 = exp1 == 'T'? true : false;
      op2 = exp2 == 'T'? true : false;
      res = (op1 || op2);
      risultato = res == true? 'T' : 'F';
      push (risultato);
      }
      else
	corretta = false;
    }
    else if (espressione[i] == '!') {
      if (top(exp1)) {
	pop();
	exp1 = exp1 == 'F'? 'T' : 'F';
	push (exp1);
      }
      else {
	corretta = false;
      }
    }
    else {
      corretta = false;
    }
  }

  if (corretta) {
    top (risultato);
    pop ();
  }
  
  if (!vuota()) {
    corretta = false;
  }
  
  deinit ();
  return risultato;
}
