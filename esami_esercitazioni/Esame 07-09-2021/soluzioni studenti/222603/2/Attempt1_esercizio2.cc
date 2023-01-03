#include <iostream>


/* Inserire qui sotto la dichiarazione della funzione extract */
char * extract (char input_string[]);
/* Inserire qui sopra la dichiarazione della funzione extract */
void extract_ric(char input_string[],char * & estratta, int & dim, int i);
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

/* Inserire qui sopra la definizione della funzione estract */
char * extract (char input_string[])
{
  char * estratta;
  int dim = 0;

  extract_ric(input_string, estratta, dim, 0);

  return estratta;
}

void extract_ric(char input_string[],char * & estratta, int & dim, int i)
{
  if (input_string[i] != '\0')
  {
    if (input_string[i] == '@')
    {
      int p = dim++;
      extract_ric(input_string, estratta, dim, i+1);
      estratta[p] = '@';
    } else
    {
      extract_ric(input_string, estratta, dim, i+1);
    }
  }
  else
  {
    estratta = new char [dim];
    // MR: Qui avrebbe dovuto usare dim + 1 per poter memorizzare lo
    // \0, e avrebbe dovuto mettere estratta[dim] = '\0'; per ottenere
    // la stringa correttamente formata.
  }

}
