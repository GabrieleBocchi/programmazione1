#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert (const char[], const int);
// Inserire qui sopra la dichiarazione della funzione convert

int toInt(char);
int potenza(int, int);
int lunghezza(const char[]);

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

bool controlla(char * num, const int maxdim, const unsigned int base=8) {
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
long long int convert(const char source[], const int DIM) {
  long long int res;
  // MR: Inefficiente perché ad ogni ricorsione calcola ricorsivamente
  // la lunghezza della stringa rimanente, ma corretto
  int dimCifre = lunghezza(source);

  if (dimCifre == 0) {
    res = 0;
  }
  else {
    res = (toInt(source[0]) * potenza(8, dimCifre-1)) + convert(source+1, DIM-1);
  }

  return res;
}
// Inserire qui sopra la definizione della funzione convert

int toInt(char c) {
  // MR: Manca controllo che c = 0, 1, ..., 7
  return (c - '0');
}

int potenza(int b, int n) {
  int res;

  if (n == 0) {
    res = 1;
  }
  else {
    res = b * potenza(b, n-1);
  }

  return res;
}

int lunghezza(const char array[]) {
  int res;
  // MR: Manca controllo che dimensione < maxdim!
  if (array[0] == '\0') {
    res = 0;
  }
  else {
    res = 1 + lunghezza(array+1);
  }

  return res;
}
