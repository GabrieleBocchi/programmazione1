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
  char risultato;
  int contatore = 0;
  for(int i = 0; espressione[i]!='\0'; i++)
    {
      push(espressione[i]);
      contatore++;
    }

  char n;
  bool no = false;
  
  // SB: dovrebbe essere "j<contatore"
  for(int j = 0; j<=contatore; j++)
    {
      top(n);
      if(n == 'F')
	{
	  if(no)
	    {
	      risultato = 'T';
	    }
	  else
	    {
	      risultato = 'F';
	    }
	}
      else if(n == 'T')
	{
	  if(no)
	    {
	      risultato = 'F';
	    }
	  else
	    {
	      risultato = 'T';
	    }
	}
      else if(n == '!')
	{

        // SB: l'operatore ! è implementato per espressioni post-fisse, non pre-fisse
	  no = true;
	}
      else if(n == '|')
	{
            // SB: operatore | non implementato
	}
      pop();
    }

  // SB: mancano "init()" e "deinit()"
  
  return risultato; 
}
