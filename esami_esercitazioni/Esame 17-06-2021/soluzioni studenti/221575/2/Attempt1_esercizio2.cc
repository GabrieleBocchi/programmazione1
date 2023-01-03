#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert (char source[], int max_dim);
void convert_rico(char numero[], long long int &decimale, int dim, int i, int max_dim);
void conta_caratteri(char stringa[], int &contatore);
void pow (int base, int esponente, long long int &result);
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
long long int convert (char source[], int max_dim) {

  int dim_source = 0;
  conta_caratteri(source, dim_source);

  long long int decimale = 0;
  int i = 0;

  convert_rico(source, decimale, dim_source, i, max_dim);

  return decimale;
}

void convert_rico(char numero[], long long int &decimale, int dim, int i, int max_dim) {
  if (i < dim) {
    int moltiplicatore = 0;
    if (numero[dim-1-i] >= 'a' && numero[dim-1-i] <= 'f') {
      moltiplicatore = numero[dim-1-i] - 'a' + 10;
    } else if (numero[dim-1-i] >= '0' && numero[dim-1-i] <= '9') {
      moltiplicatore = numero[dim-1-i] - '0';
    } else {
      moltiplicatore = -1;  // se no c'è un errore perchè la lettera inserita è sbagliata
    }

    long long int pow_result = 1;
    pow(16, i, pow_result);
    decimale += moltiplicatore * pow_result;

    convert_rico(numero, decimale, dim, ++i, max_dim);
  }
}

void conta_caratteri(char stringa[], int &contatore) {
  // MR: Potenziale ricorsione infinita se l´array non contiene \0
  if (stringa[contatore] != '\0') {
    contatore ++;
    conta_caratteri(stringa, contatore);
  }
}

void pow (int base, int esponente, long long int &result) {
  if (esponente > 0) {
    result = result * base;
    pow(base, --esponente, result);
  }
}

// Inserire qui sopra la definizione della funzione convert
