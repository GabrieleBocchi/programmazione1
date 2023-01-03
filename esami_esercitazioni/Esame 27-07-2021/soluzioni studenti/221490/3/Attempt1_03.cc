#include <iostream>

using namespace std;

bool *init(int);
void insert(bool *, int, char[]);
bool check(bool*, int, char []);
void deinit(bool *);

// funzioni ausiliare per la lunghezza di un array di char
int len(char[]);

int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale
    int n = 255;

    bool* bloom_filter = init(n);
    
    char ciao[] = { 'c', 'i', 'a', 'o', '\0' };
    insert(bloom_filter, n, ciao);
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

    deinit(bloom_filter);

    return 0;
}

// SB: ok
bool * init(int n) {
  bool *tmp = new bool[n];
  // SB: evitare di porre istruzione condizionale e corpo nella stessa riga.
  for (int i = 0; i < n; i++) tmp[i] = false;
  return tmp;
}

void insert (bool *bloom, int n, char parola[]) {
  // SB: evitare di porre istruzione condizionale e corpo nella stessa riga.
  // SB: "parola[i]-'a'" può essere maggiore della dimensione dell'array, per 
  // esempio se n = 10 e parola[i] = 'z'. Questo conduce a scrivere fuori dall'array.
  // Seppur non originando spesso errori, questo è un comportamento indefinito.
  // Il calcolo dell'indice corretto è "(int) parola[i] % n".
  for (int i = 0; i < len(parola); i++) bloom[parola[i]-'a'] = true;
}

bool check(bool* bloom, int n, char parola[]) {
  bool rtn = true;
  for (int i = 0; i < len(parola); i++)
    // SB: evitare di porre istruzione condizionale e corpo nella stessa riga.
    // SB: stesso errore della funzione "insert"
    if (!bloom[parola[i]-'a']) rtn = false;
  return rtn;
}

// SB: ok
void deinit(bool *bloom) {
  delete[] bloom;
}

int len(char parola[]) {
  char c = ' ';
  int i = -1;
  while (c!='\0') {
    i += 1;
    c = parola[i];
  }
  return i;
}
