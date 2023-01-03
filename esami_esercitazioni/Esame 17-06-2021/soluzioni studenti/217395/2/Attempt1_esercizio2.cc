//Pivetta Leonardo mat. 217395
#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convertAux(char* source, int & maxDim);
long long int convert(char* source, int maxDim);
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

bool controlla(char * num, const int maxdim, const unsigned int base = 2) {
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

long long int pow2(int n){
  if(n == 0) return 1;
  return 2*pow2(--n);
}

long long int convert(char* source, int maxDim){
  int tmp = maxDim;
  return convertAux(source, tmp);
}

long long int convertAux(char* source, int & maxDim){
  if(*source == '\0' || maxDim == 0){
    return 0;
  };
  int digit = *source -'0';
  // MR: Ok, ma sta assumendo che il carattere sia 0 o 1
  int curMax = maxDim;
  // MR: Ok, ma come detto a lezioni e' consigliabile non fare side
  // effect su argomenti passati per riferimento (e.g. maxDim qui).
  int res = convertAux(++source, --maxDim);
  return res +(digit*(pow2(curMax-maxDim-1)));
}

// Inserire qui sopra la definizione della funzione convert
