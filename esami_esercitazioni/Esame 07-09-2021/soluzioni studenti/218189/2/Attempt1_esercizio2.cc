#include <iostream>
#include <cstring>

char* extract(char* s);
/* Inserire qui sotto la dichiarazione della funzione extract */

/* Inserire qui sopra la dichiarazione della funzione extract */

/* Solo di esempio, non fate assunzioni su questo valore */
const int DIM = 255;

int main(int argc, char ** argv) {
  char input_string[DIM+1];
  char * extracted= new char[DIM+1];
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

char * extract(char s[])
{
  char *rets;
  if(*s!='\0')
    {
      if(*s=='$')
	{
	  strcat(rets,"$");
	  // MR: Cosa c'e' di non chiaro in "All’interno di questo
	  // programma non è ammesso l’utilizzo di variabili globali o
	  // di tipo static e di funzioni di libreria al di fuori di
	  // quelle definite in cstddef." La funzione strcat e'
	  // definita in cstring (che lei include)!. Inoltre non sta
	  // allocando memoria!
	  *rets=*(rets+1);
	  rets=extract(s+1);
	  // MR: Manca return
	}
      // MR: Manca return
    }
  else
    return rets;
}

/* Inserire qui sotto la definizione della funzione estract */

/* Inserire qui sopra la definizione della funzione estract */
