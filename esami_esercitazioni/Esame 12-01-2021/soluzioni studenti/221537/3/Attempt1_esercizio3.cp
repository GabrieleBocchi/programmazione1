#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta);
char charIsAllowed(char c);
char isOperator(char c);
char isTrueOrFalse(char c);

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

    // SB: attenzione che il file è nominato con estensione ".cp" e non ".cc" o ".cpp" ...

    // SB: variabile non utilizzata
    int i = 0;
    corretta = true;
    char c;
    for(int i = 0; (c = espressione[i]) != '\0' && corretta; i++) {

      // SB: due istruzioni sulla stessa riga
      if(!charIsAllowed(c)) corretta = false;
      else {
        push(c);
      }
    }

    int buffer_dim = 100;
    char boolbuffer[100];

    // SB: due istruzioni sulla stessa riga
    for(int i = 0; i < buffer_dim; i++) boolbuffer[i] = '\0';
    int boolbuffer_i = 0;

    while(!vuota() && corretta) {
      top(boolbuffer[boolbuffer_i]);
      pop();

      char result;
      // cout << boolbuffer_i <<" "<< boolbuffer << endl;
      switch(boolbuffer[boolbuffer_i]) {
        case '&':

          /* SB: l'ordine di valutazione delle singole condizioni non è lineare da sinistra a destra. 
           * Questo vuol dire che la seconda condizione " isTrueOrFalse(boolbuffer[boolbuffer_i-1]) " 
           * potrebbe essere valutata prima di "boolbuffer_i", accedendo quindi ad un'area di memoria
           * oltre i limit dell'array.
           */
          if(boolbuffer_i >= 2 && isTrueOrFalse(boolbuffer[boolbuffer_i-1]) && isTrueOrFalse(boolbuffer[boolbuffer_i-2])) {
            result = (boolbuffer[boolbuffer_i-1] == 'T' && boolbuffer[boolbuffer_i-2] == 'T') ? 'T' : 'F';
            push(result);
            boolbuffer_i -= 3;
          }
          else {
            corretta = false;
          }
          break;

        case '!':
          if(boolbuffer_i >= 1 && isTrueOrFalse(boolbuffer[boolbuffer_i-1])) {
            result = (boolbuffer[boolbuffer_i-1] == 'F') ? 'T' : 'F';
            push(result);
            boolbuffer_i -= 2;
          }
          else {
            corretta = false;
          }
          break;
      }
      boolbuffer_i++;
    }

    // cout << boolbuffer_i <<" "<< boolbuffer << endl;
    if(boolbuffer_i != 1) {
      corretta = false;
    }

    deinit();
    return boolbuffer[0];
}

char charIsAllowed(char c) {
  return isOperator(c) || isTrueOrFalse(c);
}
char isTrueOrFalse(char c) {
  return c == 'T' || c == 'F';
}
char isOperator(char c) {
  return c == '!' || c == '&';
}
