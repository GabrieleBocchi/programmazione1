#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int funzione(int n);
int funzione_rec(int n, int precedente, int contatore);

int funzione(int n) {

  int ret = 0;
  
  if (n<0) {
    ret = 0;
  }
  else {
    ret = funzione_rec(n,-1, 0);
  }
  
  return ret;
}

int funzione_rec(int n, int precedente, int contatore) {

  int ret = 0;
  
  if (n == 0) {
    ret = contatore;
  }
  else {

    int attuale;
    attuale = n%10;

    if (attuale == precedente)
      contatore++;
    
    precedente = attuale;
    n /= 10;
    
    ret = funzione_rec(n, precedente, contatore);
  }
  
  return ret;
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

