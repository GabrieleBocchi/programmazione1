#include <iostream>

using namespace std;


// Inserire qui sotto la dichiarazione della funzione convert

long long int convert(char number[],int dim);


// Inserire qui sopra la dichiarazione della funzione convert


bool check_base(const char n, const int base) {
  switch(base) {
  case 2:
    return ((n == '0') || (n == '1'));
  case 4:
    return ((n >= '0') && (n <= '3'));
  case 8:
    return ((n >= '0') && (n <= '8'));
  case 16:
    return (((n >= '0') && (n <= '9')) ||
	    ((n >= 'A') && (n <= 'D')) ||
	    ((n >= 'a') && (n <= 'd')));
  default:
    return false;
  }
}

bool controlla(char * num, const int maxdim, const unsigned int base = 4) {
  for(int i = 0; ((i < maxdim) && (num[i] != '\0')); i++) {
    if (num[i] >= 'A' && num[i] <= 'Z') {
      num[i] = 'a' + (num[i] - 'A');
    }
    if (!check_base(num[i], base)) return false;
  }
  return true;
}


int main() {
  const unsigned int maxdim = 100;
  char number[maxdim];

  cout << "Inserire numero: ";
  cin >> number;
  if (!controlla(number, maxdim)) {
    cout << "Il numero deve contenere solo caratteri rispetto alla base" << endl;
    exit(1);
  }

  long long int decimal = convert(number, maxdim);

  cout << "The converted number is: " << decimal << endl;
}

// Inserire qui sotto la definizione della funzione convert

long long int convert(char number[],int dim)
{
    int decimale;
    // MR: Ammesso che dim sia dimensione dell'array, qui sta
    // accedendo ad area di memoria spuria! Gli indici vanno da 0 a
    // maxdim-1. Inoltre, non era specificato che l'array avesse
    // dimensione pari a dim!
    if(number[dim]=='\0')
    {
        return 0;
    }

    decimale=number[dim]*4^(sizeof(number)-dim)+convert(number,dim-1);
    // MR: L'operatore ^ non fa l'elevamento a potenza ma fa lo XOR,
    // non so in che linguaggio lo avete visto! Inoltre,
    // sizeof(number) in questo caso ritorna sizeof(char *) che e'
    // quindi il size di un puntatore (e.g. 32 o 64 in base ad
    // architettura). L'idea era giusta, ma avrebbe dovuto calcolare
    // la dimensione dell'array! Infinte, number[dim] e' un carattere
    // da convertire in decimale '0' non e' 0 ma bensi 48 in codice ascii
    return decimale;

}



// Inserire qui sopra la definizione della funzione convert
