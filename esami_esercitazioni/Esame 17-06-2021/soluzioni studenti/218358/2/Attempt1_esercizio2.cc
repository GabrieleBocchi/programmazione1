#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(char * number, int maxdim);
long long int convert_aux(char * number, int maxdim, int &i);
long long int pow(int base, int number);
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

long long int convert(char * number, int maxdim){
  int i = 0;
  return convert_aux(number, maxdim, i);
}
// Inserire qui sopra la definizione della funzione convert

long long int convert_aux(char * number, int maxdim, int &i){
  long long int returnValue = 0;
  int p = i;
  if(number[p] != '\0' || p == maxdim-1){
    i++;
    // MR: Manca controllo che number[p] sia compreso tra 0 e 7
    returnValue = convert_aux(number, maxdim,i)+(long long int)(number[p]-'0') * pow(8,i-p) ;
  }
  return  returnValue;
}

long long int pow(int base, int number){ //funzione ricorsiva per il calcolo della potenza
  int returnValue = 1;
  if(number != 1){
    returnValue =  base * pow(base, number -1);
  }
  return returnValue;
}
