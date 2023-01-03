#include <iostream>

using namespace std;

bool *init(int n);
void add(bool *&bloomFilter, int size, char word[]);
bool check(bool *bloomFilter, int size, char word[]);
void destroy(bool *&bloomFilter);

int length(char word[]);

int main(int argc, char *argv[]) {
    // Se modificate la funzione "main", ricordarsi poi di ripristinare il
    // codice originale
    int n = 255;

    bool *bloom_filter = init(n);

    char ciao[] = {'c', 'i', 'a', 'o', '\0'};
    add(bloom_filter, n, ciao);
    cout << "Ho inserito la parola 'ciao' nel bloom filter" << endl;

    if (check(bloom_filter, n, ciao)) {
        cout << "La parola 'ciao' è presente nel bloom filter " << endl;
    } else {
        cout << "La parola 'ciao' NON è presente nel bloom filter " << endl;
    }

    char volo[] = {'v', 'o', 'l', 'o', '\0'};
    if (check(bloom_filter, n, volo)) {
        cout << "La parola 'volo' è presente nel bloom filter " << endl;
    } else {
        cout << "La parola 'volo' NON è presente nel bloom filter " << endl;
    }

    destroy(bloom_filter);

    return 0;
}


// inizializzo un puntatore di dimensione n
bool *init(int n) {

    // SB: l'istruzione dovrebbe essere "return new bool[n]();",
    // l'istruzione sotto crea in memoria una singola variabile di
    // tipo carattere con il valore di n, in questo caso 255 
    bool *filter = new bool(n);

    return filter;
}

// SB: ok
// scorro la parola e in base al modulo della dimensione del filtro, setto a
// true cella corrispondente alla lettera
void add(bool *&bloomFilter, int size, char word[]) {
    for (int i = 0; i < length(word); i++) {
        bloomFilter[((int)word[i]) % size] = true;
    }
}

// SB: ok
// setto la variabile di uscita a true ed eseguo il controllo. nel momento che
// trovo una lettera che non fa parte del filtro imposto la variabile d'uscita a
// false
bool check(bool *bloomFilter, int size, char word[]) {
    bool res = true;
    for (int i = 0; i < length(word); i++) {
        if (!bloomFilter[((int)word[i]) % size]) {
            res = false;
        }
    }
    return res;
}

// SB: dovrebbe essere "delete [] bloomFilter"
void destroy(bool *&bloomFilter) { delete bloomFilter; }

//utilizzo questa funzione aggiuntiva per calcolare le dimensioni dell'array di caratteri dato
int length(char word[]) {
    int counter = 0;
    while (word[counter] != '\0') {
        counter++;
    }
    return counter;
}