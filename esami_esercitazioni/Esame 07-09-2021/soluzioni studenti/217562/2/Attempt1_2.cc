#include <iostream>


/* Inserire qui sotto la dichiarazione della funzione extract */

char *extract(const char *input);
char *extract_aux(const char *input, char *&risultato ,int &indice,int &indice_2);

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
char *extract_aux(const char *input,char *& risultato,int &indice,int &indice_2)
{
    if(input[indice]=='\0')
    {
        risultato = new char[indice_2];
	// MR: Manca inserimento di '\0' per fare si che risultato sia
	// una stringa ben formata! Inoltre, manca lo spazio per
	// memorizzare \0!
    }
    else if(input[indice] == '@')
    {
        indice++;
        extract_aux(input,risultato,indice,indice_2);
    }
    else
    {
        int p = indice++;
        int q = indice_2++;
        extract_aux(input,risultato,indice,indice_2);
        risultato[q] = input[p];
    }
    return risultato;
}

char *extract(const char *input)
{
    char *c;
    int indice = 0;
    int indice_2 = 0;
    extract_aux(input,c,indice,indice_2);
    // MR: Manca return!
}
/* Inserire qui sopra la definizione della funzione estract */
