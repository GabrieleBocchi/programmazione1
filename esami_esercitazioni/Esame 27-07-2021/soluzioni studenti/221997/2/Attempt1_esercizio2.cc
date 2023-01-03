#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int funzioneRic(int n, int precedente, int contatore){
    if( n == 0){
        return contatore;
    }
    else{
      // MR: Corretto, però avrebbe potuto fare controllo e se uguale
      // incrementare contatore, e fare poi le operazioni di modifica
      // di precedente e n che sono uguali in entrambi i branch!
        if(precedente == n%10){
            precedente = n%10;
            n = n/10;
            return funzioneRic(n, precedente, contatore+1);
        }
        else{
            precedente = n%10;
            n = n/10;
            return funzioneRic(n, precedente, contatore);
        }
    }
}
int funzione(int n){
    int precedente = 10; //così da non trovare mai coppie con la prima cifra
    if(n < 0)
        return 0;
    else
        return funzioneRic(n, precedente, 0);
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
