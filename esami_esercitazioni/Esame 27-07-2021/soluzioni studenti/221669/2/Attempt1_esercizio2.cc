#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int f(int n); //Rinominata come richiesto dal docente
// Scrivere qui sopra la dichiarazione e definizione della funzione "funzione"
int funzione_aux(int n, int prec);
int controllo(int n);

int main(int argc, char ** argv) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <positivenum> " << std::endl;
    exit(1);
  }
  int n = atoi(argv[1]);
  std::cout << "The read string is: " << argv[1] << std::endl;
  std::cout << "The converted value is: " << n << std::endl;
  std::cout << "function("<< n << ") = " << f(n) << std::endl;
}

int controllo(int n){ //è una funzione per controllare che il numero non contenga lettere, in realtà è superflua perchè atoi gestisce il problema.
  int returnValue = 0;
  if(n == 0){
    returnValue = 0;
  }
  else{
    int a = n%10;
    if(a >= 0 && a <= 9){
      returnValue = 0+controllo(n/10);
    }
    else{
      returnValue = 1+controllo(n/10);
    }
  }
  return returnValue;
}

int f(int n){
  int returnValue = 0;

  if(controllo(n) == 0){
    returnValue = funzione_aux(n,-1);
  }

  return returnValue;
}

int funzione_aux(int n, int prec){
  int returnValue = 0;
  if(n <= 0){
    returnValue = 0;
  }
  else{
    int a = n%10;
    if(a == prec){
      returnValue = 1;
      returnValue = returnValue+funzione_aux(n/10,a);
      // MR: Sarebbe stato leggermente piu' efficiente returnValue = 1
      // + funzione_aux(n/10,a) evitando assegnamento precedente, ma
      // sono minime cose
    }
    else{
      returnValue = returnValue+funzione_aux(n/10,a);
    }
  }
  return returnValue;
}
