#include <cstdlib>
#include <iostream>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int funzione(int n);
// Scrivere qui sopra la dichiarazione e definizione della funzione "funzione"

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <positivenum> " << endl;
        exit(1);
    }
    int n = atoi(argv[1]);
    cout << "The read string is: " << argv[1] << endl;
    cout << "The converted value is: " << n << endl;
    cout << "function(" << n << ") = " << endl << funzione(n) << endl;
}

int funzione(int n) {
    // estraggo la prima e la seconda cifra decimale
    int firstDigit = n % 10, secondDigit = (n % 100) / 10, counter = 0;

  
    // escludo il caso in cui rimane solo una cifra decimale e il caso in cui il numero sia negativo
    if (n > 9) {
        // verifico che le due cifre estratte siano pari, e richiamo la funzione
        // shiftando i numeri di una posizione a destra
        if (firstDigit % 2 == 0 && secondDigit % 2 == 0) {
            counter = 1 + funzione(n / 10);
        } else {
            counter = funzione(n / 10);
        }
    }
    return counter;
}