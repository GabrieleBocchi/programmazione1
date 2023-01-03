#include <iostream>


/* Inserire qui sotto la dichiarazione della funzione extract */
char* extract(char input[]);
int lunghezza(char input[], int i);
void inserisci(char input[], char nuovo[], int conta, int ins);
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
char* extract(char input[])
{
    int lung = lunghezza(input, 0);
    char *nuova = new char [lung];
    inserisci(input, nuova, 0, 0);
    return nuova;
}

void inserisci(char input[], char nuovo[], int conta, int ins)
{
    if(input[conta] != '\0')
    {
        if(input[conta] != '@')
        {
            nuovo[ins] = input[conta];
            ins++;
        }
        conta++;
        inserisci(input, nuovo, conta, ins);
    }
    // MR: Manca inserimento di \0 in ultima posizione per rendere
    // nuovo ben formato!
}

int lunghezza(char input[], int i)
{
    if(input[i] != '\0')
    {
        if(input[i] == '@')
        {
            return lunghezza(input, ++i);
        }
        else
        {
            return 1+lunghezza(input, ++i);
        }
    }
    return 1;
}
/* Inserire qui sopra la definizione della funzione estract */
