#include <iostream>
using namespace std;
/* Inserire qui sotto la dichiarazione della funzione extract */
char *extract(char string[]);
int extract_aux(char input[], int i, int dim);
/* Inserire qui sopra la dichiarazione della funzione extract */

/* Solo di esempio, non fate assunzioni su questo valore */
const int DIM = 255;

int main(int argc, char **argv)
{
  char input_string[DIM + 1];
  char *extracted;
  char answer;

  do
  {
    std::cout << "Inserire la stringa da controllare: ";
    std::cin >> input_string;

    extracted = extract(input_string);
    std::cout << "La stringa estratta e': " << extracted << std::endl;

    delete[] extracted;
    std::cout << "Si vuole inserire un'altra stringa? [*/n]";
    std::cin >> answer;
  } while (answer != '\0' && answer != 'N' && answer != 'n');
  return 0;
}

/* Inserire qui sotto la definizione della funzione estract */

char *extract(char string[])
{
  char *newString;
  int dim = extract_aux(string, 0, 0);
  newString = new char[dim];
  for (int i = 0; i < dim; i++)
  {
    newString[i] = '$';
  }
  // MR: Cosa c'e' di non chiaro in "La funzione extract deve essere
  // ricorsiva ed al suo interno NON ci possono essere cicli o
  // chiamate a funzioni contenenti cicli. Si può però fare uso di
  // funzioni ausiliarie da chiamare all’interno di questa funzione
  // che NON contengano cicli o che siano ricorsive."? Lo ho ripetuto
  // diverse volte.... Mi spiace ma il voto e' 0!
  return newString;
}

int extract_aux(char input[], int i, int dim)
{
  if (input[i] != '\0')
  {
    if (input[i] == '$')
    {
      dim++;
    }
    extract_aux(input, i + 1, dim);
    // MR: Manca return!
  }
  else
  {
    return dim;
  }
}

/* Inserire qui sopra la definizione della funzione estract */
