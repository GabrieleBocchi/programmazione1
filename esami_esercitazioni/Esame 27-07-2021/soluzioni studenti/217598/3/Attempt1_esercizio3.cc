#include <iostream>
#include <cstdlib>
using namespace std;

bool * init (int);
void add (bool *&, int, char *);
bool check (bool *&, int, char *);
void destroy (bool *&);

int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale
    int n = 255;

    bool* bloom_filter = init(n);

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

// SB: ok
bool * init (int dim) {
    bool * filter = new bool [dim];
    for (int i = 0; i < dim; i++) {
        filter[i] = false;
    }
    return filter;
}

void add (bool *& filter, int dim, char * parola) {
    int letter;
    for (int i = 0; parola[i] != '\0'; i++) {
        letter = parola[i];
        // SB: la condizione dovrebbe essere "if (letter >= dim)", essendo
        // ASCII, il valore non è mai oltre 255
        if (letter > 255) {
            while (letter > dim) {
                letter %= dim;
            }
        }
        if (filter[letter] != true) {
            filter[letter] = true;   
        }
    }
}

bool check (bool *& filter, int dim, char * parola) {
    bool presente = true;
    int letter;
    for (int i = 0; parola[i] != '\0' && presente; i++) {
        letter = parola[i];
        // SB: dovrebbe essere "if (filter[letter % n] != true) {"
        if (filter[letter] != true) {
            presente = false;
        }
    }
    return presente;
}

// SB: ok
void destroy (bool *& filter) {
    delete [] filter;
}