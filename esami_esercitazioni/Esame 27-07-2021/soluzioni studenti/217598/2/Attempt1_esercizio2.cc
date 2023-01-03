#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int funzione (int);
// Scrivere qui sopra la dichiarazione e definizione della funzione "funzione"

int main(int argc, char ** argv) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <positivenum> " << endl;
    exit(1);
  }
  int n = atoi(argv[1]);
  cout << "The read string is: " << argv[1] << endl;
  cout << "The converted value is: " << n << endl;
  cout << "function("<< n << ") = " << funzione(n) << endl;
}

int controlloCopie (int number) {
  // MR: A voler essere precisi, queste operazioni a parte count = 0,
  // potevano essere messe all'interno dell'if per farle solo se
  // necessario nell'ultima chiamata.
    int cifra = number % 10;
    int cifraAdiacente = (number / 10) % 10;
    int count = 0;
    if (number >= 10) {
        count = funzione (number / 10);
        if (cifra != cifraAdiacente) {
            count++;
        }
    }
    return count;
}

int funzione (int number) {
    int check;
    if (number >= 0) {
        check = controlloCopie (number);
    }
    else {
        check = 0;
    }
    return check;
}
