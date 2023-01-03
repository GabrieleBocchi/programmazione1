#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"

int funzione(int n);
int conta(int n);
void aux(int n, int m, int &cont, int i);
void riempi(int vet[], int n, int m);

// Scrivere qui sopra la dichiarazione e definizione della funzione "funzione"

int main(int argc, char ** argv) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <positivenum> " << std::endl;
    exit(1);
  }
  int n = atoi(argv[1]);
  std::cout << "The read string is: " << argv[1] << std::endl;
  std::cout << "The converted value is: " << n << std::endl;
  std::cout << "function("<< n << ") = " << funzione(n) << std::endl;
}

int conta(int n){
	if(n/10==0)
		return 1;
	else
		return 1+conta(n/10);
}

void aux(int vet[], int m, int &cont, int i){

	if(i==m-1)
		return;
	else{
		if(vet[i]%2!=0 && i<m-1){
			if(vet[i]==vet[i+1] || vet[i+1]%2!=0)
				cont++;
		}
		return aux(vet, m, cont, i+1);
	}
}

void riempi(int vet[], int n, int m){
	int a;
	if(m<0)
		return;
	else{
		a=n%10;
		vet[m]=a;
		// MR: qui per essere precisi avrebbe dovuto fare la
		// chiamata a riempi, e poi il return!
		return riempi(vet, n/10, m-1);
	}
}

int funzione(int n){
  // MR: Soluzione contorta, non era necessario array di suspporto, ma
  // anche se inefficiente corretta!
	int m=0;
	m=conta(n);
	int vet[m];
	int contD=0;

	if(n<=0 || m<=1)
		contD=0;
	else{

		riempi(vet, n, m-1);
		aux(vet, m, contD, 0);

	}

	return contD;
}
