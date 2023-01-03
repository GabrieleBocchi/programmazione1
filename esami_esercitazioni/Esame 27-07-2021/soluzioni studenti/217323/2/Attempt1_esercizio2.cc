#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int lunghezza_rec(int n);
int funzione(int n);
void funzione_rec(int *v,int dim, int counter,int succ,int & result);
int * crearray(int n, int dim);
void crearray_rec(int * resval, int n,int dim,int counter);
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
int lunghezza_rec(int n){   //funzione che calcola la lunghezza del numero, più comodo da gestire
    if(n<10){
        return 1;
    }
    else return 1+lunghezza_rec(n/10);
}

int funzione(int n){
    int counter=0;
    int succ=1;
    int result=0;
    int dim=lunghezza_rec(n);
    int * v = crearray(n,dim);
    funzione_rec(v,dim,counter,succ,result);
    // MR: Manca deallocazione di v!!!
    return result;
}
//trasformo il numero in un array per poterlo scorrere meglio
int * crearray(int n, int dim){
    int * resval= new int[dim-1];
    crearray_rec(resval,n,dim,0);
    return resval;
}

void crearray_rec(int * resval,int n, int dim, int counter){
    if(counter<dim){
        if(n>0){
        resval[dim-counter-1]=n%10;
        crearray_rec(resval,n/10,dim,counter+1);
        }
    }
}

void funzione_rec(int *v,int dim, int counter,int succ,int & result){       //incremento il contatore se le cifre sono diverse
  // MR: Soluzione corretta, anche se contorta e poco efficiente
  // perche' non era necessario convertire in array di numeri, perche'
  // di fatto fa stesse operazioni molte volte.
    if(succ<dim){
        if(v[counter]!=v[succ]){
            result++;
        }
        funzione_rec(v,dim,counter+1,succ+1,result);
    }
}
