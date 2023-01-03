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


char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta)
{
  
  nodo* p = new nodo;
  char a;
  init();
  for(int i=99;i>=0;i--)
    {
      push(espressione[i]);
    }
  for(int i=99;i>=0;i--)
    {
      top(a);
      if(a == 1)
	{
	  corretta = true;
	}
      else if(a == 0)
	{
	  corretta = false;
	}
      //controlli ! && |
      pop();
    }

  // SB: esercizio non implementato
  
  deinit();
}
