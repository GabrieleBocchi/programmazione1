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
  bool ris = true;
  
  //creo una pila
  init();

  //indice
  int i = 0;
  
  /* SB: il primo elemento può anche essere 'T' oppure 'F', se
   * l'espressione fornita in input è composta da una sola lettera
   */
  //errore se il primo elemento è diverso da &
  if(espressione[i] != '&' && espressione[i] != '!'){
    corretta = false;
  }
  
  else{
    //compongo la mia pila
    while(espressione[i] != '\0'){
        push(espressione[i]);
        i++;
    }

    //ora analizzo
    char op;
    top(op);
    pop();
    
    /* SB: esercizio non implementato se non il caricamento della pila
     */

  }


  
  deinit();
  return ris;
}
