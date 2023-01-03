#include <iostream>

using namespace std;

bool * init(int n);
void add(bool array[], int n, char parola[]);
bool check(bool array[], int n, char parola[]);
void destroy(bool array[]);
int modulo(int n, int mod);

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
bool * init(int n){
    bool *array = new bool[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = false;
    }
    return array;
}

// SB: ok
void add(bool array[], int n, char parola[]){
    int i = 0;
    while (parola[i] != '\0')
    {
        int a = parola[i];
        if(a >= n){
            a = modulo(a,n);
        }
        if(array[a] == false){
            array[a]= true;
        }
        i++;
    }
}

// SB: ok
bool check(bool array[], int n, char parola[]){
    int i = 0;
    bool returnValue = true;
    while (parola[i] != '\0')
    {
        int a = parola[i];
        if(array[a] != true){
            returnValue = false;
        }
        i++;
    }
    return returnValue;
}

// SB: ok
void destroy(bool array[]){
    delete [] array;
}

int modulo(int n, int mod){
    while (n >= mod)
    {
        n-=mod;
    }
    return n;
}