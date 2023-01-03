#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(char number[], int maxdim, int i = 0);
long long int power(long long int base, long long int exp);
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
long long int convert(char number[], int maxdim, int i){
  // L'array e' cosi' convertito in modo inverso, quindi 1000 e' visto
  // come 1 invece che come 4096!
  long long int num = 0;
  if(number[i] == '\0' || i >= maxdim) return num;
  if(number[i] >= '0' && number[i] <= '9'){
    num = int(number[i]-'0') * power(16, i);
  }
  else{
    num = int(number[i] - 'a' + 10) * power(16, i);
  }
  return num + convert(number, maxdim, i+1);
}

long long int power(long long int base, long long int exp){
  // MR: se exp < 0 va in ricorsione infinita
  if(exp == 0) return 1;
  return base * power(base, exp-1);
}

// Inserire qui sopra la definizione della funzione convert
