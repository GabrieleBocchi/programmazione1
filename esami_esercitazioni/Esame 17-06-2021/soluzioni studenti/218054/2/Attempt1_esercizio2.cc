#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert

// Inserire qui sopra la dichiarazione della funzione convert

long long int convert(char source[], int max_dim);
long long int convert_aus(char source[], int max_dim, int i ,int & mol,int base);


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

bool controlla(char * num, const int maxdim, const unsigned int base = 2) {
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
long long int convert(char source[], int max_dim){
  int mol = 1;

  long long int res = convert_aus(source,max_dim,0,mol,2);

  return res;
}

long long int convert_aus(char source[], int max_dim, int i ,int & mol, int base){
  long long int res = 0;

  if(source[i] == '\0'){
    // MR: Manca controllo che i < max_dim!
    return 0;
  }else{
    //cout << mol << endl;
    //return( convert_aus(source,max_dim,++i,mol,base) + ((source[i] - '0') * mol ) );

    // MR: Ok, ma cosa succede se chiamo con "021"? Viene trappato
    // prima dal main, ma la funzione non controlla.
    int s = source[i] - '0';
    res = convert_aus(source,max_dim,++i,mol,base) + (s * mol );
    mol = mol * base;
    //cout << source[i] - '0' << endl;
    return res;
  }

}
