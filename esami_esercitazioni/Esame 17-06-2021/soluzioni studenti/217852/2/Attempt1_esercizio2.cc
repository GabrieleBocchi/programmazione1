#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione convert

long long int convert(char num[], int dimx);
void convertAux(char num[], int i, long long int &ris, int cont);
long long int potenza(int b, int i);
int conta(char num[], int i);

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
	    ((n >= 'A') && (n <= 'F')) ||
	    ((n >= 'a') && (n <= 'f')));
  default:
    return false;
  }
}

bool controlla(char * num, const int maxdim, const unsigned int base = 16) {
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

long long int convert(char num[], int dimx){

	int i=0;
	long long int ris=0;
	int cont=0;
	i=conta(num, i);
	convertAux(num, i-1, ris, cont);

	return ris;
}

void convertAux(char num[], int i, long long int &ris, int cont){
	long long int r;
	long long int aux;
	int def='a'-10;
	// MR: Manca controllo che se non in 0-9 sia in a-f.
	if(i<0){
		return;
	}else{
	  // MR: Manca controllo che i sia < maxdim
		if(num[i]>='a' && num[i]<='f'){
			r=num[i]-def;
		//}else if(num[i] >= 'a' && num[i] <= 'f'){
			//r=num[i]-('A'-10);
		}else{
		  r=num[i]-('9'-9); // MR: bastava num[i] - '0'
		}
		convertAux(num, i-1, ris, cont+1);
		aux=r*potenza(16, cont);
		ris=ris+aux;
	}
}

long long int potenza(int n, int i){
  // MR: Se chiamato con i < 0 va in ricorsione infinita
	if(i==0)
		return 1;
	else{
		return n*potenza(n, i-1);
	}
}

int conta(char num[], int i){
  // MR: Manca controllo i < maxdim, se manca \0 va in ricorsione infinita
	if(num[i]=='\0'){
		return i;
	}else{
		i++;
		return conta(num, i);
	}
}

// Inserire qui sopra la definizione della funzione convert
