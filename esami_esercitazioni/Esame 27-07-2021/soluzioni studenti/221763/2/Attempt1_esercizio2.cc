#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int funzioneAus(int n, int prec, int nCoppie) {
    if (n < 0) {
        return 0;
    }
    else if (n > 0) {
        if (n % 10 != prec) {
            nCoppie++;
        }
        funzioneAus(n / 10, n % 10, nCoppie);
	// MR: Che cosa ritorna in questo caso? Manca il return, e per
	// caso nCoppie e' ultimo valore sullo stack, e quindi ritorna
	// quello ma solo per caso! Questo e' comunque un errore
	// abbastanza grave! Solo per caso il valore ritornato e'
	// corretto. Il compilatore segnalava che
	// Attempt1_esercizio2.cc: In function ‘int funzioneAus(int, int, int)’:
	// Attempt1_esercizio2.cc:20:1: warning: control reaches end of non-void function
    }
    else {
        return nCoppie;
    }
}

int funzione(int n) {

    return funzioneAus(n, n % 10, 0);
}
// Scrivere qui sopra la dichiarazione e definizione della funzione "funzione"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <positivenum> " << std::endl;
        exit(1);
    }
    int n = atoi(argv[1]);
    std::cout << "The read string is: " << argv[1] << std::endl;
    std::cout << "The converted value is: " << n << std::endl;
    std::cout << "function(" << n << ") = " << funzione(n) << std::endl;
}
