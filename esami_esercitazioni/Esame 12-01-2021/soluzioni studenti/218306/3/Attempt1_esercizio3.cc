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

bool isDigit(char c) {
  return (c >= '0' && c <= '9');
}

char invert(char c) {
  return c == '0' ? '1' : '0';
}

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta) {
  char result = -1;
  int length;
  for (length = 0; espressione[length] != '\0'; length++);

  init();
  for (int i = length-1; i >=0 && corretta; i--) {
    char c = espressione[i];
    if (isDigit(c)) {
      push(c);
    } else if (c == '!') {
      /* SB: il valore di ritorno della funzione "top()" non è controllato.
       * Questo significa che il codice non indica come malformate espressioni
       * a cui manca l'argomento dell'operatore "!", come per esempio "!" e "|0!"
       */
      top(c);
      pop();
      push(invert(c));
    } else if (c == '|') {
      char c1, c2;
      /* SB: il valore di ritorno delle funzioni "top()" non è controllato.
       * Per esempio, nella (malformata) espressione composta da solo "|", il
       * codice cerca di scaricare due valori dalla pila (che però è vuota!).
       * Fortunatamente, "c1" e "c2" (che non sono inizializzati) raramente 
       * saranno entrambi casualmente delle cifre, quindi l'espressione verrà
       * indicata come malformata, ma solo per caso.
       */
      top(c1); pop();
      top(c2); pop();

      if (!isDigit(c1) || !isDigit(c2)){
        corretta = false;
      } else if (c1 == '1' || c2 == '1') {
        push('1');
      } else {
        push('0');
      }
    } else {
      corretta = false;
    }
  }

  if (corretta) {
    // SB: due istruzioni nella stessa riga
    top(result); pop();
    if (!vuota()) {
      corretta = false;
    }
  }
  deinit();

  return result;
}