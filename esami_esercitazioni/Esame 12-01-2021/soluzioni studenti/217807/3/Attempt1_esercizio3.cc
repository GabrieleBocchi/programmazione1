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
  bool current[2];
  current[0] = true;
  current[1] = true;
  corretta = true;
  int i = 0;
  char res;

  for (int j=0; espressione[j] != '\0'; j++) {
    push(espressione[j]);
  }

  while(!vuota() && corretta) {
    char buffer;
    top(buffer);
    pop();

    switch(buffer) {
    case 'F':
	if (i < 2) {
	  current[i] = false;
	  i++;
	}
	else {
	  corretta = false;
	}
	break;

    case 'T':
      if (i < 2) {
	current[i] = true;
	i++;
      }
      else {
	corretta = false;
      }
      break;

    case '!':
      /* SB: per come è scritto il codice, l'operatore "!" verrà sempre applicato al primo elemento
       * contenuto in "current". Tuttavia, questo comportamento è errato in espressioni come "|!FT",
       * in cui l'operatore "!" dovrebbe essere applicato al secondo elemento di "current"
       * SB: manca il controllo "i > 0" per la correttezza dell'espressione
       */
      current[0] = !current[0];

      /* SB: dovrebbe essere "i=1", altrimenti si sovrascriverà il valore appena calcolato"
       */
      i = 0;
      break;

    case '|':
       /* SB: manca il controllo "i == 2" per la correttezza dell'espressione
       */
      current[0] = current[0] || current[1];

      /* SB: dovrebbe essere "i=1", altrimenti si sovrascriverà il valore appena calcolato"
       */
      i = 0;
      break;

    default:
      corretta = false;
    }
  }
  
  deinit();
  
  if (current[0]) {
    res = 'T';
  }
  else {
    res = 'F';
  }
  
  return res;
}
