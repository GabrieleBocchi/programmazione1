#include <iostream>

using namespace std;


bool* create(int n);
void add(bool* bloom_filter, int n, char* c);
bool control(bool* bloom_filter, int n, char* c);
void destroy(bool* bloom_filter);
int strlen(char* c);


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

// SB: ok
bool* create(int n) {
    bool* ret = new bool[n];
    for(int i=0; i<n; i++) {
        ret[i] = false;
    }
    return ret;
}

void add(bool* bloom_filter, int n, char* c) {
    int i=0;
    // SB: "i<n" è una condizione errata, non sono state fatte 
    // assunzioni sulla lunghezza della stringa da inserire
    while(i < n && c[i] != '\0') {
        if(bloom_filter[int(c[i])%n] != true) {
            bloom_filter[int(c[i])%n] = true;
        }
        i++;
    }
}

// SB: ok
bool control(bool* bloom_filter, int n, char* c) {
    bool ret = true;
    int i=0;
    while(i<strlen(c) && ret == true) {
        if(bloom_filter[int(c[i])%n] == false) {
            ret = false;
        }
        i++;
    }
    return ret;
}

// SB: ok
void destroy(bool* bloom_filter) {
    delete [] bloom_filter;
}

int strlen(char* c) {
    int i;
    for(i=0; c[i]!='\0'; i++) {}
    return i;
}