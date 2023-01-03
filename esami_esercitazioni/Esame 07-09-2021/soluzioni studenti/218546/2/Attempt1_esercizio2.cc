#include <iostream>


/* Inserire qui sotto la dichiarazione della funzione extract */
char * extract (const char * str);
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

void extract_ric(const char * str, int i, int & len, char *ret);

char * extract (const char * str) {
    char * ret;
    int len = 0;
    extract_ric(str, 0, len, ret);
    ret[len] = '\0';
    return ret;
}

void extract_ric(const char * str, int i, int & len, char *ret) {
    if(str[i] == '\0') {
        len++;
        ret = new char[len];
	// MR: Manca spazio per carattere terminatore di stringa, e
	// scrittura del terminatore di stringa.
	// MR: Inoltre, essendo ret passato per valore e non per
	// riferimento, quando si scrive si scrive su potenziale area
	// memoria non del programma, in quanto non propagato alle
	// altre chiamate!
    }
    else if(str[i] == '$') {
        int pos = len;
        len++;
        extract_ric(str, i+1, len, ret);
        ret[pos] = '$';
    }
    else {
        extract_ric(str, i+1, len, ret);
    }
}

/* Inserire qui sopra la definizione della funzione estract */
