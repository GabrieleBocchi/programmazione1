#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int getPos(char *a);
long long int pow(int a, int n);
long long int convert(char * number, int maxdim);
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

long long int getPos(char *a){
  // MR: Manca controllo che non si ecceda dimensione dell'array!
    if(*a=='\0'){
        return 0;
    }else{
        return 1+getPos(++a);
    }
}

long long int pow(int a, int n){
    if(n==0){
        return 1;
    }else{
        return a*pow(a, --n);
    }
}

long long int convert(char * number, int maxdim){
  // MR: Un po' inefficiente perche' ad ogni ricorsione si calcola
  // ricorsivamente (per fortuna) la lunghezza della sottostringa!
    int pos=getPos(number)-1;
    // MR: Manca controllo che dimensione sia < maxdim!
    if(*number=='\0'){
        return 0;
    }else{
      // MR: Manca controllo che *number sia 0,1,2,3!
        long long int numero = *number-'0';
        return (numero*pow(4, pos))+convert(++number, --maxdim);
    }
}

// Inserire qui sopra la definizione della funzione convert
