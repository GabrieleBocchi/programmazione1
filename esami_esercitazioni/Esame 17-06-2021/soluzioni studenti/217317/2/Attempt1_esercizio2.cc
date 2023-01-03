#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert
long long int convert(char* n,int dim);
long long int aux(char *n,int dim,int i);
long long int potenza(int b,int e);
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
  // MR: Qui la base doveva essere modificata in mod che fosse 2, come
  // specificato nel testo!
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

long long int potenza(int b,int e){
  if(e==0){
      return 1;
   }
   else{
      return b*potenza(b,e-1);
   }
}

long long int convert(char* n,int dim){
  return aux(n,dim,0);
}

long long int aux(char *n,int dim,int i){
  if(n[i]=='\0'){
      return 0;
   }
   long long int tmp=(n[i]=='0')?0:1;
   // MR: il controllo solo per n[i] == '0' non e' sufficinte, infatti
   // se per caso in input metto un carattere 2, questo e'
   // interpretato come 1.
   // MR: Manca controllo che i < dim!
   tmp=tmp*potenza(2,i);
   // MR: la stringa e' interpretata in modo contrario, infatti 1000
   // in base 2 che corrisponde ad 8 in base 10, nel suo caso viene
   // convertito erroneamente in 1!
   return tmp+aux(n,dim,i+1);
}
// Inserire qui sopra la definizione della funzione convert
