#include <iostream>

using namespace std;


bool* create(int n);
void add(bool* bloom_filter, int n, char* parola);
bool control(bool* bloom_filter, int n, char* parola);
void destroy(bool* bloom_filter);

int indice_con_modulo (int indice, int n);


int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale
    int n = 255;

    bool* bloom_filter = create(n);

    char ciao[] = { 'c', 'i', 'a', 'o', '\0' };     
    add(bloom_filter, n, ciao);
    cout << "Ho inserito la parola 'ciao' nel bloom filter" << endl;
    
    if (control(bloom_filter, n, ciao)) {
        cout << "La parola 'ciao' è presente nel bloom filter " << endl;
    } else {
        cout << "La parola 'ciao' NON è presente nel bloom filter " << endl;
    }

    char volo[] = { 'v', 'o', 'l', 'o', '\0' }; 
    if (control(bloom_filter, n, volo)) {
        cout << "La parola 'volo' è presente nel bloom filter " << endl;
    } else {
        cout << "La parola 'volo' NON è presente nel bloom filter " << endl;
    }

    destroy(bloom_filter);

    return 0;
}


bool* create (int n) {
    return new bool[n]();
}


void add(bool* bloom_filter, int n, char* parola) {
    char temp = parola[0];
    int i = 0;
    while (temp != '\0') {
        bloom_filter[indice_con_modulo((int)temp, n)] = true;
        i++;
        temp = parola[i];
    }
}


bool control(bool* bloom_filter, int n, char* parola) {
    char temp = parola[0];
    int i = 0;
    bool tutte_le_celle_sono_1 = true;
    while (temp != '\0' && tutte_le_celle_sono_1) {
        if (bloom_filter[indice_con_modulo((int)temp, n)] != true) {
            tutte_le_celle_sono_1 = false;
        }
        i++;
        temp = parola[i];
    }
    return tutte_le_celle_sono_1;
}


void destroy(bool* bloom_filter) {
    delete[] bloom_filter;
}


int indice_con_modulo (int indice, int n) {
    while (indice >= n) {
        indice = indice % n;
    }
    return indice;
}