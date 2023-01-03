#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(char num[], unsigned int max);
long long int convert_aux(char num[], unsigned int max, int i, int& esp);
long long int pow(int base, int esp);
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
long long int convert(char num[], unsigned int max){
    int esp = 0;
    return  convert_aux(num, max, 0, esp);
}

long long int pow(int base, int esp){
    if(esp == 0)
        return 1;
    else
        return base * pow(base, esp-1);
}

long long int convert_aux(char num[], unsigned int max, int i, int& esp){
    long long int val;
    if((i < max) && (num[i] != '\0')){ // MR: sta confrontando un unsigned int con un int
      // MR: Manca controllo che num[i] sia 0, ..., 7
        val = num[i] - '0';
        cout << val << endl;
        int somma = convert_aux(num, max, i+1, esp);
        val = (val * pow(8, (esp - i))) + somma;
    }
    else{
        esp = i-1;
        val = 0;
    }
        cout << val << " e " << esp << " e " << i<< endl;

    return val;
}

// Inserire qui sopra la definizione della funzione convert
