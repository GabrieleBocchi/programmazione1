#include <iostream>

using namespace std;

#define BASE 16

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(char* number, int maxdim);
long long int convertRic(char* number, int size, int i);
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
	    ((n >= 'A') && (n <= 'F')) ||
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
int calcola_size_ric(char* number, int i) {
  // MR: Manca controllo che i < maxdim, infatti se non esiste \0 va
  // in ricorsione infinita
  if (number[i] != '\0') {
    return calcola_size_ric(number, i+1);
  }
  else {
    return i;
  }

}

int toInt(char c) {
  if (c >= 'a' && c <= 'f') {
    return c - 'a' + 10;  //  c = a => 0 + 10 = 10.  c = b => (b - a = 1) => 1 + 10 = 11 e cosi' via
  }
  else if (c >= 'A' && c <= 'F')
    return c - 'A' + 10;
  else {
    // MR: se c non e' >='0' <= '9' il risultato e' errato!
    return c - '0';
  }
}

int power(int base, int exp) {
  // MR: se exp < 0 va in ricorsione infinita.
  if(exp == 0)
    return 1;
  else {
    return base * power(base, exp-1);
  }
}

long long int convert(char* number, int maxdim) {
  long long int retval = -1;
  int size = calcola_size_ric(number, 0);
  // MR: Ok il controllo qui, ma andrebbe anche fatto in calcolo size
  if (size < maxdim)
    retval = convertRic(number, size, size-1);

  return retval;
}

long long int convertRic(char* number, int size, int i) {  // num = cifra * base^posiz
  if (i >= 0) {
    int pos = size - i - 1; // parto da destra
    return toInt(number[i]) * power(BASE, pos) + convertRic(number, size, i-1);
  }
  else return 0;
}

// Inserire qui sopra la definizione della funzione convert
