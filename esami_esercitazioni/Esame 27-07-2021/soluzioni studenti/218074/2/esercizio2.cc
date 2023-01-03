#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int funzione(int n);
void dim_numero(int n, int &i);
void cifra_dispari(int n, int dim, int &conta);
int power(int base, int exp);
int cifra(int n, int dim);
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

int funzione(int n){
  // MR: Soluzione corretta, anche se diverse oeprazioni potevano
  // essere fatte in modo piu' semplice!
    int conta=0;
    if(n>=0){
        int dim=0;
        dim_numero(n, dim);
        cifra_dispari(n, dim, conta);
    }
    return conta;
}

void dim_numero(int n, int &i){
    if(n>=1){
        n=n/10;
        i=i+1;
        dim_numero(n, i);
    }
}

void cifra_dispari(int n, int dim, int& conta){
    if(dim>0){
        int dim2=dim;
        int c=cifra(n, dim);
        //int c2=cifra(n, dim2-1);
        //cout<<c<<"- "<<c2<<endl;
        if(c%2!=0){
            if(cifra(n, dim-1)%2!=0){
                conta++;
            }
        }

        cifra_dispari(n, dim-1, conta);
    }
}

int cifra(int n, int dim){
    if(dim>0){
        int x = n%power(10,dim);
        x = x/power(10,dim-1);
        return x;
    }
    else{ return 0;}
}

int power(int base, int exp) {
    if (exp != 0)
        return (base*power(base, exp-1));
    else
        return 1;
}
