#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"

int coppia(int n) {
  int n1 = n%10, n2 = n/10;
  return n1==n2;
}

int funzione(int n) {
  // MR: Manca controllo che n sia < 0 per ritornare 0, infatti se la
  // lancia con -11 ritorna erroneamente 1 invece che 0 come
  // specificato nel testo.
  if (n/10 == 0) { return 0; }
  else {
    // MR: Soluzione corretta, ma fa un sacco di operazioni che
    // potevano essere eliminate facendone solo le necessarie
    // (e.g. qui per chiamare coppia fa modulo 100, poi in coppia fa
    // modulo e diviso, e comparison, poi fa diviso 10 due volte. Non
    // e' penalita', ma solo fare notare che si potevano evitare
    if (coppia(n%100)) return 1+funzione(n/10);
    else return funzione(n/10);
  }
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
