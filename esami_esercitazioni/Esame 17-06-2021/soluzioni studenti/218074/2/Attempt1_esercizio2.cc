#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert

long long int convert(char *source, const unsigned int dim);
long long int convert_ric(char *source, const unsigned int dim, int i);
long long int toInt(char);
int power(int, int);
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

bool controlla(char * num, const int maxdim, const unsigned int base = 8) {
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
long long int convert(char *source, const unsigned int dim){
  long long int x;
  // MR: Non e' detto che dim sia la lunghezza della stringa letta, e'
  // la lunghezza massima dell'array!
  x=convert_ric(source, dim, dim-1);
  return x;
}


long long int convert_ric(char *source, const unsigned int dim, int i){
  if(i>=0){
    // MR: Manca controllo che numero sia compreso tra 0 e 7, inoltre
    // essendo dim > strlen(source) viene costruito un valore errato
    // (e.g. negativo per 1001 che e' 513)
    return toInt(source[i])*power(8, dim-i-1)+convert_ric(source, dim, i-1);
  }
  else{
    return 0;
  }
}

long long int toInt(char c){
  // MR: Manca controllo che c sia compreso tra ´0' e '7'
  long long int x= c - '0';
  return x;
}
int power(int base, int exp) {
    if (exp != 0)
        return (base*power(base, exp-1));
    else
        return 1;
}
// Inserire qui sopra la definizione della funzione convert
