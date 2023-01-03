#include <iostream>

//importato la libreria math.h per effettuare il calcolo dell'elevamento a potenza
#include <math.h>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(char source[],int dimMaxSource);
// Inserire qui sopra la dichiarazione della funzione convert

//ho creato una funzione aggiuntiva
long long int convertiAggiuntiva(char source[],int dimMaxSource,int somma);

//opportune modifiche del codice base per provare a run-time se funzioni il programma
bool check_base(const char n, const int base);

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
	    ((n >= 'A') && (n <= 'F')) ||
	    ((n >= 'a') && (n <= 'f')));
  default:
    return false;
  }
}

//e' stata modificata la base perche' era 4 e nella consegna si chiede la 16
bool controlla(char * num, const int maxdim, const unsigned int base = 16) {
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
long long int convert(char source[],int dimMaxSource)
{
  long long int returnValue = 0;

  returnValue = convertiAggiuntiva(source,dimMaxSource,returnValue);
  return returnValue;
}


//inserisco un'ulteriore funzione convertiAggiuntiva
long long int convertiAggiuntiva(char source[],int dimMaxSource,int returnValue)
{
  if(dimMaxSource > 0)
    {
      // MR: Il carattere in source[dimMaxSource] doveva essere
      // convertito in decimale, i.e '0' (aka 48 in ascii) va in 0, e
      // cosi' via per gli altri. Inoltre, cosi' non interpreta
      // correttamente le posizione rispetto a quanto specificato nel
      // testo. Inoltre, gli arrau vanno da 0 a dimMaxSource - 1, qui
      // sta accedendo potenzialmente ad area di memoria spuria!
      returnValue += source[dimMaxSource] * pow(16,dimMaxSource);
      return convertiAggiuntiva(source,--dimMaxSource,returnValue);
    }

  return returnValue;
}
