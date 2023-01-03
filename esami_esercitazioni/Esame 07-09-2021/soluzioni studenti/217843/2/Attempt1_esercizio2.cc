#include <iostream>


/* Inserire qui sotto la dichiarazione della funzione extract */
char* extract ( const char* s );
void extract_aux ( const char* s, int i, char* & ret, int dim );
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

char* extract ( const char* s )
{
  int i = 0;
  char* ret;
  extract_aux ( s, i, ret, 0 );
  return ret;
}

void extract_aux ( const char* s, int i, char* & ret, int dim )
{
  if ( s[i] == '\0' )
    {
      ret = new char[dim];
      // MR: Manca spazio per in \0 in modo che stringa sia ben
      // formata. Inoltre non viene scritto in ret il terminatore di
      // stringa!
    }
  else
    {
      if ( s[i] != '$' )
	{
	  int p = dim++;
	  extract_aux ( s, i+1, ret, dim );
	  ret[p] = s[i];
	}
      else
	{
	  extract_aux ( s, i+1, ret, dim );
	}
    }
}



/* Inserire qui sopra la definizione della funzione estract */
