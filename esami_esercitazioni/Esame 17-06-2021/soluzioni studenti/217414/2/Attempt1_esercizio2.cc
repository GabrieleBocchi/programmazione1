#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(char number[], int maxdim);
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

long long int pow(long long int num, long long int e){
  long long int ret = 1;
  if(e>0){
    ret = ret*num;
    e--;
    ret *= pow(num, e);
  }
  return ret;
}

int strlen(char buffer[], int i = 0){
  int ret = 0;
  if(buffer[i] != '\0'){
    ret+= 1;
    i++;
    ret+=strlen(buffer, i);
  }
  return ret;
}

long long int convert_aux(char number[], int dim, int i);

long long int convert(char number[], int maxdim){
  int dim = strlen(number);
  return convert_aux(number, dim, 0);
}

long long int convert_aux(char number[], int dim, int i){
  long long int ret = 0;
  long long int resto = 0;
  // MR: resto a cosa serve?
  int base = 4;
  if(number[i] != '\0'){
    // MR: Manca controllo che i < dim!, manca controllo che number[dim-i-1] sia 0,1,2,3!
    ret += ((long long int)(number[dim-i-1]-'0'))*pow(base,i);
    i++;
    ret += convert_aux(number, dim, i);
  }

  return ret;
}

// Inserire qui sopra la definizione della funzione convert
