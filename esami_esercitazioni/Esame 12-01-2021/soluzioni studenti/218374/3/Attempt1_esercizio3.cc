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

  // SB: non ha usato la pila nella risoluzione dell'esercizio

  int g=0;
  int i,j;
  // SB: la condizione giusta sarebbe " espressione[i] != '\0' " 
  for(i = 0; i < 100 && espressione[i] != NULL ; i++){    
    if(espressione[i] == '&' || espressione[i] == '!' || espressione[i] == 'T' || espressione[i] == 'F'){
      // SB: l'if è vuoto, senza istruzioni
    }else{
      g++;
    }
  }

  /* SB: viene controllata la correttezza dell'espressione solo in merito al fatto che 
   * l'espressione non sia nulla. Tuttavia, l'espressione in sé (per esempio l'ordine 
   * degli operatori e il numero degli argomenti) non è controllata.
   */
  if(g != 0){
    corretta = false;
  }else{

    /* SB: la condizione dovrebbe essere "j >= 0", altrimenti il codice 
     * ignora il primo elemento dell'array, compromettendo la valutazione dell'espressione
     */
    for(j = i-1; j > 0; j--){
      if(espressione[j] == '!'){


  /* SB: se l'ultimo carattere dell'espressione è '!', allora l'accedere alla 
   * zona di memoria "espressione[j+1]" esce dai limiti dell'array e risulta 
   * in un comportamento indefinito
   */
	if(espressione[j+1] == 'F'){
	  espressione[j] = 'V';
	}else if(espressione[j+1] == 'V'){
	  espressione[j] = 'F';
	}
      }else if(espressione[j] == '&'){

  /* SB: se l'ultimo carattere dell'espressione è '&', allora l'accedere alla 
   * zona di memoria "espressione[j+2]" e "espressione[j+1]" esce dai limiti 
   * dell'array e risulta in un comportamento indefinito
   */
	if(espressione[j+2] == 'F' && espressione[j+1] == 'F'){
	  espressione[j] = 'F';
	}else if(espressione[j+2] == 'V' && espressione[j+1] == 'F'){
	  espressione[j] = 'F';
	}else if(espressione[j+2] == 'F' && espressione[j+1] == 'V'){
	  espressione[j] = 'F';
	}else if(espressione[j+2] == 'V' && espressione[j+1] == 'V'){
	  espressione[j] = 'V';
	}
      }
    }
  }

  /* SB: viene sempre ritornato il primo 
   * carattere dell'espressione booleana
   */
  return espressione[j];
}
