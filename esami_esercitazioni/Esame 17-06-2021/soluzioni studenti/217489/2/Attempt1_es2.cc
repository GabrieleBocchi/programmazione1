#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(char source[], int dimmax);
long long int convert_ric(char source[], int dimmax, int conta, int risultato, int lunghezza);
int lunghezza(char source[], int dimmax, int conta);

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
	    ((n >= 'A') && (n <= 'F')) ||  //modifica effettuata sotto indicazione
	    ((n >= 'a') && (n <= 'f')));
  default:
    return false;
  }
}

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
long long int convert(char* source, int dimmax)
{
  long long int risultato = 0;
  int val = 0;
  int lunghezzaarray = lunghezza(source, dimmax, 0);

  risultato = convert_ric(source, dimmax, 0, val, lunghezzaarray);
  return risultato;
}

long long int convert_ric(char* source, int dimmax, int conta, int risultato, int lunghezza)
{
  // MR: Manca controllo che conta < dimmax
  if(source[conta] != '\0')
  {
    // MR: source[conta] va convertito in numero, altrimenti viene usato codice ascii!!
    // MR: ^ non e' potenza, ma xor. Inoltre forse mancano delle parentesi!
    risultato = source[conta]*(16^lunghezza-1);
    lunghezza--;
    conta++;
    risultato = risultato + convert_ric(source, dimmax, conta, risultato, lunghezza);
    // MR: Dove e' il return in questo branch?
  }
  else
  {
      return risultato;
  }
}

int lunghezza(char source[], int dimmax, int conta)
{
  if(source[conta] != '\0' && conta < dimmax)
  {
    conta++;
    // MR: Manca return! Per caso forse funziona
    lunghezza(source, dimmax, conta);
  }
  else
  {
    return conta;
  }
}

// Inserire qui sopra la definizione della funzione convert
