#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert

long long int convert(char* str, int maxdim);

int getI(int a){
  // MR: Non chiara la logica!
  int tmp = a&(-a);

  return tmp;
}

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

long long int convert(char* str, int maxdim){
  // MR: Manca controllo che dimensione sia < maxdim!
  if(*str == '\0'){
    return 0;
  }
  else{
    long long int tmp = convert(str+1,maxdim);
    int i = getI(tmp);
    // Qui la base e' 4, non 2! Inoltre qualunque valore che non sia 0*1 o 0 e' scorretto!
    if(i == 0)
      i++;
    else
      i<<=2;
    // Manca controllo che *str sia 0, 1, 2, 3!
    return ((*str - '0')*i) + tmp;
  }
}


// Inserire qui sopra la definizione della funzione convert
