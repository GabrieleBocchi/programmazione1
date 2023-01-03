#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
int converti(char source[], int dim);
// Inserire qui sopra la dichiarazione della funzione convert
int conv(char source[], int dim, int i, int b);
int l(char source[], int i);
int p(int d, int b);

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

  long long int decimal = converti(number, maxdim);

  cout << "The converted number is: " << decimal << endl;
}

// Inserire qui sotto la definizione della funzione convert

int converti(char source[], int dim){

	dim = l(source, 0);
	cout << "dimensione "<< dim << endl;
	int b = p(dim, 8);
	cout << "base elevata alla potenza maggiore" << b << endl;
	return conv(source, dim, 0, b);

}

// Inserire qui sopra la definizione della funzione convert

int conv(char source[], int dim, int i, int b){

	if(source[i] == '\0') {cout << 0 << endl; return 0;}

	else{
		i++;
		cout << source[i-1] << "  ";
		cout << source[i-1]*b << endl;
		// MR: source[i-1] e' un carattere non un intero, e
		// '0' diverso da 0, infatti e' 48! Peccato perche'
		// idea era quasi corretta anche se poco
		// efficiente. Avrebbe dovuto mettere: (source[i-1] - '0')
		return source[i-1]*b + conv(source, dim, i ,b/8);
	}

}

int l(char source[], int i){
  // MR: Manca controllo che i < maxdim
	if(source[i] == '\0') return 0;
	else{
		i++;
		return 1 + l(source, i);
	}
}

int p(int dim, int b){

	dim--;
	if(dim<1) return 1;
	else	return b*p(dim, b);

}
