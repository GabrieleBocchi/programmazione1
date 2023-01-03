#include <iostream>

using namespace std;

// SB: ok
bool* init(int n) {
    bool* array = new bool[n];
    for (int i = 0; i < n;i++) {
        array[i] = false;
    }
    return array;
}

// SB: ok
void add(bool* filter, int n, char* array) {
    int i = 0;
    while (array[i] != '\0') {
        int cella = int(array[i]) % n;
        if (filter[cella] == false) {
            filter[cella] = true;
        }
        i++;
    }
}

// SB: ok
bool check(bool* filter, int n, char* array) {
    bool retval = true;
    int i = 0;
    while (array[i] != '\0') {
        int cella = int(array[i]) % n;
        if (filter[cella] == false) {
            return false;
        }
        i++;
    }
    return true;
}

// SB: l'istruzione di delete è sufficiente per l'intero array, 
// non bisogna deallocare ogni cella
void destroy(bool* filter) {
    int i = 0;
    while (filter[i] != NULL) {
        delete& filter[i];
        i++;
    }
    delete filter;
}

int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale
    int n = 255;

    bool* bloom_filter = init(n);

    char ciao[] = { 'c', 'i', 'a', 'o', '\0' };

    add(bloom_filter, n, ciao);
    cout << "Ho inserito la parola 'ciao' nel bloom filter" << endl;

    if (check(bloom_filter, n, ciao)) {
        cout << "La parola 'ciao' è presente nel bloom filter " << endl;
    }
    else {
        cout << "La parola 'ciao' NON è presente nel bloom filter " << endl;
    }

    char volo[] = { 'v', 'o', 'l', 'o', '\0' };

    if (check(bloom_filter, n, volo)) {
        cout << "La parola 'volo' è presente nel bloom filter " << endl;
    }
    else {
        cout << "La parola 'volo' NON è presente nel bloom filter " << endl;
    }

    destroy(bloom_filter);
    return 0;
}