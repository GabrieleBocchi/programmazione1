#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert

long long int convert(char n[], int dim);
long long int convert_rec (char n[], int dim, int i);
long long int pot (int a, int esp);
int strlen (char n[], int i);

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

long long int convert(char n[], int dim){

  int lunghezza = strlen (n, 0);

  return (convert_rec (n, lunghezza, 0));
}

long long int convert_rec (char n[], int dim, int i){

  long long int res = 0;

  if (n[i] == '\0'){
    res += 0;
  }

  else{
   char a = n[i];
   // MR: Manca controllo che a sia 0,1,2,3!
   res = ((int) a - '0') * pot (4, (dim-1)-i) + convert_rec (n, dim, i+1);

  }

  return res;
}

long long int pot (int a, int esp){
  long long res;

  if (esp == 0){
    res = 1;
  }

  else{
    res = a * pot (a, esp-1);
  }

  return res;
}

int strlen (char n[], int i){

  int res = 0;
  // MR: Manca controllo che i < maxdim!
  if (n[i] == '\0'){
    res += 0;
  }

  else {
    res = 1 + strlen (n, i+1);
  }



  return res;
}



// Inserire qui sopra la definizione della funzione convert
