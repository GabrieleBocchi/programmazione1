#include <iostream>


/* Inserire qui sotto la dichiarazione della funzione extract */
char *extract(char input_string[]);
void extract_ric(char input_string[], int i, char stringa2[], int i_stringa2);
/* Inserire qui sopra la dichiarazione della funzione extract */



/* Solo di esempio, non fate assunzioni su questo valore */
const int DIM = 255;

int main(int argc, char ** argv) {
  char input_string[DIM+1];
  char * extracted;
  char answer;

  do {
    std::cout << "Inserire la stringa da controllare: ";
    std::cin >> input_string;

    extracted = extract(input_string);
    std::cout << "La stringa estratta e': " << extracted << std::endl;

    delete [] extracted;
    std::cout << "Si vuole inserire un'altra stringa? [*/n]";
    std::cin >> answer;
  } while (answer != '\0' && answer != 'N' && answer != 'n');
  return 0;
}

/* Inserire qui sotto la definizione della funzione estract */
void extract_ric(char input_string[], int i, char stringa2[], int i_stringa2) {
  // MR: Cosa succede se i_stringa2 eccedono dimensioni degli array?
	if (input_string[i] == '\0') {
		stringa2[i_stringa2] = '\0';
	} else {
		if ((input_string[i] == '@')) {
			stringa2[i_stringa2] = input_string[i];
			extract_ric(input_string, i + 1, stringa2, i_stringa2 + 1);
		} else {
			extract_ric(input_string, i + 1, stringa2, i_stringa2);
		}
	}
}

char *extract(char input_string[]) {
  // MR: Cosa non e' chiaro nella frase "Le uniche assunzioni che si
  // possono fare sull’input e su dimensioni di eventuali
  // strutture/array utilizzate nel file di partenza fornito sono solo
  // quelle espressamente specificate in questo testo (e NON quelle
  // riportate nel file fornito, che sono SOLO indicative per
  // consentire di svolgere l’esame)."? Qui sta usando DIM e NON era
  // consentito! Doveva calcolare la dimensione di stringa2 in base a
  // quanto memorizzato in input_string! Al limite avrebbe potuto
  // calcolarsi la dimensione di input_string!
	char * stringa2 = new char[DIM];

	extract_ric(input_string, 0, stringa2, 0);

	return (stringa2);
}


/* Inserire qui sopra la definizione della funzione estract */
