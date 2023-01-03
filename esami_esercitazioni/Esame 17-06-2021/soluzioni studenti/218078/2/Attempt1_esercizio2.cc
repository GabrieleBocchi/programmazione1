#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(char* source, const int dim);

long long int convert_aux(char* source, const int dim, int i=0);

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
  if (!controlla(number, maxdim, 2)) { // HO AGGIUNTO PERSONALMENTE , 2
    cout << "Il numero deve contenere solo caratteri rispetto alla base" << endl;
    exit(1);
  }

  long long int decimal = convert(number, maxdim);

  cout << "The converted number is: " << decimal << endl;
}

// Inserire qui sotto la definizione della funzione convert
long long int pow(const int base, int exp){
    if (exp < 0){
        pow(base, -exp);
    } else if (exp > 0){
        return base * pow(base, exp-1);
    }
    return 1; //base case, when exp==0;
}

int strlen(char* source, int i=0){
  // MR: Per completezza si dovrebbe verificare che i < maxDim onde
  // evitare di andare out of bound se l'array non terminato con \0
    if (source[i] != '\0')
        return strlen(source, i+1);
    else {
        return i;
    }
}

long long int convert(char* source, const int dim){ // dim == maxdim
    int arrayDim = strlen(source);
    return convert_aux(source, arrayDim, 0);
}

long long int convert_aux(char* source, const int dim, int i){ //dim == actual dim, calculated by strlen()
    if (source[i] != '\0'){
      // MR: Ok, ma sarebbe meglio controllo che i < dim! Inoltre, che
      // source[i] sia effettivamente o 0 o 1!
        int target = source[i++] - '0';
        cout << target << endl;
        //cout << dim-i << endl;
        return pow(2, dim-i)*target + convert_aux(source, dim, i);
    }
    return 0;
}

// Inserire qui sopra la definizione della funzione convert
