#include <iostream>

using namespace std;

bool * init(int & numero);
bool add(bool * bloom_filter, int n, char * parola);
bool check(bool * bloom_filter, int n, char * parola);
bool destroy(bool * bloom_filter);

int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale
    int n = 255;

    bool * bloom_filter = init(n);

    char ciao[] = { 'c', 'i', 'a', 'o', '\0' };     
    add(bloom_filter, n, ciao);
    cout << "Ho inserito la parola 'ciao' nel bloom filter" << endl;
    
    if (check(bloom_filter, n, ciao)) {
        cout << "La parola 'ciao' è presente nel bloom filter " << endl;
    } else {
        cout << "La parola 'ciao' NON è presente nel bloom filter " << endl;
    }

    char volo[] = { 'v', 'o', 'l', 'o', '\0' }; 
    if (check(bloom_filter, n, volo)) {
      cout << "La parola 'volo' è presente nel bloom filter " << endl;
    } else {
      cout << "La parola 'volo' NON è presente nel bloom filter " << endl;
    }

    destroy(bloom_filter);

    return 0;
}

// SB: l'array dev'essere creato dinamicamente con la keyword "new"
bool * init(int & numero) {
  bool * array[numero];
  int contatore = numero;
  for (int i=0; i<numero; i++) {
    return array[i];
  }
  return array[0];
}

// SB: la funzione add non deve ritornare un valore
bool add(bool * bloom_filter, int n, char * parola) {
  // SB: "i<n" è una condizione errata, non sono state fatte 
  // assunzioni sulla lunghezza della stringa da inserire
  for (int i=0; i<n; i++) {
    // SB: per considerare casi in cui il valore ASCII del carattere è maggiore di n, 
    // è necessario fare il modulo => "int n_ascii = (int)parola[i] % n;"
    int n_ascii = (int)parola[i];
    if (n_ascii<= n) bloom_filter[n_ascii] = 1;
  }
  return true;
}

bool check(bool * bloom_filter, int n, char * parola) {
  // SB: "i<n" è una condizione errata, non sono state fatte 
  // assunzioni sulla lunghezza della stringa da inserire
  for (int i=0; i<n; i++) {
    if (bloom_filter[i] == 1) return false;
  }
  return true;
}

// SB: la funzione delete non deve ritornare un valore
bool destroy(bool * bloom_filter) {
  // SB: la deallocazione avviene con l'istruzione "delete [] bloom_filter"
  while (bloom_filter != NULL) {
    delete bloom_filter;
  }
  return true;
}