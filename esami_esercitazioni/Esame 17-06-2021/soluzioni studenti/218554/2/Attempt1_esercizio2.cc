#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert

// Inserire qui sopra la dichiarazione della funzione convert

long long int convert(char array[], int dim);
long long int convert_ric(char array[], int dim, int i);

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


// Inserire qui sopra la definizione della funzione convert

long long int convert(char array[], int dim){
  int i = 0;

  int contatore = 0;
  // MR: Qui le due variabilu sopra sono inutili!
  return (convert_ric(array, dim, 0));
}

long long int convert_ric(char array[], int dim, int i){

  if(array[i] == '\0' || dim>100){
    // MR: Come puo' modificare dim? Cosa succede se i >= dim?
    return 0;
  }else{

    long long int n;
    long long int risultato;

    if(array[i] == '0'){
      n = 0;
    }else if(array[i] == '1'){
      n = 1;
    }else if(array[i] == '2'){
      n = 2;
    }else if(array[i] == '3'){
      n = 3;
    }
    // MR: Che succede se non e' 0,1,2,3?
    // MR: Che succede se i >= maxdim?
    if(array[i+1]=='\0'){
      risultato = n;
    }else{
      risultato = n*(4^i);
      // MR: Mi spiace ma la potenza in c++ non e' ^ ma va calcolata!
      // Questo operatore cosi' come scritto fa lo xor bit a bit
    }

    return (risultato + convert_ric(array,dim,i+1));
  }
}
