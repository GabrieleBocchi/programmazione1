#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta);

bool is_valid_character(char character);
bool is_valid_value(char character);
bool get_value(char character);
char get_char(bool value);

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
  bool ris;
  char val1, val2, op;
  char tmp;
  int cont_val;
  bool trovato_op;
  init();

  corretta = true;
  for (int i = 0; espressione[i] != '\0' && corretta; i++) {
    if (is_valid_character(espressione[i])) {
      corretta = push(espressione[i]);
    } else {
      corretta = false;
    }
  }

  cont_val = 0;
  while (!vuota() && corretta) {
    do {
      if ((corretta = top(tmp))) {
	if (is_valid_value(tmp)) {
	  trovato_op = false;
	  if (cont_val == 0) {
	    val1 = tmp;
	    cont_val++;
	  } else if (cont_val == 1) {
	    val2 = tmp;
	    cont_val++;
	  } else {
	    corretta = false;
	  }
	} else {
	  op = tmp;
	  trovato_op = true;
	}
      }
      corretta = pop();

	/* SB: se l'espressione booleana in input è composta da una sola lettera (per esempio, "T"), 
	 * questo diventa un ciclo infinito.
	 */
    } while (!trovato_op);

    // Valuta l'espressione
    switch (op) {
    case '|':
      if (cont_val == 2) {
	ris = get_value(val1) || get_value(val2);
	val1 = get_char(ris);
	cont_val = 1;
      } else {
	corretta = false;
      }
      break;
    case '!':
      if (cont_val == 2) {
	ris = !get_value(val2);
	val2 = get_char(ris);
      } else {
	ris = !get_value(val1);
	val1 = get_char(ris);
	cont_val = 1;
      }

      // Non metto il default perchè a questo punto so già che in op
      // non ci possono essere caratteri non consentiti
    }
  }
  
  deinit();
  return val1;
}

bool is_valid_character(char character) {
  return (character == 'F' || character == 'T' ||
	  character == '!' || character == '|');
}

bool is_valid_value(char character) {
  return (character == 'T' || character == 'F');
}

bool get_value(char character) {
  return (character == 'T');
}

char get_char(bool value) {
  return (value)? 'T' : 'F'; 
}
