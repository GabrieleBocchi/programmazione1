#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int funzione(int n, int precedente, int * count){
  // MR: Questo e' pi C like invece che C++, infatti avrebbe potuto
  // passare count per riferimento invece che come puntatore! Inoltre,
  // se passato per puntatore, perche' poi ritornarlo?

  // MR: Grave perche' ha cambiato il main (NON LO DOVEVA FARE) e ha
  // cambiato la segnatura della funzione che nel testo diceva
  // esplicitamente che aveva come unico argomento un intero! Poteva
  // wrappare la sua funzione in una che rispettava quanto previsto
  // nel testo dell'esame e sarebbe andata bene! Sono magnanimo, e
  // considero 50% del voto, anche se avrei dovuto considerare 0
  // perche' non rispecchia completamente quanto chiesto! Se le
  // chiedono una funzione che ha una certa API non può cambiarla!
  // All'interno può fare quasi quello che vuole se i requisiti lo
  // consentono, ma l'API NON puo' essere cambiata!
    if(n < 0){
        *count = 0;
    }else if(precedente < 0){
      // MR: Queste operazioni sono analoghe a quelle fatte sotto, si
      // poteva scrivere in modo piu' fattorizzato.
        int attuale = n % 10;
        n = n / 10;

        funzione(n, attuale, count);
    }else if(n > 0){
        int attuale = n % 10;
        n = n / 10;

        if(precedente != attuale){
            *count = *count + 1;
        }

        funzione(n, attuale, count);
    }

    return *count;
}
// Scrivere qui sopra la dichiarazione e definizione della funzione "funzione"

int main(int argc, char ** argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <positivenum> " << std::endl;
        exit(1);
    }
    int n = atoi(argv[1]);
    int count = 0;

    std::cout << "The read string is: " << argv[1] << std::endl;
    std::cout << "The converted value is: " << n << std::endl;
    std::cout << "function("<< n << ") = " << funzione(n, -1, &count) << std::endl;
}
