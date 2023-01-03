#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"

int funzione(int n){

  int risultato = 0;
  if(n > 0){
    if(n%10 != (n/10)%10 && n/10 != 0){
      risultato += funzione(n/10) +1;
    }else{
      risultato += funzione(n/10);
    }
  }
  else{
    // MR: perche' ritornare subito 0 e non risultato come fatto negli
    // altri casi?
    return 0;
  }

  return risultato;
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
