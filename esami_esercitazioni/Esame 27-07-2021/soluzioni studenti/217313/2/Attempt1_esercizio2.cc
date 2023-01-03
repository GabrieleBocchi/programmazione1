#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"

int funzione(int n){
  int c=0;
  if(n<0){
    c=-1;
  }
  else{
    int num=n%10;
    n=n/10;
    if(num==n%10 && n%10!=0){
      // MR: Cosa succede quando entra qui? c non viene modificato, e
      // ritorna 0, perdendo il risultato delle chiamate
      // successive. E.g. se passa come numero da analizzare: 101101
      // ottiene con suo codice 2 invece che il valore corretto 4. Se
      // avesse fatto c = funzione(n) il risultato sarebbe stato
      // corretto.
      funzione(n);
    }
    else if(n!=0){
      c=1+funzione(n);
    }
  }
  return c;
}


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
